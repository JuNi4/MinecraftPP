#version 300 es

precision mediump float;
out vec4 FragColor;

in vec4 color;
in vec2 texCoord;

void main()
{
    FragColor = color;
}