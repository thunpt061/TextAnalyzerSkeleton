#include <iostream>
#include <vector>
#include <string>
#include "Diff.h"
#include "FileMerge.h"

using namespace std;

// ==========================================
// CÁC MÃ MÀU ANSI Ð? TRANG TRÍ MENU
// ==========================================
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

// ==========================================
// CÁC L?P KHUNG (Ch? ghép code ? các tu?n sau)
// ==========================================
class TextAnalyzer {};
class PatternExtractor {};
class FindAndReplaceEngine {};
class ReportExporter {};

// ==========================================
// L?P QU?N LÝ T?NG (Dành cho Leader)
// ==========================================
class TextDocumentEngine {
private:
    string currentText;
    
    // Khai báo các module con
    TextAnalyzer analyzer;
    FindAndReplaceEngine fnrEngine;

public:
    TextDocumentEngine() {
        currentText = "";
    }

    void runMenu() {
        int choice = -1;
        while (choice != 0) {
            // Giao di?n Menu có màu s?c
            cout << "\n" << CYAN << BOLD << "=====================================================" << RESET << "\n";
            cout << CYAN << BOLD << "   ?? TEXT DOCUMENT ANALYST ENGINE - NHÓM S? B?N" << RESET << "\n";
            cout << CYAN << BOLD << "=====================================================" << RESET << "\n";
            
            cout << GREEN << " 1. " << RESET << "Nh?p van b?n m?i (Kh?i t?o b? nh? t?m)\n";
            cout << GREEN << " 2. " << RESET << "Phân tích van b?n (Word Count, Frequency, N-Gram)\n";
            cout << GREEN << " 3. " << RESET << "Trích xu?t d? li?u (Email, URL)\n";
            cout << GREEN << " 4. " << RESET << "Tìm ki?m & Thay th? (Find & Replace)\n";
            cout << GREEN << " 5. " << RESET << "So sánh 2 t?p (File Diff Engine)\n";
            cout << GREEN << " 6. " << RESET << "G?p t?p & S?p x?p (File Merger & Sorting)\n";
            cout << GREEN << " 7. " << RESET << "Xu?t báo cáo t?ng h?p (Analytics Report Exporter)\n";
            cout << RED << " 0. " << RESET << "Thoát chuong trình\n";
            
            cout << CYAN << BOLD << "=====================================================" << RESET << "\n";
            cout << YELLOW << "Nh?p l?a ch?n c?a b?n (0-7): " << RESET;
            
            cin >> choice;
            cin.ignore(); // Xóa b? d?m phím Enter

            // X? lý các l?a ch?n
            switch (choice) {
                case 1:
                    cout << BLUE << "\nNh?p do?n van b?n c?n x? lý: " << RESET;
                    getline(cin, currentText);
                    cout << GREEN << "? Ðã luu van b?n thành công vào b? nh? h? th?ng!\n" << RESET;
                    break;
                case 2:
                    cout << YELLOW << "\n[Ðang phát tri?n] Ch? ghép module c?a Thuong & Lam...\n" << RESET;
                    break;
                case 3:
                    cout << YELLOW << "\n[Ðang phát tri?n] Ch? ghép module c?a Ð?ng Vy & Nhiên...\n" << RESET;
                    break;
                case 4:
                    cout << YELLOW << "\n[Ðang phát tri?n] Ch? ghép module c?a T?n Ðông...\n" << RESET;
                    break;
                case 5:
{
    string file1, file2;

    cout << BLUE << "\nNh?p du?ng d?n file th? nh?t: " << RESET;
    getline(cin, file1);

    cout << BLUE << "Nh?p du?ng d?n file th? hai: " << RESET;
    getline(cin, file2);

    vector<DiffLine> result = diffTwoFiles(file1, file2);

    printDiff(result);

    break;
}
                case 6:
{
    int n;

    cout << BLUE << "\nNh?p s? lu?ng file c?n g?p: " << RESET;
    cin >> n;
    cin.ignore();

    vector<string> inputFiles;

    for (int i = 0; i < n; i++) {
        string file;

        cout << BLUE << "Nh?p du?ng d?n file " << i + 1 << ": " << RESET;
        getline(cin, file);

        inputFiles.push_back(file);
    }

    string outputFile;

    cout << BLUE << "Nh?p tên file d?u ra: " << RESET;
    getline(cin, outputFile);

    FileMerger merger;
    merger.mergeFiles(inputFiles, outputFile);

    break;
}
                case 7:
                    cout << YELLOW << "\n[Ðang phát tri?n] Các tính nang File I/O s? du?c tích h?p ? Tu?n 3...\n" << RESET;
                    break;
                case 0:
                    cout << GREEN << "\nÐang dóng ?ng d?ng. C?m on b?n dã s? d?ng! ??\n" << RESET;
                    break;
                default:
                    cout << RED << "\n? L?a ch?n không h?p l?. Vui lòng nh?p s? t? 0 d?n 7!\n" << RESET;
            }
        }
    }
};

int main() {
    TextDocumentEngine engine;
    engine.runMenu();
    return 0;
}
