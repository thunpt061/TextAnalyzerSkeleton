//#include "TextAnalyzer.h"
//TextAnalyzer.h ở đâu ?
#include <sstream>
#include <cctype>
#include <map>

// Constructor
TextAnalyzer::TextAnalyzer(const std::string& input_text)
{
    textData = input_text;
}

// WordCount
int TextAnalyzer::getWordCount()
{
    std::stringstream ss(textData);
    std::string word;
    int count = 0;

    while (ss >> word)
    {
        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.front())))
        {
            word.erase(word.begin());
        }
        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.back())))
        {
            word.pop_back();
        }
        for (char& c : word)
        {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        if (!word.empty())
        {
            count++;
        }
    }
    return count;
}
// FrequencyMap
std::map<std::string, int> TextAnalyzer::getFrequencyMap()
{
    std::map<std::string, int> frequencyMap;
    std::stringstream ss(textData);
    std::string word;

    while (ss >> word)
    {
        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.front())))
        {
            word.erase(word.begin());
        }

        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.back())))
        {
            word.pop_back();
        }

        for (char& c : word)
        {
            c = std::tolower(static_cast<unsigned char>(c));
        }

        if (!word.empty())
        {
            frequencyMap[word]++;
        }
    }

    return frequencyMap;
}
