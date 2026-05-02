#include <cstdint>
#include <iostream>

int main()
{
    uint64_t total = 0;

    for (uint64_t i = 1; i < 537000; i += 2)
    {
        total += i * i;
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}