if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	
project(adwin_test)
SET(TESTFILES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

FILE(GLOB TEST_FILES ${TESTFILES_SOURCE_DIR}/*.cpp)

SOURCE_GROUP("Source" FILES ${TEST_FILES})

add_executable(adwin_test ${TEST_FILES})

if(BUILD_STATIC_LIBS)
target_link_libraries(adwin_test adwin_static)
add_dependencies(adwin_test adwin_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(adwin_test adwin)
add_dependencies(adwin_test adwin)
endif()

set_target_properties(adwin_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}/adon/adwin/tests/${CMAKE_BUILD_TYPE}"
)

if(BUILD_SHARED_LIBS)
add_custom_command(TARGET adwin_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:adwin>" $<TARGET_FILE_DIR:adwin_test>)
add_custom_command(TARGET adwin_test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:glfw>" $<TARGET_FILE_DIR:adwin_test>)
endif()
endif()