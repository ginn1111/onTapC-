#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int binarySearch(const int a[], int, int);
void printHeader(const int a[], int);
void printRow(const int a[], int, int, int, int);

int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = i * 3;
    }

    int key;
    cout << "Enter key (0 -> 27): ";
    cin >> key;

    printHeader(a, 10);
    int res = binarySearch(a, key, 5);
    if(res != -1) {
        cout << res;
    } else {
        cout << "not found";
    }
    
    return 0;
}

void printRow(const int a[], int low, int middle, int high, int size) {
    for(int i = 0; i < size; i++) {
        if(i < low || i > high) {
            cout << "    ";
        } else {
            if(i == middle) {
                cout << a[i] << "*  ";
            } else {
                cout << a[i] << "  ";
            }
        }
    }
    cout << endl;
}

void printHeader(const int a[], int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << "   ";
    }
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << "-----";
    }
    cout << endl;
}

int binarySearch(const int a[], int key, int size) {
    int low = 0;
    int high = size - 1;
    while( low <= high) {
        int middle = (low + high) / 2;
        printRow(a, low, middle, high, size);
        if(a[middle] == key) {
            return middle;
        } else {
            if(key < a[middle]) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
    }
    return -1;
}