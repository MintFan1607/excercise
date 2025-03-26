#include <iostream>
using namespace std;

void generateBinaryStrings(int n, string str) {
    
    if (str.length() == n) { // điều kiện dừng khi độ dài chuỗi str = n
        cout << str << endl;
        return;
    }
    generateBinaryStrings(n, str + "0");
    generateBinaryStrings(n, str + "1"); // gọi hàm 2 lần, thêm 0 và 1 vào chuỗi str
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output: "<<endl;
    generateBinaryStrings(n, "");

    return 0;
}