/* 
 * unordered_map
 */
#include <unordered_map>
unordered_map<int, char> map;
// iterators
map.begin(); map.end();
// size
map.empty(); map.size();
// clear
map.clear();
// operator[]
map[3] = 'c';
auto search = map.find(3);
if (search != map.end()) {
	cout << search.first << search.second;
} else {
	cout << "not found" << endl;
}

/*
 * set
 */
#include <set>
set<int> a;
// iterators
a.begin(); a.end(); 
// size
a.empty(); a.size();
// modifiers
a.clear();
a.insert(3);
// count ?
a.count(3);
a.find(3);

/*
 * vector
 */
#include <vector>
vector<char> a;
// access
a.at(3)='c';
a[2]; a.front(); a.back();
// iterators
a.begin(); a.end();
// size
a.empty(); a.size();
// modifier
a.clear();
a.insert(0, 'w');
a.resize(10);

/*
 * stack
 */
#include <stack>
stack<int> a;
// access
a.top(); a.top() -= 5;
// size
a.empty(); a.size();
// modifier
a.push(5);
int i = a.pop();

/*
 * list
 */
#include <list>
list<int> a;
// access
a.top(); a.top() -= 5;
a.back();
// size
a.empty(); a.size();
// iterators
a.begin(); a.end();
// capacity
a.empty(); a.size();
// modifiers
a.clear();
a.insert(iterator pos, const T& value);
a.push_back(const T& value); a.push_back(T&& value);

/*
 * priority queue
 */
#include <queue>
priority_queue<int> a;
// access
a.top();
// capacity
a.empty(); a.size();
// modifiers
a.push(); a.pop();
// examples
while (!q.empty()) {
	cout << q.top() << endl;
	q.pop();
}

/*
 * string
 */
#include <string>
string a;
// Access
a[3] = 'c';
cout << a.at(i);
// capacity
a.empty(); a.size();
a.length();
// iterators
a.begin(); a.end();
// modifiers
a.clear();
a.insert(index, "abc");
// compare
str1.compare(str2) != 0;
a += b;
// find
