cmake_minimum_required(VERSION 3.22)

#specify project name
project(petBench)

# Create a target executable
add_executable(petBench-bench)

# Add src as a subdirectory, include the file src/CMakelists.txt
add_subdirectory(src)

target_include_directories(petBench-bench
	PRIVATE
		"src"
)

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's test" FORCE)
add_subdirectory(vendor/google/benchmark)

## build tests (targets: gtest_main, gtest)
#add_subdirectory(vendor/google/googletest/googletest)

# link targets
target_link_libraries("${PROJECT_NAME}-bench" benchmark)
#target_link_libraries("${PROJECT_NAME}-test" gtest)
