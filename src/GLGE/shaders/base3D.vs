#version 300 es

layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texcoord;
uniform mat4 moveMat;

layout (location = 0) out vec4 FragmentColor;
layout (location = 1) out vec2 FragmentTexcoord;

void main()
{
    FragmentColor = color;
    FragmentTexcoord = texcoord;
    gl_Position = vec4(pos ,1.0) * moveMat;
}