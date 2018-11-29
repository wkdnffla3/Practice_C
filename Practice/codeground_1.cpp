/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include<algorithm>
using namespace std;

int Answer;
int N, val[300002];
void proc() {
	int high = 0;
	sort(val, val + N);
	for (int i = 0; i < N; i++) {
		if (val[i] + N - i > high)high = val[i] + N - i;
	}
	for (int i = 0; i < N; i++)if (high > val[i])high = val[i] + 1;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (val[i] >= high)
			count++;
	}
	
	
	Answer = count;
};
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> val[j];
		//////////////////////////////////////////////////////////////a///////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer = 0;
		proc();
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}