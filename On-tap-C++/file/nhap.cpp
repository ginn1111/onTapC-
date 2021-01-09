#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

string const fileName = "test.txt";

void docFile() {
    fstream file;
    file.open(fileName, ios::in);
    if(file.fail()) {
        cout << "File loi!\n";
        exit(1);
    }
   string name;
   char ch;
    while(!file.eof()) {
        file.get(ch);
        name += ch;
    }
        cout << name.substr(0, name.length() - 1) << endl;
}

long gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
    /**
     * while(b != 0) {
     *  int temp = b;
     *  b = a % b;
     *  a = temp;
     * }
    */
}
/**
 * f1 = 0;
 * f2 = 1;
 * fibonnaci[0] = 0;
 * fibonacci[1] = 1; 
 * int fibonacci[MAX];
 * for(int i = 2; i <= n; i++) {
 *  fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
 * }
*/

void Fibonacci(unsigned long long a[], int n) {
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
}

string format(unsigned long long a) {
    string res;
    string temp = to_string(a);
    int counter = 0;
    for(int i = temp.length() - 1; i >= 0; i--) {
        res += temp[i];
        counter++;
        if(counter % 3 == 0 && temp.length() > counter) {
            res += '.';
        } 
        
    }
    return res;
}

string strRev(string s) {
    string res;
    for(int i = s.length() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

int main() {
    int n = 100;
   unsigned long long fibonacci[100];
    Fibonacci(fibonacci, 100);
    for(int i = 0 ; i < n; i++) {
        cout <<"So Fibonacci thu " 
        << setw(n % 10 + 1)
        << i + 1 << ": "
        << setw(30) << strRev(format(fibonacci[i])) 
        << endl;
    }
    return 0;
}