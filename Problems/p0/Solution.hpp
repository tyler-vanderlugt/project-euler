#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

/*
 * Sums the squares of odd integers up to N
 * Uses brute force
*/

class Solution
{
public:
    Solution() : N(537000) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        uint64_t total = 0;

        for (uint64_t i = 1; i < N; i += 2)
        {
            total += i * i;
        }

        std::cout << total << std::endl;
    }

private:
    const uint32_t N;
};