#include <iostream>
#include <vector>
#include <algorithm>

// polymorphism
// inheritance

// higher order functions
// lambda function because why not (not in class)

bool isEven(int x) {
	return x % 2 == 0;
}

int main() {

	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	

	// lambda
	//v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }));

	// same as lamda
	v.erase(std::remove_if(v.begin(), v.end(), isEven));

	for (int c : v) {

		//c.Meow();
		[](int c1) {std::cout << c1 << std::endl; }(c);

		// same as above, but with captured variables
		//[c]() {std::cout << c.data * c.data << std::endl; }();

		[](int x) {return x * x; };

	}

	return 0;
}