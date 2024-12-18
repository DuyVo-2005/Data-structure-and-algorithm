#include <iostream>
using namespace std;
#define ElementType int
#define maxLen 100
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
ElementType SearchNode(LIST l, ElementType x);
ElementType BinarySearchNode(LIST l, ElementType x, int left, int right);
bool IsSmaller(ElementType a, ElementType b);
void QuickSort(ElementType a[], int len, int left, int right);
void DoSort(LIST& l);
void PrintList(LIST l);
void TakeElementsHaveValueMoreThanOrEqual(LIST l, ElementType x);
void RemoveElementsHaveValueMoreThanOrEqual(LIST& l, ElementType x);
void TakeMaxElementOfList(LIST& l, LIST& subL);
int countNegativeElementOfList(LIST l);
ElementType maxNegativeElementOfList(LIST l);
ElementType minPositiveElementOfList(LIST l);
int countElementsEqualX(LIST l, ElementType x);
int main()
{
    LIST l;
    InitList(l);
    //cout << l.len;
    int x;
    /*cout << "\nNhap phan tu can them vao dau: ";
    cin >> x;
    AddFirst(l, x);
    PrintList(l);

    cout << "\nNhap phan tu can them vao cuoi: ";
    cin >> x;
    AddLast(l, x);
    PrintList(l);*/

    /*cout << "\nList sau khi xoa phan tu dau: " << "\n";
    RemoveFirst(l);
    PrintList(l);*/

    /*cout << "\n";
    RemoveLast(l);
    PrintList(l);*/

    //cout << "\n" << SearchNode(l, 9);
    //cout <<"\n"<< BinarySearchNode(l, 9, 0, l.len - 1);

    /*cout << "\n";
    DoSort(l);
    PrintList(l);*/

    AddFirst(l, 1);
    AddFirst(l, 2);
    AddLast(l, 6);
    AddFirst(l, 5);
    AddLast(l, 6);
    AddFirst(l, 1);
    cout << "\n";
    PrintList(l);
    //TakeElementsHaveValueMoreThanOrEqual(l, 10);
    //RemoveElementsHaveValueMoreThanOrEqual(l, 10);
    //cout<<countNegativeElementOfList(l);

    /*int ans=maxNegativeElementOfList(l);
    if (ans==0)
        cout<<"Khong co phan tu am lon nhat";
    else
        cout<<ans;*/
        /*int res=minPositiveElementOfList(l);
        if(res==0)
            cout<<"Khong co phan tu duong be nhat";
        else
            cout<<res;*/
            /*int res=countElementsEqualX(l,21);
            if(res==0)
                cout<<"Khong co gia tri bang x";
            else
                cout<<res;*/
                //RemoveElementsHaveValueMoreThanOrEqual(l, 2);

           /*LIST subL;
           InitList(subL);
           TakeMaxElementOfList(l, subL);
           PrintList(subL);*/
    return 0;
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
ElementType SearchNode(LIST l, ElementType x) {
    for (int i = 0; i < l.len; i++)
        if (l.m[i] == x)
            return i;
    return -1;
}
ElementType BinarySearchNode(LIST l, ElementType x, int left, int right) {
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (l.m[mid] > x)
            right = mid - 1;
        else
            if (l.m[mid] < x)
                left = mid + 1;
            else
                return mid;
    }
    return -1;// khong co
}
void PrintList(LIST l) {
    cout << "Do dai List: " << l.len << "\n";
    if (l.len != 0) {
        cout << "Cac phan tu List: ";
        for (int i = 0; i < l.len; i++) {
            cout << l.m[i] << " ";
        }
    }
    else
        cout << "List rong!";
}bool IsSmaller(ElementType a, ElementType b) {
    if (a < b)
        return true;
    return false;
}
void QuickSort(ElementType a[], int len, int left, int right) {
    int i = left, j = right, x = a[(left + right) / 2];
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
void TakeElementsHaveValueMoreThanOrEqual(LIST l, ElementType x) {
    if (IsEmpty(l))
        cout << "Khong co phan tu >= x";
    else {
        bool flag = false;//gia su khong co
        for (int i = 0; i < l.len; i++) {
            if (l.m[i] >= x) {
                cout << l.m[i] << " ";
                flag = true;
            }
        }
        if (flag == false)
            cout << "Khong co phan tu >= x";
        cout << "\n";
    }
}
void RemoveElementsHaveValueMoreThanOrEqual(LIST& l, ElementType x) {
    QuickSort(l.m, l.len, 0, l.len - 1);
    for (int i = l.len - 1; l.m[i] >= x; i--)
        RemoveLast(l);//do list co thu tu
    cout << "\nList sau khi xoa phan tu >=x: " << "\n";
    PrintList(l);
}
void TakeMaxElementOfList(LIST& l, LIST& subL) {
    if (IsEmpty(l))
        exit(0);
    QuickSort(l.m, l.len, 0, l.len - 1);
    ElementType max = l.m[l.len - 1];
    for (int i = l.len - 1; l.m[i] == max; i--)
        AddFirst(subL, max);
}
int countNegativeElementOfList(LIST l) {
    int count = 0;
    QuickSort(l.m, l.len, 0, l.len - 1);
    for (int i = 0; l.m[i] < 0; i++)
        count++;
    return count;
}
ElementType maxNegativeElementOfList(LIST l) {
    if (IsEmpty(l))
        return 0;//khong co
    int i = 0;
    QuickSort(l.m, l.len, 0, l.len - 1);
    while (l.m[i] < 0) i++;
    if (i == 0)
        return 0;
    return l.m[i - 1];
}
ElementType minPositiveElementOfList(LIST l) {
    if (IsEmpty(l))
        return 0;//khong co
    int i = l.len - 1;
    QuickSort(l.m, l.len, 0, l.len - 1);
    while (l.m[i] > 0) i--;
    if (i == l.len - 1)
        return 0;
    return l.m[i + 1];
}
int countElementsEqualX(LIST l, ElementType x) {
    int count = 0;
    QuickSort(l.m, l.len, 0, l.len - 1);
    if (BinarySearchNode(l, x, 0, l.len - 1) != -1)//co x
        for (int i = 0; l.m[i] <= x; i++)
            if (l.m[i] == x)
                count++;
    return count;
}
