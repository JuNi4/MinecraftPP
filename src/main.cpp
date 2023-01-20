//test script to check if GLGE works, no real commenting of the script
#include "GLGE.h"
#include "GLGE3Dcore.h"

#include <iostream>

#include "save/options.h"


#include <iostream>
#include <fstream>
#include <algorithm>

Object test;
Camera camera;

float camSpeed = 0.005;
float camRot = 0.0025;

void display()
{
    //draw the object
    test.draw();
}

void mainLoop()
{
    //update the projection matrix
    camera.recalculateProjection();
    camera.update();
    //update the object
    //test.rotate(0.5,0.131,0);
    test.update();

    if (glgeGetKeys().w)
    {
        camera.move(0,0,camSpeed*glgeGetDeltaTime());
    }
    if (glgeGetKeys().s)
    {
        camera.move(0,0,-camSpeed*glgeGetDeltaTime());
    }
    if (glgeGetKeys().a)
    {
        camera.move(-camSpeed*glgeGetDeltaTime(),0,0);
    }
    if (glgeGetKeys().d)
    {
        camera.move(camSpeed*glgeGetDeltaTime(),0,0);
    }
    if (glgeGetKeys().space)
    {
        camera.move(0,camSpeed*glgeGetDeltaTime(),0);
    }
    if (glgeGetKeys().shift)
    {
        camera.move(0,-camSpeed*glgeGetDeltaTime(),0);
    }

    if (glgeGetKeys().arrowUp)
    {
        camera.rotate(0,camRot*glgeGetDeltaTime());
    }
    if (glgeGetKeys().arrowDown)
    {
        camera.rotate(0,-camRot*glgeGetDeltaTime());
    }
    if (glgeGetKeys().arrowRight)
    {
        camera.rotate(-camRot*glgeGetDeltaTime(),0);
    }
    if (glgeGetKeys().arrowLeft)
    {
        camera.rotate(camRot*glgeGetDeltaTime(),0);
    }
}

int main(int argc, char** argv)
{
    // Config Tests
    

    // std::ifstream is RAII, i.e. no need to call close
    std::ifstream cFile ("src/save/options.txt");
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
            continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            //std::cout << name << " " << value << '\n';
            // Set Options
            if (name == "fps") {FPS = std::stoi(value);}
            if (name == "renderDistance") {renderDistance = std::stoi(value);}
            if (name == "fov") {FOV = std::stoi(value);}
            if (name == "title") {windowTitle = value.c_str();}
        }
        
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
    }

    //init functions
    glgeInit(argc, argv);
    glgeCreateWindow(windowTitle, 600,600);
    glgeInit3DCore();
    //setup
    glgeSetMaxFPS(FPS);
    glgeSetClearColor(.5,.5,.5);
    glgeBindDisplayFunc(display);
    glgeBindMainFunc(mainLoop);

    //object setup - rainbow cube
    Vertex vertices[] = {
                         Vertex(-1,-1, 1, 1,0,0,1),
                         Vertex( 1,-1, 1, 0,1,0,1),
                         Vertex(-1, 1, 1, 0,0,1,0),
                         Vertex( 1, 1, 1, 1,1,0,0),

                         Vertex(-1,-1,-1, 1,1,0,1),
                         Vertex( 1,-1,-1, 0,1,1,1),
                         Vertex(-1, 1,-1, 1,0,1,0),
                         Vertex( 1, 1,-1, 0,0,0,0),
                        };

    uint indices[] = {//front and back
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

    test = Object(vertices, indices, sizeof(vertices), sizeof(indices), Transform(vec3(0,0,0),vec3(0,0,0),1));
    test.bindShader(GLGE_DEFAULT_3D_SHADER);

    //camera setup
    camera = Camera(FOV, 0.1, renderDistance, Transform(vec3(0,0,-5),vec3(0,0,0),1));
    camera.update();
    camera.recalculateProjection();
    glgeBindCamera(&camera);

    glgeRunMainLoop();
    return 0;
}