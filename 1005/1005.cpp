#include <iostream>
using namespace std;

int main() {
	string opt[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char temp[10000];
	int sum = 0, i = 0, j = 0;

	cin >> temp;
	while (temp[i]) {
		sum += (int)temp[i++] - '0';  
	}
	sprintf(temp, "%d", sum);

	while (temp[j]) {
		cout << opt[(int)temp[j] - '0'].c_str();
		if (temp[++j]) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
	return 0;
}