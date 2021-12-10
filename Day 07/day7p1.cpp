#include <bits/stdc++.h>
using namespace std;

#define MAX_INT 2147483647


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

    unsigned long long min = MAX_INT;
    sort(v.begin(), v.end());
    unsigned long long max = v[v.size()-1];

    for(int i = 0; i < max; i++){
        unsigned long long at = 0;
        for(int j = 0; j < v.size(); j++){
            at += abs(v[j] - i);
        }
        if(at < min){
            min = at;
        }
    }
    cout << min << endl;

}