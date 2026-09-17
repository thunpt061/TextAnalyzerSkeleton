#include "TextAnalyzer.h"
#include <sstream>
#include <cctype>
#include <map>
#include <vector>

namespace
{
    std::string normalizeWord(const std::string& input)
    {
        std::string word = input;

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
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }

        return word;
    }
}

// 
TextAnalyzer::TextAnalyzer(const std::string& input_text)
{
    textData = input_text;
}

// từ để chứa 
int TextAnalyzer::getWordCount()
{
    std::stringstream ss(textData);
    std::string word;
    int count = 0;

    while (ss >> word)
    {
        std::string normalized = normalizeWord(word);

        if (!normalized.empty())
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
        std::string normalized = normalizeWord(word);

        if (!normalized.empty())
        {
            frequencyMap[normalized]++;
        }
    }

    return frequencyMap;
}







std::vector<std::string> TextAnalyzer::getNGrams(int n)
{
    std::vector<std::string> grams;
    if (n <= 0)
    {
        return grams;
    }

    std::vector<std::string> words;
    std::stringstream ss(textData);
    std::string word;

    while (ss >> word)
    {
        std::string normalized = normalizeWord(word);
        if (!normalized.empty())
        {
            words.push_back(normalized);
        }
    }

    const std::size_t windowSize = static_cast<std::size_t>(n);
    for (std::size_t i = 0; i + windowSize <= words.size(); ++i)
    {
        std::string gram;
        for (std::size_t j = 0; j < windowSize; ++j)
        {
            if (j > 0)
            {
                gram += ' ';
            }
            gram += words[i + j];
        }
        grams.push_back(gram);
    }

    return grams;
}