#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string_view>
#include "FileReader.hpp"

int main(int argc, char* argv[]) {
    
    if(argc != 3){
        std::cerr << "Usage: ./search <search_term> <filepath> \n";
        return 1;
    }


    TextSearcher term(argv[1]);
    FileReader path;

    std::vector<std::string> res = path.search_in_file(argv[2], term);

    for(const auto& line : res){
        
        size_t start = line.find_first_not_of(" \t");
        
        if (start != std::string::npos) {
            std::cout << line.substr(start) << "\n";
        } else {
            std::cout << line << "\n";
        }
    }

    return 0;
}