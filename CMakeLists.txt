cmake_minimum_required(VERSION 3.26)
project(PTTAT_DM_GTFS)

set(CMAKE_CXX_STANDARD 20)

# ----------------------------------------------
# Data structure

add_subdirectory(modules/PTTAT-structure)

# Include structure
if(DEFINED PTTAT_S_exist)
    include_directories(${PTTAT_S_PATH}/include)
    include_directories(${PTTAT_S_PATH}/libraries)

else()
    include(ExternalProject)
    ExternalProject_Add(PTTAT_Structure
            GIT_REPOSITORY https://github.com/FilipCysEk/PTTAT-structure.git
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/modules
            )
    include_directories(modules/PTTAT-structure/include)
    include_directories(modules/PTTAT-structure/libraries)

    set(PTTAT_S_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules/PTTAT-structure)

endif()

# ----------------------------------------------
# Libraries


# ----------------------------------------------
# Start library

add_library(PTTAT_DM_GTFS SHARED src/GtfsDirector.cpp)

target_link_libraries(PTTAT_DM_GTFS PTTAT_structure)
target_link_libraries(PTTAT_DM_GTFS spdlog::spdlog)

set_target_properties(PTTAT-DM-GTFS PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
