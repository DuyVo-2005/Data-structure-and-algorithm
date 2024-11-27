#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int ConvertBinaryNumberToDecimalNumber(string BinaryNumber);
string ConvertDecimalNumberToBinaryNumber(int DecimalNumber);
int ConvertWordToNumber(string word);

int main(int argc, char *argv[])
{
	cout << "\n" << ConvertWordToNumber("B");
	return 0;
}

int ConvertBinaryNumberToDecimalNumber(string BinaryNumber)
{
	long long res = 0;
	for (int i = BinaryNumber.length() - 1, j = 0; i >= 0; i--, j++)
	{
		res += (BinaryNumber[i] - '0') * pow(2, j);
	}
	cout<< "\n" <<res;
	return res;
}
string ConvertDecimalNumberToBinaryNumber(int DecimalNumber)
{
	string res = "";
	while (DecimalNumber > 0)
	{
		res += DecimalNumber % 2 + '0';
		DecimalNumber /= 2;
	}
	reverse(res.begin(), res.end());
	while (res.length() < 8)
	{
		//Chen so 0 thieu ben trai chuoi nhi phan
		res = '0' + res;
	}
	cout << "\n" << res;
	return res;
}
int ConvertWordToNumber(string word)
{
	string res = "";
	while (word.length() != 0)
	{ //chua duyet het chuoi word
		//lay phan tu cuoi chuoi
		int tmp = int(word[word.length() - 1]);
		res += ConvertDecimalNumberToBinaryNumber(tmp);
		//xoa phan tu cuoi chuoi de xet den ki tu tiep theo ke cuoi
		word.pop_back();
	}
	cout << "\n" << res;
	return ConvertBinaryNumberToDecimalNumber(res);
}
