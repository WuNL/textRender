#version 330 core
layout(location=0) in vec4 vVertex; //object space vertex
out vec2 vUV;   // texture coordinates for texture lookup in the fragment shader

void main()
{
    gl_Position = vec4(vVertex.xy,0,1);
    vUV = vVertex.zw; // texture coordinate
}
