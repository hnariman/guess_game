enable_testing()

add_executable( game_test main.cpp)

find_package(GTest)
target_link_libraries(game_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(game_test)
