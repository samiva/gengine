cmake_minimum_required(VERSION 3.11)
project(gengine)

set(CMAKE_CXX_STANDARD 17)
# set(GENGINE_SOURCE ${CMAKE_SOURCE_DIR}/graphic-stuff/source)
# set(GENGINE_INCLUDES ${CMAKE_SOURCE_DIR}/graphic-suff/include)
set(SDL2_INCLUDE ${CMAKE_SOURCE_DIR}/deps/SDL2-2.0.12/include)
set(GLM_INCLUDE ${CMAKE_SOURCE_DIR}/deps/glm)
set(SDL2_IMAGE_INCLUDE ${CMAKE_SOURCE_DIR}/deps/SDL2_image-2.0.5/include)
set(GLEW_INCLUDE ${CMAKE_SOURCE_DIR}/deps/glew-2.1.0/include/GL)


set(LIBRARIES ${CMAKE_SOURCE_DIR}/deps)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(graphic-stuff)

