#include<iostream>
#include<tuple>
using namespace std;
tuple<string, int, float> TestTuple(){
	return {"hi", 18, 6.9f};
}
int main(int argc, char *argv[])
{
	auto [msg, n, avg] = TestTuple();
	cout<<msg<<" "<<n<<" "<<avg;
	return 0;
}
