#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

int main()
{
    const uint64_t N = 10001;

    uint64_t upper_bound = N * (std::log(N) + std::log(std::log(N)) - 0.5);

    std::vector<bool> sieve(upper_bound, true);
    std::vector<uint64_t> primes;
    sieve[0] = false;

    for (uint64_t p = 2; p <= upper_bound; ++p)
    {
        if (sieve[p-1])
        {
            primes.push_back(p);

            if (primes.size() == N)
            {
                std::cout << primes[N-1] << std::endl;
                return 0;
            }

            for (uint64_t step = p * p; step <= upper_bound; step += p)
            {
                sieve[step-1] = false;
            }
        }
    }
    
    std::cout << primes[N-1] << std::endl;

    return 0;
}