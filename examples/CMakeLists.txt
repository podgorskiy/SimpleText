cmake_policy(SET CMP0072 NEW)

option (GLFW_BUILD_EXAMPLES OFF)
option (GLFW_BUILD_TESTS OFF)
option (GLFW_INSTALL OFF)
option (USE_MSVC_RUNTIME_LIBRARY_DLL OFF)
set(SKIP_INSTALL_ALL ON CACHE BOOL "Skip install" FORCE)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

include(CheckTypeSize)
include(CheckFunctionExists)
include(CheckIncludeFile)

##############################################################
# Setup compiler options and configurations
##############################################################

if(MSVC)
    add_definitions(-D__STDC_LIMIT_MACROS)
    add_definitions(-D__STDC_FORMAT_MACROS)
    add_definitions(-D__STDC_CONSTANT_MACROS)
    add_definitions(-D__STDC_LIMIT_MACROS)
    add_definitions(-D__STDC_FORMAT_MACROS)
    add_definitions(-D__STDC_CONSTANT_MACROS)
    add_definitions(-D_HAS_EXCEPTIONS=0)
    add_definitions(-D_SCL_SECURE)
    add_definitions(-D_SECURE_SCL)
    add_definitions(-D_ALLOW_KEYWORD_MACROS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    add_definitions(-DWINVER=0x0602)
    add_definitions(-D_WIN32_WINNT=0x0602)
    add_definitions(-DNTDDI_VERSION=0x06020000)
    set(COMMON_OPTIONS /W3 /wd4996 /we4239 /we4002 /we4700 /we4305 -DGUID_WINDOWS /EHsc /MP)
    set(DEBUG_OPTIONS /MTd /Od /Zi)
    set(RELEASE_OPTIONS /MT /Ox /fp:fast /GL /GR- -DUSE_ARCHIVE -DSTATIC_CONST)
elseif(APPLE)
    set(COMMON_OPTIONS -DGUID_CFUUID)
    set(DEBUG_OPTIONS -g)
    set(RELEASE_OPTIONS -Os -DUSE_ARCHIVE -DSTATIC_CONST)
else()
    set(COMMON_OPTIONS -DGUID_LIBUUID)
    set(DEBUG_OPTIONS -g)
    set(RELEASE_OPTIONS -Os -DUSE_ARCHIVE -DSTATIC_CONST)
endif()

set(DEBUG_OPTIONS ${DEBUG_OPTIONS} ${COMMON_OPTIONS})
set(RELEASE_OPTIONS ${RELEASE_OPTIONS} ${COMMON_OPTIONS})

add_compile_options(
        "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>"
        "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /DEBUG")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG /INCREMENTAL:NO")
endif()


find_package(OpenGL)

if (OPENGL_FOUND)
    message("OpenGL Correctly Found")
    include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
    message("OpenGL environment missing")
endif (OPENGL_FOUND)

##############################################################
# Generating OpenGL profile
##############################################################
message("Executing gl3w_gen.py")
execute_process(COMMAND python ${PROJECT_SOURCE_DIR}/examples/libs/gl3w/gl3w_gen.py WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/examples/libs/gl3w)



##############################################################
# Externals
##############################################################
add_subdirectory(libs/glfw)
add_subdirectory(libs/gl3w)

include_directories(libs/glfw/include)

add_executable(simple_text_example ${PROJECT_SOURCE_DIR}/examples/glfw_example.cpp)

target_link_libraries(simple_text_example glfw gl3w ${OPENGL_LIBRARIES})
