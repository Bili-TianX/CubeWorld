cmake_minimum_required(VERSION 3.25)
project(CubeWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH bin)

file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Stb REQUIRED)

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
elseif (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    add_executable(${PROJECT_NAME} ${SOURCES})
endif ()

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})