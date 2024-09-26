#include<iostream>
#include<string>
using namespace std;
struct BOOK{
	string name;
	string author;
	string pulisher;
	int pulishedYear;
};
struct NODE{
	BOOK info;
	struct NODE *pNext;
};
struct LIST{
	NODE *pHead;
	NODE *pTail;
};
void addLast(LIST &l,  BOOK x);
LIST bookIsPulishedByPulisherXInYear(LIST l, string pulisherName, int pulishedYear);
NODE *createNode(BOOK x);
void enterElement(BOOK &x);
void enterList(LIST &l, int &n);
void initList(LIST &l);
bool isEmptyList(LIST l);
void printElement(BOOK x);
void printList(LIST l);
int theNumberOfAuthorXBook(LIST l, string authorName);
int main(int argc, char *argv[])
{
	LIST l;
	initList(l);
	int n;
	enterList(l,n);
	
	cout<<"\n---------------";
	string tmpName;
	cin.ignore();
	cout<<"\nNhap ten tac gia: ";
	getline(cin,tmpName);
	cout<<"\nSo luong sach cua tac gia "<<tmpName<<" :"<<theNumberOfAuthorXBook(l,tmpName);
	
	cout<<"\n---------------";
	int tmpYear;
	cout<<"\nNhap nam hop le: ";
	cin>>tmpYear;
	string pulisherName;
	cout<<"Nhap ten 1 nha xuat ban: ";
	cin.ignore();
	getline(cin,pulisherName);
	cout<<"Trong nam "<<tmpYear<<", nha xuat ban "<<pulisherName<<" da phat hanh nhung quyen sach :"<<"\n";

	LIST l2=bookIsPulishedByPulisherXInYear(l,pulisherName,tmpYear);
	if(!isEmptyList(l2))
		printList(l2);
	else
		cout<<"Khong co";
	return 0;
}
/*
input mau:
4
C++
Van A, Thi B
Pro Pulisher
2020
Python
Khanh D
AB Pulisher
2022
C#
Dinh C, Thi B
AB Pulisher
2022
Java Programming
Van A, Khanh D
Pro Pulisher
2018
*/
void addLast(LIST &l, BOOK x){
	NODE *p=createNode(x);
	if(isEmptyList(l)){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
LIST bookIsPulishedByPulisherXInYear(LIST l, string pulisherName, int pulishedYear);
NODE *createNode(BOOK x){
	NODE *p=new NODE;
	if(p==NULL)	exit(1);// ko tao duoc
	p->info=x;
	p->pNext=NULL;
	return p;
}
void enterList(LIST &l, int &n){
	BOOK tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		enterElement(tmp);
		addLast(l,tmp);
	}
}
void enterElement(BOOK &x){
	//moi thuoc tinh viet tren 1 dong
	cin.ignore();
	getline(cin,x.name);
	getline(cin,x.author);//neu nhieu tac gia thi moi tac gia cach nhau boi dau phay
	getline(cin,x.pulisher);
	cin>>x.pulishedYear;
}
void initList(LIST &l){
	l.pHead=l.pTail=NULL;
}
bool isEmptyList(LIST l){
	if(l.pHead==NULL)
		return true;
	return false;
}
void printElement(BOOK x){
	cout<<"\n"<<x.name<<"\n"<<x.author<<"\n"<<x.pulisher<<"\n"<<x.pulishedYear;
}
void printList(LIST l){
	for(NODE *p=l.pHead;p!=NULL;p=p->pNext)
		printElement(p->info);
}
int theNumberOfAuthorXBook(LIST l, string authorName){
	int count=0;
	for(NODE *p=l.pHead;p!=NULL;p=p->pNext){
		size_t found= p->info.author.find(authorName);//tra ve so nguyen khong dau_thuong dung trong sizeof
		if(found!=std::string::npos)
			count++;
	}
	return count;
}
LIST bookIsPulishedByPulisherXInYear(LIST l, string pulisherName, int pulishedYear){
	LIST res;
	initList(res);
	for(NODE *p=l.pHead;p!=NULL;p=p->pNext)
		if(p->info.pulishedYear==pulishedYear&&p->info.pulisher==pulisherName){
			addLast(res,p->info);
		}
	return res;
}
