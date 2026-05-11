#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

/*
 * Finds the total amount of letters of each word
 * from 1 to N inclusive in word form
 * Iterates over each number, breaking it up and 
 * adding based on it. Breaks at some point between
 * N = 1,000 and N = 500,000
*/

class Solution
{
public:
    Solution() : N(1000) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        
        for (uint32_t i = 1; i <= N; ++i)
        {

            letter_count(i);
        }

        std::cout << running_sum << std::endl;
    }

private:
    void letter_count(uint32_t num, uint32_t base_scale=0)
    {
        uint32_t scaled_num = num % 1000;

        uint32_t hundreds = scaled_num / 100;
        uint32_t tens_value = scaled_num % 100;

        uint32_t chunk_sum = 0;
        if (hundreds > 0)
        {
            chunk_sum += ones_teens[hundreds] + 7;
            if (tens_value != 0) { chunk_sum += 3; }
        }

        if (tens_value < 20) { chunk_sum += ones_teens[tens_value]; }
        else
        {
            chunk_sum = chunk_sum + tens[tens_value / 10] + ones_teens[tens_value % 10];
        }

        chunk_sum += base_3s[base_scale];

        if (num / 1000 > 0)
        {
            letter_count(num / 1000, base_scale + 1);
        }
        running_sum += chunk_sum;

    }

    uint32_t running_sum = 0;

    const std::vector<uint32_t> ones_teens = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8
    };

    const std::vector<uint32_t> tens = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6, 
    };

    const std::vector<uint32_t> base_3s = {
        0, 8
    };

    const uint32_t N;
};