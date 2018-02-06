ADD_LIBRARY(exts INTERFACE)

option(ENABLE_XERCES_SUBPROJECTS "USE XERCES SUB PROJECTS" OFF)

SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")	

ADD_SUBDIRECTORY(glfw-3.2.2)
ADD_SUBDIRECTORY(xerces-c-3.2.0)

SET_TARGET_PROPERTIES(glfw PROPERTIES FOLDER "exts/glfw")
SET_TARGET_PROPERTIES(xerces-c PROPERTIES FOLDER "exts/xerces-c")
set_target_properties(xerces-c-missing PROPERTIES FOLDER "exts/xerces-c/Library")
set_target_properties(xerces-c-headers PROPERTIES FOLDER "exts/xerces-c/Library")

TARGET_INCLUDE_DIRECTORIES(exts INTERFACE glfw-3.2.2/include glad/src glad/include glad/src linmath)