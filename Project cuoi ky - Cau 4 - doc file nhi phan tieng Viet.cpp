#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <io.h>// lấy hàm _setmode()
#include <fcntl.h>// lấy hàm _O_WTEXT
#include <codecvt>
using namespace std;
int main() {
    _setmode(_fileno(stdout), _O_WTEXT);//đặt lại chuẩn stdout
    _setmode(_fileno(stdin), _O_WTEXT);//đặt lại chuẩn stdin

    // Thiết lập locale UTF-8
    locale::global(locale("en_US.UTF-8"));

    wifstream inFile("D:\\english_vietnamese_dictionary.bin", ios::binary);
    if (!inFile) {
        wcout << L"Không thể mở tệp nhị phân" << endl;
        return 1;
    }

    size_t length;
    while (inFile.read(reinterpret_cast<wchar_t*>(&length), sizeof(length))) {
        // Đọc nội dung dòng
        wstring line(length, L'\0');
        inFile.read(&line[0], length);
        wcout << line << endl;
    }

    inFile.close();
    return 0;
}
