ADD_LIBRARY(exts INTERFACE)

SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")	

#ADD_SUBDIRECTORY(glfw-3.2.2)
ADD_SUBDIRECTORY(tinyxml2-master)

#SET_TARGET_PROPERTIES(glfw PROPERTIES FOLDER "extensions/glfw")
SET_TARGET_PROPERTIES(tinyxml2 PROPERTIES FOLDER "extensions/tinyxml2")

TARGET_INCLUDE_DIRECTORIES(exts INTERFACE glfw-3.2.2/include glad/src glad/include glad/src linmath tinyxml2-master)