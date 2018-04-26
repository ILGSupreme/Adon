PROJECT(Adon)

SET(FILECONFIG_FILES ${CMAKE_CURRENT_SOURCE_DIR}/fileconfig.h ${CMAKE_CURRENT_SOURCE_DIR}/fileconfig.cpp)

add_subdirectory(Exception)
add_subdirectory(AdonObjects)
add_subdirectory(AdonScript)
add_subdirectory(Application)
