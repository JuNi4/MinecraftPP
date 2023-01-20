/**
 * @file GLGE3Dcore.h
 * @author DM8AT
 * @brief this is the 3D core for GLGE. It is used to create 3D graphics and such things. DEPENDECYS: GLGE.h
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//check for double include 
#ifndef _GLGE_3D_CORE_H_
#define _GLGE_3D_CORE_H_

//include glew
#include <GL/glew.h>

//include the needed components from CML
//vectors
#include "GLGE/CML/CMLVec3.h"
#include "GLGE/CML/CMLVec2.h"
//matrices
#include "GLGE/CML/CMLMat4.h"

///////////
//STRUCTS//
///////////

/**
 * @brief a variable type to store position, rotation and scaling information for an object
 * 
 * the transform type is used by objects of the GLGE library to capsule all the movement operations in one varaiable, to not have a lot
 * of different variables to have in an object. 
 */
struct Transform
{
    vec3 pos;
    vec3 rot;
    vec3 scale;

    /**
     * @brief Construct a new Transform
     * 
     * default constructor
     */
    Transform();

    /**
     * @brief Construct a new Transform
     * 
     * @param position the position data stored in the transform
     * @param rotation the rotation stored in the transform
     * @param scale the size information stored in the transform
     */
    Transform(vec3 position, vec3 rotation, vec3 scale);

    /**
     * @brief Construct a new Transform
     * 
     * @param position the position of the transform
     * @param rotation the rotation of the transform
     * @param scale the scale on all axis of the transform
     */
    Transform(vec3 position, vec3 rotation, float scale);

    /**
     * @brief Get the Matrix to transform an object to this
     * 
     * @return mat4 transformation matrix
     */
    mat4 getMatrix();
};

/**
 * @brief this variable stores information about a single vertex of an Object
 */
struct Vertex
{
    //information about the vertex

    //the position in 3D space
    vec3 pos;
    //the color of the vertex
    vec4 color;
    //where to sample a texture
    vec2 texCoord;
    //should the color or a texture be used?
    bool useTex;

    /**
     * @brief Construct a new Vertex
     * 
     * default constructor
     */
    Vertex();

    /**
     * @brief Construct a new Vertex
     * 
     * using a color for the vertex
     * 
     * @param position the position of the vertex in 3D space
     * @param color the color of the vertex
     */
    Vertex(vec3 position, vec4 color=vec4(1,0,0,1));

    /**
     * @brief Construct a new Vertex
     * 
     * unsing a color for the vertex
     * 
     * @param x the x position for the vertex
     * @param y the y position for the vertex
     * @param z the z position for the vertex
     * @param r the amount of red in the color
     * @param g the amount of green in the color
     * @param b the amount of blue in the color
     * @param a the transparency of the vertex
     */
    Vertex(float x, float y, float z, float r=1, float g=0, float b=0, float a=1);

    /**
     * @brief Construct a new Vertex
     * 
     * using a texture
     * 
     * @param position the position of the vertex in 3D space
     * @param texturePosition where to sample the texture for this vertex
     */
    Vertex(vec3 position, vec2 texturePosition);

    /**
     * @brief Construct a new Vertex
     * 
     * @param x the x position for the vertex
     * @param y the y position for the vertex
     * @param z the z position for the vertex
     * @param tX the X position for the texture sampler
     * @param tY the Y position for the texture sampler
     */
    Vertex(float x, float y, float z, float tX, float tY);
};

/**
 * @brief stores data for a 3D object
 * 
 * This variable stores the exterior data for every object. 
 */
struct Mesh
{
    //the vartices and how to conect them into triangles

    //the vertices of the mesh
    Vertex* vertices;
    //how to conect the mesh
    unsigned int* indices;

    //the amount of vertices
    unsigned int amountVertices;
    //the length of the indices
    unsigned int indicesLength;

    //store the amount of triangles in the mesh
    unsigned int amountTriangles;

