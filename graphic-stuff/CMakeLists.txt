include_directories(${SDL2_INCLUDE})
include_directories(${GLM_INCLUDE})
include_directories(${SDL2_IMAGE_INCLUDE})
include_directories(${GLEW_INCLUDE})
set(PROJ_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJ_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source)

include_directories(${PROJ_INCLUDE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# https://stackoverflow.com/questions/34863374/how-to-use-cmake-file-glob-srcs-with-a-build-directory
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.11.0")
    file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.h *.cpp ${PROJ_SOURCE}/*.cpp ${PROJ_INCLUDE}/*.h)
else()
    file(GLOB SOURCE_FILES *.cpp *.h */*.h */*.cpp)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LIB_DIR ${LIBRARIES}/x64)
    set(OUTPUT_DIR ${BIN_DIR}/x64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(LIB_DIR ${LIBRARIES}/Win32)
    set(OUTPUT_DIR ${BIN_DIR}/Win32)
endif()

link_directories(${LIB_DIR})

find_library(glew32 glew32.lib ${LIB_DIR})
find_library(SDL2 SDL2.lib ${LIB_DIR})
find_library(SDL2_image SDL2_image.lib ${LIB_DIR})
find_library(SDL2main SDL2main.lib ${LIB_DIR})
find_library(OpenGL32 opengl32.lib)


add_executable(graphic-stuff ${SOURCE_FILES})
target_link_libraries(graphic-stuff glew32 OpenGL32 SDL2 SDL2_image SDL2main)

set_target_properties(graphic-stuff PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

install(TARGETS graphic-stuff RUNTIME DESTINATION ${OUTPUT_DIR}/_install)
