#include<iostream>
using namespace std;
#define data int
struct NODE{
	data info;
	struct NODE *pPre;
	struct NODE *pNext;
};
struct LIST{
	NODE *pHead;
	NODE *pTail;
};
void initList(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
bool isEmpty(LIST l){
	if(l.pHead==NULL)//
		return true;
	return false;
}
NODE *createNode(data x){
	NODE *p= new NODE;
	if(p==NULL){
		cout<<"\nKhong du bo nho!";	
		exit(0);
	}
	p->info=x;
	p->pNext=p->pPre=NULL;
	return p;
}
void addFirst(LIST &l, NODE *p){
	if(isEmpty(l)){
		l.pHead=l.pTail=p;
	}
	else{
		p->pNext=l.pHead;
		l.pHead->pPre=p;//
		l.pHead=p;
	}
}
void addLast(LIST &l, NODE *p){
	if(isEmpty(l)){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		p->pPre=l.pTail;
		l.pTail=p;
	}
}
void addPAfterQ(LIST &l, NODE *p, NODE *q){
	if(q==NULL)
		addLast(l,p);
	else{
		if(q->pNext!=NULL)//
			p->pNext=q->pNext;//
		q->pNext=p;
		p->pPre=q;
		if(q==l.pTail)
			l.pTail==p;
	}
}
/*void addPBeforeQ(LIST &l, NODE *p, NODE *q){
	if(isEmpty(l))
		addFirst(l,p);
	else{
		if(q!=NULL){//co q
			NODE *tmp=q->pPre;
			if(tmp!=NULL){// co node truoc q
				p->pPre=tmp;
				p->pNext=q;
				q->pPre=p;
			}
			else{
				p->pPre=NULL;	
				p->pNext=q;
				l.pHead=p;	
			}
		}
		else
			addFirst(l,p);
	}//ver 1
}*/

void addPBeforeQ(LIST &l, NODE *p, NODE *q){
	NODE *tmp=q->pPre;//
	if(q!=NULL){
		p->pNext=q;
		q->pPre=p;
		p->pPre=tmp;
		if(tmp!=NULL)
			tmp->pNext=p;
		else//q la head
			l.pHead=p;
	}
}
void interchangeSort(LIST& l) {
	NODE* p = l.pHead, *q=NULL;
	while (p != l.pTail) {
		q=p->pNext;
		while (q != NULL) {
			if (p->info > q->info)
				swap(p, q);
			q = q->pNext;
		}
		p = p->pNext;
	}
}
void removeFirst(LIST &l){
	if(isEmpty(l)||(l.pHead==l.pTail)){// mang co 0 hoac 1 phan tu
		l.pHead=l.pTail=NULL;
	}
	else{
		NODE*tmp=l.pHead, *tmp2=tmp->pNext;
		tmp2->pPre=NULL;
		tmp->pNext=NULL;
		l.pHead=tmp2;
		delete tmp;
	}
}
void printList(LIST l){
	for(NODE *p=l.pHead;p!=NULL;p=p->pNext)
		cout<<p->info<<"\n";
}
int main(int argc, char *argv[])
{
	LIST l;
	initList(l);
	NODE *a=createNode(1),*b = createNode(2);
	addFirst(l,a);
	addFirst(l,b);
	addLast(l,createNode(3));
	addPAfterQ(l,createNode(4),b);
	addPBeforeQ(l,createNode(5),a);
	interchangeSort(l);
	//removeFirst(l);
	printList(l);
	return 0;
}
// 2 4 1 3
