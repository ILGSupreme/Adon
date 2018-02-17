LIBNAME = adem

ADEM_SRC=${wildcard ${ADON_DIRECTORY}/Adem/src/*.cpp}
ADEM_HEADERS=${wildcard ${ADON_DIRECTORY}/src/*.h}
ADEM_OBJECT_FILES = ${ADEM_SRC:.cpp=.o}
ADEM_OBJ=${wildcard ${ADEM_CURRENT_DIR}/*.o}


all:staticlib testing

staticlib:libadem.a libadema COPY_FILE_TO_DIRECTORY

testing:
	+${MAKE} -C ${ADON_DIRECTORY}/Adem/test all

libadem.a: ${LIBNAME}.o
	${AR} ${ARFLAGS}s $@ $^

libadema:
	ar -t libadem.a

COPY_FILE_TO_DIRECTORY:
	cp -rf libadem.a ${ADON_DIRECTORY}/libs/libadem.a

${LIBNAME}.o:
	${CXX} ${CXX_FLAGS} -c -o $@ ${ADEM_SRC} ${TARGET_INCLUDE_DIR} ${TARGET_LD_FLAGS} ${TARGET_LB_FLAGS} ${TARGET_ARCHITECTURE}

clean:
	rm -f *.o *.so *.a
