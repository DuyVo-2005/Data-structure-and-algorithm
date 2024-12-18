#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#define MAX 100
#define FALSE 0
#define TRUE 1
#define NONE -99999999
using namespace std;
struct Key {
	string EnglishMeaning;
	string VietnameseMeaning;
};
const int m = 15013;
typedef struct tagNode
{
	Key key;
	tagNode* pNext;
} Node;
typedef struct
{
	Node* pHead;
	Node* pTail;
}LINKEDLIST;
LINKEDLIST hashtable[m];
int HashFunction(string EnglishMeaning) {
	long long ascii = int(EnglishMeaning[0]);
	for (int i = 1; i < EnglishMeaning.length(); i++) {
		ascii *= 10;
		ascii += int(EnglishMeaning[i]);
		ascii %= m;
	}
	return ascii;
}
Node* CreateNode(string EnglishMeaning, string VietnameseMeaning) {
	Node* p = new Node;
	if (p == NULL)   return NULL;
	p->key.EnglishMeaning = EnglishMeaning;
	p->key.VietnameseMeaning = VietnameseMeaning;
	p->pNext = NULL;
	return p;
}
void InitList(LINKEDLIST& l) {
	l.pHead = l.pTail = NULL;
}
bool IsEmptyList(LINKEDLIST l) {
	return l.pHead == NULL;
}
void AddFirst(LINKEDLIST& l, string EnglishMeaning, string VietnameseMeaning) {
	Node* p = CreateNode(EnglishMeaning, VietnameseMeaning);
	if (IsEmptyList(l))  l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddLast(LINKEDLIST& l, string EnglishMeaning, string VietnameseMeaning) {
	Node* p = CreateNode(EnglishMeaning, VietnameseMeaning);
	if (IsEmptyList(l))  l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void AddAfter(LINKEDLIST& l, Node* p, string EnglishMeaning, string VietnameseMeaning) {
	//them node moi sau node p
	Node* q = CreateNode(EnglishMeaning, VietnameseMeaning);
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
string SearchNode(LINKEDLIST l, string EnglishMeaning) {
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->key.EnglishMeaning == EnglishMeaning) return p->key.VietnameseMeaning;//tim thay tai vi tri HashFunction(x)
	return "None";//khong tim thay
}
void PushElementToTheBeginningOfHashTable(int b, string EnglishMeaning, string VietnameseMeaning)
{
	Node* p = new Node;
	p->key.EnglishMeaning = EnglishMeaning;
	p->key.VietnameseMeaning = VietnameseMeaning;
	p->pNext = hashtable[b].pHead;
	hashtable[b].pHead = p;
}
void Place(int b, string EnglishMeaning, string VietnameseMeaning)
{
	Node* p, * q;
	q = NULL;
	for (p = hashtable[b].pHead; p != NULL && EnglishMeaning > p->key.EnglishMeaning; p = p->pNext)
		q = p;
	if (q == NULL)
		PushElementToTheBeginningOfHashTable(b, EnglishMeaning, VietnameseMeaning);
	else
		AddAfter(hashtable[b], q, EnglishMeaning, VietnameseMeaning);
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
void RemoveItem(LINKEDLIST hashtable[MAX], string EnglishMeaning) {
	Node* p, * q = NULL;
	int b = HashFunction(EnglishMeaning);
	p = hashtable[b].pHead;
	while (p != NULL && p->key.EnglishMeaning != EnglishMeaning) {
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
		cout << p->key.EnglishMeaning << " " <<p->key.VietnameseMeaning;
		p = p->pNext;
	}
}
void PrintHashtable(LINKEDLIST hashtable[]) {
	for (int b = 0; b < 100; b++) {
		cout << "\nBucket thu " << b << ": ";
		TraverseBucket(b);
	}
}
int main()
{
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
				Key newKey;
				cout << "\nNhap phan tu can them";
				cout << "\nNhap nghia tieng Anh: ";
				cin.ignore();
				getline(cin, newKey.EnglishMeaning);
				cout << "\nNhap nghia tieng Viet: ";
				getline(cin, newKey.VietnameseMeaning);
				AddItem(hashtable, newKey.EnglishMeaning, newKey.VietnameseMeaning);
				break;
			}
			case 2: {
				string EnglishMeaning;
				cout << "\nNhap phan tu can xoa";
				cin.ignore();
				getline(cin, EnglishMeaning);
				RemoveItem(hashtable, EnglishMeaning);
				break;
			}
			case 3: {
				string EnglishMeaning;
				cout << "\nNhap tu tieng Anh can tim nghia tieng Viet: ";
				cin.ignore();
				getline(cin, EnglishMeaning);
				int pos = HashFunction(EnglishMeaning);
				string VietnameseMeaning = SearchNode(hashtable[pos], EnglishMeaning);
				if (VietnameseMeaning == "None")
					cout << "\nKhong tim nghia tieng Viet cua tu " << EnglishMeaning;
				else
					cout << "\nTim thay nghia tieng Viet cua tu " << EnglishMeaning << " la " << VietnameseMeaning;
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
