cmake_minimum_required(VERSION 3.10)
project(pi_approximations)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

include_directories(vendor/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/glfw/include)

include_directories(vendor/imgui-plot/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/imgui-plot/include)

set(IMGUI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor)
add_subdirectory(vendor/imgui-plot)

target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    imgui
    imgui_plot
)