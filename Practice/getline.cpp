#include<iostream>

using std::cout;
using std::endl;
using std::cin;

double area(float input);

namespace my_test {
	void OutPut() {
		std::cout << "ธÞที" << std::endl;
	}
}

namespace my_test2 {
	void OutPut() {
		std::cout << "ธÞที2" << std::endl;
	}
}


int main() {
	int n = 0;
	char a = '#';
	float b = 0.3333333333333333333333333333333;
	std::cout << "std::cout<<" << n << " " << a << std::endl;
	std::cout << "It's test" << b << std::endl;
	my_test::OutPut();
	my_test2::OutPut();

	char name[30];
	cin >> name;
	//for (int i = 0; name != '\0'; i++);
	cout << name << '\n';

	cin.getline(name, 30, ';');
	cout << name << endl;



	return 0;
}

double area(float input) {
	return input*input;
}