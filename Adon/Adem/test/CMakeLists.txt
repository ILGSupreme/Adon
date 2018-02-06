project(adem_tests)

SET(TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(ADEM_LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.../bin/debug)

FILE(GLOB TEST_FILES ${TESTFILES_DIR}/*.cpp)

add_executable(adem_tests ${TEST_FILES})
include_directories(adem)
target_link_libraries(adem_tests ${CMAKE_SOURCE_DIR}/Adon/Adem/bin/debug/adem.dll)
add_dependencies(adem_tests adem)
