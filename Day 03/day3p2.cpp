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
    vector<string> v, v2;
    int tamStr;
    string str;

    while(cin >> str){
        v.push_back(str);
    }
    tamStr = v[0].size();
    v2 = v;

    string S = "";
    string S2 = "";

    for(int i = 0; i < tamStr; i++){
        long on=0, off=0;
        for(int j = 0; j < v.size(); j++){
            if(v[j][i] == '1') on++;
            else off++;
        }
        if(on >= off) S += '1';
        else S += '0';
        
        on = 0; off = 0;

        for(int j = 0; j < v2.size(); j++){
            if(v2[j][i] == '1') on++;
            else off++;
        }
        if(on < off) S2 += '1';
        else S2 += '0';
        
        for(int j = 0; j < v.size(); j++){
            if(v.size() == 1) break;
            if(v[j][i] != S[i]) {
                v.erase(v.begin() + j);
                j--;
            }
        }
        
        for(int j = 0; j < v2.size(); j++){
            if(v2.size() == 1) break;
            if(v2[j][i] != S2[i]) {
                v2.erase(v2.begin() + j);
                j--;
            }
        }
    }
    cout << binToDec(v[0]) * binToDec(v2[0]) << endl;
    cout << v[0] << " " << v2[0] << endl;



}