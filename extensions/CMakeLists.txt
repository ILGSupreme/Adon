ADD_LIBRARY(exts INTERFACE)

ADD_SUBDIRECTORY(tinyxml2)
ADD_SUBDIRECTORY(glfw)
ADD_SUBDIRECTORY(glad)

#SET TESTS OFF
SET(BUILD_TESTING OFF CACHE BOOL "turning off tests" FORCE)
SET(BUILD_TESTS BOOL OFF CACHE BOOL "turning off tests" FORCE)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "turning off glfw build examples" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "turning off build tests" FORCE)
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "turning off build docs" FORCE)
SET(GLFW_VULKAN_STATIC OFF CACHE BOOL "vulkan static glfw off" FORCE)
SET(GLFW_DOCUMENT_INTERNALS OFF CACHE BOOL "glfw documents off" FORCE)

add_custom_target(copy_glad_file ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${GLAD_INCLUDE_DIRS}/glad/glad.h ${ROOT_DIR}/output/includes/glad/glad.h)
add_dependencies(copy_glad_file glad)

add_custom_target(copy_khr_file ALL
COMMAND ${CMAKE_COMMAND} -E copy ${GLAD_INCLUDE_DIRS}/KHR/khrplatform.h ${ROOT_DIR}/output/includes/KHR/khrplatform.h)
add_dependencies(copy_khr_file glad)

configure_file(${ROOT_DIR}/extensions/tinyxml2/tinyxml2.h
${ROOT_DIR}/output/includes/tinyxml2/tinyxml2.h COPYONLY)

configure_file(${ROOT_DIR}/extensions/glfw/include/GLFW/glfw3.h
${ROOT_DIR}/output/includes/GLFW/glfw3.h COPYONLY)

configure_file(${ROOT_DIR}/extensions/glfw/include/GLFW/glfw3native.h
${ROOT_DIR}/output/includes/GLFW/glfw3native.h COPYONLY)

if(BUILD_STATIC_LIBS)
SET_TARGET_PROPERTIES(tinyxml2_static PROPERTIES FOLDER "extensions/tinyxml2_static")
OS_BUILD_MACRO(tinyxml2_static)
endif()
if(BUILD_SHARED_LIBS)
SET_TARGET_PROPERTIES(tinyxml2 PROPERTIES FOLDER "extensions/tinyxml2_shared")
OS_BUILD_MACRO(tinyxml2)
endif()

SET_TARGET_PROPERTIES(glfw PROPERTIES FOLDER "extensions/glfw")
OS_BUILD_MACRO(glfw)
SET_TARGET_PROPERTIES(glad PROPERTIES FOLDER "extensions/glad")
OS_BUILD_MACRO(glad)

TARGET_INCLUDE_DIRECTORIES(exts INTERFACE tinyxml2 glfw glad glad/include glad/src)
