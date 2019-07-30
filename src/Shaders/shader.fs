#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 ourColor

uniform sampler2D texture_diffuse1;

void main()
{
    FragColor = texture(texture_diffuse1, TexCoords) * vec4(ourColor, 1.0);
}