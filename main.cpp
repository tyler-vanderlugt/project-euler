#ifndef SOLUTION_HEADER
    #define SOLUTION_HEADER "placeholder.hpp"
#endif

#include SOLUTION_HEADER
#include <vector>
#include <string>
#include <chrono>
#include <iostream>

int main(int argc, char** argv)
{
    std::vector<std::string> args(argv + 1, argv + argc);

    auto start = std::chrono::steady_clock::now();

    Solution s(args);
    std::cout << "Output: ";
    s.solve();

    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Program completed in: " << diff.count() << " ms" << std::endl;

    return 0;
}