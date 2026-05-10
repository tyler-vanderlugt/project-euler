#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Calculates thenumber of lattice paths to reach the 
 * bottom right corner in a grid from the top left corner
 * only being able to go down or right
 * Uses pascals triangle to calculate the binomial 
 * expansion, in place to save memory and speed
*/

class Solution
{
public:
    Solution() : GRID_SIZE(20) {};
    Solution(const std::vector<std::string>& args) :
        GRID_SIZE(static_cast<uint64_t>(std::stoul(args[0]))) {}

    void solve()
    {
        uint64_t target_row = GRID_SIZE * 2;
        std::vector<uint64_t> row(target_row + 1, 0);
        row[0] = 1;

        for (uint64_t i = 1; i <= target_row; ++i)
        {
            for (uint64_t j = i; j > 0; --j)
            {
                row[j] = row[j] + row[j - 1];
            }
        }
        std::cout << row[GRID_SIZE] << std::endl;
    }

private:
    const uint64_t GRID_SIZE;
};