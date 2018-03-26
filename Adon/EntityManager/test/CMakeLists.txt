project(xmreader_tests)

SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(XML_TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)
FILE(GLOB XML_FILES ${XML_TESTFILES_DIR}/*.xml)

SOURCE_GROUP("Source" FILES ${TEST_FILES})
SOURCE_GROUP("XML" FILES ${XML_FILES})

add_executable(entitymanager_test ${TEST_FILES} ${XML_FILES})

if(BUILD_STATIC_LIBS)
target_link_libraries(entitymanager_test entitymanager_static)
add_dependencies(entitymanager_test entitymanager_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(entitymanager_test entitymanager)
add_dependencies(entitymanager_test entitymanager)
endif()

OS_TEST_MACRO(entitymanager_test)

#set_target_properties(adem_tests
#    PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}/adon/adem/tests/${CMAKE_BUILD_TYPE}"
#)

#needs fixing..
if(BUILD_SHARED_LIBS)
add_custom_command(TARGET entitymanager_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:entitymanager>" $<TARGET_FILE_DIR:entitymanager_test>)
add_custom_command(TARGET entitymanager_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:tinyxml2>" $<TARGET_FILE_DIR:entitymanager_test>)
endif()
