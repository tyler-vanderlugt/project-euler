#include <iostream>
#include <cstdint>

int main()
{
    const uint32_t N = 1000;

    const uint32_t N1 = 3, R1 = (N-1) / N1;
    const uint32_t N2 = 5, R2 = (N-1) / N2;
    const uint32_t M12 = N1 * N2, R3 = (N-1) / M12;

    uint32_t total = 0;

    total += N1 * R1 * (R1 + 1) / 2;
    total += N2 * R2 * (R2 + 1) / 2;
    total -= M12 * R3 * (R3 + 1) / 2;

    std::cout << "Total: " << total << std::endl;

    return 0;
}