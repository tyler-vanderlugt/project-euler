#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates the smallest positive number that is evenly divisible
 * by all numbers 1 through 20 inclusive
 * Iteratively computes the least common multiple (lcm) of the 
 * current result and the next integer in the sequence using the
 * greatest common divisor (gcd)
*/

class Solution
{
public:
    Solution() {}

    void solve()
    {
        uint32_t running_lcm = 1;

        for (uint32_t i = 2; i <= N; ++i)
        {
            if (running_lcm % i == 0) { continue; }
            running_lcm = running_lcm * i / gcd(running_lcm, i);
        }

        std::cout << running_lcm << std::endl;
    }

private:
    uint32_t gcd(uint32_t a, uint32_t b)
    {
        if (a < b) { std::swap(a, b); }
        a = a % b;
        if (a == 0) { return b; }
        return gcd(a, b);
    }

    const uint32_t N = 20;
};