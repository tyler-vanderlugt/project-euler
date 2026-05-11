#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates the sum of even-valued Fibonnaci numbers
 * whose values do not exceed 4,000,000
 * Uses brute force, checking each term and if even
 * adding to a running total 
*/

class Solution
{
public:
    Solution() {}

    void solve()
    {
        uint32_t n1 = 1;
        uint32_t n2 = 2;
        uint32_t sum = 0;

        while (n2 < MAX_N)
        {
            if (n2 % 2 == 0) { sum += n2; }

            uint32_t n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }

        std::cout << sum << std::endl;
    }

private:
    const uint32_t MAX_N = 4'000'000;
};