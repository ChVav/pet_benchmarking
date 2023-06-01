# Specify the (private) sources of the petBench excecutable
target_sources(petBench-bench
    PRIVATE
        # Headers
        "string_bench.h"

        # Sources
        "string_bench.cpp"
)
