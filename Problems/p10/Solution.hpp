#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

class Solution
{
public:
    Solution() :
        N(2000000),
        ROOT_N(std::sqrt(N) + 1) {}
    Solution(const std::vector<std::string>& args) :
        N(static_cast<uint32_t>(std::stoul(args[0]))),
        ROOT_N(std::sqrt(N) + 1) {}

    void solve()
    {
        std::vector<bool> sieve(ROOT_N, true);
        sieve[0] = false;
        std::vector<uint64_t> primes;
        uint64_t sum = 0;

        for (uint64_t p = 2; p <= ROOT_N; ++p)
        {
            if (sieve[p-1])
            {
                sum += p;
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

                if (sieve[i])
                {
                    sum += p_off;
                    primes.push_back(p_off);
                }
            }

            offset += ROOT_N;
        }
        
        // uint64_t sum = 0;
        // for (const auto& p : primes)
        // {
        //     sum += p;
        // }

        std::cout << sum << std::endl;
    }

private:
    const uint32_t N, ROOT_N;
};