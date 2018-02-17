TEST_DIR = ${shell pwd}

TESTSOURCE_DIR = ${TEST_DIR}/src
SOURCE_FILES = ${wildcard ${TEST_DIR}/src/*.cpp}
HEADER_FILES = ${${TEST_DIR}/src/*h}
INCLUDE_DIRS += ${TESTSOURCE_DIR}
LIBS = adem tinyxml2

TARGET_INCLUDE_DIR = $(foreach includedir,$(INCLUDE_DIRS), -I$(includedir))
TARGET_LB_FLAGS = $(foreach lib,$(LIBS), -l$(lib))

all: test

test:
	${CXX} ${CXX_FLAGS} -o $@ ${SOURCE_FILES} ${TARGET_INCLUDE_DIR} ${TARGET_LD_FLAGS} ${TARGET_LB_FLAGS} ${TARGET_ARCHITECTURE}
clean:
	rm -f test *.o
