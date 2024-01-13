cmake_minimum_required(VERSION 3.5.0)
project(raylib-project VERSION 0.1.0 LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Copy all the required libs and main executable to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)

# Collect all the source and header files
file(GLOB ALL_SOURCE_FILES src/*.cpp)
file(GLOB ALL_HEADER_FILES include/*.hpp)

# Add the main target.
add_executable(${PROJECT_NAME} ${ALL_SOURCE_FILES} ${ALL_HEADER_FILES})

# Use C++17 standards
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Include directories for main target
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include/
)
