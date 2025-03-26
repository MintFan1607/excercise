#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n == 0) { 
		return 0; // n=0 thì trả về 0 vì là số đầu tiên trong dãy
	}
	else if (n == 1) {
		return 1; // n=1 thì trả về 1 vì là số thứ hai trong dãy
	}
	else
		return fibonacci(n - 2) + fibonacci(n - 1); // n>2 thì trả về tổng của 2 số liền trước
}
void solve(int n) {
	for (int i = 0; i <= n; i++) { // vòng lặp chạy từ i=0 -> i=n
		cout << fibonacci(i) << " ";
	}
}

int main() {
	int n;
	cout << "Input: ";
	cin >> n;
	cout << "Output: ";
	solve(n); // trả về kết quả dãy fibonacci kéo dài tới số thứ n trong dãy
	return 0;
}