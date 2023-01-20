/**
 * @file GLGE3Dcore.cpp
 * @author DM8AT
 * @brief in this file, all files to use the 3D functions for GLGE are defined
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//include the 3d core
#include "GLGE3Dcore.h"

//include the GLGE dependencys
#include "GLGE/glgeErrors.h"
#include "GLGE/glgeVars.h"
#include "GLGE/glgeFuncs.h"
#include "GLGE/GLGEDefines.h"
#include "GLGE/glgePrivDefines.h"

//include needed CML librarys
#include "GLGE/CML/CMLQuaternion.h"

//include freeglut
#include <GL/freeglut.h>

//include the default librarys
#include <iostream>
#include <cstring>
#include <math.h>

/////////////////////
//PRIVATE FUNCTIONS//
/////////////////////

vec3 rotateVector(float angle, vec3 v, vec3 target)
{
    Quaternion RotationQ = Quaternion(angle, v);

    Quaternion ConjugateQ = RotationQ.conjugate();

    Quaternion W = (RotationQ * target) * ConjugateQ;

    return vec3(W.x,W.y,W.z);
}

//////////////////////
//PRIAVATE VAIRABLES//
//////////////////////

//store the camera GLGE is using
Camera* glgeMainCamera;

////////////////////////////
//Decalrations for Structs//
////////////////////////////

/////////////
//TRANSFORM//
/////////////

//default constructor
Transform::Transform()
{
    //initalise the object, say that it exists
}

//constructor using a position, rotation and a scale on 3 axis
Transform::Transform(vec3 pos, vec3 rot, vec3 scale)
{
    //set the values to the input
    this->pos = pos;
    //set the rotation to the rotation in radians
    this->rot.x = rot.x*GLGE_TO_RADIANS;
    this->rot.y = rot.y*GLGE_TO_RADIANS;
    this->rot.z = rot.z*GLGE_TO_RADIANS;
    this->scale = scale;
}

//constructor using a position, rotation and a uniform scale
Transform::Transform(vec3 pos, vec3 rot, float scale)
{
    //set position amd rotation to the inputs
    this->pos = pos;
    //set the rotation to the rotation in radians
    this->rot.x = rot.x*GLGE_TO_RADIANS;
    this->rot.y = rot.y*GLGE_TO_RADIANS;
    this->rot.z = rot.z*GLGE_TO_RADIANS;
    //set the scale to the input scale on all 3 axis
    this->scale = vec3(scale,scale,scale);
}

//get the transformation matrix for this point
mat4 Transform::getMatrix()
{
    //calculate the translation matrix
    mat4 transl = mat4(1, 0, 0, this->pos.x,
                       0, 1, 0, this->pos.y,
                       0, 0, 1, this->pos.z,
                       0, 0, 0, 1);
    
    //rotation on x axis
    mat4 rotXMat = mat4(1, 0,                     0,                     0,
                        0, std::cos(this->rot.x),-std::sin(this->rot.x), 0,
                        0, std::sin(this->rot.x), std::cos(this->rot.x), 0,
                        0, 0,                     0,                     1);

    //rotation on y axis
    mat4 rotYMat = mat4(std::cos(this->rot.y), 0, std::sin(this->rot.y), 0,
                        0,                     1,                     0, 0,
                       -std::sin(this->rot.y), 0, std::cos(this->rot.y), 0,
                        0,                     0,                     0, 1);

    //rotation on z axis
    mat4 rotZMat = mat4(std::cos(this->rot.z),-std::sin(this->rot.z), 0, 0,
                        std::sin(this->rot.z), std::cos(this->rot.z), 0, 0,
                        0,                     0,                     1, 0,
                        0,                     0,                     0, 1);

    //scaling matrix
    mat4 scaleMat = mat4(this->scale.x, 0, 0, 0,
                         0, this->scale.y, 0, 0,
                         0, 0, this->scale.z, 0,
                         0, 0, 0,             1);

    //return a multiplycation of the matrices
    return transl * scaleMat * ((rotXMat * rotYMat) * rotZMat);
}

//////////
//Vertex//
//////////

//default constructor
Vertex::Vertex()
{
    //initalise the vertex
}

//constuctor using a position and a color
Vertex::Vertex(vec3 pos, vec4 color)
{
    //set the position and the color to the input
    this->pos = pos;
    this->color = color;
    //set the texture coordinate to 0,0 and say to use the color
    this->texCoord = vec2(0,0);
    this->useTex = false;
}

//constructor usinga a position and a color out of a lot of floats
Vertex::Vertex(float x, float y, float z, float r, float g, float b, float a)
{
    //set the position and the color to the input
    this->pos = vec3(x,y,z);
    this->color = vec4(r,g,b,a);
    //set the texture coordinate to 0,0 and say to use the color
    this->texCoord = vec2(0,0);
    this->useTex = false;
}

//constructor using a position and a texture position
Vertex::Vertex(vec3 pos, vec2 texCoord)
{
    //set the position and the texCoord to the inputs and say to use a texture
    this->pos = pos;
    this->texCoord = texCoord;
    this->useTex = true;
    //set the color to 0,0,0,
    this->color = vec4(0,0,0,1);
}

//constructor using a position and a texture position from a lot of floates
Vertex::Vertex(float x, float y, float z, float tX, float tY)
{
    //set the position and the texCoord to the inputs and say to use a texture
    this->pos = vec3(x,y,z);
    this->texCoord = vec2(tX,tY);
    this->useTex = true;
    //set the color to 0,0,0,
    this->color = vec4(0,0,0,1);
}

////////
//MESH//
////////

//default constructor
Mesh::Mesh()
{
    //initalise the object
}

//construct a custom Mesh
Mesh::Mesh(Vertex *verts, unsigned int *ind, unsigned int verticesLength, unsigned int indicesLength)
{
    //check for errors
    bool error = false;

    //check if the vertices or the indices are a nullpointer
    if (verts == nullptr || ind == nullptr)
    {
        //output an warning message
        if(glgeWarningOutput)
        {
            printf(GLGE_WARNING_POINTER_IS_NULLPOINTER);
        }
        //say that something was wrong
        error = true;
    }

    //check if something was wrong
    if (error)
    {
        //say where the warning occured
        if(glgeWarningOutput)
        {
            std::cerr << GLGE_WARNING_POS_MESH_MESH << std::endl;
        }
        //stop this function
        return;
    }

    //get the storage space needet to store the vertices and indices
    this->vertices = (Vertex*) malloc(sizeof(Vertex)*verticesLength);
    this->indices = (unsigned int*) malloc(sizeof(unsigned int)*indicesLength);

    //if everything is correct, set the vertices and the indices to the input
    this->vertices = verts;
    this->indices = ind;

    //store the length of the two arrays
    this->amountVertices = verticesLength / sizeof(Vertex);
    this->indicesLength = indicesLength / sizeof(unsigned int);

    //set the amount of stored triangles
    this->amountTriangles = this->indicesLength/3;
}

//create a primitive object
Mesh::Mesh(const char* prim)
{
    //TODO//


    //check if the inputed primitive is a cube
    if (prim == (const char*)GLGE_DEFAULT_CUBE)
    {
        //set the indices and vertices so they resamble a cube
        this->vertices = (Vertex*)(Vertex[]){
                         Vertex(-1,-1, 1, 1,0,0,1),
                         Vertex( 1,-1, 1, 0,1,0,1),
                         Vertex(-1, 1, 1, 0,0,1,0),
                         Vertex( 1, 1, 1, 1,1,0,0),

                         Vertex(-1,-1,-1, 1,1,0,1),
                         Vertex( 1,-1,-1, 0,1,1,1),
                         Vertex(-1, 1,-1, 1,0,1,0),
                         Vertex( 1, 1,-1, 0,0,0,0),
                        };

    this->indices = (uint*)(uint[]){//front and back
                      0,2,1,
                      1,2,3,
                      4,5,6,
                      5,7,6,
                      //top and bottom
                      0,1,4,
                      1,5,4,
                      2,6,3,
                      3,6,7,
                      //left and right
                      0,4,2,
                      2,4,6,
                      1,3,5,
                      3,7,5};

        //store the amount of indices and vertices
        this->amountVertices = 8;
        this->indicesLength = 36;

        //store the amount of triangles
        this->amountTriangles = 12;

        return;
    }
}

//clear the mesh
void Mesh::clear()
{
    free(vertices);
    free(indices);
}

//delete the mesh
Mesh::~Mesh()
{
}

//replace the mesh by a mesh loaded from a file
void Mesh::loadFile(const char*)
{
    //load the file
}

//get the vertices
Vertex* Mesh::getVertices()
{
    return this->vertices;
}

//get the indices
unsigned int* Mesh::getIndices()
{
    return this->indices;
}

//////////
//OBJECT//
//////////

//PUBLIC

//default constructor
Object::Object()
{
    //initalise the object
}

//constructor using a mesh
Object::Object(Mesh mesh, Transform transform)
{
    //set the mesh to the local mesh
    this->mesh = mesh;

    //generate the buffers for the mesh
    generateBuffers(this->mesh);

    //save the transform to the object
    this->transf = transform;
}

Object::Object(Vertex* vertices, unsigned int* indices, unsigned int amountVertices, unsigned int indicesLength, Transform transform)
{
    //store the incoming mesh data
    this->mesh = Mesh(vertices, indices, amountVertices, indicesLength);

    //generate the vertex and index buffer
    generateBuffers(this->mesh);

    //store the transform
    this->transf = transform;
}

//constructor using a preset or file
Object::Object(const char* string, Transform transform)
{
    //check if the string is a preset for a cube
    if (string == (const char*)GLGE_DEFAULT_CUBE)
    {
        this->mesh = Mesh(GLGE_DEFAULT_CUBE);
    }
    else
    {
        //else load the file
        this->mesh.loadFile(string);
    }

    //generate the buffers for the mesh
    generateBuffers(this->mesh);

    //save the transform to the object
    this->transf = transform;
}

//constructor using allready existing buffers
Object::Object(GLuint vbo, GLuint ibo, Transform transform)
{
    //save the location of the buffers
    this->vbo = vbo;
    this->ibo = ibo;

    //store the transform
    this->transf = transform;
}

//draw the object
void Object::draw()
{
    //bind the buffers
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    //bind the sub elements
    //say where the position vector is
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    //say where the color is
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex, color));
    //say where texture coordinates are
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex, texCoord));

    //input the move matrix
    glUniformMatrix4fv(moveMatLoc, 1, GL_FALSE, &this->moveMatrix.m[0][0]);

    //draw the elements to the screen
    glDrawElements(GL_TRIANGLES, this->mesh.indicesLength*2, GL_UNSIGNED_INT, 0);

    //unbind the buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //disable all bound elements
    //disable position argument
    glDisableVertexAttribArray(0);
    //disable color argument
    glDisableVertexAttribArray(1);
    //disable texture coordinate argument
    glDisableVertexAttribArray(2);
}

//get the currently bound shader
GLint Object::getShader()
{
    //return the id of the currently bound shader
    return shader;
}

//bind and compile shaders
void Object::bindShader(const char* vs, const char* fs)
{
    //compile and bind the shader
    compileShader(vs, fs);
}

//bind and compile shader
void Object::bindShader(const char* file)
{
    //create two strings
    //store the path to the vertex shader
    std::string vs = file;
    //store the path to the fragment shader
    std::string fs = file;

    //add the suffixes
    vs += ".vs";
    fs += ".fs";

    //compile the shader
    compileShader(vs.c_str(), fs.c_str());
}

//bind an allready compiled shader
void Object::bindShader(GLint shaderProgram)
{
    //check if the input is valide
    if (shaderProgram < (GLint)1)
    {
        //print an error
        if (glgeErrorOutput)
        {
            //print an error message
            printf(GLGE_ERROR_INVALIDE_SHADER_INPUT);
            //say where the error occured
            std::cerr << GLGE_ERROR_STR_OBJECT_BIND_SHADER << std::endl;
        }
        //stop the program
        exit(1);
    }
    //if the input is valide store the input
    shader = shaderProgram;
}

void Object::bindShader(Object obj)
{
    //get the shader from the object
    GLint shader = obj.getShader();
    //bind the shader to this object
    this->bindShader(shader);
}

//update the object
void Object::update()
{
    //recalculate the move matrix
    calculateMoveMatrix();
}

//get the transform of the object
Transform Object::getTransform()
{
    //return the transform of this object
    return this->transf;
}

//set the transform of the object
void Object::applyTransform(Transform t)
{
    //set the transform of this object to the inputed transform
    this->transf = t;
}

//rotate the object
void Object::rotate(vec3 r)
{
    //rotate the object
    this->transf.rot += r.scale(vec3(GLGE_TO_RADIANS, GLGE_TO_RADIANS, GLGE_TO_RADIANS));
}

//rotate the object
void Object::rotate(float x, float y, float z)
{
    //rotate the object
    this->transf.rot += vec3(x*GLGE_TO_RADIANS, y*GLGE_TO_RADIANS, z*GLGE_TO_RADIANS);
}

//TODO//
void Object::move(float dist)
{
    //do something
    dist = dist;
}

//move the object
void Object::move(vec3 dist)
{
    //move the object on all 3 axis
    this->transf.pos += dist;
}

//move the object
void Object::move(float x, float y, float z)
{
    //move the object on all 3 axis
    this->transf.pos += vec3(x,y,z);
}

//scale the object
void Object::scale(float scale)
{
    //scale the object with the same on all 3 axis
    this->transf.scale += vec3(scale,scale,scale);
}

//scale the object
void Object::scale(vec3 scale)
{
    //scale the object differently on all 3 axis
    this->transf.scale += scale;
}

//scale the object
void Object::scale(float x, float y, float z)
{
    //scale the object differently on all 3 axis
    this->transf.scale += vec3(x,y,z);
}

//PRIVATE

//generate the buffers for the object
void Object::generateBuffers(Mesh mesh)
{
    //generate the vertex buffer for the object
    glGenBuffers(1, &this->vbo);
    //bind the vertex buffer object to store data
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    //store the mesh data in the vertex buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices[0])*(mesh.amountVertices), &(mesh.vertices[0]), GL_STATIC_DRAW);
    //unbind the vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //generate the index buffer
    glGenBuffers(1, &this->ibo);
    //bind the index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
    //store the index information in the index buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh.indices[0])*(mesh.indicesLength), &(mesh.indices[0]), GL_STATIC_DRAW);
    //unbind the index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//reacalculate the move matrix
void Object::calculateMoveMatrix()
{
    //objet transform matrix
    mat4 objMat = transf.getMatrix();

    //camera projection matrix
    mat4 projMat = glgeMainCamera->getProjectionMatrix();

    //camera view matrix
    mat4 viewMat = glgeMainCamera->getViewMatrix();
    
    //set the movement matrix
    this->moveMatrix = projMat*(viewMat*objMat);
}

//add a shader to an shader program
void Object::addShader(GLuint shaderProgram, const char* shadertext, GLenum shaderType)
{
    //create a new shader with the inputed type
    GLuint shaderObj = glCreateShader(shaderType);

    //check if the shader object could be created
    if (shaderObj == 0)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            std::cout << GLGE_ERROR_COULD_NOT_CREATE_SHADER << shaderType << std::endl;
            //print where the error occured
            std::cerr << GLGE_ERROR_STR_OBJECT_ADD_SHADER << std::endl;
        }
        //stop the script
        exit(1);
    }

    //set a GLchar to the inputed text
    const GLchar* p[1];
    p[0] = shadertext;

    //store the length of the text
    GLint lengths[1];
    lengths[0] = strlen(shadertext);

    //set the shader source code
    glShaderSource(shaderObj, 1, p, lengths);

    //compile to the new shader object
    glCompileShader(shaderObj);

    //check for compiling errors
    GLint success;
    glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);

    //if there was an error, print a message and exit
    if (!success)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            //create an info log to store the error created by open gl
            GLchar InfoLog[1024];
            glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
            //print the message
            printf(GLGE_ERROR_SHADER_COMPILE_ERROR, shaderType, InfoLog);
            //print where the error occured
            std::cerr << GLGE_ERROR_STR_OBJECT_ADD_SHADER << std::endl;
        }
        //stop the script
        exit(1);
    }

    //attach the shader object to the final program
    glAttachShader(shaderProgram, shaderObj);
}

//get a uniform variable from a shader
GLint Object::getUniformVar(GLuint program, const char* name)
{
    //create the output variable
    GLint ret;
    //set the output variable to the uniform variable in the shader
    ret = glGetUniformLocation(program, name);
    //if the id is -1, output an error
    if (ret == -1)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_UNIFORM_VAR_NOT_FOUND, name);
            //say where the error occured
            std::cerr << GLGE_ERROR_STR_OBJECT_GET_UNIFORM_VARIABLE << std::endl;
        }
        //stop the program
        exit(1);
    }
    //if no error occured, return the id of the uniform variable
    return ret;
}

//compile and add the shaders to this object
void Object::compileShader(const char* fileNameVS, const char* fileNameFS)
{
    //create a new shader program
    GLuint shaderProgram = glCreateProgram();

    //check if the shader could be created
    if (shaderProgram == 0)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_COULD_NOT_CREATE_SHADER);
            //say where the error occured
            std::cerr << GLGE_ERROR_STR_OBJECT_COMPILE_SHADERS << std::endl;
        }
        //stop the program
        exit(1);
    }

    //create strings for the shaders
    std::string vs, fs;

    //read the files
    if (!readFile(fileNameVS, vs))
    {
        //output an error message
        if (glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_OBJECT_COMPILE_SHADERS << std::endl;
        }
        //stop the script
        exit(1);
    }
    //add the shader program from the first file
    addShader(shaderProgram, vs.c_str(), GL_VERTEX_SHADER);

    //read the second file
    if (!readFile(fileNameFS, fs))
    {
        //if the file can't be read, output an error message
        if (glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_OBJECT_COMPILE_SHADERS << std::endl;
        }
        //stop the program
        exit(1);
    }
    //add the shader program from the second file
    addShader(shaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

    //create an variable to check for success
    GLint success = 0;
    //setup an error log
    GLchar ErrorLog[1024] = {0};

    //link the shader program
    glLinkProgram(shaderProgram);

    //get the program iv from the shader
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    //check if the program linking was no success
    if (success == 0)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            //get the error from open gl and output it with an custom message
            glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
            printf(GLGE_ERROR_SHADER_VALIDATE_ERROR, ErrorLog);
        }
        //stop the program
        exit(1);
    }

    //store the location of the move matrix in the shader
    moveMatLoc = getUniformVar(shaderProgram, glgeMoveMatrix);

    //check if the program is valide
    glValidateProgram(shaderProgram);
    //get the program iv again
    glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
    //check for success
    if (!success)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            //get the error from open gl and output it with an custom message
            glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
            printf(GLGE_ERROR_SHADER_VALIDATE_ERROR, ErrorLog);
        }
        //stop the program
        exit(1);
    }

    //say open GL to use the shader program
    glUseProgram(shaderProgram);
    //save the shader program in the GLGE Object
    shader = shaderProgram;
}

//////////
//CAMERA//
//////////

//PUBLIC

//default constructor
Camera::Camera()
{
    //initalise the object
}

//initalise with parameters
Camera::Camera(float FOV, float near, double far, Transform transform)
{
    //check for errors
    bool error = false;

    //check if the FOV is 0 or less
    if (FOV <= 0)
    {
        //output an error
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_CAMERA_FOV_LESS_EQUAL_ZERO, FOV);
        }
        //say that an error occured
        error = true;
    }
    //check if the near cliping plane is 0 or less
    if (near <= 0)
    {
        //output an error
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_CAMERA_NEAR_LESS_EQUAL_ZERO, near);
        }
        //say that an error occured
        error = true;
    }
    //check if the far cliping plane is 0 or less
    if (far <= 0)
    {
        //output an error
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_CAMERA_FAR_LESS_EQUAL_ZERO, far);
        }
        //say that an error occured
        error = true;
    }
    //check if the far cliping plane is less or equal to the near cliping plane
    if (far <= near)
    {
        //output an error
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_CAMERA_FAR_LESS_EQUAL_NEAR);
        }
        //say that an error occured
        error = true;
    }

    //if an error occured
    if (error)
    {
        //output where the error occured
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_CAMERA_CAMERA << std::endl;
        }
        //stop the script
        exit(1);
    }

    //if no error occured, store the variables
    this->fov = FOV*GLGE_TO_RADIANS;
    this->near = near;
    this->far = far;
    this->transf = transform;
}

//update the view matrix
void Camera::update()
{
    //recalculate the view matrix
    this->viewMatrix = this->calculateViewMatrix();
}

//update the projection matrix
void Camera::recalculateProjection()
{
    //recalculate the projection matrix
    this->projectionMatrix = this->calculateProjectionMatrix();
}

//get the view matrix
mat4 Camera::getViewMatrix()
{
    //return the view matrix
    return this->viewMatrix;
}

//get the projection matrix
mat4 Camera::getProjectionMatrix()
{
    //return the projection matrix
    return this->projectionMatrix;
}

//movement stuff

//apply a new transform to the camera
void Camera::applyTransform(Transform t)
{
    //set the transform to the inputed transform
    this->transf = t;
}

//set the position of the camera
void Camera::set(vec3 p)
{
    //apply the new position
    this->transf.pos = p;
}

//set the position of the camera
void Camera::set(float x, float y, float z)
{
    //apply the new position
    this->transf.pos = vec3(x,y,z);
}

//move the camera
void Camera::move(vec3 v)
{
    //change the position of the camera
    this->transf.pos += v;
}

//move the camera
void Camera::move(float x, float y, float z)
{
    //change the position of the camera
    this->transf.pos += vec3(x,y,z);
}

//set the rotation of the camera
void Camera::setRotation(vec2 r)
{
    //apply the new rotation
    this->transf.rot = vec3(r.x,r.y,0);
}

//set the rotation of the camera
void Camera::setRotation(float x, float y)
{
    //apply the new rotation
    this->transf.rot = vec3(x,y,0);
}

//rotate the camera
void Camera::rotate(vec2 r)
{
    //rotate the camera
    this->transf.rot += vec3(r.x,r.y,0);
}

//rotate the camera
void Camera::rotate(float x, float y)
{
    //rotate the camera
    this->transf.rot += vec3(x,y,0);
}

//set the field of view from the camera
void Camera::setFOV(float f)
{
    //apply the new fov
    this->fov = f*GLGE_TO_RADIANS;
}

//change the field of view
void Camera::sizeFOV(float df)
{
    //change the fov
    this->fov += (df*GLGE_TO_RADIANS);
}

//change the fov


//PRIVATE

mat4 Camera::calculateViewMatrix()
{
    //store a vector for the y axis
    vec3 yaxis = vec3(up.x,up.y,up.z);
    //start rotation things
    //calculate the view vector
    //setup the vector to face right
    vec3 view = vec3(right.x,right.y,right.z);
    //rotathe the vector around the y axis by the x rotation amount
    view = rotateVector(transf.rot.x,yaxis, view);
    //normaise the vector
    view.normalize();

    //rotate the view vector and calculate U
    //calculate the cross product of the yaxis and the view vector
    vec3 U = view.cross(yaxis);
    //normalise the U vector
    U.normalize();
    //rotate the view vector around U by the rotation on the y axis
    view = rotateVector(transf.rot.y, U, view);
    
    //setup the vectors
    //N is equal to the view vector
    vec3 N = view;
    //noralise N
    N.normalize();

    //V is the cross product of U and N. Both are normalised, so no normalistion needed
    vec3 V = U.cross(N);

    //setup the view matrix
    //IMPORTANT: the vectors are in reversd order!
    mat4 vRotMat = mat4(U.z,U.y,U.x,0,
                        V.z,V.y,V.x,0,
                        N.z,N.y,N.x,0,
                        0,  0,  0,  1);

    mat4 vTraMat = mat4(1,0,0,-transf.pos.x,
                        0,1,0,-transf.pos.y,
                        0,0,1,-transf.pos.z,
                        0,0,0,1);

    mat4 viewMat = vRotMat * vTraMat;

    //TEMP: DEBUG
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << viewMat.m[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //return the matrix
    return viewMat;
}

mat4 Camera::calculateProjectionMatrix()
{
    float ar = glgeWindowAspect;
    float zRange = far - near;
    float tHF = std::tan((fov/2.f));

    return mat4(1.f/(tHF*ar), 0.f, 0.f, 0.f,
                0.f, 1/tHF, 0.f, 0.f,
                0.f, 0.f, (-near - far)/zRange, (2.f*far * near) / zRange,
                0.f, 0.f, 1.f, 0.f);
}

/////////////
//FUNCTIONS//
/////////////

//bind a camera
void glgeBindCamera(Camera* camera)
{
    //check if the inputed parameter is valide
    if (camera == nullptr)
    {
        //output an error
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_INPUT_NULLPOINTER);
            //say where the error occured
            std::cerr << GLGE_ERROR_STR_BIND_MAIN_CAMERA << std::endl;
        }
        //stop the program
        exit(1);
    }
    //else bind the camera
    glgeMainCamera = camera;
}

//initalise for 3D
void glgeInit3DCore()
{
    //set the depth test correctly
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
}