#include <iostream>
#include<string>
#include<string.h>
using namespace std;
#define ElementType char
struct Node
{
    ElementType Info; //Thông tin của Node
    Node* pNext; //Con trỏ chỉ đến phần tử node tiếp theo
};
typedef struct
{
    Node* pTop;
} STACK;
Node* CreateNode(ElementType x) {
    Node* p = new Node;
    if (p != NULL) {
        p->Info = x;
        p->pNext = NULL;
    }
    else {
        cout << "\nBo nho day khong tao duoc!";
    }
    return p;
}
void InitStack(STACK& name) {
    name.pTop = NULL;
}
void Push(STACK& name, Node* p) {
    p->pNext = name.pTop;
    name.pTop = p;
}
int IsEmptyStack(STACK name) {
    if (name.pTop == NULL)
        return 1;
    return 0;
}
Node* Pop(STACK& name) {
    if (IsEmptyStack(name) == 1) {
        cout << "\nStack rong khong huy duoc!";
    }
    else {
        Node* res = CreateNode(name.pTop->Info);
        Node* p = name.pTop;
        name.pTop = name.pTop->pNext;
        delete p;
        return res;
    }
}
Node* Top(STACK name) {
    return name.pTop;
}
void printStack(STACK name) {
    //in tu top
    for (Node* p = name.pTop; p != NULL; p = p->pNext)
        cout << p->Info << " ";
    cout << "\n";
}
bool IsOpcode(char chr){
	return chr == '+' || chr == '-' || chr == '*' || chr == '/';
}
bool IsDigit(char chr){
	return chr >= '0' && chr <= '9';
}
int Pri(char opcode){//priority
	if(opcode == '$')	return 1;
	if(opcode == '(')	return 2;
	if(opcode == '+' || opcode == '-')	return 3;
	return 4;//* /
}
string InfixToPostfix(string infix) {
    STACK tmp;
    InitStack(tmp);
    string E1 = ""; // Biểu thức hậu tố

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') { 
            // Gặp dấu mở ngoặc, đẩy vào ngăn xếp
            Push(tmp, CreateNode('('));
        } 
        else if (infix[i] == ')') {
            // Gặp dấu đóng ngoặc, xử lý tất cả toán tử cho đến khi gặp '('
            while (!IsEmptyStack(tmp) && Top(tmp)->Info != '(') {
                E1 += Pop(tmp)->Info;
            }
            if (!IsEmptyStack(tmp) && Top(tmp)->Info == '(') {
                Pop(tmp); // Loại bỏ dấu '(' khỏi ngăn xếp
            }
        } 
        else if (IsOpcode(infix[i])) {
            // Xử lý toán tử
            while (!IsEmptyStack(tmp) && Pri(Top(tmp)->Info) >= Pri(infix[i])) {
                E1 += Pop(tmp)->Info;
            }
            Push(tmp, CreateNode(infix[i]));
        } 
        else if (IsDigit(infix[i])) {
            // Xử lý toán hạng (có thể nhiều chữ số)
            string tmpString = "";
            while (i < infix.length() && IsDigit(infix[i])) {
                tmpString += infix[i];
                i++;
            }
            E1 += tmpString + " "; // Thêm toán hạng vào hậu tố
            i--; // Giảm chỉ số để xử lý ký tự tiếp theo
        }
    }

    // Xử lý các toán tử còn lại trong ngăn xếp
    while (!IsEmptyStack(tmp)) {
        if (Top(tmp)->Info == '(') {
            Pop(tmp); // Loại bỏ dấu ngoặc thừa
        } else {
            E1 += Pop(tmp)->Info;
        }
    }

    return E1;
}
int main()
{
   string algebraicExpression;
   cout<<"Nhap 1 bieu thuc dang infix: ";
   getline(cin,algebraicExpression);
   cout<<InfixToPostfix(algebraicExpression);
   return 0;
}
//(2*13+8/12)*(5-1)
