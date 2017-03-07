include_directories(${CMAKE_SOURCE_DIR}/gtest-1.7.0/include ${CMAKE_SOURCE_DIR}/source)

add_executable( _triangleTests
	main.cpp
	triangle_test.cpp
)

target_link_libraries( _triangleTests
	gtest
	triangle
)

add_custom_command(
	TARGET _triangleTests
    POST_BUILD
    COMMAND _triangleTests
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
