#include "T1_TextAnalyzerSkeleton.cpp"

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    const string sampleText = "This is a sample text for testing text analysis. This sample text has repeated words.";
    TextAnalyzer analyzer(sampleText);

    cout << "Word count: " << analyzer.getWordCount() << "\n";

    map<string, int> frequency = analyzer.getFrequencyMap();
    cout << "Frequency map:\n";
    for (const auto& entry : frequency) {
        cout << "  " << entry.first << " -> " << entry.second << "\n";
    }

    cout << "\nProgram is ready for real file input.\n";
    return 0;
}
