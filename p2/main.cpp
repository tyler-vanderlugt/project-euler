#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
    const uint32_t MAX_N = 4000000;

    uint32_t n1 = 1;
    uint32_t n2 = 2;
    uint32_t sum = 0;

    while (n2 < MAX_N)
    {
        if (n2 % 2 == 0) { sum += n2; }

        uint32_t n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }

    std::cout << "Total: " << sum << std::endl;

    return 0;
}