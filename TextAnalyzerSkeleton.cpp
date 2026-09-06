// Bo khung TextAnalizer
#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <string>
#include <map>
#include <vector>

class TextAnalyzer {
private:
    std::string textData; 

public:

    TextAnalyzer(const std::string& input_text);
    
    int getWordCount(); 
    std::map<std::string, int> getFrequencyMap(); 

    std::vector<std::string> getNGrams(int n); 
};

#endif
