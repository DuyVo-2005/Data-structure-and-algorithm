// bai1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>//dung setw
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
#define ElementType string
#define LH -1 //cay con trai cao hon
#define EH 0//cay con trai bang cay con phai
#define RH 1 //cay con phai cao hon
#include<vector>
ifstream infile("D:\\input.txt");
ofstream outfile("D:\\23110196.txt", ios::trunc);//file da ton tai noi dung -> xoa noi dung cu
bool taller = false;//(gia su) true khi cay co tang truong chieu cao
bool shorter = false;//true khi cay giam chieu cao
typedef struct tagTNode
{
    int balFactor; //chỉ số cân bằng
    ElementType EnglishMeaning;
    tagTNode* pLeft, * pRight;
    string VietnameseMeaning;
} TNode;
TNode* CreateNode(ElementType EnglishMeaning, ElementType VietnameseMeaning) {
    TNode* p = new TNode;
    if (p == NULL) return NULL;
    p->EnglishMeaning = EnglishMeaning;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->balFactor = EH;
    p->VietnameseMeaning = VietnameseMeaning;
    return p;
}
int HighTree(TNode* root);
void InitTree(TNode*& root) {
    root = NULL;
}
int IsEmptyTree(TNode* root) {
    if (root == NULL) {
        return 1;
    }
    return 0;
}
void LL(TNode*& T) {
    TNode* T1 = T->pLeft;
    T->pLeft = T1->pRight;
    T1->pRight = T;
    switch (T1->balFactor)
    {
    case LH: {
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    }

    case EH: {
        T->balFactor = LH;
        T1->balFactor = RH;
        break;
    }
    }
    T = T1;
}
void RR(TNode*& T)
{
    TNode* T1 = T->pRight;
    T->pRight = T1->pLeft;
    T1->pLeft = T;
    switch (T1->balFactor)
    {
    case RH: {
        T->balFactor = EH;

        T1->balFactor = EH; break;
    }

    case EH: {
        T->balFactor = RH;

        T1->balFactor = LH; break;
    }
    }
    T = T1;
}
void LR(TNode*& T)
{
    TNode* T1 = T->pLeft;
    TNode* T2 = T1->pRight;
    T->pLeft = T2->pRight;
    T2->pRight = T;
    T1->pRight = T2->pLeft;
    T2->pLeft = T1;
    switch (T2->balFactor)
    {
    case LH: T->balFactor = RH;

        T1->balFactor = EH; break;

    case EH: T->balFactor = EH;

        T1->balFactor = EH; break;

    case RH: T->balFactor = EH;

        T1->balFactor = LH; break;

    }T2->balFactor = EH; T = T2;
    //RR(T->pLeft);//quay trai cay con trai
    //LL(T);//quay phai nut dang xet
}
void RL(TNode*& T)
{
    TNode* T1 = T->pRight;
    TNode* T2 = T1->pLeft;
    T->pRight = T2->pLeft;
    T2->pLeft = T;
    T1->pLeft = T2->pRight;
    T2->pRight = T1;
    switch (T2->balFactor)
    {
    case RH: T->balFactor = LH;

        T1->balFactor = EH; break;

    case EH: T->balFactor = EH;

        T1->balFactor = EH; break;

    case LH: T->balFactor = EH;

        T1->balFactor = RH; break;

    }
    T2->balFactor = EH; T = T2;
    /*LL(T->pRight);
    RR(T);*/
}
int HighTree(TNode* root)
{
    if (!root) return 0;
    int hl = HighTree(root->pLeft);
    int hr = HighTree(root->pRight);
    if (hl > hr)
        return (1 + hl);
    else
        return (1 + hr);
}

