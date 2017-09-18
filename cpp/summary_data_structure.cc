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
