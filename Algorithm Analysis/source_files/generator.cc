#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//Compile the program like this: g++ -o generator generator.cc
//Run the program like this: generator 200000 > input_rem_search200k
int main(int argc, char **argv) {
	int size = 10000;
	if (argc <= 1) {
		cout << "Run the program like this: generator 200000 > input_rem_search200k\n";
		exit(1);
	}
	if (argc > 1) size = atoi(argv[1]);
	cerr << "Size is " << size << endl;

	srand(time(NULL));
	vector<int> vec;
	for (int i = 0; i < size ; i++) {
		int x = rand() % 10'000;
		vec.push_back(x);
		cout << x << endl;
	}
}
