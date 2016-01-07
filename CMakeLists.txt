cmake_minimum_required (VERSION 2.6)

project (MyRythmFever)

include_directories(source)

file(GLOB SOURCES "source/*.cpp")

# SDL2 headers
#set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/build")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_Image REQUIRED)
#find_package(SDL2_ttf REQUIRED)

#include_directories(${SDL2_INCLUDE_DIR}
#${SDL2_IMAGE_INCLUDE_DIR}
#${SDL2_TTF_INCLUDE_DIR})
#target_link_libraries(target ${SDL2_LIBRARY}
#${SDL2_IMAGE_LIBRARIES}
#${SDL2_TTF_LIBRARIES})

find_package(SDL)

add_executable(myRythmFever ${SOURCES})

include_directories(MyRythmFever ${SDL2_INCLUDE_DIR})
link_libraries(MyRythmFever ${SDL2_LIBRARY})
