#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Finds starting term under N with longest collatz sequence
 * Uses partial memorization to break out of sequences early
 * when running into previosly identified and saved values
 * (below N)
*/

class Solution
{
public:
    Solution() : N(1000000) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        terms = std::vector<uint32_t>(N, 0);
        terms[1] = 1;

        uint32_t max_ch_idx = 0, max_ch_len = 0;
        for (uint32_t i = 1; i < N; ++i)
        {
            uint32_t curr_ch_len = collatz_length(i);
            if (curr_ch_len > max_ch_len)
            {
                max_ch_idx = i;
                max_ch_len = curr_ch_len;
            }
        }
        std::cout << max_ch_idx << std::endl;
    }

private:
    uint32_t collatz_length(uint32_t n)
    {
        if (n < N)
        {
            if (terms[n] != 0) { return terms[n]; }
            terms[n] = (n % 2 == 0) ? collatz_length(n / 2) + 1 : collatz_length(n * 3 + 1) + 1;
            return terms[n];
        }
        uint32_t too_big_len = (n % 2 == 0) ? collatz_length(n / 2) + 1 : collatz_length(n * 3 + 1) + 1;
        return too_big_len;
    }

    const uint32_t N;
    std::vector<uint32_t> terms;
};