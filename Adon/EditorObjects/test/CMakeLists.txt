project(Editor_Objects_Tests)

SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(XML_TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)
FILE(GLOB XML_FILES ${XML_TESTFILES_DIR}/*.xml)

SOURCE_GROUP("Source" FILES ${TEST_FILES})
SOURCE_GROUP("XML" FILES ${XML_FILES})

add_executable(editor_objects_test ${TEST_FILES} ${XML_FILES})

if(BUILD_STATIC_LIBS)
target_link_libraries(editor_objects_test editor_objects_static)
add_dependencies(editor_objects_test editor_objects_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(editor_objects_test editor_objects)
add_dependencies(editor_objects_test editor_objects)
endif()

OS_TEST_MACRO(editor_objects_test)

#needs fixing..
if(BUILD_SHARED_LIBS)
add_custom_command(TARGET editor_objects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:editor_objects>" $<TARGET_FILE_DIR:editor_objects_test>)
add_custom_command(TARGET editor_objects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:tinyxml2>" $<TARGET_FILE_DIR:editor_objects_test>)
configure_file(xmltestfile.xml ${PROJECT_BIN_DIR}/adon/${project_target}/${OS_PLATFORM}/${CMAKE_BUILD_TYPE}/xmltestfile.xml COPYONLY)
endif()
