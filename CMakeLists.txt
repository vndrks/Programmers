cmake_minimum_required (VERSION 3.8)

project ("Programmers")

message("Project : " ${PROJECT_NAME})
add_executable (MainApp "MainApp.cpp" ${HEADER_FILES} ${SOURCE_FILES})

add_subdirectory( CheckSkills )
add_subdirectory( Practice )

include_directories (
	"CheckSkills/"
	"Practice/"
)

target_compile_features(MainApp PRIVATE cxx_range_for)
target_link_libraries(MainApp LINK_PUBLIC CheckSkills Practice)
