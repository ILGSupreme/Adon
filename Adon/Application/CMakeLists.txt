if(${CMAKE_SYSTEM_NAME} MATCHES "Windows" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR
	${CMAKE_SYSTEM_NAME} MATCHES "Linux")

PROJECT(Application) # Editor Window


SUBDIRLIST(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

GETSRCFILES(APP_SOURCE ${SOURCE_DIR})
GETHEADERFILES(APP_HEAD ${SOURCE_DIR})

SET(EDITOR_FILES ${APP_HEAD} ${APP_SOURCE})
SET(EDITOR_SOURCE_FILES ${APP_SOURCE})
SET(EDITOR_HEADER_FILES ${APP_HEAD})

include_directories(${SOURCE_DIR} ${PROJECT_LIB_INCLUDES} ${EXTS_INCLUDES_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

SOURCE_GROUP("Source" FILES ${EDITOR_SOURCE_FILES})
SOURCE_GROUP("Header" FILES ${EDITOR_HEADER_FILES})
SOURCE_GROUP("Include" FILES ${EDITOR_INCLUDE_FILES})

add_executable(adon ${EDITOR_FILES})

if(BUILD_STATIC_LIBS)
target_link_libraries(adon glad glfw exts ${OPENGL_LIBRARIES} adonobjects_static)
add_dependencies(adon glfw exts adonobjects_static)
endif()

if(BUILD_SHARED_LIBS)
target_link_libraries(adon glad glfw exts ${OPENGL_LIBRARIES} adonobjects)
add_dependencies(adon glfw exts adonobjects)
endif()

target_include_directories(adon PUBLIC ${EXTS_INCLUDES_DIR} ${PROJECT_EXPORT_DIR})
OS_TEST_MACRO(adon)

if(BUILD_SHARED_LIBS)
	add_custom_command(TARGET adon POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:adonobjects>" $<TARGET_FILE_DIR:adon>)
	add_custom_command(TARGET adon POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:glfw>" $<TARGET_FILE_DIR:adon>)
	add_custom_command(TARGET adon POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:glad>" $<TARGET_FILE_DIR:adon>)
	add_custom_command(TARGET adon POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:tinyxml2>" $<TARGET_FILE_DIR:adon>)
endif()

SET_TARGET_PROPERTIES(adon PROPERTIES FOLDER "Adon/Application")

endif()
