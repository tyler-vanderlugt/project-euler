#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Finds the largest palindrome made of the product 
 * of two 3-digit numbers. Iterates through products
 * checking for palindromic identity and tracks the
 * maximum
*/

class Solution
{
public:
    Solution() {}
    Solution(const std::vector<std::string>& args) {}

    void solve()
    {
        for (uint32_t i = 999; i > 100; --i)
        {
            for (uint32_t j = 999; j > 100; --j)
            {
                uint32_t product = i * j;
                if (product > max_palindrome && is_palindrome(product)) { max_palindrome = product; }
            }
        }

        std::cout << max_palindrome << std::endl;
    }

private:
    bool is_palindrome(uint32_t p)
    {
        uint32_t reversed = 0;
        if (p % 10 == 0) { return false; }

        while (p > reversed)
        {
            reversed = reversed * 10 + p % 10;
            p /= 10;
        }

        return (p == reversed || p == (reversed / 10));
    }

    uint32_t max_palindrome = 0;
};