/*
 * Compiles and runs every problem 5 times, recording
 * the average in averages.csv
*/

#include <iostream>
#include <cstdint>
#include <cstdio>
#include <map>
#include <charconv>
#include <cstring>
#include <system_error>

#ifndef PROBLEM_COUNT
    #define PROBLEM_COUNT 0
#endif

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
    auto s_pos = output.rfind(": ");
    if (s_pos == std::string::npos) { return UINT32_MAX; }

    uint32_t ms;
    const char* start = output.data() + s_pos + 2;

    auto [ptr, ec] = std::from_chars(start, output.data() + output.size(), ms);
    return (ec == std::errc()) ? ms : UINT32_MAX;
}

bool run_trials(std::map<uint32_t, uint32_t>& entries, const uint32_t n)
{
    std::string pn = "p" + std::to_string(n);
    std::string header_path = "\"Problems/" + pn + "/Solution.hpp\"";
    std::string compile_cmd = "g++ -std=c++20 -DSOLUTION_HEADER='" + header_path + "' main.cpp -o output";
    std::remove("./output");
    run_command(compile_cmd);

    uint32_t total_time = 0;
    bool success = true;

    for (uint32_t run = 0; run < 5; ++run)
    {
        std::string output = run_command("./output");
        uint32_t ms = extract_time(output);
        
        if (ms != UINT32_MAX) { total_time += ms; }
        else
        {
            std::cerr << "Error running trial " << run + 1 << " for problem " << n << std::endl;
            std::remove("./output");
            return false;
        }
    }

    entries[n] = total_time / 5;
    std::remove("./output");
    return true;
}

void load_entries(std::map<uint32_t, uint32_t>& entries)
{
    FILE* f = fopen("averages.csv", "r");
    if (!f) { return; }

    fscanf(f, "%*[^\n]\n");

    uint32_t p_num, avg_time;
    while (fscanf(f, "%u,%u", &p_num, &avg_time) == 2)
    {
        entries[p_num] = avg_time;
    }
    fclose(f);
}

bool write_entries(std::map<uint32_t, uint32_t>& entries)
{
    FILE* f = fopen("averages.csv", "w");
    if (!f)
    {
        std::cerr << "Error opening averages.csv to write" << std::endl;
        return false;
    }

    fprintf(f, "Problem #, Average Time (ms)\n");

    for (const auto& [n, ms_avg] : entries)
    {
        fprintf(f, "%u,%u\n", n, ms_avg);
    }
    fclose(f);
    return true;
}

int main(int argc, char** argv)
{
    std::map<uint32_t, uint32_t> entries;
    load_entries(entries);
    
    if (argc > 1)
    {
        uint32_t n;
        if (std::from_chars(argv[1], argv[1] + strlen(argv[1]), n).ec == std::errc())
        {
            if (!run_trials(entries, n)) { return -1; }
            std::cout << "Problem: " << n << "; Average time: " << entries[n] << std::endl;
        }
    } else
    {
        uint32_t problem_count = PROBLEM_COUNT;
        for (uint32_t i = 0; i <= problem_count; ++i)
        {
            if (entries.contains(i)) { continue; }
            std::cout << "Working problem: " << i << '\n';
            if (!run_trials(entries, i)) { return -1; }
        }
        std::cout << "All problems tested successfully" << std::endl;
    }

    if (!write_entries(entries)) { return -1; }
    std::cout << "All entries successfully recorded" << std::endl;

    return 0;
}