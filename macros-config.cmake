macro(OS_BUILD_MACRO)
	SET(project_target	"${ARGN}")
	set_target_properties(${project_target}
	    PROPERTIES
	    ARCHIVE_OUTPUT_DIRECTORY
	    "${PROJECT_LIB_DIR}/${CMAKE_BUILD_TYPE}/${OS_PLATFORM}/${ANDROID_PLATFORM}/${ANDROID_ABI}"
	    LIBRARY_OUTPUT_DIRECTORY
	    "${PROJECT_LIB_DIR}/${CMAKE_BUILD_TYPE}/${OS_PLATFORM}/${ANDROID_PLATFORM}/${ANDROID_ABI}"
	    RUNTIME_OUTPUT_DIRECTORY
	    "${PROJECT_BIN_DIR}/${CMAKE_BUILD_TYPE}/${OS_PLATFORM}/${ANDROID_PLATFORM}/${ANDROID_ABI}"
	)
endmacro(OS_BUILD_MACRO)

macro(OS_TEST_MACRO)
	set(project_target 	${ARGN})
	set_target_properties(${project_target}
	    PROPERTIES
	    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BIN_DIR}/TEST/${PROJECT_NAME}/${OS_PLATFORM}/${CMAKE_BUILD_TYPE}"
	)
endmacro(OS_TEST_MACRO)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist ${curdir})
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

MACRO(GETSRCFILES	result dirs)
	SET(SRC_FILES "")
	FOREACH(dir ${ARGV})
		if(IS_DIRECTORY ${dir})
			File(GLOB SRC ${dir}/*.cpp)
			LIST(APPEND SRC_FILES ${SRC})
		endif()
	ENDFOREACH()
	SET(${result} ${SRC_FILES})
ENDMACRO()

MACRO(GETHEADERFILES	result dirs)
	SET(SRC_FILES "")
	FOREACH(dir ${ARGV})
		if(IS_DIRECTORY ${dir})
			File(GLOB SRC ${dir}/*.h)
			LIST(APPEND SRC_FILES ${SRC})
		endif()
	ENDFOREACH()
	SET(${result} ${SRC_FILES})
ENDMACRO()
