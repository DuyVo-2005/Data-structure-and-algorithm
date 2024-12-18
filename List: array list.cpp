#include <iostream>
using namespace std;
#define ElementType int
#define maxLen 100
struct LIST {
    ElementType m[maxLen];
    int len;
};
void InitList(LIST &l) {
    l.len = 0;
}
bool IsEmpty(LIST l) {
    if (l.len == 0) 
        return true;
    return false;
}
bool IsFull(LIST l) {
    if (l.len == maxLen)
        return true;
    return false;
}
void AddFirst(LIST& l, ElementType x) {
    if (IsEmpty(l)) {
        l.m[0] = x;
        l.len++;
    }   
    else
        if (IsFull(l))
            cout << "List day! Khong the them phan tu!";
        else {
            for (int i = l.len - 1; i >= 1; i--) {
                l.m[i + 1] = l.m[i];
            }
            l.m[0] = x;
            l.len++;
        }
}
void AddLast(LIST& l, ElementType x) {
    if (IsEmpty(l)) {
        l.m[0] = x;
        l.len++;
    }
    else
        if(IsFull(l))
            cout << "List day! Khong the them phan tu!";
        else {
            l.len++;
            l.m[l.len - 1] = x;
        }
}
void RemoveFirst(LIST &l) {
    if (IsEmpty(l))
        cout << "List rong khong huy phan tu duoc";
    else {
        for (int i = 0; i < l.len - 1; i++)
            l.m[i] = l.m[i + 1];
        l.len--;
    }
}
void RemoveLast(LIST& l) {
    if (IsEmpty(l)) {
        cout<<"List rong khong huy phan tu duoc";
    }
    else{
        l.len--;
    }
}
ElementType SearchNode(LIST l, ElementType x) {
    for (int i = 0; i < l.len; i++)
        if (l.m[i] == x)
            return i;
    return -1;
}
void PrintList(LIST l) {
    cout << "Do dai List: " << l.len << "\n";
    cout << "Cac phan tu List: ";
    for (int i = 0; i < l.len -1; i++) {
        cout << l.m[i] << " ";
    }
}
bool IsSmaller(ElementType a, ElementType b) {
    if (a < b) return true;
    return false;
}
void QuickSort(ElementType a[], int len, int left, int right) {
    int i = left, j = right, x=a[(left+right)/2];
    while (left<=right) {
        while (IsSmaller(a[i], x)) i++;
        while (IsSmaller(x, a[j])) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (i < right) {
        QuickSort(a, len, i, right);
    }
    if (left < j) {
        QuickSort(a, len, left, j);
    }
}
void DoSort(LIST& l) {
    QuickSort(l.m, l.len, 0, l.len - 1);
}
int main()
{ 
    LIST l;
    InitList(l);
    int choice = -1;
    while (true)
    {
        cout << "1. Kiem tra rong";
        cout << "\n2. Kiem tra day";
        cin >> choice;
    }
    return 0;
}
