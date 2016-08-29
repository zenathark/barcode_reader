cmake_minimum_required(VERSION 3.4.0)


# =========================================================================
#
#                           Main Project Section
#
# =========================================================================

# Project name
set(PROJECT_NAME_STR barcode_scanner)

# Project language
project(${PROJECT_NAME_STR} C CXX)

# Source Files
file(GLOB MAIN_SRC "src/*.cpp")
file(GLOB TEST_SRC "test/*.cpp")


# Platform project specific code
# if(WIN32)
#   set(MAIN_SRC ${MAIN_SRC} ${PROJECT_SOURCE_DIR}/platform/windows.c)
# else ()
#   set(MAIN_SRC ${MAIN_SRC} ${PROJECT_SOURCE_DIR}/platform/unix.c)
# endif()

#Main Executable
add_executable(${PROJECT_NAME_STR} ${MAIN_SRC})

# Output build path
set_target_properties(${PROJECT_NAME_STR}
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
include_directories(${PROJECT_SOURCE_DIR}/include)

# 3rd party libs
set(EXTRA_DEPS_PATH ${PROJECT_SOURCE_DIR}/extra)
set(EXTRA_LIBS_PATH ${PROJECT_BINARY_DIR}/extra)

# =========================================================================
#
#                              Test Section
#
# =========================================================================

enable_testing()
set(GTEST_PATH ${EXTRA_DEPS_PATH}/googletest/googletest)
set(GTEST_LIB_PATH ${EXTRA_LIBS_PATH}/googletest/googletest)

add_subdirectory(${GTEST_PATH})
include_directories(${GTEST_PATH}/include)
# find_library(GTEST gtest ${EXTRA_LIBS_PATH}/googletest/googletest)
# find_library(GTESTMAIN gtest ${EXTRA_LIBS_PATH}/googletest/googletest)

# Project test name(s)
set(PROJECT_TEST ${PROJECT_NAME_STR}_test)

# Project Test(s) executables
add_executable(${PROJECT_TEST} ${TEST_SRC})

# Project test Output path
set_target_properties(${PROJECT_TEST}
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
)

target_link_libraries(${PROJECT_TEST} ${GTEST_LIB_PATH}/libgtest.a ${GTEST_LIB_PATH}/libgtest_main.a)

# Using Google Test Unit
# find_package(GTest REQUIRED)

# =========================================================================
#
#                              Zlib Section
#
# =========================================================================

set(ZLIB_PATH ${EXTRA_DEPS_PATH}/zlib)
set(ZLIB_LIB_PATH ${EXTRA_LIBS_PATH}/zlib)
set(ZLIB_INCLUDE_DIR ${EXTRA_DEPS_PATH}/zlib ${EXTRA_LIBS_PATH}/zlib)
set(ZLIB_LIBRARY_RELEASE ${EXTRA_LIBS_PATH}/zlib)

add_subdirectory(${ZLIB_PATH})
include_directories(${ZLIB_PATH}/include)

# =========================================================================
#
#                              libpng Section
#
# =========================================================================

set(PNG_PATH ${EXTRA_DEPS_PATH}/libpng)
set(PNG_LIB_PATH ${EXTRA_LIBS_PATH}/libpng)

add_subdirectory(${PNG_PATH})
include_directories(${PNG_PATH})
# =========================================================================
#
#                             Logging Section
#
# =========================================================================

# Logger spdlog, only headers are required
# set(LOGGER_PATH ${EXTRA_LIBS_PATH}/spdlog)
# include_directories(${LOGGER_PATH}/include)

# spdlog requrie c++11 extension
# target_compile_features(${PROJECT_NAME_STR} PRIVATE cxx_alias_templates)


# =========================================================================
#
#                       Command Line Flags Section
#
# =========================================================================

# Using Google Flags Library for command line flags parsing
# Flags compiled libs per platform
# if(APPLE)
#   set(GFLAGS_PATH ${EXTRA_LIBS_PATH}/gflags/osx)
# elseif(WIN32)
#   set(GFLAGS_PATH ${EXTRA_LIBS_PATH}/gflags/win)
# else()
#   set(GFLAGS_PATH ${EXTRA_LIBS_PATH}/gflags/unix)
# endif()

# Headers
# include_directories(${GFLAGS_PATH}/include)

# Links OSX
# if(APPLE)
#   target_link_libraries(${PROJECT_NAME_STR} ${GFLAGS_PATH}/lib/libgflags_nothreads.dylib)
# endif()
