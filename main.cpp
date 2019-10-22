#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;
map <char,int>num_rom{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
void printRomano(string exp){
    int resultado=0;
    for (int i = 0; i < exp.size();) {
        if(num_rom[exp[i]]< num_rom[exp[i+1]]){
            resultado+= num_rom[exp[i+1]] - num_rom[exp[i]];
            i+=2;
        }
        else{
            resultado+= num_rom[exp[i]];
            i+=1;
        }
    }
    cout << resultado << endl;
}
void printNum(int num) {
    char r[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L",
                               "XL", "X", "IX", "V", "IV", "I"};
    int val[13] = {1000, 900, 500, 400, 100, 90, 50,
                         40, 10, 9, 5, 4, 1};
    char roman[30], id = 0;
    for(int i = 0; i < 13; i++) {
        while(num >= val[i]) {
            num -= val[i];
            roman[id++] = r[i][0];
            if(r[i][1] != '\0')
                roman[id++] = r[i][1];
        }
    }
    roman[id] = '\0';
    cout <<  roman <<endl;
}
int main() {
    string exp;
    while (cin >> exp){
        if (!isdigit(exp[0])) {
            printRomano(exp);
        } else {
            printNum(stoi(exp));
        }
    }
}
