#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string const fileName = "test.txt";
bool ktGiaiMa = true;
bool ktMaHoa = true;

int maHoa();
int giaiMa();
string docFile();
int ghiFile(string);
void nhapChuoiGhiFile();
bool ktChuThuong(char);
bool ktChuHoa(char);
void meNu();


int main() {
    while(1) {
        meNu();
        system("cls");
    }
    return 0;
}

void meNu() {
    cout << "\t\t[1] Doc File.\n";
    cout << "\t\t[2] Ghi File.\n";
    cout << "\t\t[3] Ma Hoa.\n";
    cout << "\t\t[4] Giai Ma.\n";
    cout << "\t\t[0] Thoat.\n";
    int luaChon;
    cout << "> ";
    cin >> luaChon;
    switch (luaChon)
    {
    case 1:
        docFile();
        break;
    case 2:
        nhapChuoiGhiFile();
        break;
    case 3:
       {
           if(maHoa() == 0) {
               cout << "Ma hoa thanh cong\n";
           } else {
               cout << "File da duoc ma hoa\n";
           }
       }
        break;
    case 4:{
        if(giaiMa() == 0) {
            cout << "Giai ma thanh cong\n";
        } else {
            cout << "File da duoc giai ma\n";
        }
    }
        break;
    case 0:
        exit(1);
        break;
    default:
        cerr << "Lua chon khong ton tai!\n";
        break;
    }
}

string docFile() {
    fstream file(fileName, ios::in);
    string res;
    if(file.fail()) {
        cout << "File loi!\n";
        exit(1);
    }
    while(!file.eof()) {
        char c[255];
        string s;
        file.getline(c, 255);
        s = c;
        res += s + '\n';
    }
    cout << res;
    return res.substr(0, res.length() - 1);
}

int ghiFile(string content) {
    fstream file(fileName, ios::out);
     if(file.fail()) {
        cout << "File loi!\n";
        exit(1);
    }
    if(content.empty()) {
        return -1;
    }
    file << content;
    return 0;
}

void nhapChuoiGhiFile() {
    string s;
    cout << "Nhap vao mot chuoi: \n";
    getline(cin, s, '~');
    if(ghiFile(s) == -1) {
        cout << "Khong co du lieu de luu!\n";
    } else {
        cout << "Luu file thanh cong!\n";
    }
}

int giaiMa() {
    if(!ktGiaiMa) {
        return -1;
    }
     string s = docFile();
        for(int i = 0; i < s.length(); i++) {
            if(ktChuThuong(s[i])) {
                s[i] -= 5;
                if(s[i] < 'a') {
                    s[i] = 'z' + 1 - ('a' - s[i]);
                }
            } else if(ktChuHoa(s[i])) {
                 s[i] -= 5;
                if(s[i] < 'A') {
                    s[i] = 'Z' + 1 - ('A' - s[i]); 
                }
            }
        }
        ktGiaiMa = false;
        ktMaHoa =  true;
        ghiFile(s);
    return 0;
}

int maHoa() {
    if(!ktMaHoa) {
        return -1;
    } 
    string s = docFile();
        for(int i = 0; i < s.length(); i++) {
            if(ktChuThuong(s[i])) {
                s[i] += 5;
                if(s[i] > 'z') {
                    s[i] = (s[i] - 'z') + 'a' - 1;
                }
            } else if(ktChuHoa(s[i])) {
                s[i] += 5;
                if(s[i] > 'Z') {
                    s[i] = (s[i] - 'Z') + 'A' - 1;
                }
            }
        }
        ktMaHoa = false;
        ktGiaiMa = true;
        ghiFile(s);
    return 0;
}

bool ktChuHoa(char c) {
    return c >= 'A' && c <= 'Z';
}

bool ktChuThuong(char c) {
    return c >= 'a' && c <= 'z';
}