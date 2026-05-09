#include <iostream>
#include <cstdint>
#include <filesystem>

#ifndef PROBLEM_COUNT
    #define PROBLEM_COUNT 0
#endif

int main()
{
    uint32_t problem_count = PROBLEM_COUNT;
    std::string dir_path = "Problems/p" + std::to_string(problem_count);

    if (!std::filesystem::create_directories(dir_path))
    {
        std::cerr << "Error creating path for new file or it already exists" << std::endl;
        return -1;
    }
    
    std::filesystem::path source = "boilerplate.hpp";
    std::filesystem::path destination = dir_path + "/Solution.hpp";

    try { std::filesystem::copy(source, destination); }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }     

    std::cout << "Created problem " << problem_count << " boilerplate" << std::endl;
    return 0;
}