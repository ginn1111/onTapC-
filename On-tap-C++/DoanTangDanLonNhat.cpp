#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
/**
 * De tim ra nhung doan tang dan lon nhat thi:
 * b1: tim ra doan co do dai lon nhat
 * b2: neu la nhung doan co do dai bang do dai cua doan lon nhat thi xuat ra man hinh or luu lai
 **/

int main() {
    srand(time(NULL));
    int arr[12];
    for(int i = 0; i < 12; i++) {
        arr[i] = rand() % 50;
    }

    cout << "MANG SAU KHI RANDOM: \n";

    for(int i = 0; i < 12; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int maxx = 0;
    int cnt = 0;
    int indexSaveUn = 0;
    int indexTemp = 0;
    int indexSaveOn = 0;
    for (int i = 1; i < 12; i++) {
        if(arr[i - 1] < arr[i]) {
            cnt++;
            // Neu la phan tu cuoi thi gan indexSaveOn la pt cuoi cung
            if(i == 11 && cnt > maxx) {
                indexSaveUn = indexTemp;
                indexSaveOn = i;
            }
        } else {
            if(cnt > maxx) {
                maxx = cnt;
                indexSaveUn = indexTemp;
                indexSaveOn = i - 1;
           }
           indexTemp = i;
            cnt = 0;
        }
    }
    cout << indexSaveUn << " " << indexSaveOn << endl;
    for(int i = indexSaveUn; i <= indexSaveOn; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}