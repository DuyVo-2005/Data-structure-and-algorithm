#include <iostream>
#include <string>
using namespace std;
//#define ElementType int
struct STUDENT {
    string id;
    string name;
    float gpa;
};
#define ElementType STUDENT
struct DNode {
    ElementType info;
    struct DNode* pNext;
    struct DNode* pPre;
};
struct DLIST {
    DNode* pHead;
    DNode* pTail;
};
void InitList(DLIST& l);
DNode* CreateNode(ElementType x);
int IsEmptyList(DLIST l);
void AddFirst(DLIST& l, ElementType x);
void AddLast(DLIST& l, ElementType x);
void RemoveFirst(DLIST& l);
void RemoveLast(DLIST& l);
ElementType SearchNode(DLIST  l, DNode *p);
bool SearchNode(DLIST  l, string x);
void PrintElement(int x);
void PrintElement(STUDENT x);
void PrintList(DLIST l);
void EnterElement(int& x);
void EnterStudentList(DLIST& l);
bool FindStudent(DLIST l,string name);
void RemoveNodeX(DLIST& l, DNode* x);
void removeAfterX(DLIST& l, DNode* x);
void RemoveStudentHaveIDX(DLIST& l, string idX);
DLIST StudentHaveGPAGreaterOrEqualThan(DLIST l, float gpa);
string Evaluate(STUDENT x) {
    if (x.gpa <= 4.9)
        return "Loai yeu";
    if (x.gpa >= 5 && x.gpa < 6.5)
        return "Loai trung binh";
    if (x.gpa >= 6.5 && x.gpa < 7)
        return "Loai trung binh kha";
    if (x.gpa >= 7 && x.gpa < 8)
        return "Loai kha";
    if (x.gpa >= 8 && x.gpa < 9)
        return "Loai gioi";
    return "Loai xuat sac";
}
void EvaluateAndPrint(DLIST l) {
    for (DNode* p = l.pHead; p != NULL; p = p->pNext) {
        PrintElement(p->info);
        cout << " " << Evaluate(p->info) << "\n";
    }
}
bool IsGreater(STUDENT a, STUDENT b) {
    if (a.gpa > b.gpa)
        return true;
    return false;
}
void QuickSort(DLIST &l) {
    if (l.pHead == l.pTail)
        return;
    DLIST l1, l2;
    InitList(l1);
    InitList(l2);
    DNode* key = l.pHead;
    DNode* p = l.pHead->pNext;
    while (p != NULL) {
        if (IsGreater(p->info, key->info))
            AddLast(l2, p->info);
        else
            AddLast(l1, p->info);
        p = p->pNext;
    }
    QuickSort(l1);
    QuickSort(l2);
    if (!IsEmptyList(l1)) {
        l.pHead = l1.pHead;
        l1.pTail->pNext = key;
        key->pPre = l1.pTail;
    }
    else
        l.pHead = key;
    if (!IsEmptyList(l2)) {
        l.pTail = l2.pTail;
        key->pNext = l2.pHead;
        l2.pHead->pPre = key;
    }
    else
        l.pTail = key;
}
void EnterElement(STUDENT& x) {
    cin.ignore();
    getline(cin, x.name);
    getline(cin, x.id);
    cin >> x.gpa;
}
// p q
void insertNotChangeOrder(DLIST &l, STUDENT z) {
    QuickSort(l);
    DNode *p=l.pHead;
    while (z.gpa > p->info.gpa&&p!=NULL) {
        p = p->pNext;
    }
    DNode* q = CreateNode(z);
    if (p == l.pHead)
        AddFirst(l, z);
    else {
        if (p == NULL)
            AddLast(l, z);
        else {
            q->pNext = p->pNext;
            q->pPre = p;
        }
    }
}
int main()
{
    DLIST l;
    InitList(l);
    //DNode* a = CreateNode(96);
    //cout << a->info << " " << a->pNext << " " << a->pNext;
    /*AddFirst(l, 8);
    AddFirst(l, 9);*/
    /*AddLast(l, 5);
    AddLast(l, 7);*/
    //RemoveFirst(l);
    //RemoveLast(l);
    //cout << l.pHead->info << " " << l.pHead->pPre << " " << l.pHead->pNext;
    //cout << l.pTail->info << " " << l.pTail->pPre << " " << l.pTail->pNext;
    EnterStudentList(l);
    //PrintList(l);
    /*string tmp;
    cout << "\nNhap ten sv can tim: ";
    getline(cin, tmp);
    if (FindStudent(l, tmp))
        cout << "\nTim thay!";
    else
        cout << "\nKhong tim thay!";*/
    /*string idTmp;
    cout << "\nNhap ma so sinh vien can xoa: ";
    getline(cin, idTmp);
    RemoveStudentHaveIDX(l, idTmp);
    PrintList(l);*/
    /*DLIST l2 = StudentHaveGPAGreaterOrEqualThan(l, 5);
    PrintList(l2);*/
    //EvaluateAndPrint(l);
    QuickSort(l);
    cout << "\nDanh sach tang dan diem trung binh: " << "\n";
    PrintList(l);
    /*cout << "\nNhap sinh vien can chen: ";
    STUDENT z;
    EnterElement(z);
    insertNotChangeOrder(l, z);
    PrintList(l);*/
    return 0;
}
/*
Khanh Duy
23
9.1
Van E
26
8.9
Thi A
86
9.0
Thi K
98
4.0
Van E
110
2.1
*/
/*
Le z
55
5.6

*/
void InitList(DLIST& l) {
    l.pHead = l.pTail = NULL;
}

