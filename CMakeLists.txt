cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

project(tmp_rk2)

add_library(visitor_lib STATIC
    src/city.cpp
    src/house.cpp
    src/industry.cpp
    src/xmlvisitor.cpp
)

include_directories(visitor_lib
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(main src/main.cpp)
target_link_libraries(main visitor_lib)


if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
  add_executable(check ${TEST_SOURCES})
  target_link_libraries(check gtest_main visitor_lib)
  add_test(NAME check COMMAND check)
endif()