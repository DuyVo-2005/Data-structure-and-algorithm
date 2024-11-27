#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <io.h>// lấy hàm _setmode()
#include <fcntl.h>// lấy hàm _O_WTEXT
#include <codecvt>
using namespace std;
int main() {
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    // Thiết lập locale UTF-8
    locale::global(locale("en_US.UTF-8"));  

    // Mở tệp văn bản để đọc
    wifstream inFile("D:\\english_vietnamese_dictionary.txt");
    inFile.imbue(locale("en_US.UTF-8")); // Đọc tệp dưới dạng UTF-8
    if (!inFile) {
        wcerr << L"Không thể mở tệp văn bản"<< endl;
        return 1;
    }

    // Mở tệp nhị phân để ghi
    wofstream outFile("D:\\english_vietnamese_dictionary.bin", ios::binary);
    if (!outFile) {
        wcerr << L"Không thể mở tệp nhị phân" << endl;
        return 1;
    }

    wstring line;
    while (getline(inFile, line)) {
        // Tính số ký tự trong chuỗi
        size_t length = line.size();

        // Ghi số ký tự vào tệp
        outFile.write(reinterpret_cast<const wchar_t*>(&length), sizeof(length));

        // Ghi nội dung dòng
        outFile.write(line.c_str(), length);
    }

    inFile.close();
    outFile.close();

    wcout << L"Ghi tệp nhị phân thành công!" << endl;
    return 0;
}
