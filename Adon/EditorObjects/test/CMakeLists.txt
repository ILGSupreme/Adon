project(Editor_Objects_Tests)

SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(XML_TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(EXCEPTION_FILE ${EXTS_INCLUDES_DIR}/exception/exception.h)

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)
FILE(GLOB XML_FILES ${XML_TESTFILES_DIR}/*.xml)

SOURCE_GROUP("Source" FILES ${TEST_FILES})
SOURCE_GROUP("XML" FILES ${XML_FILES})

include_directories(${EXTS_INCLUDES_DIR})

add_executable(editor_objects_test ${TEST_FILES} ${XML_FILES} ${EXCEPTION_FILE})

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
add_custom_command(TARGET editor_objects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/xmltestfile.xml $<TARGET_FILE_DIR:editor_objects_test>)
endif()