    /**
     * @brief Construct a new Mesh
     * 
     * the mesh stores information about the visuals of an object
     */
    Mesh();

    /**
     * @brief Construct a new Mesh
     * 
     * @param vertices the vertices for the object
     * @param indices how to conect the vertices
     * @param verticesLength the length of the vertices array (sizeof(vertices))
     * @param indicesLength the length of the indices array (sizeof(indices))
     */
    Mesh(Vertex *vertices, unsigned int *indices, unsigned int verticesLength, unsigned int indicesLength);

    /**
     * @brief Construct a new Mesh
     * 
     * PRIMITIVES:
     * - Cube : a default cube : name: "CUBE" ; define: GLGE_DEFAULT_CUBE
     * 
     * @param primitive the name of the primitive to use
     */
    Mesh(const char* primitive);

    /**
     * @brief override the loaded mesh with a mesh from a file
     * 
     * @param filename the name of the file to get it from
     */
    void loadFile(const char* filename);

    /**
     * @brief deletes the data stored in the mesh
     * 
     * call this if the mesh is supposed to be reused or deleted
     */
    void clear();

    /**
     * @brief Destroy the Mesh
     */
    ~Mesh();

    /**
     * @brief Get the Vertices
     * 
     * @return Vertex* a pointer to a lot of vertices
     */
    Vertex* getVertices();

    /**
     * @brief Get the Indices
     * 
     * @return unsigned int* how the points are conected to triangles
     */
    unsigned int* getIndices();
};

///////////
//CLASSES//
///////////

/**
 * @brief a simple 3D object, used by GLGE for basically everything that has to do with 3D graphics
 */
class Object
{
public:
    /**
     * @brief Construct a new Object
     * 
     * A object is, what can be drawn to the screen. 
     */
    Object();

    /**
     * @brief Construct a new Object
     * 
     * @param mesh the mesh for the object. It defines how the object looks
     * @param transform the transform of the object. It says where the object is and how it is
     */
    Object(Mesh mesh, Transform transform = Transform());

    /**
     * @brief Construct a new Object
     * 
     * @param vertices the vertices for the object
     * @param indices the indices for the object
     * @param amountVertices the amount of incoming vertices (sizeof(vertices))
     * @param indicesLength the amount of incoming indices (sizeof(indices))
     * @param transform the transform of the object. It says where the object is and how it is
     */
    Object(Vertex* vertices, unsigned int* indices, unsigned int amountVertices, unsigned int indicesLength, Transform transform = Transform());

    /**
     * @brief Construct a new Object
     * 
     * @param string the string contains information on where to get the object data. It can be a preset, that is also supported by the mesh Preset, or a file path.
     * @param transform the transform of the object. It says where the object is and how it is
     */
    Object(const char* string, Transform transform = Transform());

    /**
     * @brief Construct a new Object
     * 
     * @param vertexBuffer says where the vertex buffer for this object is
     * @param indexBuffer says where on the graphics card the index buffer for this object is
     * @param transform the transform of the object. It says where the object is and how it is
     */
    Object(GLuint vertexBuffer, GLuint indexBuffer, Transform transform = Transform());

    /**
     * @brief draw the object to the screen
     */
    void draw();

    /**
     * @brief compile and bind a vertex and a fragment shader to the object
     * 
     * @param vertexShader the path to the file that stores the vertex shader
     * @param fragmentShader the path to the file that stores the fragment shader
     */
    void bindShader(const char* vertexShader, const char* fragmentShader);

    /**
     * @brief compile and bind a vertex and a fragment shader to the object
     * 
     * Vertx shader suffix: .vs
     * Fragment shader suffix: .fs
     * 
     * @param filePrefix the path and the prefix of two files with different suffixes
     */
    void bindShader(const char* filePrefix);

    /**
     * @brief bind a shader program to this object
     * 
     * @param shaderProgram the id of the shader program
     */
    void bindShader(GLint shaderProgram);

    /**
     * @brief get the shader from this object and use it
     * 
     * @param objectForShader the object to get the shader from
     */
    void bindShader(Object objectForShader);

