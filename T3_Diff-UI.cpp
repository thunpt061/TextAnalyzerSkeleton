void printDiff(const vector<DiffLine>& diffs) {
    cout << "\n========== DIFF RESULT ==========\n\n";

    if (diffs.empty()) {
        cout << "No differences found.\n";
        cout << "\n=================================\n";
        return;
    }

    for (size_t i = 0; i < diffs.size(); ++i) {
        const DiffLine& d = diffs[i];

        if (d.type == '=') {
            // Dong giong nhau thi giu mau binh thuong
            cout << "  Line " << d.lineNum
                 << ": " << d.content1 << "\n";
        }

        else if (d.type == '!') {
            // Dong file 1 bi thay doi mau do
            cout << "\033[31m"
                 << "- Line " << d.lineNum
                 << ": " << d.content1
                 << "\033[0m\n";

            // Dong file 2 bi thay doi mau xanh
            cout << "\033[32m"
                 << "+ Line " << d.lineNum
                 << ": " << d.content2
                 << "\033[0m\n";
        }

        else if (d.type == '<') {
            // Chi co trong file 1 thi mau do
            cout << "\033[31m"
                 << "- Line " << d.lineNum
                 << ": " << d.content1
                 << "\033[0m\n";
        }

        else if (d.type == '>') {
            // Chi co trong file 2 thi mau xanh
            cout << "\033[32m"
                 << "+ Line " << d.lineNum
                 << ": " << d.content2
                 << "\033[0m\n";
        }
    }

    cout << "\n=================================\n";
}
