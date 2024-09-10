cmake_minimum_required(VERSION 3.1)
project(myprog)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(test OFF)
if(test)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
	add_executable(myprog ./test/test.cpp ./src/lib.cpp)
	target_link_libraries(myprog ${GTEST_LIBRARIES} pthread)
	add_custom_command(
		TARGET myprog
		POST_BUILD
		COMMAND ./myprog
		COMMAND gcov ./CMakeFiles/runTests.dir/Users/kalinenkov/lab1/src/lib.cpp.gcda
		COMMAND lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent
		COMMAND lcov --directory . --zerocounters
		COMMAND lcov --remove coverage.info '/usr/*' --output-file coverage_filtered.info
		COMMAND genhtml  genhtml --ignore-errors inconsistent --ignore-errors missing coverage_filtered.info --output-directory out
		COMMAND open out/index.html)
else()
	include_directories(src)
	add_executable(myprog main.cpp src/prog.cpp src/lib.cpp)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std  gnu++2b")
endif()