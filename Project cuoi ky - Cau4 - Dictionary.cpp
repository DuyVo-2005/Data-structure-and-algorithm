#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include<fstream>
#include <io.h>// lấy hàm _setmode()
#include <fcntl.h>// lấy hàm _O_WTEXT
#include <codecvt>
//thêm L vào chuỗi -> tạo chuỗi ký tự rộng -> Latin, Tiếng Việt
using namespace std;

const int m = 15013;


struct Meaning {
    wstring EnglishMeaning;
    wstring VietnameseMeaning;
};
#define ElementType Meaning
struct Node
{
    Meaning meaning;
    Node* pLeft, * pRight;
};
Node* hashtable[m];//khai bao mang bam co moi phan tu la goc cay BST

unsigned long long ConvertBinaryNumberToDecimalNumber(wstring BinaryNumber);
wstring ConvertDecimalNumberToBinaryNumber(unsigned long long DecimalNumber);
unsigned long long ConvertWordToNumber(wstring word);
Node* CreateNode(Meaning meaning);
void DeleteNode(Node*& root, ElementType node);
unsigned long long HashFunction(wstring EnglishMeaning);
void InitTree(Node*& root);
void InsertNode(Node*& root, Node* newNode);
bool IsEmptyTree(Node* T);
void PrintTree_InOrder(Node* root);
void ReadBinaryFile(wifstream &inFile);
void ReplaceNode(Node*& p, Node*& T);
Meaning SplitStringBy(wstring s, char sep);
wstring TranslateEnglishMeaningToVietnameseMeaning(Node* root, wstring EnglishMeaning);

int main()
{
	//wcout << ConvertWordToNumber("pneumonoultramicroscopicsilicovolcanoconiosis");
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	// Thiết lập locale UTF-8
	locale::global(locale("en_US.UTF-8"));
	wifstream inFile("D:\\english_vietnamese_dictionary.bin", ios::binary);
	if (!inFile) {
		wcout << L"Không thể mở tệp nhị phân" << endl;
		return 1;
	}
	ReadBinaryFile(inFile);
	inFile.close();
	bool continue_ = true;
	/*while (continue_) {
		int choice = -1;
		while (choice != 4) {
			wcout << L"\n- - - - - - - -- - - - - - - - - - - - - - - -";
			wcout << L"\nDanh sach các thao tác ";
			wcout << L"\n1. Thêm 1 từ vào từ điển";
			wcout << L"\n2. Xoá 1 từ khỏi từ điển";
			wcout << L"\n3. Dịch 1 từ tiếng Anh sang tiếng Việt";
			wcout << L"\n4. Thoát";
			wcout << L"\nNhập một số nguyên tương ứng với lựa chọn: ";
			cin >> choice;
			switch (choice) {
			case 1: {
				Meaning newWord;
				wcout << L"\nNhap phan tu can them";
				wcout << L"\nNhap nghia tieng Anh: ";
				wcin.ignore();
				getline(wcin, newWord.EnglishMeaning);
				wcout << L"\nNhap nghia tieng Viet: ";
				getline(wcin, newWord.VietnameseMeaning);
				InsertNode(hashtable[HashFunction(newWord.EnglishMeaning)], CreateNode(newWord));
				break;
			}
			case 2: {
				Meaning meaning;
				wcout << L"\nNhap tu Tieng Anh can xoa";
				wcin.ignore();
				getline(wcin, meaning.EnglishMeaning);
				DeleteNode(hashtable[HashFunction(meaning.EnglishMeaning)], meaning);
				break;
			}
			case 3: {
				wstring EnglishMeaning;
				wcout << L"\nNhap tu tieng Anh can dich nghia tieng Viet: ";
				wcin.ignore();
				getline(wcin, EnglishMeaning);
				long long pos = HashFunction(EnglishMeaning);
				wstring VietnameseMeaning = TranslateEnglishMeaningToVietnameseMeaning(hashtable[pos], EnglishMeaning);
				if (VietnameseMeaning == L"None")
					wcout << L"\nKhong tim nghia tieng Viet cua tu " << EnglishMeaning;
				else
					wcout << L"\nTim thay nghia tieng Viet cua tu " << EnglishMeaning << " la " << VietnameseMeaning;
				break;
			}
			case 4: {
				continue_ = false;
				break;
			}
			default: {
				wcout << L"\nSo vua nhap khong hop le! ";
				break;
			}
			}
		}
	}*/
    return 0;
}