void InsertNode(TNode*& root, TNode* node, bool& taller) {
    if (node == NULL) {
        outfile << "\nNode truyen vao la NULL! Khong chen duoc!";
        return;
    }
    if (root == NULL) {
        root = node;
        taller = true; // cây tăng chiều cao
        return;
    }
    //if (root->EnglishMeaning == node->EnglishMeaning) return;
    if (node->EnglishMeaning < root->EnglishMeaning) {
        InsertNode(root->pLeft, node, taller);
        if (taller) {
            //UpdateRootAndChildren(root);
            if (root->balFactor == LH) { // Cây mất cân bằng trái
                if (root->pLeft->balFactor == LH) {// cây con trái cũng mất cân bằng trái
                    LL(root);
                }
                else {//cây con trái mất cân bằng phải
                    LR(root);
                }
                taller = false;//cây đã cân bằng sau khi quay
            }
            else if (root->balFactor == EH) {
                root->balFactor = LH;
                taller = true; // Chiều cao tăng
            }
            else { // root->balFactor == RH
                root->balFactor = EH;
                taller = false; // Cây cân bằng -> không tăng chiều cao
            }
        }
    }
    else {
        if (node->EnglishMeaning > root->EnglishMeaning) {
            InsertNode(root->pRight, node, taller);
            if (taller) {
                //UpdateRootAndChildren(root);
                if (root->balFactor == RH) { // Cây mất cân bằng phải
                    if (root->pRight->balFactor == RH) {// cây con phải cũng mất cân bằng phải
                        RR(root);
                    }
                    else {// cây con phải mất cân bằng trái
                        RL(root);
                    }
                    taller = false;
                }
                else if (root->balFactor == EH) {
                    root->balFactor = RH;
                    taller = true;
                }
                else { // root->balFactor == LH
                    root->balFactor = EH;
                    taller = false;
                }
            }
        }
        else {
            return;
        }
    }
}
void BalanceAfterDelete(TNode*& root, bool& shorter) {
    if (root->balFactor == LH) { // Trái cao hơn
        if (root->pLeft->balFactor == LH) { // LL Case
            LL(root);
            shorter = true;
        }
        else if (root->pLeft->balFactor == EH) { // Trái cân bằng trước, sau khi xóa sẽ cân bằng
            LL(root);
            root->balFactor = RH; // Điều chỉnh lại cân bằng
            root->pLeft->balFactor = LH;
            shorter = false;
        }
        else { // root->pLeft->balFactor == RH : LR Case
            LR(root);
            shorter = true;
        }
    }
    else if (root->balFactor == EH) { // Cây đã cân bằng, giảm chiều cao
        root->balFactor = RH;
        shorter = false;
    }
    else { // RH
        if (root->pRight->balFactor == RH) { // RR Case
            RR(root);
            shorter = true;
        }
        else if (root->pRight->balFactor == EH) { // Giống bên trên
            RR(root);
            root->balFactor = LH;
            root->pRight->balFactor = RH;
            shorter = false;
        }
        else { // RL
            RL(root);
            shorter = true;
        }
    }
}
void ThayThe(TNode*& p, TNode*& T) {
    if (T->pLeft != NULL)  ThayThe(p, T->pLeft);
    else
    {
        p->EnglishMeaning = T->EnglishMeaning;
        p = T;
        T = T->pRight;
    }
}
void DeleteNode(TNode*& root, ElementType EnglishMeaning, bool& shorter) {
    if (root == NULL) return;

    if (EnglishMeaning < root->EnglishMeaning) {
        DeleteNode(root->pLeft, EnglishMeaning, shorter);
        if (shorter) BalanceAfterDelete(root, shorter);
    }
    else if (EnglishMeaning > root->EnglishMeaning) {
        DeleteNode(root->pRight, EnglishMeaning, shorter);
        if (shorter) BalanceAfterDelete(root, shorter);
    }
    else { // Tìm thấy node cần xóa
        TNode* temp = root;
        if (root->pLeft == NULL) {
            root = root->pRight;
            shorter = true;
            //delete temp;
        }
        else if (root->pRight == NULL) {
            root = root->pLeft;
            shorter = true;
            //delete temp;
        }
        else { // node có 2 con 
            ThayThe(temp, root->pRight);//nut trai nhat ben phai
            //if (shorter)
            BalanceAfterDelete(root, shorter);
        }
        delete temp;
    }
}
TNode* SearchNode(TNode* root, ElementType x) {
    TNode* p = root;
    while (p != NULL)
    {
        if (x == p->EnglishMeaning) return p;
        else
            if (x < p->EnglishMeaning) p = p->pLeft;
            else p = p->pRight;
    }
    return NULL;
}

