#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int fountAndCounter(string a, string s[], int check[]) {
    int counter = 0;
    for(int i = 0; s[i] != "\0" ; i++) {
        if(s[i] == a) {
            check[i] = 1;
            counter++;
        }
    }
    return counter;
} 

int main() {
    // input
    char input[255];
    cin.getline(input, 255);
    char *tokens;
    string resTok[100];
    // cut string
    tokens = strtok(input, " ");
    int i = 0;
    while(tokens != NULL) {
        resTok[i++] = tokens;
        tokens = strtok(NULL, " ");
    }
    resTok[i] = "\0";
    int check[100] = {0};
    string tokenSave[100];
    int counter[100] = {0};
    int j = 0;
    int q = 0;
    // found and count, check
    for(int i = 0; resTok[i] != "\0"; i++) {
        if(check[i] == 0) {
            tokenSave[j++] = resTok[i];
            counter[q++] = fountAndCounter(resTok[i], resTok, check);
        }
    }
    tokenSave[j] = "\0";
    for(int i = 0; tokenSave[i] != "\0"; i++) {
        cout << tokenSave[i] << " " << counter[i] << endl;
    }
    
    return 0;
}