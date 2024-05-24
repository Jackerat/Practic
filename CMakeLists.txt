cmake_minimum_required(VERSION 3.16)
project(test2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "tools/*.h")
include_directories(tools)
include_directories(tools)

file(GLOB FILES "files/*.png" "files/*.ttf")
file(COPY ${FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/files)

add_executable(test2 ${SOURCES} ${HEADERS}
        main.cpp)

target_link_libraries(test2 PRIVATE sfml-graphics)
target_compile_features(test2 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET test2
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:test2>
            VERBATIM)
endif()

install(TARGETS test2)
install(FILES ${FILES} DESTINATION build/files)

