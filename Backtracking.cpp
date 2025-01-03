//Near branch
#include<iostream>
using namespace std;
#define endl '\n'
#include<string.h>
const int Max=105;
int N, MinC, T[Max];//T[i] cho biết số ký tự "C" trong đoạn từ X[1] đến X[i]
char X[Max], Best[Max];
//Hàm Same(i, l) cho biết xâu gồm l ký tự kết thúc tại X[i] có trùng với xâu l ký tự liền trước nó không ?
bool Same(int i, int l){
	int j=i-l, k;
	for(k=0;k<=l-1;k++){
		if(X[i-k]!=X[j-k])	return false;
	}
	return true;
}
//Hàm Check(i) cho biết X[i] có làm hỏng tính không lặp của dãy X[1..i] hay không
bool Check(int i){
	int l;
	for(l=1;l<=i/2;l++) //thử các độ dài l	
		if(Same(i,l))//Nếu có xâu độ dài l kết thúc bởi X[i] bị trùng với xâu liền trước
			return false;
	return true;
}
void KeepResult(){
	MinC=T[N];
	for(int i=1;i<=N;i++)	Best[i]=X[i];
}
void Try(int i){
	char j;
	for(j='a';j<='c';j++){
		X[i]=char(j);// ép thành kiểu ký tự
		if(Check(i)){
			if(j=='c')	T[i]=T[i-1]+1;
			else T[i]=T[i-1];
			if(T[i]+(N-i)/4<MinC){
				if(i==N)	KeepResult();
				else Try(i+1);
			}
		}
	}
}
void PrintResult(){
	int i;
	for(i=1;i<=N;i++)	cout<<Best[i];
	cout<<"\n'C' letter count: "<<MinC;
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	T[0]=0;
	MinC=N;//first BestConfig is very bad
	Try(1);
	PrintResult();
	return 0;
}
/*in: 10
out: ABACABCBAB*/
