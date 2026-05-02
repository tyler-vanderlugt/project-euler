#include <iostream>
#include <cstdint>

bool is_palindrome(uint64_t product)
{
    uint64_t reversed = 0;

    while (product > reversed)
    {
        reversed = reversed * 10 + product % 10;
        product /= 10;
    }

    return (product == reversed || product == (reversed % 10));

}

int main()
{
    bool found = false;

    uint64_t max_palindrome = 0;

    for (uint64_t i = 999; i > 100; --i)
    {
        for (uint64_t j = 999; j > 100; --j)
        {
            uint64_t product = i * j;
            if (product > max_palindrome && is_palindrome(product)) { max_palindrome = product; }
        }
    }

    std::cout << max_palindrome << std::endl;

    return 0;
}