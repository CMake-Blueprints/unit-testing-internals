cmake_minimum_required(VERSION 3.25...3.30)
project(MyProject VERSION 1.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(BUILD_TESTING "Build the tests" ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

if(BUILD_TESTING)
  enable_testing()
endif()

add_subdirectory(mylib)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
