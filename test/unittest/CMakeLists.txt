project(${PROJECT_NAME}Unittest CXX)

add_executable(${PROJECT_NAME}
    game_unittest.cpp
    operate_effect_unittest.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OBJLIB} GTest::gtest GTest::gtest_main)

gtest_add_tests(TARGET ${PROJECT_NAME})