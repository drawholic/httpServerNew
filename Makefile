CXX = g++
CXXFLAGS = -I include

BUILD_DIR = build
SRC_DIR = src

all: ${BUILD_DIR} ${BUILD_DIR}/main

${BUILD_DIR}:
	mkdir -p $@

${BUILD_DIR}/main: ${SRC_DIR}/main.cpp ${BUILD_DIR}/Server.o
	${CXX} ${CXXFLAGS} $^ -o $@

${BUILD_DIR}/Server.o: ${SRC_DIR}/Server.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@