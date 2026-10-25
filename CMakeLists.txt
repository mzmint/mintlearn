cmake_minimum_required(VERSION 4.3)
project(MintLearn)

set(CMAKE_CXX_STANDARD 20)

add_executable(MintLearn main.cpp)

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(json)

target_link_libraries(MintLearn PRIVATE nlohmann_json::nlohmann_json)
