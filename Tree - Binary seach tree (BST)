// 6.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define ElementType int
typedef struct tagTNode
{
    ElementType key;
    tagTNode* pLeft, * pRight;
} TNode;
void InitTree(TNode*& root) {
    root = NULL;
}
TNode* CreateNode(ElementType value) {
    TNode* p = new TNode;
    if (!p)  return NULL;
    p->key = value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int IsEmptyTree(TNode* T) {
    if (T == NULL) return 1;
    return 0;
}
void InsertNode(TNode*& root, TNode* newNode) {
    if (root == NULL)    root = newNode;
    else {
        if (newNode->key < root->key)   InsertNode(root->pLeft, newNode);
        else
        {
            if (newNode->key > root->key)
                InsertNode(root->pRight, newNode);
        }
    }
}
void ThayThe(TNode*& p, TNode*& T) {
    if (T->pLeft != NULL)  ThayThe(p, T->pLeft);
    else
    {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}
void DeleteNode(TNode*& root, ElementType node) {
    //co thi xoa, khong thi thoi
    if (root == NULL) return;
    if (root->key > node)//tim ben trai
        DeleteNode(root->pLeft, node);
    else {
        if (root->key < node)//tim ben phai
            DeleteNode(root->pRight, node);
        else// tim thay x trong cay
        {
            TNode* p = root;
            if (root->pLeft == NULL)// co 1 nut con tro den chinh no
                root = root->pRight;// la nut con phai
            else
            {
                if (root->pRight == NULL)
                    root = root->pLeft;//la nut con trai
                else//TH co 2 nut con chon min ben phai
                    ThayThe(p, root->pRight);
            }
        }
    }
}
TNode* SearchNode(TNode* root, ElementType x) {
    TNode* p = root;
    while (p != NULL)
    {
        if (x == p->key) return p;
        else
            if (x < p->key) p = p->pLeft;
            else p = p->pRight;
    }
    return NULL;
}
void PrintTree_PreOrder(TNode* root) {
    if (root != NULL) {
        cout << "\n" << root->key;
        PrintTree_PreOrder(root->pLeft);
        PrintTree_PreOrder(root->pRight);
    }
}
void PrintTree_InOrder(TNode* root) {
    if (root != NULL) {
        PrintTree_InOrder(root->pLeft);
        cout << "\n" << root->key;
        PrintTree_InOrder(root->pRight);
    }
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
int CountNodeNhanh(TNode* root) {
    return CountNode(root) - CountNodeLeaf(root);
}
void PrintTree_PostOrder(TNode* root) {
    if (root != NULL) {
        PrintTree_PostOrder(root->pLeft);
        PrintTree_PostOrder(root->pRight);
        cout << "\n" << root->key;
    }
}
long SumNode(TNode* root)
{
    if (!root) return 0;
    int suml = SumNode(root->pLeft);
    int sumr = SumNode(root->pRight);
    return (root->key + suml + sumr);
}
int main()
{
    TNode* root;
    InitTree(root);
    InsertNode(root, CreateNode(1));
    InsertNode(root, CreateNode(2));
    InsertNode(root, CreateNode(-1));
    DeleteNode(root, 1);
    PrintTree_InOrder(root);
    if (SearchNode(root, 2) != NULL)
        cout << "\n" << SearchNode(root, 2) << " " << SearchNode(root, 2)->key;
    else
    {
        cout << "\nKhong tim thay!";
    }
    if (SearchNode(root, 3) != NULL)
        cout << "\n" << SearchNode(root, 3) << " " << SearchNode(root, 3)->key;
    else
    {
        cout << "\nKhong tim thay!";
    }
    cout << "\nTong: " << SumNode(root);
    return 0;
}
