#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;
#define MAX 100
#define FALSE 0
#define TRUE 1
#define NONE -99999999
ifstream infile("danh sach ma so_ten.txt");
struct Word {
	string mssv;
	string tenSv;
};
const int m = 15013;
typedef struct tagNode
{
	Word key;
	tagNode* pNext;
} Node;
typedef struct
{
	Node* pHead;
	Node* pTail;
}LINKEDLIST;
LINKEDLIST hashtable[m];
int HashFunction(string mssv) {
	long long ascii = int(mssv[0]);
	for (int i = 1; i < mssv.length(); i++) {
		ascii *= 10;
		ascii += int(mssv[i]);
		ascii %= m;
	}
	return ascii;
}
Node* CreateNode(string mssv, string tenSV) {
	Node* p = new Node;
	if (p == NULL)   return NULL;
	p->key.mssv = mssv;
	p->key.tenSv = tenSV;
	p->pNext = NULL;
	return p;
}
void InitList(LINKEDLIST& l) {
	l.pHead = l.pTail = NULL;
}
bool IsEmptyList(LINKEDLIST l) {
	return l.pHead == NULL;
}
void AddFirst(LINKEDLIST& l, string mssv, string tenSV) {
	Node* p = CreateNode(mssv, tenSV);
	if (IsEmptyList(l))  l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddLast(LINKEDLIST& l, string mssv, string tenSV) {
	Node* p = CreateNode(mssv, tenSV);
	if (IsEmptyList(l))  l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void AddAfter(LINKEDLIST& l, Node* p, string mssv, string tenSV) {
	//them node moi sau node p
	Node* q = CreateNode(mssv, tenSV);
	if (p == NULL || q == NULL)  cout << "\nKhong them node moi duoc!";
	else {
		q->pNext = p->pNext;//luu dia chi phia sau q truoc
		p->pNext = q;
		if (p == l.pTail)    l.pTail = q;
	}
}
void RemoveFirst(LINKEDLIST& l) {
	if (IsEmptyList(l))  cout << "\nKhong xoa duoc do list rong!";
	else if (l.pHead == l.pTail) {
		//1 phan tu
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else {
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void RemoveLast(LINKEDLIST& l) {
	if (IsEmptyList(l)) cout << "\nKhong xoa duoc do list rong!";
	else if (l.pHead == l.pTail) {//1 phan tu
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else {
		//nhieu hon 1 phan tu
		Node* p = l.pHead;// p la nut truoc l.tail
		while (p->pNext != l.pTail) {
			p = p->pNext;
		}
		delete l.pTail;
		l.pTail = p;
		l.pTail->pNext = NULL;
	}
}
string SearchNode(LINKEDLIST l, string mssv) {
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->key.mssv == mssv) return p->key.tenSv;//tim thay tai vi tri HashFunction(x)
	return "None";//khong tim thay
}
void PushElementToTheBeginningOfHashTable(int b, string mssv, string tenSV)
{
	Node* p = new Node;
	p->key.mssv = mssv;
	p->key.tenSv = tenSV;
	p->pNext = hashtable[b].pHead;
	hashtable[b].pHead = p;
}
void Place(int b, string mssv, string tenSV)
{
	Node* p, * q;
	q = NULL;
	for (p = hashtable[b].pHead; p != NULL && mssv > p->key.mssv; p = p->pNext)
		q = p;
	if (q == NULL)
		PushElementToTheBeginningOfHashTable(b, mssv, tenSV);
	else
		AddAfter(hashtable[b], q, mssv, tenSV);
}
void AddItem(LINKEDLIST hashtable[m], string EnglishMeaning, string VietnameseMeaning) {
	int b = HashFunction(EnglishMeaning);
	Place(b, EnglishMeaning, VietnameseMeaning); //chen x vao danh sach lien ket
}
void FreeNode(Node* p) {
	delete p;
}
bool IsEmptyBucket(int b) {
	return hashtable[b].pHead == NULL;
}
void PopThebeginningOfBucket(int b)
{
	Node* p;
	int k;
	if (IsEmptyBucket(b)) {
		cout << "Bucket dang rong, khong xoa duoc!";
		exit(1);
	}
	p = hashtable[b].pHead;
	hashtable[b].pHead = p->pNext; FreeNode(p);
}
void RemoveAfter(Node* p) {
	Node* q;//nut can xoa la q
	int k;
	if (p == NULL || p->pNext == NULL) {
		cout << "\nKhong xoa node duoc!";
		exit(1);
	}
	q = p->pNext;
	p->pNext = q->pNext;
	FreeNode(q);
}
void RemoveItem(LINKEDLIST hashtable[MAX], string mssv) {
	Node* p, * q = NULL;
	int b = HashFunction(mssv);
	p = hashtable[b].pHead;
	while (p != NULL && p->key.mssv != mssv) {
		q = p;
		p = p->pNext;
	}
	if (p == NULL)	cout << "\nKhong co node co khoa can xoa!";
	else if (p == hashtable[b].pHead)	PopThebeginningOfBucket(b);
	else	RemoveAfter(q);
}
void TraverseBucket(int b) {
	Node* p = hashtable[b].pHead;
	while (p != NULL) {
		cout << p->key.mssv << " " << p->key.mssv;
		p = p->pNext;
	}
}
void PrintHashtable(LINKEDLIST hashtable[]) {
	for (int b = 0; b < 100; b++) {
		cout << "\nBucket thu " << b << ": ";
		TraverseBucket(b);
	}
}
void ReadFile() {
	Word newWord;
	while (!infile.eof()) {
		infile >> newWord.mssv >> newWord.tenSv;
		AddItem(hashtable, newWord.mssv, newWord.tenSv);
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
				AddItem(hashtable, newKey.mssv, newKey.tenSv);
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
				string tenSV = SearchNode(hashtable[pos], mssv);
				if (tenSV == "None")
					cout << "\nKhong tim thay ten cua ma so " << mssv;
				else
					cout << "\nTen sinh vien co ma so sinh vien " << mssv << " la " << tenSV;
				break;
			}
			case 4: {
				PrintHashtable(hashtable);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
