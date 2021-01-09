#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string const fileName = "tracnghiem.txt";
char dapAn[10];
char luaChon[10] = {'a'};



void chonPhuongAn(int i) {
        cout << "\nDap An Cau " << i + 1 << " > ";
        cin >> luaChon[i];
}

void docFile() {
    fstream file(fileName, ios::in);
    if(file.fail()) {
        cout <<"File loi!\n";
        exit(1);
    }
    int i = 0;
    while(!file.eof()) {
        char c[255];
        string s;
        file.getline(c, 255);
        s = c;
        if(s == "DAPAN") {
            file >> dapAn[i];
            chonPhuongAn(i++);
        } else {
            cout << s << endl;
        }
    }
}


int diem() {
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        if(luaChon[i] == dapAn[i]) {
            cnt++;
        }
    }
    return cnt;
}



int main() {
    docFile();
    cout << "So diem ban dat duoc la: ";
    cout << diem() << endl;
    return 0;
}