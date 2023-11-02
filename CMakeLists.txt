cmake_minimum_required(VERSION 3.5)

cmake_path(GET CMAKE_SOURCE_DIR FILENAME PROJECT_ID)
string(REPLACE " " "_" PROJECT_NAME ${PROJECT_ID})

project(${PROJECT_NAME}
        VERSION 1.0.0
        LANGUAGES CXX
)

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(${PROJECT_NAME} src/main.cpp)