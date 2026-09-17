#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "TextAnalyzer.h"

using namespace std;

int main()
{
    string text = "This is a sample text. ...";

    TextAnalyzer analyzer(text);

    cout << "INPUT TEXT: " << text << endl;
    cout << "WORD COUNT : " << analyzer.getWordCount() << endl;


    cout << endl;
    cout << " FREQUENCY MAP " << endl;

    map<string, int> frequencyMap = analyzer.getFrequencyMap();
    for (const auto& item : frequencyMap)
    {
        cout << item.first << " : " << item.second << endl;
    }

    cout << endl;
    cout << "2-GRAM " << endl;

    vector<string> nGrams = analyzer.getNGrams(2);
    for (const string& gram : nGrams)
    {
        cout << gram << endl;
    }

    return 0;
}