    /**
     * @brief Get the Shader id of this Object
     * 
     * @return GLint the id of the shader
     */
    GLint getShader();

    /**
     * @brief update the object
     * CALCULATE:
     * - move matrix
     */
    void update();

    /**
     * @brief Get the Transform from this object
     * 
     * @return Transform the transform of this object
     */
    Transform getTransform();

    /**
     * @brief apply a specific transform to an object
     * 
     * @param transform the transform to use
     */
    void applyTransform(Transform transform);

    /**
     * @brief rotate the object around all axis
     * 
     * @param angle the angle for the different axis
     */
    void rotate(vec3 angle);

    /**
     * @brief rotate the object around all axis
     * 
     * @param x rotation on x axis
     * @param y rotation on y axis
     * @param z rotation on z axis
     */
    void rotate(float x, float y, float z);

    /**
     * @brief move the object
     * 
     * --TODO--
     * 
     * @param distance the distance to move it in a direction
     */
    void move(float distance);

    /**
     * @brief move the object on all 3 axis
     * 
     * @param distance the distance for the 3 axis to move the object
     */
    void move(vec3 distance);

    /**
     * @brief move the object on all 3 axis
     * 
     * @param x the distance for the x axis
     * @param y the distance for the y axis
     * @param z the distance for the z axis
     */
    void move(float x, float y, float z);

    /**
     * @brief scale the object
     * 
     * @param scale the scale for all 3 axis
     */
    void scale(float scale);

    /**
     * @brief scall the object on all 3 axis
     * 
     * @param scale the scale for all 3 axis
     */
    void scale(vec3 scale);

    /**
     * @brief scale the object on all 3 axis
     * 
     * @param x the scale for the x axis
     * @param y the scale for the y axis
     * @param z the scale for the z axis
     */
    void scale(float x, float y, float z);

private:

    //PRIVATE VARIABLES

    //store the position, rotation and scale of the object
    Transform transf;
    //store the mesch of the object
    Mesh mesh;
    //stores where the Vertex buffer is
    GLuint vbo;
    //stores where the index buffer is
    GLuint ibo;
    //store the compiled fragment and vertex shader
    GLuint shader;
    //store the location of the move matrix for the shader
    GLint moveMatLoc;
    //store the final movement matrix
    mat4 moveMatrix = mat4(1,0,0,0,
                           0,1,0,0,
                           0,0,1,0,
                           0,0,0,1);

    //PRIVATE FUNCTIONS

    /**
     * @brief this function compiles an inputed mesh into the vertex and index shader
     * 
     * @param mesh the mesh for the shaders
     */
    void generateBuffers(Mesh mesh);

    /**
     * @brief recalculate the move matrix
     */
    void calculateMoveMatrix();

    /**
     * @brief Get a uniform variable in a shader
     * 
     * @param shaderProgram the program to get the variable from
     * @param name the name of the variable
     */
    GLint getUniformVar(GLuint shaderProgram, const char* name);

    /**
     * @brief add a new shader object
     * 
     * @param shaderProgram the program it should be added to
     * @param shadertext the text for the shader code
     * @param shaderType the type of the shader
     */
    void addShader(GLuint shaderProgram, const char* shadertext, GLenum shaderType);

    /**
     * @brief this function compiles the inputed two files into shaders
     * 
     * @param vertex the file for the vertex shader
     * @param fragment the file for the fragment shader
     */
    void compileShader(const char* vertex, const char* fragment);
};

/**
 * @brief a Camera used for 3D projection, position usw
 */
class Camera
{
public:
    /**
     * @brief default constructor
     */
    Camera();

    /**
     * @brief Construct a new Camera
     * 
     * @param FOV the field of view for the camera
     * @param near the near cliping plane for the camera
     * @param far the far cliping plane for the camera
     * @param transform the position and rotation of the camera. Scaling is ignored. 
     */
    Camera(float FOV, float near = 0.1, double far = 10.0, Transform transform = Transform());

