#include "FileMerge.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool FileMerger::sortAlphabetically(const string& a, const string& b) {
    return a < b;
}

void FileMerger::mergeFiles(
    const vector<string>& inputFiles,
    const string& outputFile
) {
    vector<string> allLines;

    // 1. Ð?c d? li?u t? t?t c? các file d?u vào
    for (const string& filename : inputFiles) {
        ifstream inFile(filename);

        if (!inFile.is_open()) {
            cout << "\033[31m"
                 << "Loi: Khong the mo tep " << filename
                 << "\033[0m\n";
            continue;
        }

        string line;
        while (getline(inFile, line)) {
            allLines.push_back(line);
        }

        inFile.close();

        cout << "\033[32m"
             << "Da doc thanh cong: " << filename
             << "\033[0m\n";
    }

    // 2. S?p x?p A-Z
    sort(allLines.begin(), allLines.end(), sortAlphabetically);

    // 3. Ghi ra file m?i
    ofstream outFile(outputFile);

    if (!outFile.is_open()) {
        cout << "\033[31m"
             << "Loi: Khong the tao tep dau ra " << outputFile
             << "\033[0m\n";
        return;
    }

    for (const string& line : allLines) {
        outFile << line << "\n";
    }

    outFile.close();

    cout << "\033[32m"
         << "Gop tep thanh cong! Vui long kiem tra file: "
         << outputFile
         << "\033[0m\n";
}
