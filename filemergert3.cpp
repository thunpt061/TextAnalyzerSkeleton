#include <"FileMerge.h">
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

    // Thuật toán sắp xếp cơ bản (Tấn Đông sẽ nâng cấp phần custom comparators này sau)
    static bool sortAlphabetically(const string& a, const string& b) {
        return a < b;
    }

    void mergeFiles(const vector<string>& inputFiles, const string& outputFile) {
        vector<string> allLines;
        
        // 1. Đọc dữ liệu từ tất cả các file đầu vào
        for (const string& filename : inputFiles) {
            ifstream inFile(filename);
            
            if (!inFile.is_open()) {
                cout << "\033[31m" << "❌ Lỗi: Không thể mở tệp " << filename << "\033[0m\n";
                continue; // Bỏ qua file lỗi, tiếp tục với file khác
            }

            string line;
            while (getline(inFile, line)) {
                allLines.push_back(line);
            }
            inFile.close();
            cout << "\033[32m" << "Đã đọc thành công: " << filename << "\033[0m\n";
        }

        // 2. Tích hợp phần sắp xếp của Tấn Đông
        // Tạm thời dùng sắp xếp theo bảng chữ cái A-Z
        sort(allLines.begin(), allLines.end(), sortAlphabetically);

        // 3. Ghi toàn bộ dữ liệu đã gộp và sắp xếp ra file mới
        ofstream outFile(outputFile);
        if (!outFile.is_open()) {
            cout << "\033[31m" << "❌ Lỗi: Không thể tạo tệp đầu ra " << outputFile << "\033[0m\n";
            return;
        }

        for (const string& l : allLines) {
            outFile << l << "\n";
        }
        outFile.close();
        
        cout << "\033[32m" << "✅ Gộp tệp thành công! Vui lòng kiểm tra file: " << outputFile << "\033[0m\n";
    }
;