    /**
     * @brief update the view matrix
     */
    void update();

    /**
     * @brief recalculate the projection matrix
     */
    void recalculateProjection();

    /**
     * @brief Get the View Matrix for the camera
     * 
     * @return mat4 the view matrix for the camera
     */
    mat4 getViewMatrix();

    /**
     * @brief Get the Projection Matrix for the camera
     * 
     * @return mat4 the projection matrix for the camera
     */
    mat4 getProjectionMatrix();

    /**
     * @brief apply a specific transform to the camera
     * 
     * @param transform the new transform for the camera
     */
    void applyTransform(Transform transform);

    /**
     * @brief position the camera new
     * 
     * @param position the new position for the camera
     */
    void set(vec3 position);

    /**
     * @brief position the camera new
     * 
     * @param x the new x position for the camera
     * @param y the new y position for the camera
     * @param z the new z position for the camera
     */
    void set(float x, float y, float z);

    /**
     * @brief move the camera in a direction
     * 
     * @param deltaDir an angle between the camera and the vector to move it
     * @param speed the speed to move the camera
     */
    void move(float deltaDir, float speed);

    /**
     * @brief move the camera
     * 
     * @param deltaPosition the difference from the old to the new position
     */
    void move(vec3 deltaPosition);

    /**
     * @brief move the camera
     * 
     * @param dX the difference on the x axis
     * @param dY the difference on the y axis
     * @param dZ the difference on the z axis
     */
    void move(float dX, float dY, float dZ);

    /**
     * @brief Set the Rotation of the camera
     * 
     * @param rotation the new rotation for the camera
     */
    void setRotation(vec2 rotation);

    /**
     * @brief Set the Rotation of the camera
     * 
     * @param x the x rotation for the camera
     * @param y the y rotation for the camera
     */
    void setRotation(float x, float y);

    /**
     * @brief rotate the camera
     * 
     * @param deltaRotation the difference for the rotation
     */
    void rotate(vec2 deltaRotation);

    /**
     * @brief rotate the camera
     * 
     * @param dX the difference of rotation on the x axis
     * @param dY the difference of rotation on the y axis
     */
    void rotate(float dX, float dY);

    /**
     * @brief set the field of view of the camera
     * 
     * @param fov the new field of view for the camera
     */
    void setFOV(float fov);

    /**
     * @brief change the size of the field of view
     * 
     * @param deltaFOV the difference in the size of the field of view
     */
    void sizeFOV(float deltaFOV);

private:
    //store the right direction of the camera
    vec4 right = vec4(1,0,0,0);
    //store the left direction of the camera
    vec4 left = vec4(-1,0,0,0);
    //store the up direction of the camera
    vec4 up = vec4(0,1,0,0);
    //store the down direction of the camera
    vec4 down = vec4(0,-1,0,0);
    //store the forward direction of the camera
    vec4 forward = vec4(0,0,1,0);
    //store the backwards direction of the camera
    vec4 backward = vec4(0,0,-1,0);
    //store the position of the camera in camera space
    vec4 position = vec4(0,0,0,1);
    //store the field of view for the camera
    float fov = 90.f;
    //store the near cliping plane
    float near = 0.1f;
    //store the far cliping plane
    double far = 10.0;
    //store the transform of the camera
    Transform transf;

    //store the view matrix
    mat4 viewMatrix;
    //store the projection matrix
    mat4 projectionMatrix;

    //calculate the view matrix
    mat4 calculateViewMatrix();

    //calculate the projection matrix
    mat4 calculateProjectionMatrix();
};

/////////////
//FUNCTIONS//
/////////////

/**
 * @brief bind a camera to use by GLGE to use
 * 
 * @param camera a pointer to the camera so parameters can be changed later
 */
void glgeBindCamera(Camera* camera);

/**
 * @brief initalise the 3D core. Call directly after createing the window
 * 
 * this function initalises all values to draw 3D things
 */
void glgeInit3DCore();

#endif