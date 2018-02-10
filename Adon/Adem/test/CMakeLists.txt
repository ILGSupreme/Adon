project(adem_tests)

SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(XML_TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "XML_TESTFILES_DIR=${XML_TESTFILES_DIR}")

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)
FILE(GLOB XML_FILES ${XML_TESTFILES_DIR}/*.xml)

SOURCE_GROUP("Source" FILES ${TEST_FILES})
SOURCE_GROUP("XML" FILES ${XML_FILES})

add_executable(adem_tests ${TEST_FILES} ${XML_FILES})
include_directories(adem)
target_link_libraries(adem_tests adem)
add_dependencies(adem_tests adem)

set_target_properties( adem_tests
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ROOT_DIR}/build/adon/adem/test/bin"
)

add_custom_command(TARGET adem_tests POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:adem>" $<TARGET_FILE_DIR:adem_tests>)