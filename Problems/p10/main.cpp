#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

int main()
{
    const uint64_t N = 2000000;
    const uint64_t ROOT_N = std::sqrt(N) + 1;

    std::vector<bool> sieve(ROOT_N, true);
    sieve[0] = false;
    std::vector<uint64_t> primes;

    for (uint64_t p = 2; p <= ROOT_N; ++p)
    {
        if (sieve[p-1])
        {
            primes.push_back(p);
            for (uint64_t m = p*p; m <= ROOT_N; m += p)
            {
                sieve[m-1] = false;
            }
        }
    }
    
    uint64_t offset = ROOT_N;
    while (offset < N)
    {
        uint64_t offset_ub = offset + ROOT_N;
        std::fill(sieve.begin(), sieve.end(), true);

        for (const auto& p : primes)
        {
            uint64_t r = offset % p;
            uint64_t r_off = p - r;

            while (r_off <= ROOT_N)
            {
                sieve[r_off-1] = false;
                r_off += p;
            }
        }
        
        for (uint64_t i = 0; i < ROOT_N; ++i)
        {
            uint64_t p_off = offset + i + 1;
            if (p_off > N) { break; }

            if (sieve[i]) { primes.push_back(p_off); }
        }

        offset += ROOT_N;
    }
    
    uint64_t sum = 0;
    for (const auto& p : primes)
    {
        sum += p;
    }

    std::cout << sum << std::endl;

    return 0;
}