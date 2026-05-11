#ifndef SOLUTION_HEADER
    #define SOLUTION_HEADER "placeholder.hpp"
#endif

#include SOLUTION_HEADER
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <memory>

int main()
{
    Solution s;
    std::cout << "Output: ";
    
    auto start = std::chrono::steady_clock::now();
    
    s.solve();

    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Program completed in: " << diff.count() << " ms" << std::endl;

    return 0;
}