DNode* CreateNode(ElementType x) {
    DNode* p = new DNode;
    if (p == NULL) {
        cout << "\nKhong cap phan node moi duoc";
        exit(1);
    }
    p->info = x;
    p->pNext = p->pPre = NULL;
    return p;
}
int IsEmptyList(DLIST l) {
    if (l.pHead == NULL)
        return 1;//dung
    return false;//sai
}
void AddFirst(DLIST& l, ElementType x) {
    DNode* p = CreateNode(x);
    if (IsEmptyList(l) == 1) {
        l.pHead = p;
        l.pTail = p;
    }
    else {
        l.pHead->pPre = p;
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddLast(DLIST& l, ElementType x) {
    if (IsEmptyList(l) == 1)
        AddFirst(l, x);
    else {
        DNode* p = CreateNode(x);
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}
void RemoveFirst(DLIST& l) {
    if (IsEmptyList(l))
        cout << "\nDanh sach rong! Khong huy duoc";
    else {
        if (l.pHead == l.pTail)//1 phan tu
            l.pHead = l.pTail = NULL;
        else {//2 phan tu tro len
            DNode* p = l.pHead->pNext;
            p->pPre = NULL;
            l.pHead->pNext = NULL;
            delete l.pHead;
            l.pHead = p;
        }
    }
}
void RemoveLast(DLIST& l) {
    if (IsEmptyList(l))
        cout << "\nDanh sach rong! Khong huy duoc";
    else {
        if (l.pHead == l.pTail)
            l.pHead = l.pTail = NULL;
        else {
            DNode* p = l.pTail->pPre;
            p->pNext = NULL;
            l.pTail->pPre = NULL;
            delete l.pTail;
            l.pTail = p;
        }
    }
}
ElementType SearchNode(DLIST  l, DNode* p) {
    //tra ve info phan tu dau tien bang p
    for (DNode* q = l.pHead; q != NULL; q = q->pNext)
        if (q == p)
            return q->info;
    cout << "Khong tim thay!";
}
bool SearchNode(DLIST  l, string x) {
    for (DNode* q = l.pHead; q != NULL; q = q->pNext)
        if (q->info.name == x)
            return true;
    return false;
}
void PrintList(DLIST l) {
    for (DNode* p = l.pHead; p != NULL; p = p->pNext)
        PrintElement(p->info);
    cout << "\n";
}
void EnterElement(int& x) {
    cin >> x;
}
void EnterStudentList(DLIST& l) {
    STUDENT tmp;
    string tmpString = ".";
    while (tmpString != "") {
        getline(cin, tmpString);
        if (tmpString != "") {
            tmp.name = tmpString;
            getline(cin, tmp.id);
            cin >> tmp.gpa;
            cin.ignore();
            AddFirst(l, tmp);
        }
        else
            break;
    }
}
bool FindStudent(DLIST l, string name) {
    if (SearchNode(l, name))
        return true;
    return false;
}
void removeAfterX(DLIST& l, DNode *x) {
    if (x == NULL)
        return;
    DNode* p=x->pNext;//nut can xoa
    if (p != NULL) {
        x->pNext = p->pNext;
        if (p == l.pTail)
            l.pTail = x;
        else {
            p->pNext->pPre = x;
        }
        delete p;
    }
}
void RemoveNodeX(DLIST& l, DNode* x) {
    if (l.pHead == x)
        RemoveFirst(l);
    else {
        if (l.pTail == x)
            RemoveLast(l);
        else {
            DNode* q = NULL, *r=NULL;// q la nut truoc nut can xoa, r la nut sau nut can xoa
            for (DNode* p = l.pHead->pNext; p != l.pTail;) {// p la nut can xoa
                q = p->pPre;
                r = p->pNext;
                //p = p->pNext;
                if (p == x) {
                    q->pNext = p->pNext;
                    r->pPre = p->pPre;
                    p->pPre = p->pNext = NULL;
                    delete p;
                    p = q->pNext;// do p la bien chay
                }
                else
                    p = p->pNext;
            }
        }
    }
}
void RemoveStudentHaveIDX(DLIST& l, string idX) {
    if (l.pHead->info.id == idX)
        RemoveFirst(l);
    else {
        if (l.pTail->info.id == idX)
            RemoveLast(l);
        else {
            for (DNode* p = l.pHead->pNext; p != l.pTail; )
                if (p->info.id == idX) {
                    p->pPre->pNext = p->pNext;
                    p->pNext->pPre = p->pPre;
                    p->pNext = p->pPre = NULL;
                    delete p;
                    break;
                }
                else
                    p = p->pNext;
        }
    }
}
DLIST StudentHaveGPAGreaterOrEqualThan(DLIST l, float gpa) {
    DLIST res;
    InitList(res);
    for (DNode* p = l.pHead; p != NULL; p = p->pNext)
        if (p->info.gpa >= gpa)
            AddLast(res, p->info);
    return res;
}

void PrintElement(int x) {
    cout << x << "\n";
}

void PrintElement(STUDENT x) {
    cout << x.id << " " << x.name << " " << x.gpa << "\n";
}
