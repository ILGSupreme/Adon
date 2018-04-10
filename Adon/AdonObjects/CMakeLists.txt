PROJECT(AdonObjects) #Adon Entity Manager

include(GenerateExportHeader)

SUBDIRLIST(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

GETSRCFILES(APP_SOURCE ${SOURCE_DIR})
GETHEADERFILES(APP_HEAD ${SOURCE_DIR})

SET(ADEM_FILES ${APP_HEAD} ${APP_SOURCE})
SET(ADEM_SOURCE_FILES ${APP_SOURCE})
SET(ADEM_HEADER_FILES ${APP_HEAD})

include_directories(${SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

SOURCE_GROUP("Source" FILES ${ADEM_SOURCE_FILES})
SOURCE_GROUP("Header" FILES ${ADEM_HEADER_FILES})

if(BUILD_STATIC_LIBS)
add_library(adonobjects_static STATIC ${ADEM_FILES})
target_link_libraries(adonobjects_static tinyxml2_static exts)
generate_export_header(adonobjects_static EXPORT_FILE_NAME ${PROJECT_EXPORT_DIR}/adonobjects_exports.h)
add_dependencies(adonobjects_static tinyxml2_static)
target_include_directories(adonobjects_static PUBLIC ${PROJECT_EXPORT_DIR})

OS_BUILD_MACRO(adonobjects_static)

file(MAKE_DIRECTORY ${EXTS_INCLUDES_DIR}/adonobjects)
add_custom_target(copy_files ALL COMMAND ${CMAKE_COMMAND} -E copy ${APP_HEAD} ${EXTS_INCLUDES_DIR}/adonobjects)
add_dependencies(copy_files adonobjects_static)
endif()

if(BUILD_SHARED_LIBS)
add_library(adonobjects SHARED ${ADEM_FILES})
target_link_libraries(adonobjects tinyxml2 exts)
generate_export_header(adonobjects EXPORT_FILE_NAME ${PROJECT_EXPORT_DIR}/adonobjects_exports.h)
add_dependencies(adonobjects tinyxml2)
target_include_directories(adonobjects PUBLIC ${PROJECT_EXPORT_DIR})

OS_BUILD_MACRO(adonobjects)

file(MAKE_DIRECTORY ${EXTS_INCLUDES_DIR}/adonobjects)
add_custom_target(copy_files ALL COMMAND ${CMAKE_COMMAND} -E copy ${APP_HEAD} ${EXTS_INCLUDES_DIR}/adonobjects)
add_dependencies(copy_files adonobjects)
endif()


add_subdirectory(test)

if(BUILD_STATIC_LIBS)
SET_TARGET_PROPERTIES(adonobjects_static PROPERTIES FOLDER "Adon/AdonObjects")
endif()
if(BUILD_SHARED_LIBS)
SET_TARGET_PROPERTIES(adonobjects PROPERTIES FOLDER "Adon/AdonObjects")
endif()
SET_TARGET_PROPERTIES(adonobjects_test PROPERTIES FOLDER "Adon/AdonObjects/tests")
