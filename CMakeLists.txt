cmake_minimum_required(VERSION 3.20)
project(LauncherProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------
# Ensure git submodules are initialized
# -------------------------------
execute_process(
    COMMAND git submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GIT_SUBMOD_RESULT
)

if(NOT GIT_SUBMOD_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to initialize/update git submodules. Make sure git is installed.")
endif()

# -------------------------------
# Launcher executable
# -------------------------------
add_executable(launcher launcher.cpp)

# Set output directory for launcher.exe
set_target_properties(launcher PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# -------------------------------
# Build Logisim (Windows)
# -------------------------------
add_custom_target(build_logisim ALL
    COMMAND gradlew.bat build -x test
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/logisim-evolution
    COMMENT "Building Logisim-Evolution..."
)

# -------------------------------
# Build RARS (Windows)
# -------------------------------
add_custom_target(build_rars ALL
    COMMAND cmd /c build-jar.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/rars
    COMMENT "Building RARS..."
)

# -------------------------------
# Launcher depends on submodules
# -------------------------------
add_dependencies(launcher build_logisim build_rars)

# -------------------------------
# Copy JARs to launcher bin folder
# -------------------------------
set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
file(MAKE_DIRECTORY ${BIN_DIR})

# Copy Logisim JAR
add_custom_command(TARGET launcher POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/logisim-evolution/build/libs/logisim-evolution-4.1.0dev-all.jar
        ${BIN_DIR}/
)

# Copy RARS JAR
add_custom_command(TARGET launcher POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/rars/rars.jar
        ${BIN_DIR}/
)

# Copy launcher.exe
add_custom_command(TARGET launcher POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${BIN_DIR}/Debug/launcher.exe
        ${CMAKE_CURRENT_BINARY_DIR}/
)
