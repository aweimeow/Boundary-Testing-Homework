include_directories(${CMAKE_SOURCE_DIR}/gtest-1.7.0/include ${CMAKE_SOURCE_DIR}/source)

add_executable( _Tests
	main.cpp
	triangle_test.cpp
    nextdate_test.cpp
)

target_link_libraries( _Tests
	gtest
	triangle
    nextdate
)

add_custom_command(
	TARGET _Tests
    POST_BUILD
    COMMAND _Tests
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
