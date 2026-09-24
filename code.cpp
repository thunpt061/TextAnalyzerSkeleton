#include <iostream>
#include <string>

using namespace std;

// ==========================================
// CÁC MÃ MÀU ANSI ĐỂ TRANG TRÍ MENU
// ==========================================
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

// ==========================================
// CÁC LỚP KHUNG (Chờ ghép code ở các tuần sau)
// ==========================================
class TextAnalyzer {};
class PatternExtractor {};
class FindAndReplaceEngine {};
class FileDiffEngine {};
class FileMerger {};
class ReportExporter {};

// ==========================================
// LỚP QUẢN LÝ TỔNG (Dành cho Leader)
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
            // Giao diện Menu có màu sắc
            cout << "\n" << CYAN << BOLD << "=====================================================" << RESET << "\n";
            cout << CYAN << BOLD << "   🚀 TEXT DOCUMENT ANALYST ENGINE - NHÓM SỐ BỐN" << RESET << "\n";
            cout << CYAN << BOLD << "=====================================================" << RESET << "\n";
            
            cout << GREEN << " 1. " << RESET << "Nhập văn bản mới (Khởi tạo bộ nhớ tạm)\n";
            cout << GREEN << " 2. " << RESET << "Phân tích văn bản (Word Count, Frequency, N-Gram)\n";
            cout << GREEN << " 3. " << RESET << "Trích xuất dữ liệu (Email, URL)\n";
            cout << GREEN << " 4. " << RESET << "Tìm kiếm & Thay thế (Find & Replace)\n";
            cout << GREEN << " 5. " << RESET << "So sánh 2 tệp (File Diff Engine)\n";
            cout << GREEN << " 6. " << RESET << "Gộp tệp & Sắp xếp (File Merger & Sorting)\n";
            cout << GREEN << " 7. " << RESET << "Xuất báo cáo tổng hợp (Analytics Report Exporter)\n";
            cout << RED << " 0. " << RESET << "Thoát chương trình\n";
            
            cout << CYAN << BOLD << "=====================================================" << RESET << "\n";
            cout << YELLOW << "Nhập lựa chọn của bạn (0-7): " << RESET;
            
            cin >> choice;
            cin.ignore(); // Xóa bộ đệm phím Enter

            // Xử lý các lựa chọn
            switch (choice) {
                case 1:
                    cout << BLUE << "\nNhập đoạn văn bản cần xử lý: " << RESET;
                    getline(cin, currentText);
                    cout << GREEN << "✅ Đã lưu văn bản thành công vào bộ nhớ hệ thống!\n" << RESET;
                    break;
                case 2:
                    cout << YELLOW << "\n[Đang phát triển] Chờ ghép module của Thương & Lam...\n" << RESET;
                    break;
                case 3:
                    cout << YELLOW << "\n[Đang phát triển] Chờ ghép module của Đặng Vy & Nhiên...\n" << RESET;
                    break;
                case 4:
                    cout << YELLOW << "\n[Đang phát triển] Chờ ghép module của Tấn Đông...\n" << RESET;
                    break;
                case 5:
                case 6:
                case 7:
                    cout << YELLOW << "\n[Đang phát triển] Các tính năng File I/O sẽ được tích hợp ở Tuần 3...\n" << RESET;
                    break;
                case 0:
                    cout << GREEN << "\nĐang đóng ứng dụng. Cảm ơn bạn đã sử dụng! 👋\n" << RESET;
                    break;
                default:
                    cout << RED << "\n❌ Lựa chọn không hợp lệ. Vui lòng nhập số từ 0 đến 7!\n" << RESET;
            }
        }
    }
};

int main() {
    TextDocumentEngine engine;
    engine.runMenu();
    return 0;
}