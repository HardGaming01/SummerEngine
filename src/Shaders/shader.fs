#version 330 core
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoords;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float degree;

void main()
{
    FragColor = mix(texture(texture1, TexCoords), texture(texture2, TexCoords), 0.5) * ourColor;
}
