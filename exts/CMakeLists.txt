ADD_LIBRARY(exts INTERFACE)

#SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
#SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
#SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
#SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")	
#SET_TARGET_PROPERTIES(glfw PROPERTIES FOLDER "extensions/glfw")
#ADD_SUBDIRECTORY(glfw-3.2.2)

ADD_SUBDIRECTORY(tinyxml2-master)
if(BUILD_STATIC_LIBS)
SET_TARGET_PROPERTIES(tinyxml2_static PROPERTIES FOLDER "extensions/tinyxml2_static")
endif()
if(BUILD_SHARED_LIBS)
SET_TARGET_PROPERTIES(tinyxml2 PROPERTIES FOLDER "extensions/tinyxml2_shared")
endif()

TARGET_INCLUDE_DIRECTORIES(exts INTERFACE glfw-3.2.2/include glad/src glad/include glad/src linmath tinyxml2-master)