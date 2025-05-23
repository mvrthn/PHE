cmake_minimum_required(VERSION 3.25)
project(PHE LANGUAGES CXX)

file(GLOB SRC_PATH "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(PHE ${SRC_PATH})
target_link_libraries(PHE PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(PHE PRIVATE cxx_std_23)

if(WIN32)
    add_custom_command(
        TARGET PHE
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PHE>
        VERBATIM)
endif()