#include<iostream>
#define MAX 10000
using namespace std;

int prime[MAX];

int main() {
    int n;
    cout << "Moi ban nhap vao so n: ";
    cin >> n;
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }    

    for(int i = 2; i <= n; i++) {
        if(prime[i] != 1) {
            cout << i << " ";
        }
    }
    return 0;
}