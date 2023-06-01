cmake_minimum_required(VERSION 3.22)

#specify project name
project(petString)

# Create target executables
add_executable(petString-bench) #benchmarking
add_executable(petString)

# Add src and bench as a subdirectories, including contained (private) CMakeLists.txt files
add_subdirectory(bench)
add_subdirectory(src)

target_include_directories(petString-bench
	PRIVATE
		"bench"
)

target_include_directories(petString
	PRIVATE
		"src"
)

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's test" FORCE)
add_subdirectory(vendor/google/benchmark)

## build tests (targets: gtest_main, gtest)
#add_subdirectory(vendor/google/googletest/googletest)

# link targets to the benchmark/tests libraries
target_link_libraries("${PROJECT_NAME}-bench" benchmark)
#target_link_libraries("${PROJECT_NAME}-test" gtest)
