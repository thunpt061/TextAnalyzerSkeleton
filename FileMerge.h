#ifndef MERGEFILE_H
#define MERGEFILE_H

#include <string>
#include <vector>

class FileMerger {
public:
    static bool sortAlphabetically(const std::string& a, const std::string& b);

    void mergeFiles(
        const std::vector<std::string>& inputFiles,
        const std::string& outputFile
    );
};

#endif
