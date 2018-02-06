project(adem_tests)

SET(TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(ADEM_LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.../bin/debug)

FILE(GLOB TEST_FILES ${TESTFILES_DIR}/*.cpp)

add_executable(adem_tests ${TEST_FILES})
include_directories(adem)
target_link_libraries(adem_tests adem)
add_dependencies(adem_tests adem)

set_target_properties( adem_tests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ROOT_DIR}/build/adon/adem/test/bin"
)

add_custom_command(TARGET adem_tests POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:adem>" $<TARGET_FILE_DIR:adem_tests>)