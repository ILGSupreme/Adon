project(AdonObjects_Test)

SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(XML_TESTFILES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(EXCEPTION_FILE ${EXTS_INCLUDES_DIR}/exception/exception.h)

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)
FILE(GLOB XML_FILES ${XML_TESTFILES_DIR}/*.xml)

SOURCE_GROUP("Source" FILES ${TEST_FILES})
SOURCE_GROUP("XML" FILES ${XML_FILES})

include_directories(${EXTS_INCLUDES_DIR})

add_executable(adonobjects_test ${TEST_FILES} ${XML_FILES} ${EXCEPTION_FILE})

if(BUILD_STATIC_LIBS)
target_link_libraries(adonobjects_test adonobjects_static)
add_dependencies(adonobjects_test adonobjects_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(adonobjects_test adonobjects)
add_dependencies(adonobjects_test adonobjects)
endif()

OS_TEST_MACRO(adonobjects_test)

#needs fixing..
if(BUILD_SHARED_LIBS)
add_custom_command(TARGET adonobjects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:adonobjects>" $<TARGET_FILE_DIR:adonobjects_test>)
add_custom_command(TARGET adonobjects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:tinyxml2>" $<TARGET_FILE_DIR:adonobjects_test>)
add_custom_command(TARGET adonobjects_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/xmltestfile.xml $<TARGET_FILE_DIR:adonobjects_test>)
endif()
