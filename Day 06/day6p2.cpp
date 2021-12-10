#include <bits/stdc++.h>
using namespace std;

typedef struct fish{
    int n;
    unsigned long long qt;

    bool operator ==(const fish &f) const{
        return n == f.n;
    }
    bool operator ==(const int &f) const{
        return n == f;
    }

} fish;


int main(){
    string s;
    cin >> s;
    char c[s.size()];
    char * p;
    vector <fish> v;

    strcpy(c, s.c_str());
    p = strtok(c,",");
    while(p != NULL){
        v.push_back({atoi(p), 1});   
        p = strtok(NULL, ",");
    }

    for(int i = 0; i<256; i++){
        int n = v.size();
        for(int j = 0; j<n; j++){
            if(v[j] == 0){
                v[j].n = 6;
                if(n == v.size())
                    v.push_back({8, v[j].qt});
                else{
                    v[n].qt += v[j].qt;
                }
                    
            }
            else v[j].n--;
        }
    }

    unsigned long long ans = 0;
    for(int i = 0; i<v.size(); i++){
        ans += v[i].qt;
    }

    cout << ans << endl;

}