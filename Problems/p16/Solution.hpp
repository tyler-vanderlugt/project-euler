#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates the sum of digits of 2^1000
 * Stores each number as parts of base 10^2 allowing 18
 * digits to be processed in each double/carry step, 
 * reducing the number of iterations compared to a base
 * 10 approach
*/

class Solution
{
public:
    Solution() {}

    void solve()
    {
        std::vector<uint64_t> digits = {1};
        for (uint32_t n = 1; n <= N; ++n)
        {
            if (digits.back() != 0) { digits.push_back(0); }
            uint64_t carry = 0;
            for (uint32_t dig_idx = 0; dig_idx < digits.size(); ++dig_idx)
            {
                uint64_t dd = digits[dig_idx] * 2 + carry;
                digits[dig_idx] = dd % BASE;
                carry = dd / BASE;
            }
            if (carry) { digits.push_back(carry); }
        }

        uint32_t digit_sum = 0;
        for (uint64_t digit : digits)
        {
            while (digit != 0)
            {
                digit_sum += (digit % 10);
                digit /= 10;
            }
        }
        std::cout << digit_sum << std::endl;
    }

private:
    const uint32_t N = 1'000;
    const uint64_t BASE = 1'000'000'000'000'000'000;
};