#include <iostream>
using namespace std;

#define MAXN 4
#define rep(i,a,b) for(int i=a;i<b;++i)
char s[MAXN + 1] = "abcd";
int r[MAXN];
int len = 1 << MAXN;

void proc(int n) {
	if (n==0)return;
	
	proc(n - 1);
	r[n - 1] = !r[n - 1];
	rep(j, 0, MAXN) {
		if (r[j]) {
			cout << s[j];
		}
	}
	cout << '\n';
	proc(n - 1);
	
}
int main() {
	proc(MAXN);
	return 0;
}