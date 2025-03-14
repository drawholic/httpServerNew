CXX = g++
CXXFLAGS = -I include

BUILD_DIR = build
SRC_DIR = src

all: ${BUILD_DIR} ${BUILD_DIR}/main

OBJS = ${BUILD_DIR}/ReadWrite.o \
		${BUILD_DIR}/Parser.o \
		${BUILD_DIR}/ClientsContainer.o \
		${BUILD_DIR}/Request.o

${BUILD_DIR}:
	mkdir -p $@

${BUILD_DIR}/main: ${SRC_DIR}/main.cpp ${OBJS} ${BUILD_DIR}/Server.o
	${CXX} ${CXXFLAGS} $^ -o $@

${BUILD_DIR}/Server.o: ${SRC_DIR}/Server.cpp ${OBJS}
	${CXX} ${CXXFLAGS} -c $^ -o $@

${BUILD_DIR}/ReadWrite.o: ${SRC_DIR}/ReadWrite.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@

${BUILD_DIR}/Parser.o: ${SRC_DIR}/Parser.cpp ${BUILD_DIR}/Request.o
	${CXX} ${CXXFLAGS} -c $^ -o $@

${BUILD_DIR}/ClientsContainer.o: ${SRC_DIR}/ClientsContainer.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@

${BUILD_DIR}/Request.o: ${SRC_DIR}/Request.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@