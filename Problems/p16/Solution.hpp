#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    Solution() : N(1000) {};
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))) {}

    void solve()
    {
        std::vector<char> cur_num = {1};
        for (uint32_t n = 1; n <= N; ++n)
        {
            if (cur_num.back() != 0) { cur_num.push_back(0); }
            char carry = 0;
            for (uint32_t dig_idx = 0; dig_idx < cur_num.size() - 1; ++dig_idx)
            {
                char doubled_digit = cur_num[dig_idx] * 2;
                char r_dig = doubled_digit % 10;
                cur_num[dig_idx] = r_dig + carry;
                carry = doubled_digit / 10;
            }
            cur_num[cur_num.size() - 1] = carry;
        }

        uint32_t digit_sum = 0;
        for (const auto digit : cur_num)
        {
            digit_sum += digit;
        }
        std::cout << digit_sum << std::endl;
    }

private:
    const uint32_t N;
};