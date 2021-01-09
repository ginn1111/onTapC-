#include<iostream>
#include<map>
#define MAX 1000
using namespace std;

int main() {
    int n;
    cout << "Moi ban nhap vao so n: ";
    cin >> n;
    int prime[MAX] = {0};
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }

    map<int,int> maps;

    while(n != 1) {
        for(int i = 2; i <= n; i++) {
            int cnt = 0;
            if(prime[i] == 0) {
                while(n % i == 0) {
                    cnt++;
                    n /= i;
                }
            }
            if(cnt != 0) {
                cout << i << "^" << cnt;
                if(n != 1) {
                    cout << " x "; 
                }
            }
            
        }
    }
    // map<int,int>::iterator i;
    // for(i = maps.begin(); i != maps.end();) {
    //     cout << i -> first << "^" << i -> second;
    //     if((i++) != maps.end()) {
    //         cout << " x ";
    //     }
    // }
    return 0;
}