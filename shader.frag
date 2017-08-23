#version 330 core
layout (location=0) out vec4 vFragColor;
in vec2 vUV;
uniform sampler2D textureMap;

void main()
{                                              
    vFragColor = texture(textureMap, vUV);
}
