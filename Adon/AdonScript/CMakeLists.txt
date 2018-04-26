PROJECT(adonscript)

SET(MAIN_PROGRAM ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
SET(LUA_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/src/luascript.h)

include_directories(${LUA_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(adon_script_test ${MAIN_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/src/luascript.cpp)

MESSAGE(STATUS "TEST=${LUA_LIBRARIES}")

target_link_libraries(adon_script_test ${LUA_LIBRARIES})

OS_TEST_MACRO(adon_script_test)
