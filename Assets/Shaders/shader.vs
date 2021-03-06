#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoords;

out vec4 ourColor;
out vec2 TexCoords;

void main()
{
    TexCoords = aTexCoords;
    ourColor = aColor;
    gl_Position =vec4(aPos, 1.0);
}
