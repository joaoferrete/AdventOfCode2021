#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector <string> v;

    while(getline(cin, s)){
        char c[s.size()];
        char * p;

        strcpy(c, s.c_str());
        p = strtok(c," ");
        bool insere = false;
        while(p != NULL){
            if(insere){
                v.push_back(p);
            }
            if(p[0] == '|'){
                insere = true;
            }
            p = strtok(NULL, " ");
        }
    }
    
    long cont = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].size() == 2 || v[i].size() == 3 || v[i].size() == 4 || v[i].size() == 7){
            cont++;
        }
    }
    cout << cont << endl;
}