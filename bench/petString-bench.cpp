// Function rewritten from example https://www.youtube.com/watch?v=UNvCuYQCXAI

#include <benchmark/benchmark.h>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Function to benchmark
void TestFunction(int len){
    vector<string> v;
    v.reserve(1000);
    for(int i = 0; i < 1000; i++){
        string str(len,'x');
        v.push_back(str);
    }
}

// wrapper used by framework
static void stringBench(benchmark::State &s){
   for (auto _ : s){
    // code that gets timed
    int len = s.range(0);// extract length from current state
    TestFunction(len);
   }    
}

//Register the benchmark, test a range of strings
BENCHMARK(stringBench)->DenseRange(0,32)->Unit(benchmark::kMillisecond);

// replaces normal main function
BENCHMARK_MAIN();