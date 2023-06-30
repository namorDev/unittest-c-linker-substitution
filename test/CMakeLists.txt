cmake_minimum_required(VERSION 3.14)
project(my_project)

# From: https://google.github.io/googletest/quickstart-cmake.html

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  led_test
  led_test.cpp
  ${CMAKE_CURRENT_LIST_DIR}/../src/led.c
  ${CMAKE_CURRENT_LIST_DIR}/test_doubles/zephyr/drivers/gpio_mock.cpp
)
target_link_libraries(
    led_test
  GTest::gtest_main
  GTest::gmock_main
)

target_include_directories(led_test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../src ${CMAKE_CURRENT_LIST_DIR}/test_doubles)

include(GoogleTest)
gtest_discover_tests(led_test)