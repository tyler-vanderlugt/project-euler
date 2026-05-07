#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Finds the largest prime factor of a given n
 * Iteratively divies n by 2 then every odd
 * number, effectively taking every prime factor
 * out of it until only the largest prime remains.
*/

class Solution
{
public:
    Solution() {}
    Solution(const std::vector<std::string>& args) :
        n(static_cast<uint64_t>(std::stoul(args[0]))) {}

    void solve()
    {
        uint64_t large_prime = 2;
        while (n % 2 == 0)
        {
            n /= 2;
        }

        for (uint64_t i = 3; i * i < n + 1; i += 2)
        {
            while (n % i == 0)
            {
                n /= i;
                large_prime = n;
            }
        }

        std::cout << large_prime << std::endl;
    }

private:
    uint64_t n = 600851475143;
};