cmake_minimum_required(VERSION 3.10)
project(EVC)

###### OPTIONS SECTION ######

option(BUILD_STATIC "Building static library" ON)
option(BUILD_SHARED "Building shared library" OFF)
option(BUILD_TESTS "Building tests for library" ON)

set(C_COMPILER "clang" CACHE STRING "Compiler for C")
set(OPT_LEVEL "3" CACHE STRING "Optimization level")

###### SETUP COMPILERS SECTION ######

find_program(C_COMPILER_PATH ${C_COMPILER})

if(C_COMPILER_PATH)
  message(STATUS "${C_COMPILER} found: ${C_COMPILER_PATH}")
  set(CMAKE_C_COMPILER ${C_COMPILER_PATH})
else()
  message(WARNING "${C_COMPILER} not found. Please install it.")
endif()

###### SETUP C SECTION ######

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/EVC
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O${OPT_LEVEL}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif()

###### INSTALL AND BUILDING SECTION ######

install(DIRECTORIES ${CMAKE_SOURCE_DIR}/EVC DESTINATION include)

file(GLOB_RECURSE LibSources
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/src/*.s
  ${CMAKE_SOURCE_DIR}/src/*.S
)

if(BUILD_STATIC)
  add_library(evc-static STATIC ${LibSources})
  set_target_properties(evc-static PROPERTIES OUTPUT_NAME evc)  
  install(TARGETS evc-static DESTINATION lib)
endif()

if(BUILD_SHARED)
  add_library(evc-shared SHARED ${LibSources})
  set_target_properties(evc-shared PROPERTIES OUTPUT_NAME evc)
  target_compile_options(evc-shared PRIVATE "-DAPI_SHARED_BUILD")
  install(TARGETS evc-shared DESTINATION lib)
endif()

###### TESTS SECTION ######

if(BUILD_TESTS)
  add_subdirectory(${CMAKE_SOURCE_DIR}/Tests/)
endif()

