#include "Constant.hpp"

const std::string Constant::VERTEX_SHADER_SOURCE = R"(
#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vTexPos;

out vec2 fTexPos;

void main()
{
    gl_Position = vec4(vPos, 1.0);
    fTexPos = vTexPos;
}
)";

const std::string Constant::FRAGMENT_SHADER_SOURCE = R"(
#version 330 core

in vec2 fTexPos;

out vec4 fColor;

uniform sampler2D fTex;

void main()
{
    fColor = texture(fTex, fTexPos);
}
)";