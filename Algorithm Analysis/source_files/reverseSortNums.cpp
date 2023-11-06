#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	string filename;
	if (argc > 1) filename = argv[1];
	else {
		cout << "Please enter the filename you want to read: " << endl;
		cin >> filename;
		if (!cin) throw runtime_error("Invalid file passed in!\n");
	}
	vector<int> vec;
	ifstream file(filename);
	while (file) {
		int x = 0;
		file >> x;
		if (!file) break;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int x : vec) cout << x << endl;
}
