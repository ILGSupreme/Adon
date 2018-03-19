if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Linux")

project(Editor_tests)
SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)

SOURCE_GROUP("Source" FILES ${TEST_FILES})

add_executable(editor_test ${TEST_FILES})

if(BUILD_STATIC_LIBS)
target_link_libraries(editor_test editor_static)
add_dependencies(editor_test editor_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(editor_test editor)
add_dependencies(editor_test editor)
endif()

set_target_properties(editor_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}/adon/adwin/tests/${CMAKE_BUILD_TYPE}"
)

if(BUILD_SHARED_LIBS)
add_custom_command(TARGET editor_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:editor>" $<TARGET_FILE_DIR:editor_test>)
add_custom_command(TARGET editor_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:glfw>" $<TARGET_FILE_DIR:editor_test>)
endif()
endif()
