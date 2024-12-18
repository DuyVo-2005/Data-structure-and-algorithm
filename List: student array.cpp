#include <iostream>
#include<string>
using namespace std;
#define maxLen 100
struct STUDENT {
    string name;
    string id;
    float gpa;
};
#define ElementType STUDENT
struct LIST {
    ElementType m[maxLen];
    int len;
};
void InitList(LIST& l);
bool IsEmpty(LIST l);
bool IsFull(LIST l);
void AddFirst(LIST& l, ElementType x);
void AddLast(LIST& l, ElementType x);
void RemoveFirst(LIST& l);
void RemoveLast(LIST& l);
void RemoveStudentHaveGPAMoreThanOrEqual(LIST& l, float x);
int SearchNode(LIST l, ElementType x);
void SearchKStudentHaveTheMostGPA(LIST& l, int k);
int BinarySearchNode(LIST l, ElementType x, int left, int right);
bool IsSmaller(ElementType a, ElementType b);
void QuickSort(ElementType a[], int len, int left, int right);
void DoSort(LIST& l);
void TakeElementsHaveGPAMoreThanOrEqual(LIST l,float x);
void PrintStudent(ElementType a);
void PrintList(LIST l);
void EnterStudent(ElementType& a);
void InsertValueNotChangeOrder(LIST& l, ElementType x);

int main()
{
    LIST l;
    InitList(l);
    ElementType x,y,z,t;
    EnterStudent(y);
    EnterStudent(z);
    EnterStudent(t);
    AddFirst(l, y);
    AddFirst(l, z);
    AddLast(l, t);
    /*EnterStudent(x);
    InsertValueNotChangeOrder(l, x);
    PrintList(l);*/
    /*cout << "\nDanh sach sinh vien co diem trung binh >= x: " << "\n";
    TakeElementsHaveGPAMoreThanOrEqual(l, 5);*/

    /*cout << "\nList sau khi xoa phan tu >=x: " << "\n";
    RemoveStudentHaveGPAMoreThanOrEqual(l, 5);
    PrintList(l);*/
    cout << "\nDanh sach k sinh vien diem cao nhat: " << "\n";
    SearchKStudentHaveTheMostGPA(l, 2);
    return 0;
}
void EnterStudent(ElementType& a) {
    cout << "\nNhap ma so sinh vien: ";
    getline(cin,a.id);
    cout << "Nhap ten sinh vien: ";
    getline(cin, a.name);
    cout << "Nhap diem trung binh: ";
    cin >> a.gpa;
    cin.ignore();
}
void InsertValueNotChangeOrder(LIST& l, ElementType x) {
    AddLast(l, x);
    QuickSort(l.m, l.len, 0, l.len-1);
}
void InitList(LIST& l) {
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
            for (int i = l.len - 1; i >= 0; i--) {
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
        if (IsFull(l))
            cout << "List day! Khong the them phan tu!";
        else {
            l.len++;
            l.m[l.len - 1] = x;
        }
}
void RemoveFirst(LIST& l) {
    if (IsEmpty(l))
        cout << "List rong khong huy phan tu duoc";
    else {
        for (int i = 0; i < l.len - 1; i++)
            l.m[i] = l.m[i + 1];
        l.len--;
    }
}
void RemoveLast(LIST& l) {
    if (IsEmpty(l))
        cout << "List rong khong huy phan tu duoc";
    else
        l.len--;
}
void RemoveStudentHaveGPAMoreThanOrEqual(LIST& l, float x) {
    QuickSort(l.m, l.len, 0, l.len - 1);
    for (int i = l.len - 1; l.m[i].gpa >= x; i--)
        RemoveLast(l);//do list co thu tu
}
int SearchGPA(LIST l, ElementType x) {
    for (int i = 0; i < l.len; i++)
        if (l.m[i].gpa == x.gpa)
            return i;
    return -1;
}
void SearchKStudentHaveTheMostGPA(LIST& l, int k) {
    if (IsEmpty(l))
        cout << "\nKhong co do list rong!";
    else {
        QuickSort(l.m, l.len, 0, l.len - 1);
        int i = l.len - 1;
        while (k--) {
            cout << "\n";
            PrintStudent(l.m[i]);
            cout << "\n";
            i--;
        }
    }
}
int BinarySearchGPA(LIST l, ElementType x, int left, int right) {
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (l.m[mid].gpa > x.gpa)
            right = mid - 1;
        else
            if (l.m[mid].gpa < x.gpa)
                left = mid + 1;
            else
                return mid;
    }
    return -1;// khong co
}
void PrintList(LIST l) {
    cout << "Do dai List: " << l.len << "\n";
    if (!IsEmpty(l)) {
        cout << "Cac phan tu List: "<<"\n";
        for (int i = 0; i < l.len; i++) {
            PrintStudent(l.m[i]);
            cout<< " ";
        }
    }
    else
        cout << "List rong!";
}
void PrintStudent(ElementType a) {
    cout << a.id << " " << a.name << " " << a.gpa;
    cout << "\n";
}
void TakeElementsHaveGPAMoreThanOrEqual(LIST l, float x) {
    if (IsEmpty(l))
        cout << "Khong co phan tu >= x";
    else {
        bool flag = false;//gia su khong co
        for (int i = 0; i < l.len; i++) {
            if (l.m[i].gpa >= x) {
                PrintStudent(l.m[i]);
                cout<< "\n";
                flag = true;
            }
        }
        if (flag == false)
            cout << "Khong co phan tu >= x";
        cout << "\n";
    }
}
bool IsSmaller(ElementType a, ElementType b) {
    if (a.gpa < b.gpa)
        return true;
    return false;
}
void QuickSort(ElementType a[], int len, int left, int right) {
    int i = left, j = right;
    ElementType x = a[(left + right) / 2];
    while (i <= j) {
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
