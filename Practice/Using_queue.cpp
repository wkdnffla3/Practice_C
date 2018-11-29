#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue<char> Q;

	Q.push('a');
	Q.push('b');
	Q.push('c');

	cout << "Queue Size" << Q.size() << endl;

	cout << "Queue Items" << endl;

	/*for (; !Q.empty();)
	{
		cout << Q.front() << endl;
		Q.pop();
	}*/

	for(int i=1;;i*=8)




	return 0;
}