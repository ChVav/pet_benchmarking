cmake_minimum_required(VERSION 3.22)

#specify project name
project(petString)

# Create a target executable
add_executable(petString-bench)

# Add src as a subdirectory, include the file src/CMakelists.txt
add_subdirectory(bench)

target_include_directories(petString-bench
	PRIVATE
		"bench"
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
