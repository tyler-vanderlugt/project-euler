#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

/*
 * Finds the first triangle number with more than 500 divisors
 * Uses the property that for T_n = n(n + 1) / 2, n and n + 1
 * are coprimes and thus, gcd(n, n+1) = 1
 * Breaks the numbers into two coprimes which are easier to
 * factor
 * Lazily generates primes with a segmented sieve as needed
*/

class Solution
{
public:
    Solution() {}

    void solve()
    {
        sieve_init();
        while (max_factors < F)
        {
            ++n_step;
            uint32_t curr_factors = triangle_factorization();
            max_factors = (curr_factors > max_factors) ? curr_factors : max_factors;
        }

        std::cout << n_step * (n_step + 1) / 2 << std::endl;
    }

private:
    void sieve_again()
    {
        ++offset;
        std::fill(sieve.begin(), sieve.end(), true);
        uint32_t window_start = offset * SIZE;
        uint32_t window_end = window_start + SIZE;

        for (const auto prime : primes)
        {
            uint32_t first_multiple = (window_start + prime - 1) / prime * prime;
            if (first_multiple < window_start) { first_multiple += prime; }
            
            for (uint32_t m = first_multiple; m < window_end; m += prime)
            {
                sieve[m - window_start] = false;
            }
        }

        for (uint32_t p = 0; p < SIZE; ++p)
        {
            if (sieve[p]) { primes.push_back(window_start + p); }
        }
    }

    void sieve_init()
    {
        sieve.resize(SIZE, true);
        sieve[0] = false;

        for (uint32_t p = 2; p <= SIZE; ++p)
        {
            if (sieve[p - 1])
            {
                primes.push_back(p);
                for (uint32_t m = p * p; m <= SIZE; m += p)
                {
                    sieve[m - 1] = false;
                }
            }
        }
    }

    uint32_t get_factors(uint32_t k)
    {
        uint32_t product = 1;
        for (const auto prime : primes)
        {
            if (prime * prime > k) { break; }
            if (k % prime == 0)
            {
                uint32_t count = 0;
                while (k % prime == 0)
                {
                    k /= prime;
                    ++count;
                }
                product *= (count + 1);
            }
        }
        if (k > 1) { product *= 2; }
        return product;
    }

    uint32_t triangle_factorization()
    {
        uint32_t cp1, cp2;
        if (n_step % 2 == 0)
        {
            cp1 = n_step/2;
            cp2 = n_step+1;
        }
        else
        {
            cp1 = n_step;
            cp2 = (n_step+1)/2;
        }

        while (primes.back() <  cp2)
        {
            sieve_again();
        }
    
        return get_factors(cp1) * get_factors(cp2);
    }

    const uint32_t F = 500, SIZE = 10000;
    std::vector<bool> sieve;
    std::vector<uint32_t> primes;
    uint32_t max_factors = 0, n_step = 0, offset = 0;
};