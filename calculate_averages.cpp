/*
 * Compiles and runs every problem 3 times, recording
 * the average in averages.csv
*/

#include "placeholder.hpp"

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <cstdint>

std::string run_command(const std::string& cmd)
{
    char buffer[128];
    std::string result = "";

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) { return "ERROR"; }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    {
        result += buffer;
    }

    pclose(pipe);
    return result;
}

uint32_t extract_time(const std::string& output)
{
    std::regex time_regex("Program completed in: ([0-9.]+) ms");
    std::smatch match;

    return (std::regex_search(output, match, time_regex)) ? std::stoi(match[1]) : -1;
}

std::pair<bool, uint32_t> run_trials(const std::string& pn)
{
    std::string header_path = "\"Problems/" + pn + "/Solution.hpp\"";
    std::string compile_cmd = "g++ -std=c++20 -DSOLUTION_HEADER='" + header_path + "' main.cpp -o output";
    std::remove("./output");
    run_command(compile_cmd);

    uint32_t total_time = 0;
    bool success = true;

    for (uint32_t run = 0; run < 3; ++run)
    {
        std::string output = run_command("./output");
        uint32_t t = extract_time(output);
        
        if (t != UINT32_MAX) { total_time += t; }
        else
        {
            return {false, UINT32_MAX};
        }
    }

    return {true, total_time};
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {        
        auto result = run_trials("p" + std::string(argv[1]));
        if (result.first)
        {
            std::cout << "Problem " << argv[1] << " average: " << result.second / 3 << " ms" << std::endl;
            return 0;
        } else
        {
            std::cerr << "Error during trials" << std::endl;
            return -1;
        }
    }

    std::ofstream csv_file("averages.csv");
    csv_file << "Problem #,Average Time (ms)\n";

    for (uint32_t i = 0; i <= problem_count; ++i)
    {
        auto result = run_trials("p" + std::to_string(i));
        if (result.first)
        {
            uint32_t average = result.second / 3;
            csv_file << i << "," << average << "\n";
        } else
        {
            std::cerr << "Error: failure during iteration: " << i << std::endl;
            return -1;
        }
    }

    csv_file.close();
    return 0;
}