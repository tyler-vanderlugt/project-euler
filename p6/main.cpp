#include <iostream>
#include <cstdint>

int main()
{
    const uint32_t N = 100;
    
    const uint32_t sum_sq = N * (N + 1) * (2 * N + 1) / 6;
    const uint32_t sq_sum = (N * (N + 1) / 2) * (N * (N + 1) / 2);
    std::cout << sq_sum - sum_sq << std::endl;

    return 0;
}