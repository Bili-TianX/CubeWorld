#pragma once

#ifdef NDEBUG
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#endif

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "Util/Constant.hpp"