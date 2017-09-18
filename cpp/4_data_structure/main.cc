#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	priority_queue<int, vector<int>, std::greater<int> > q;
	for (int i = 10; i >= 0; --i)
		q.push(i);

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}

	return 0;
}
