#version 310 es

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 iColor;
layout (location = 2) in vec2 iTexcoord;
uniform mat4 moveMat;

out vec4 color;
out vec2 texCoord;

void main()
{
    color = iColor;
    texCoord = iTexcoord;
    gl_Position = vec4(pos ,1.0) * moveMat;
}