cmake_minimum_required (VERSION 3.8)

project ("Practice")

file(GLOB HEADER_FILES
	Hash/IncompletePlayer.h
	Hash/TelephoneBook.h
	Hash/Camouflage.h
	Hash/BestAlbum.h
	StackNQueue/FeaturesDevelop.h
	StackNQueue/Top.h
)

file(GLOB SOURCE_FILES
	Hash/IncompletePlayer.cpp
	Hash/TelephoneBook.cpp
	Hash/Camouflage.cpp
	Hash/BestAlbum.cpp
	StackNQueue/FeaturesDevelop.cpp
	StackNQueue/Top.cpp
)

set(Module_PRACTICE ${HEADER_FILES} ${SOURCE_FILES})
add_library(Practice SHARED ${Module_PRACTICE})