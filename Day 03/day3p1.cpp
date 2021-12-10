#include <bits/stdc++.h>
using namespace std;

long binToDec(string bin) {
    long dec = 0;
    for (int i = 0; i < bin.length(); i++) {
        dec += (bin[i] - '0') * pow(2, bin.length() - i - 1);
    }
    return dec;
}

int main(){
    vector<string> v;
    int tamStr;
    string str;

    while(cin >> str){
        v.push_back(str);
    }
    tamStr = v[0].size();

    string S = "";

    for(int i = 0; i < tamStr; i++){
        long on=0, off=0;
        for(int j = 0; j < v.size(); j++){
            if(v[j][i] == '1') on++;
            else off++;
        }
        if(on > off) S += '1';
        else S += '0';
    }
    string S2 = "";
    for(int i = 0; i < tamStr; i++){
        if(S[i] == '1') S2 += '0';
        else S2 += '1';
    }

    cout << binToDec(S) * binToDec(S2) << endl;


}