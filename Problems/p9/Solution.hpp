#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Finds the product abc of the only Pythagorean triplet
 * where a + b + c = 1000
 * Solves for b in terms of 'a' and 'P' to find the
 * integer solution in O(P) time
*/

class Solution
{
public:
    Solution() {}
    Solution(const std::vector<std::string>& args) {}

    void solve()
    {
        const uint32_t P = 1000;
        for (uint32_t a = 1; a < P / 3; ++a)
        {
            uint32_t b = (P*P - 2 * P * a) / (2 * P - 2 * a);
            
            uint32_t c = P - a - b;

            if (a*a + b*b == c*c)
            {
                std::cout << a*b*c << std::endl;
                return;
            }
        }
    }
};