#include "Diff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<DiffLine> diffTwoFiles(
    const string& path1,
    const string& path2
) {
    ifstream f1(path1);
    ifstream f2(path2);
    
    if (!f1.is_open()) {
        cerr << "Khong mo duoc file: " << path1 << "\n";
        return vector<DiffLine>();
    }
    if (!f2.is_open()) {
        cerr << "Khong mo duoc file: " << path2 << "\n";
        return vector<DiffLine>();
    }

    vector<DiffLine> result;
    string line1, line2;
    int lineNum = 0;

    bool has1 = static_cast<bool>(getline(f1, line1));
    bool has2 = static_cast<bool>(getline(f2, line2));

    while (has1 || has2) {
        ++lineNum;

        if (has1 && has2) {
            DiffLine d;
            d.lineNum = lineNum;
            d.content1 = line1;
            d.content2 = line2;
            d.type = (line1 == line2) ? '=' : '!';
            result.push_back(d);
        } else if (has1) {
            DiffLine d;
            d.lineNum = lineNum;
            d.content1 = line1;
            d.content2 = "";
            d.type = '<';
            result.push_back(d);
        } else {
            DiffLine d;
            d.lineNum = lineNum;
            d.content1 = "";
            d.content2 = line2;
            d.type = '>';
            result.push_back(d);
        }

        has1 = static_cast<bool>(getline(f1, line1));
        has2 = static_cast<bool>(getline(f2, line2));
    }

    f1.close();
    f2.close();
    return result;
}
