#include <bits/stdc++.h>
using namespace std;


bool ordena(string a, string b){
    return a.size() < b.size();
}

bool taContido(string a, string b){
    for(int i = 0; i < b.size(); i++){
        if(a.find(b[i]) == string::npos) return false;
    }
    return true;
}

string subtraiString(string a, string b){
    string res = "";
    for(int i = 0; i < a.size(); i++){
        if(b.find(a[i]) == string::npos) res += a[i];
    }
    return res;
}

int main(){
    string s;
    vector <string> v;
    vector <string> a;
    unsigned long long sum = 0;

    while(getline(cin, s)){
        char c[s.size()];
        char * p;

        string g[10];
        string Result = "";

        strcpy(c, s.c_str());
        p = strtok(c," ");
        bool insere = false;

        while(p != NULL){
            if(insere) v.push_back(p);
            else a.push_back(p);
            
            if(p[0] == '|'){
                insere = true;
            }
            p = strtok(NULL, " ");
        }

        sort(a.begin(), a.end(), ordena);

        

        for(int i = 0; i < a.size(); i++){
            if(a[i].size() == 2){
                g[1] = a[i];
            }
            else if(a[i].size() == 3){
                g[7] = a[i];
            }
            else if(a[i].size() == 4){
                g[4] = a[i];
            }
            else if(a[i].size() == 7){
                g[8] = a[i];
            }
            else if(a[i].size() == 5){
                string aux = subtraiString(g[4], g[7]);
                if(taContido(a[i], g[7])) g[3] = a[i];
                else if(taContido(a[i], aux)) g[5] = a[i];
                else g[2] = a[i];
            }
            else if(a[i].size() == 6){
                string aux = subtraiString(g[2], g[3]);
                if(!taContido(a[i], g[1])) g[6] = a[i];
                else if(taContido(a[i], aux)) g[0] = a[i];
                else g[9] = a[i];
            }
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < 10; j++){
                if(taContido(v[i], g[j]) && taContido(g[j], v[i])){
                    Result += to_string(j);
                    break;
                }
            }
        }
        cout << Result << endl;
        sum += atoi(Result.c_str());

        a.clear();
        v.clear();
        Result = "";
        
    }

    cout << sum << endl;
}