#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates the difference between the square of the sum
 * and the sum of the squares for the first N natural numbers
 * Utilizes Faulhaber's formulas for sum(i) and sum(i^2) to
 * reach the result in constant time
*/

class Solution
{
public:
    Solution() : N(100) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        const uint32_t sum_sq = N * (N + 1) * (2 * N + 1) / 6;
        const uint32_t sq_sum = (N * (N + 1) / 2) * (N * (N + 1) / 2);
        std::cout << sq_sum - sum_sq << std::endl;
    }

private:
    const uint32_t N;
};