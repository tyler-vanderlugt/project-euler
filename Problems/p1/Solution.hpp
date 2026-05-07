#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates the sum of all multiples of 3 or 5 below N
 * Uses inclusion-exclusion principle via Arithmetic Series
 * Formula
*/

class Solution
{
public:
    Solution() : N(1000) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        const uint32_t N1 = 3, R1 = (N-1) / N1;
        const uint32_t N2 = 5, R2 = (N-1) / N2;
        const uint32_t M12 = N1 * N2, R3 = (N-1) / M12;

        uint32_t total = 0;

        total += N1 * R1 * (R1 + 1) / 2;
        total += N2 * R2 * (R2 + 1) / 2;
        total -= M12 * R3 * (R3 + 1) / 2;

        std::cout  << total << std::endl;
    }

private:
    const uint32_t N;

};