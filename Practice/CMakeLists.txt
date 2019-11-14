cmake_minimum_required (VERSION 3.8)

project ("Practice")

file(GLOB HEADER_FILES
	Hash/IncompletePlayer.h
	Hash/TelephoneBook.h
	Hash/Camouflage.h
	Hash/BestAlbum.h
)

file(GLOB SOURCE_FILES
	Hash/IncompletePlayer.cpp
	Hash/TelephoneBook.cpp
	Hash/Camouflage.cpp
	Hash/BestAlbum.cpp
)

add_executable (Practice "Practice.cpp" ${HEADER_FILES} ${SOURCE_FILES})
add_subdirectory(Hash)