void PrintTree_PreOrder(TNode* root) {
    if (root != NULL) {
        outfile << "\n" << root->EnglishMeaning;
        PrintTree_PreOrder(root->pLeft);
        PrintTree_PreOrder(root->pRight);
    }
}
void PrintTree_InOrder(TNode* root) {
    if (root != NULL) {
        PrintTree_InOrder(root->pLeft);
        outfile << "\n" << root->EnglishMeaning;
        PrintTree_InOrder(root->pRight);
    }
}
void PrintTree_PostOrder(TNode* root) {
    if (root != NULL) {
        PrintTree_PostOrder(root->pLeft);
        PrintTree_PostOrder(root->pRight);
        outfile << "\n" << root->EnglishMeaning;
    }
}
void PrintTree(TNode* root, int space = 0, int height = 6)
{
    if (root == NULL)        return;

    space += height;

    PrintTree(root->pRight, space);

    outfile << endl;
    outfile << setw(space) << root->EnglishMeaning << "(" << root->balFactor << ")" << endl;

    PrintTree(root->pLeft, space);
}
int CountNode(TNode* root)
{
    if (!root) return 0;
    int nl = CountNode(root->pLeft);
    int nr = CountNode(root->pRight);
    return (1 + nl + nr);
}
int CountNodeLeaf(TNode* root)
{
    if (!root) return 0;
    if (!root->pLeft && !root->pRight) return 1;
    int nll = CountNodeLeaf(root->pLeft);
    int nrl = CountNodeLeaf(root->pRight);
    return (nll + nrl);
}
int CountBranchNode(TNode* root) {
    return CountNode(root) - CountNodeLeaf(root) - 1;//-1 node goc
}
void SplitWord(string x, string& EnglishMeaning, string& VietnameseMeaning) {
    int i;
    EnglishMeaning = "", VietnameseMeaning = "";
    for (i = 0; i < x.length(); i++)
        if (x[i] != ',')	EnglishMeaning += x[i];
        else	break;
    for (i = i + 1; i < x.length(); i++)
        VietnameseMeaning += x[i];
}
void Print_InOrder(TNode* root) {
    if (root != NULL) {
        Print_InOrder(root->pLeft);
        outfile << "\n" << root->EnglishMeaning << ", " << root->VietnameseMeaning << ", ";
        if (root->pLeft != NULL)	outfile << root->pLeft->EnglishMeaning;
        else	outfile << "NULL";
        outfile << ", ";

        if (root->pRight != NULL)	outfile << root->pRight->EnglishMeaning;
        else	outfile << "NULL";
        Print_InOrder(root->pRight);
    }
}
void PrintDictionary(TNode* root) {
    outfile << "goc: ";
    if (root != NULL) {
        outfile << "\n{";
        Print_InOrder(root);
        outfile << "\n}";
    }
    else	outfile << "NULL";
}
int main()
{
    TNode* root;
    InitTree(root);
    bool continue_ = true;
    while (continue_) {
        /*outfile << "\n- - - - - - - - - - - - - - - - - - - -";
        outfile << "\n0. Them tu moi vao tu dien";
        outfile << "\n1. Xoa mot tu";
        outfile << "\n2. Tim kiem nghia tieng Viet cua mot tu tieng Anh";
        outfile << "\n3. Xuat toan bo tu dien ra tap tin";
        outfile << "\n4. Thoat";*/
        int choice;
        //outfile << "\nNhap lua chon (so nguyen): ";
        infile >> choice;
        switch (choice)
        {
        case 0: {
            int numberOfWords;
            infile >> numberOfWords;
            string tmp, EnglishMeaning, VietnameseMeaning;
            infile.ignore();
            for (int i = 0; i < numberOfWords; i++) {
                getline(infile, tmp);
                SplitWord(tmp, EnglishMeaning, VietnameseMeaning);
                taller = false;
                InsertNode(root, CreateNode(EnglishMeaning, VietnameseMeaning), taller);
            }
            break;
        }
        case 1: {
            string tmp;
            getline(infile, tmp);
            shorter = false;
            DeleteNode(root, tmp, shorter);
            break;
        }
        case 2: {
            string tmp;
            getline(infile, tmp);
            TNode* p = SearchNode(root, tmp);
            if (p == NULL)	outfile << "\nNULL";
            else	outfile << "\n" << p->EnglishMeaning << "," << p->VietnameseMeaning;
            break;
        }
        case 3: {
            PrintDictionary(root);
            break;
        }
        case 4: {
            continue_ = false;
            break;
        }
        default:
            outfile << "\nSo vua nhap khong hop le!";
            break;
        }
    }
    infile.close();
    outfile.close();
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
