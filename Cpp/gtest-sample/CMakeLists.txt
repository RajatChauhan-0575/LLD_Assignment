cmake_minimum_required(VERSION 3.10)

project(calculator)

add_executable(calculator Calc.cpp CalcTest.cpp)
target_compile_features(calculator PUBLIC cxx_std_17)

set(gtest_inc /opt/homebrew/Cellar/googletest/1.14.0/include/)
set(gtest_lib /opt/homebrew/Cellar/googletest/1.14.0/lib)

target_include_directories(calculator PUBLIC "${gtest_inc}")

target_link_directories(calculator PUBLIC "${gtest_lib}")

target_link_libraries(calculator gtest gtest_main)