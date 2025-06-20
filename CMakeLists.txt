cmake_minimum_required(VERSION 3.15)
project(freud VERSION 1.0.1 DESCRIPTION "freud is an image analyst")

# Set everything to use our image library
set(ESTIA_IMAGE_PATH ${CMAKE_SOURCE_DIR}/estia-image)
set(GETOPT_PATH ${CMAKE_SOURCE_DIR}/getopt)
 
# Include directory
include_directories( ${ESTIA_IMAGE_PATH}/include )
include_directories( ${GETOPT_PATH}/include )

# Add executable files : NOTE it is a bad way of doing it since you would
# Need to rerun cmake . -B build to be sure they are in the correct folder
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/ SOURCE_FILES)
add_executable( freud ${SOURCE_FILES})

target_compile_options(freud PRIVATE -Wall -Wextra)
#target_compile_options(freud PRIVATE -Wall -Wextra -Wpedantic -Werror)
# Find the Library
find_library(ESTIA_IMAGE_LIB
    NAMES estia-image
    HINTS "${ESTIA_IMAGE_PATH}/lib"
)

# Find the Library
find_library(GETOPT_LIB
    NAMES getopt
    HINTS "${GETOPT_PATH}/lib"
)
# Link it
target_link_libraries( freud PUBLIC ${ESTIA_IMAGE_LIB})
target_link_libraries( freud PUBLIC ${GETOPT_LIB})

install(TARGETS freud
        CONFIGURATIONS Debug
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR})
install(TARGETS freud
        CONFIGURATIONS Release
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/dist
)
