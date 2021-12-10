#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char c[s.size()];
    char * p;
    vector <int> v;

    strcpy(c, s.c_str());
    p = strtok(c,",");
    while(p != NULL){
        v.push_back(atoi(p));   
        p = strtok(NULL, ",");
    }

    for(int i = 0; i<80; i++){
        int n = v.size();
        for(int j = 0; j<n; j++){
            if(v[j] == 0){
                v[j] = 6;
                v.push_back(8);
            }
            else v[j]--;
            //cout << v[j] << " ";
        }
        //cout << endl;
    }

    cout << v.size() << endl;

}