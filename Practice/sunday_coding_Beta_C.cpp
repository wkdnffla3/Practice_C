#include<iostream>

using namespace std;

int N;
int dp[103] = { 0 };
int cv = 0;
//int save[103] = { 0 };
void proc() {
	for (int i = 1; i <= 5; i++)
		dp[i] = i;
	if (N > 5)
		for (int A = 6; A <= N; A++) {
			int temp = dp[A - 3];
			if (dp[A - 1] + 1 <= dp[A - 3] + temp&&dp[A - 1] + cv <= dp[A - 3] + temp) {
				cv = temp;
				dp[A] = cv + dp[A - 3];
			}
			else if (dp[A - 1] + 1 <= dp[A - 1] + cv&&dp[A - 3] + temp <= dp[A - 1] + cv) {
				dp[A] = dp[A - 1] + cv;
			}
			else if (dp[A - 1] + cv <= dp[A - 1] + 1 && dp[A - 3] + temp <= dp[A - 1] + 1)
			{
				dp[A] = dp[A - 1] + 1;
			}
		}
	cout << dp[N];

}


int main() {
	cin >> N;
	proc();
	return 0;
}