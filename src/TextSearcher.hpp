#pragma once
#include <string>   
#include <string_view>


class TextSearcher{

    private:
        std::string search_term;

    public:

        TextSearcher(std::string term) : search_term(std::move(term)){}

        bool matches( std:: string_view line) const{

            // auto result = line.find(search_term);

            // if(result != std::string_view::npos) return true;
            
            return line.find(search_term) != std::string_view::npos;

        }    

}; 