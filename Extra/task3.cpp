#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int power_mod(int a, int b, int n){ // Функция возведения в степень по модулю
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }
    return result;
}

bool is_prime(int n, int k){ // Функция проверки числа на простоту с помощью алгоритма Миллера-Рабина
    if (n == 2 || n == 3) {
        return true;
    }
    if (n <= 1 || n % 2 == 0) {
        return false;
    }

    // Представляем n-1 в виде (2^s)*d
    int s = 0, d = n - 1;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        int a = rand() % (n - 3) + 2;
        int x = power_mod(a, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }

        for (int r = 1; r < s; r++) {
            x = power_mod(x, 2, n);
            if (x == n - 1) {
                break;
            }
        }
        if (x != n - 1) {
            return false;
        }
    }
    return true;
}

int main(){
    srand(time(NULL));
    int n;
    cout << "Enter a number: "; cin >> n;
    if (is_prime(n, 10)) {
        cout << n << " is prime" << endl;
    } 
    else {
        cout << n << " is composite" << endl;
    }
}