#include <iostream>
#include <cstdint>

int main()
{
    uint64_t n = 600851475143;
 
    uint64_t large_prime = 2;
    while (n % 2 == 0)
    {
        n /= 2;
    }

    for (uint64_t i = 3; i * i < n + 1; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            large_prime = n;
        }
    }

    std::cout << large_prime << std::endl;

    return 0;
}