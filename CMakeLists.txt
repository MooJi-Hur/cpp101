cmake_minimum_required(VERSION 3.30)
project(cpp101)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files for each lecture
file(GLOB_RECURSE SRC_FILES "src/*/*.cpp")

# Create an executable for the project
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Set output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
