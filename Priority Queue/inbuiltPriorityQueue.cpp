#include <iostream>
using namespace std;
#include <queue>
//inbuilt priority queue uses maximum heap order property
	
int main() {
	priority_queue<int> p;

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);

	cout << p.size() << endl;
	cout << p.empty() << endl;
	cout << p.top() << endl;    //we'll get max element

	while(!p.empty()) {
		cout << p.top() << endl;//elements will be printed in decreasing order
		p.pop();
	}
}