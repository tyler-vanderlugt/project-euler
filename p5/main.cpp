#include <iostream>
#include <cstdint>

#include <numeric>

uint32_t gcd(uint32_t a, uint32_t b)
{
    if (a < b) { std::swap(a, b); }
    a = a % b;
    if (a == 0) { return b; }
    return gcd(a, b);
}

int main()
{
    const uint32_t N = 20;

    uint32_t running_lcm = 1;

    for (uint32_t i = 2; i <= N; ++i)
    {
        if (running_lcm % i == 0) { continue; }
        running_lcm = running_lcm * i / gcd(running_lcm, i);
    }

    std::cout << running_lcm << std::endl;

    return 0;
}