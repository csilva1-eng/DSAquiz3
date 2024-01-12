cmake_minimum_required(VERSION 3.22)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

#compile flags to match Gradescope test environment
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main

include_directories(src)

#the first word is the name of the executble
# everything else are the files to include - yours will probably look a bit different than mine
add_executable(Main
        src/main.cpp # your main
        # add your own header files below
        )

#this one doesn't include main, instead having your test.cpp
add_executable(Tests #this will be named Project1 by default - either change it to Tests or see the comment at the bottom of the file
        test.cpp # your test file
        # add your own header files below
        )
        
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain) #link catch to test.cpp file
# the name here must match that of your testing executable (the one that has test.cpp)

include(CTest)
include(Catch)
catch_discover_tests(Tests) # must be named the same as your test executable