unsigned long long ConvertBinaryNumberToDecimalNumber(wstring BinaryNumber)
{
	unsigned long long res = 0;
	for (long long i = BinaryNumber.length() - 1, j = 0; i >= 0; i--, j++)
	{
		res += (BinaryNumber[i] - L'0') * pow(2, j);
	}
	return res;
}
wstring ConvertDecimalNumberToBinaryNumber(unsigned long long DecimalNumber)
{
	wstring res = L"";
	while (DecimalNumber > 0)
	{
		res += DecimalNumber % 2 + L'0';
		DecimalNumber /= 2;
	}
	reverse(res.begin(), res.end());
	while (res.length() < 8)
	{
		//Chen so 0 thieu ben trai chuoi nhi phan
		res = L'0' + res;
	}
	return res;
}
unsigned long long ConvertWordToNumber(wstring word)
{
	wstring res = L"";
	while (word.length() != 0)
	{	//chua duyet het chuoi word
		//lay phan tu cuoi chuoi
		int tmp = int(word[word.length() - 1]);
		res = ConvertDecimalNumberToBinaryNumber(tmp) + res;
		//xoa phan tu cuoi chuoi de xet den ki tu tiep theo ke cuoi
		word.pop_back();
	}
	return ConvertBinaryNumberToDecimalNumber(res);
}
Node* CreateNode(Meaning meaning) {
    Node* p = new Node;
    if (p == NULL)   return NULL;
    p->meaning.EnglishMeaning = meaning.EnglishMeaning;
    p->meaning.VietnameseMeaning = meaning.VietnameseMeaning;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void DeleteNode(Node*& root, ElementType node) {
    //co thi xoa, khong thi thoi
    if (root == NULL) return;
    if (root->meaning.EnglishMeaning > node.EnglishMeaning)//tim ben trai
        DeleteNode(root->pLeft, node);
    else {
        if (root->meaning.EnglishMeaning < node.EnglishMeaning)//tim ben phai
            DeleteNode(root->pRight, node);
        else// tim thay x trong cay
        {
            Node* p = root;
            if (root->pLeft == NULL)// co 1 nut con tro den chinh no
                root = root->pRight;// la nut con phai
            else
            {
                if (root->pRight == NULL)
                    root = root->pLeft;//la nut con trai
                else//TH co 2 nut con chon min ben phai
                    ReplaceNode(p, root->pRight);
            }
        }
    }
}
unsigned long long HashFunction(wstring EnglishMeaning) {
    unsigned long long k = ConvertWordToNumber(EnglishMeaning);
    double A = 1 / 2 * (sqrt(5) - 1);
    return unsigned long long((double(m) * (int((double(k) * A)) % 1)));
}
void InitTree(Node*& root) {
    root = NULL;
}
void InsertNode(Node*& root, Node* newNode) {
    if (root == NULL)    root = newNode;
    else {
        if (newNode->meaning.EnglishMeaning < root->meaning.EnglishMeaning)   InsertNode(root->pLeft, newNode);
        else
        {
            if (newNode->meaning.EnglishMeaning > root->meaning.EnglishMeaning)
                InsertNode(root->pRight, newNode);
        }
    }
}
bool IsEmptyTree(Node* T) {
    if (T == NULL) return true;
    return false;
}
void PrintTree_InOrder(Node* root) {
    if (root != NULL) {
        PrintTree_InOrder(root->pLeft);
        wcout << L"\n" << root->meaning.EnglishMeaning << " " << root->meaning.VietnameseMeaning;
        PrintTree_InOrder(root->pRight);
    }
}
void ReadBinaryFile(wifstream& inFile) {
	size_t length;
	while (inFile.read(reinterpret_cast<wchar_t*>(&length), sizeof(length))) {
		// Đọc nội dung dòng
		wstring line(length, L'\0');
		inFile.read(&line[0], length);
		Meaning newWord;
		neword = SplitStringBy(line, L'-');
		InsertNode(hashtable[newWord.EnglishMeaning], CreateNode(newWord));
	}
}
void ReplaceNode(Node*& p, Node*& T) {
    //thay the bang nut trai nhat ben trai
    if (T->pLeft != NULL)  ReplaceNode(p, T->pLeft);
    else
    {
        p->meaning = T->meaning;
        p = T;
        T = T->pRight;
    }
}
Meaning SplitStringBy(wstring s, wchar sep) {
	Meaning res;
	res.EnglishMeaning = L"", res.VietnameseMeaning = L"";
	int i = 0;
	while (s[i] != sep)
	{
		res.EnglishMeaning += s[i];
		i++;
	}
	i++;// bỏ qua vị trí dấu phân cách
	while (i < s.length()) {
		res.VietnameseMeaning += s[i];
		i++;
	}
	return res;
}
wstring TranslateEnglishMeaningToVietnameseMeaning(Node* root, wstring EnglishMeaning) {
    Node* p = root;
    while (p != NULL)
    {
        if (EnglishMeaning == p->meaning.EnglishMeaning) return p->meaning.VietnameseMeaning;
        else
            if (EnglishMeaning < p->meaning.EnglishMeaning) p = p->pLeft;
            else p = p->pRight;
    }
    return L"None";
}
