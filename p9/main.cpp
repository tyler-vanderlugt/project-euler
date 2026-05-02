#include <iostream>
#include <cstdint>

int main()
{
    const uint32_t P = 1000;

    for (uint32_t a = 1; a < P / 3; ++a)
    {
        uint32_t b = (P*P - 2 * P * a) / (2 * P - 2 * a);
        
        uint32_t c = P - a - b;

        if (a*a + b*b == c*c)
        {
            std::cout << a*b*c << std::endl;
            return 0;
        }
    }

    return 0;
}