cmake_minimum_required (VERSION 3.8)

project ("CheckSkills")

file(GLOB HEADER_FILES
	./Level_1/Sol1.h
)

file(GLOB SOURCE_FILES
	./Level_1/Sol1.cpp
)

set(Module_CHECK_SKILLS ${HEADER_FILES} ${SOURCE_FILES})
add_library(CheckSkills SHARED ${Module_CHECK_SKILLS})