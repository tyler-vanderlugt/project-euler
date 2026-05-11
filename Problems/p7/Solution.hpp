#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

/*
 * Finds the 10,001st primes number using the Sieve of Eratosthenes
 * Estimates an upper bound using the Prime Number Theorem, then
 * iteratively marks non-primes to isolate prime values until
 * reaching the Nth prime
 */

class Solution
{
public:
    Solution() {}

    void solve()
    {
        std::vector<bool> sieve(UPPER_BOUND, true);
        sieve[0] = false;
        std::vector<uint64_t> primes;

        for (uint64_t p = 2; p <= UPPER_BOUND; ++p)
        {
            if (sieve[p-1])
            {
                primes.push_back(p);

                if (primes.size() == N)
                {
                    std::cout << primes[N-1] << std::endl;
                    return;
                }

                for (uint64_t step = p * p; step <= UPPER_BOUND; step += p)
                {
                    sieve[step-1] = false;
                }
            }
        }

        std::cout << primes[N-1] << std::endl;
    }

private:
    const uint64_t N = 10'001, UPPER_BOUND = N * (std::log(N) + std::log(std::log(N)) - 0.5);
};