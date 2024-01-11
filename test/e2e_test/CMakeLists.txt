project(${PROJECT_NAME}E2ETest CXX)

add_executable(${PROJECT_NAME}
    test_main.cc
    game_setup_e2etest.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OBJLIB} GTest::gtest)

gtest_add_tests(TARGET ${PROJECT_NAME})