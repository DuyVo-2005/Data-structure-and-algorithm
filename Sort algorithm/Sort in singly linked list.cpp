#include<iostream>
using namespace std;
#define data int
struct NODE {
	data info;
	struct NODE* next;
};
struct LIST {
	NODE* head;
	NODE* tail;
};
void initList(LIST& l) {
	l.head = l.tail = NULL;
}
NODE* createNode(data x) {
	NODE* p = new NODE;
	if (p == NULL) exit(1);
	p->info = x;
	p->next = NULL;
	return p;
}
bool isEmpty(LIST l) {
	if (l.head == NULL) return true;
	return false;
}
void addFirst(LIST& l, NODE* p) {
	if (isEmpty(l)) {
		l.head = p;
		l.tail = l.head;
	}
	else {
		p->next = l.head;//->
		l.head = p;
	}
}
void addLast(LIST& l, NODE* p) {
	if (isEmpty(l))
		addFirst(l, p);
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
void addPAfterQ(LIST& l, NODE* q, NODE* p) {
	if (q == NULL)
		addLast(l, p);
	else {
		p->next = q->next;//
		q->next = p;//
		if (q == l.tail) {
			l.tail = p;
		}
	}
}
void InterchangeSort(LIST& l) {
	// 5 4 3 2 1
	for (NODE* p = l.head; p->next!= NULL; p = p->next) {
		for(NODE *q=p->next;q!=NULL;q=q->next)
			if (p->info > q->info) {
				//swap(p, q);//false because don't have the data
				int temp = p->info;
                p->info = q->info;
                q->info = temp;
			}
	}
}
void Swap(NODE*& p1, NODE*& p2) {
	NODE* tmp = p1;
	p1 = p2;
	p2 = tmp;
}
void QuickSort(LIST& l) {
	if (l.head == l.tail) return;//mang 0-1 phan tu->da co thu tu
	LIST l1, l2;
	initList(l1);
	initList(l2);
	NODE* key = l.head;
	NODE* p = l.head->next;
	while (p != NULL) {
		NODE* q = p;
		p = p->next;
		q->next = NULL;//co lap q
		if (key->info > q->info)
			addFirst(l1, q);
		else
			addFirst(l2, q);

	}
	QuickSort(l1);
	QuickSort(l2);
	if (!isEmpty(l1)) {
		l.head = l1.head;
		l1.tail->next = key;
	}
	else
		l.head = key;//
	key->next = l2.head;//
	if (!isEmpty(l2)) {
		l.tail = l2.tail;
	}
	else
		l.tail = key;
}
void removeFirst(LIST& l) {
	NODE* p;
	if (isEmpty(l))	exit(0);
	p = l.head;
	l.head = l.head->next;
	delete p;
	if (l.head == NULL)
		l.tail = NULL;
}//
void removeAfterQ(LIST& l, NODE* q) {
	if (q == NULL)	exit(1);
	else {
		NODE* p = q->next;
		if (p != NULL) {
			q->next = p->next;
			if (p == l.tail)
				l.tail = q;
			delete p;
		}
	}
}
void removeKeyX(LIST& l, data x) {
	// 1 2 3
	NODE* p = l.head;//vi tri can xoa
	NODE* q = NULL;
	while (p != NULL && p->info != x) {
		q = p;//q truoc p
		p = p->next;
	}
	if (p == NULL)
		exit(1);
	else {
		if (q == NULL)//p la head
			l.head = p->next;
		else
			q->next = p->next;
		delete p;
	}
}
void printList(LIST l) {
	for (NODE* p = l.head; p != NULL; p = p->next)
		cout << p->info << "\n";
}
void RemoveList(LIST& l) {
	NODE* p;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
int main(int argc, char* argv[])
{
	LIST l;
	initList(l);
	NODE* a = createNode(1);
	addFirst(l, a);
	addLast(l, createNode(3));
	addPAfterQ(l, a, createNode(2));
	//removeFirst(l);
	//removeAfterQ(l,a);
	//removeKeyX(l,6);
	/*RemoveList(l);
	cout<<l.head;*/
	addLast(l, createNode(5));
	addFirst(l, createNode(4));
	printList(l);
	cout << "\n";
	//InterchangeSort(l);
	QuickSort(l);
	printList(l);
	//cout<<a->info<<" "<<a->next;
	return 0;
}
