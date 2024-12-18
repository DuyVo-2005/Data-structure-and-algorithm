#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;
#define FALSE 0
#define TRUE 1
ifstream infile("danh sach ma so_ten.txt");
struct Word {
	string mssv;
	string tenSv;
};
const int m = 15013;
#define MAX 15013
#define NONE "None"
Word hashtable[MAX];
void FillHashtable(Word hashtable[]) {
	for (int i = 0; i < MAX; i++) {
		hashtable[i].mssv = "None";
		hashtable[i].tenSv = "None";
	}
}
int HashFunction(string mssv) {
	long long ascii = int(mssv[0]);
	for (int i = 1; i < mssv.length(); i++) {
		ascii *= 10;
		ascii += int(mssv[i]);
		ascii %= m;
	}
	return ascii;
}
void AddItem(Word newWord) {
		int b = HashFunction(newWord.mssv);
		if (hashtable[b].mssv == "None") {
			hashtable[b].mssv = newWord.mssv;
			hashtable[b].tenSv = newWord.tenSv;
		}
		else {
			for (int i = 1; i < MAX; i++)
				if (hashtable[b + i].mssv == "None") {
					hashtable[b + i].mssv = newWord.mssv;
					hashtable[b + i].tenSv = newWord.tenSv;
					break;
				}
		}
}
void RemoveItem(Word hashtable[MAX], string x) {
	int b = HashFunction(x);
	if (hashtable[b].mssv == x) {
		hashtable[b].mssv = NONE;
		hashtable[b].tenSv = NONE;
		return;
	}
	else {
		for (int i = 1; i < MAX; i++)
			if (hashtable[b + i].mssv == x) {
				hashtable[b + i].mssv = NONE;
				hashtable[b + i].tenSv = NONE;
				return;
			}
	}
	cout << "\nKhong tim thay phan tu can xoa!";
}
string SearchItem(Word hashtable[MAX], string x) {
	//tra ve vi tri luu tru khoa x
	int b = HashFunction(x);
	if (hashtable[b].mssv == x)	return hashtable[b].tenSv;
	else {
		for (int i = 1; i < MAX; i++) {
			if (hashtable[b + i].mssv == x)	return hashtable[b + i].tenSv;
		}
	}
	return NONE;
}
void Traverse(Word hashtable[]) {
	cout << "\n";
	for (int i = 0; i < MAX; i++)
		if (hashtable[i].mssv != NONE)	cout << "\n" << i << "\t" << hashtable[i].mssv<<"\t"<<hashtable[i].tenSv;
		else	cout << "\n" << i << "\t" << "NONE";
}
void ReadFile() {
	Word newWord;
	while (!infile.eof()) {
		infile >> newWord.mssv >> newWord.tenSv;
		AddItem(newWord);
	}
}
int main()
{
	ReadFile();//khoi tao du lieu tu file
	bool continue_ = true;
	while (continue_) {
		int choice = -1;
		while (choice != 6) {
			cout << "\n- - - - - - - -- - - - - - - - - - - - - - - -";
			cout << "\nDanh sach cac thao tac ";
			cout << "\n1. Them 1 phan tu vao bang bam";
			cout << "\n2. Xoa 1 phan tu khoi bang bam";
			cout << "\n3. Tim kiem 1 phan tu trong bang bam";
			cout << "\n4. Xuat bang bam";
			cout << "\n5. Tao 1 node moi va xuat thong tin node";
			cout << "\n6. Thoat";
			cout << "\nNhap so nguyen tuong ung voi lua chon: ";
			cin >> choice;
			switch (choice) {
			case 1: {
				Word newKey;
				cout << "\nNhap phan tu can them";
				cout << "\nNhap ma so sinh vien: ";
				cin.ignore();
				getline(cin, newKey.mssv);
				cout << "\nNhap ten sinh vien: ";
				getline(cin, newKey.tenSv);
				AddItem(newKey);
				break;
			}
			case 2: {
				string mssv;
				cout << "\nNhap ma so sinh vien can xoa: ";
				cin.ignore();
				getline(cin, mssv);
				RemoveItem(hashtable, mssv);
				break;
			}
			case 3: {
				string mssv;
				cout << "\nNhap ma so sinh vien can tim ten sinh vien: ";
				cin.ignore();
				getline(cin, mssv);
				int pos = HashFunction(mssv);
				string tenSV = SearchItem(hashtable, mssv);
				if (tenSV == "None")
					cout << "\nKhong tim thay ten cua ma so " << mssv;
				else
					cout << "\nTen sinh vien co ma so sinh vien " << mssv << " la " << tenSV;
				break;
			}
			case 4: {
				Traverse(hashtable);
				break;
			}
				  /*case 5: {
					  int x;
					  cout << "\nNhap gia tri nguyen cho node can tao: ";
					  cin >> x;
					  Node* p = CreateNode(x);
					  cout << "\nThong tin node vua tao: key " << p->key << " | dia chi node ke tiep " << p->pNext;
				  }*/
			case 6: {
				continue_ = false;
				break;
			}
			default: {
				cout << "\nSo vua nhap khong hop le! ";
				break;
			}
			}
		}
	}
	return 0;
}
