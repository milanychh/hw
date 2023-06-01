#include <iostream>
using namespace std;

void move(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    move(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    move(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    move(n, 'A', 'B', 'C');
}