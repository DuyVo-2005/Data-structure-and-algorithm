# #include<vector>
# #include<queue>
# #include<set>
How to use: use to contain separate elements (appear 1 time), input, erase, find() 1 element O(n) [faster than normal array O(n^2)]
Khai báo set <data type> name_set
Hàm
.size(): O(1)
.empty(): O(1)
.insert(): insert 1 elment into set( if this element is existed - no change) ,O(logn)
.find(): find 1 element in set-return interater(con trỏ đại diện) ,O(logn)
.count(x): use to find x element appear in set because return 1 or 0
.erase(x): erase x in set
Print set: for(int i: name_set) cout<<i<<' ';
     C++11:auto it=name_set.begin(); cout<<*it;//address of first element
Or change auto by set<it>::iterator
.begin():
.end(): address of end element(use must -1 unit)

multiset<int>s; alow repeat element, when we erase one element, all element has equal value will be erased too
If we just want to erase one element, use: auto it=s.find(x); [return iterator 1 if it exist s else return s.end()] s.erase(it); [if(it!=s.end()]
//.count(): more necessary
# #include<deque>//hàng đợi 2 đầu-mạnh
.push_back():
.pop_back():
.push_front():
.pop_front():
.back(): return last element (check empty before)
.front(): return first element (check empty before)
.empty():
.size():
.insert(iterator,x):
.erase(iterator):
Take x's adrress: .begin+x (indexed)
# #include<stack> // ngăn xếp
Declare: stack<data type> name_stack
FILO- First in last out
.push(x): push x on the top (O(1))
.pop(): erase the top element (O(1))
.top(): take the top element(don't clear)
.size(): O(1)
.empty(): O(1)
Stack doesn't have clear function- use while(!name_stack.empty()) name_stack.pop(); instead
When stack is empty, pop and top function will be fault "runtime error".

# #include<map>
Declare: map<data_type1,data_typy2>name_map;
data_type1 is key, data_type2 is value
Ex: map<int,string> mp;
//1:one mp[1]=" one";
//2:two mp[2]="two";
.find(x): x(key)
.erase(x): 
.size():
.count(x): 
.empty():
Ex: map<int,char> mp;
string s="abcde....tuvxyz";
for(char c:s) mp[c]++;
for(pair<char,int>x:mp) cout<<x.first<<" "<<x.second<<endl;

# #include<algorithm>
sort(start,end)
star,end: iterator

