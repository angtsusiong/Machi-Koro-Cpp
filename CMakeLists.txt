cmake_minimum_required(VERSION 3.15)
project(MachiKoroCPP CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(OBJLIB ${PROJECT_NAME}Obj)

foreach(DIR controllers filters models models/card models/events plugins usecases)
    aux_source_directory(${DIR} OBJLIB_SRC)
endforeach()
add_library(${OBJLIB} OBJECT ${OBJLIB_SRC})

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${OBJLIB} PUBLIC Drogon::Drogon)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OBJLIB})

find_package(GTest REQUIRED)
enable_testing()
add_subdirectory(test/unittest)
add_subdirectory(test/e2e_test)