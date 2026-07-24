#include <string>
#include <vector>
#include <fstream>
#include "TextSearcher.hpp"

class FileReader {
public:
    // Notice we pass the TextSearcher by const reference (Section 1) so we don't copy it!
    std::vector<std::string> search_in_file(std::string_view file_path, const TextSearcher& searcher) {
        
        std::vector<std::string> results;
        std::ifstream file(std::string{file_path});

        if(!file.is_open()){
            return results;
        }

        std::string current_line;
        
        while (std::getline(file, current_line)) {       
            if (searcher.matches(current_line)) {          
                results.push_back(std::move(current_line));
            }
        }
        return results;
    }
};