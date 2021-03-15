cmake_minimum_required(VERSION 3.8)
project(hello_world)
INCLUDE_DIRECTORIES(code/include)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(SOURCE_LIB code/src/megafile.c code/src/myfilter.c code/src/myinput.c)	

add_library(study_std_lib STATIC ${SOURCE_LIB})
add_executable(prog code/src/main.c)
target_link_libraries(prog study_std_lib)

#enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})
message(${GTEST_INCLUDE_DIRS})

add_executable(tests code/src/tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests study_std_lib)
