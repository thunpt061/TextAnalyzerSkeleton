#ifndef DIFF_H
#define DIFF_H

#include <string>
#include <vector>

struct DiffLine {
    int lineNum;
    std::string content1;
    std::string content2;
    char type;
};

std::vector<DiffLine> diffTwoFiles(
    const std::string& path1,
    const std::string& path2
);

void printDiff(const std::vector<DiffLine>& diffs);

#endif
