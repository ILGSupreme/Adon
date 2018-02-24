ADD_LIBRARY(exts INTERFACE)

ADD_SUBDIRECTORY(tinyxml2-master)
if(BUILD_STATIC_LIBS)
SET_TARGET_PROPERTIES(tinyxml2_static PROPERTIES FOLDER "extensions/tinyxml2_static")
endif()
if(BUILD_SHARED_LIBS)
SET_TARGET_PROPERTIES(tinyxml2 PROPERTIES FOLDER "extensions/tinyxml2_shared")
endif()

TARGET_INCLUDE_DIRECTORIES(exts INTERFACE tinyxml2-master)