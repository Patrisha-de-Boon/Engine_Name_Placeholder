cmake_minimum_required(VERSION 3.0)

project(Engine_Name_Placeholder)

set(GLFW "/path/to/glfw" CACHE STRING "glfw file location")
set(deps ${GLFW}/deps/)

set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -std=c++11")

set(alldeps 
    PUBLIC ${deps}/glad.c
    PUBLIC ${deps}/linmath.h
    PUBLIC ${deps}/tinycthread.c
    PUBLIC ${deps}/getopt.c
    PUBLIC ${deps}/getopt.h
    PUBLIC ${deps}/tinycthread.h
    PUBLIC ${deps}/glad/glad.h
    PUBLIC ${deps}/KHR/khrplatform.h
    PUBLIC ${deps}/mingw/dinput.h
    PUBLIC ${deps}/mingw/_mingw_dxhelper.h
    PUBLIC ${deps}/mingw/xinput.h
    PUBLIC ${deps}/vulkan/vulkan.h
    PUBLIC ${deps}/vulkan/vk_platform.h
)

set(sourcefiles
    src/particles.c
)

include_directories(${deps})
include_directories(${GLFW}/include/)

add_executable(particles ${sourcefiles})

target_sources(particles ${alldeps})

target_link_libraries(particles -lGL)
target_link_libraries(particles -lglfw3)
target_link_libraries(particles -lX11)
target_link_libraries(particles -lXxf86vm)
target_link_libraries(particles -lXrandr)
target_link_libraries(particles -lpthread)
target_link_libraries(particles -lXi)
target_link_libraries(particles -ldl)
target_link_libraries(particles -lm)
target_link_libraries(particles -lXcursor)
target_link_libraries(particles -lXinerama)
target_link_libraries(particles -lrt)
