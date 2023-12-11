#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void read_file(std::string& a, const std::string& path)
{
    std::string line;
    std::stringstream stream;
    std::fstream fin(path, std::fstream::in);
    if(!fin.is_open())
    {
        std::cout << "\nthe file isn't opened to read(str)!\n";
        return;
    }

    // std::string tmp;
    while (getline(fin, line))
        stream << line << '\n';

    // while (stream >> tmp)
        // a += tmp;

    a = stream.str();
    fin.close();
}
