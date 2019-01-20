cmake_minimum_required(VERSION 3.0)

project(Engine_Name_Placeholder)

set(GLFW "/path/to/glfw" CACHE STRING "glfw file location")
set(deps ${GLFW}/deps/)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(exe "engine")

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
    src/main.cpp
    src/mainloop.cpp
    src/mainloop.h
    src/callbacks.cpp
    src/callbacks.h
    src/globals.h
)

include_directories(${deps})
include_directories(${GLFW}/include/)

add_executable(${exe} ${sourcefiles})

target_sources(${exe} ${alldeps})

target_link_libraries(${exe} -lGL)
target_link_libraries(${exe} -lglfw3)
target_link_libraries(${exe} -lX11)
target_link_libraries(${exe} -lXxf86vm)
target_link_libraries(${exe} -lXrandr)
target_link_libraries(${exe} -lpthread)
target_link_libraries(${exe} -lXi)
target_link_libraries(${exe} -ldl)
target_link_libraries(${exe} -lm)
target_link_libraries(${exe} -lXcursor)
target_link_libraries(${exe} -lXinerama)
target_link_libraries(${exe} -lrt)

include_directories(/path/to/glm CACHE STRING "glm library location")
find_package(glm REQUIRED)
