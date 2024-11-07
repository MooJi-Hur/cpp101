cmake_minimum_required(VERSION 3.30)
project(cpp101)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)


# Find all lecture folders that contain main.cpp
file(GLOB_RECURSE LECTURE_MAIN_FILES "src/*/main.cpp")

# Iterate over each main.cpp file to create an executable
foreach(MAIN_FILE ${LECTURE_MAIN_FILES})
    # Extract the directory name from the path to use as the target name
    get_filename_component(LECTURE_DIR ${MAIN_FILE} DIRECTORY)
    get_filename_component(LECTURE_NAME ${LECTURE_DIR} NAME)

    # Gather all .cpp files within the directory
    file(GLOB LECTURE_SRC_FILES "${LECTURE_DIR}/*.cpp")

    # Create an executable for each lecture
    add_executable(${LECTURE_NAME} ${LECTURE_SRC_FILES})

    # Set output directory for the executable
    set_target_properties(${LECTURE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${LECTURE_NAME})
endforeach()
