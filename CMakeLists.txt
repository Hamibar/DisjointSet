cmake_minimum_required(VERSION 3.5)

project(DisjointSet)

set(SOURCES main.cpp DisjSet.cpp)
set(HEADERS DisjSet.h Kruskal.h)
set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(disj_set ${SOURCES} ${HEADERS})

set_target_properties(
	disj_set PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)