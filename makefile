
#directories
CURRENT_DIR = ${shell pwd}
EXTENSION_DIR = ${CURRENT_DIR}/exts
TINYXML2_DIR = ${EXTENSION_DIR}/tinyxml2-master
TINYXML2_INCLUDE_DIR = ${EXTENSION_DIR}/tinyxml2-master
ADON_DIRECTORY = ${CURRENT_DIR}/Adon
LIB_DIRECTORY = ${ADON_DIRECTORY}/libs ${TINYXML2_DIR}
INCLUDE_DIRS = ${ADON_DIRECTORY}/Adem/src ${TINYXML2_DIR}
LIBS = tinyxml2

TARGET_INCLUDE_DIR = $(foreach includedir,$(INCLUDE_DIRS), -I$(includedir))
TARGET_LD_FLAGS = $(foreach librarydir,$(LIB_DIRECTORY), -L$(librarydir))
TARGET_LB_FLAGS = $(foreach lib,$(LIBS), -l$(lib))

#compiler flags
CXX =
CXX_FLAGS =
TARGET_ARCHITECTURE=
CXX_FLAGS_LIBS=

ifndef $(CXX)
CXX = g++
endif

ifndef $(CXX_FLAGS)
CXX_FLAGS =  -g -std=c++14 -Wall
endif
CXX_FLAGS_LIBS = -static ${CXX_FLAGS}

COMPILERFLAGS = ${CXX} ${CXX_FLAGS} ${TARGET_INCLUDE_DIR} ${TARGET_LD_FLAGS} ${TARGET_LB_FLAGS} ${TARGET_ARCHITECTURE}

export
all:
		+${MAKE} -C ${CURRENT_DIR}/exts/tinyxml2-master all
		+${MAKE} -C ${CURRENT_DIR}/Adon/Adem all

clean:
		+${MAKE} -C ${CURRENT_DIR}/exts/tinyxml2-master clean
		+${MAKE} -C ${CURRENT_DIR}/Adon/Adem clean
