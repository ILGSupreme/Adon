PROJECT(Editor_Objects) #Adon Entity Manager

include(GenerateExportHeader)

SET(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
SET(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

FILE(GLOB APP_INCLUDE_HEAD ${INCLUDE_DIR}/*.h)
FILE(GLOB APP_HEAD ${SOURCE_DIR}/*.h)
FILE(GLOB APP_SOURCE ${SOURCE_DIR}/*.cpp)

SET(ADEM_FILES ${APP_HEAD} ${APP_SOURCE})
SET(ADEM_SOURCE_FILES ${APP_SOURCE})
SET(ADEM_HEADER_FILES ${APP_HEAD})
SET(ADEM_INCLUDE_FILES ${APP_INCLUDE_HEAD})

include_directories(${SOURCE_DIR})

SOURCE_GROUP("Source" FILES ${ADEM_SOURCE_FILES})
SOURCE_GROUP("Header" FILES ${ADEM_HEADER_FILES})
SOURCE_GROUP("Include" FILES ${ADEM_INCLUDE_FILES})

if(BUILD_STATIC_LIBS)
add_library(editor_objects_static STATIC ${ADEM_FILES})
target_link_libraries(editor_objects_static tinyxml2_static exts)
generate_export_header(editor_objects_static EXPORT_FILE_NAME ${PROJECT_EXPORT_DIR}/editor_objects_exports.h)
add_dependencies(editor_objects_static tinyxml2_static)
target_include_directories(editor_objects_static PUBLIC ${PROJECT_EXPORT_DIR})
OS_BUILD_MACRO(editor_objects_static)
endif()

if(BUILD_SHARED_LIBS)
add_library(editor_objects SHARED ${ADEM_FILES})
target_link_libraries(editor_objects tinyxml2 exts)
generate_export_header(editor_objects EXPORT_FILE_NAME ${PROJECT_EXPORT_DIR}/editor_objects_exports.h)
add_dependencies(editor_objects tinyxml2)
target_include_directories(editor_objects PUBLIC ${PROJECT_EXPORT_DIR})
OS_BUILD_MACRO(editor_objects)
endif()

add_subdirectory(test)

if(BUILD_STATIC_LIBS)
SET_TARGET_PROPERTIES(editor_objects_static PROPERTIES FOLDER "Adon/EditorObjects")
endif()
if(BUILD_SHARED_LIBS)
SET_TARGET_PROPERTIES(editor_objects PROPERTIES FOLDER "Adon/EditorObjects")
endif()
SET_TARGET_PROPERTIES(editor_objects_test PROPERTIES FOLDER "Adon/EditorObject/tests")
