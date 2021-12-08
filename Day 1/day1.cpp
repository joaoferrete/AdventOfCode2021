#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int n;
    while(cin >> n){
        v.push_back(n);
    }
    long x = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i] > v[i-1]){
            x ++;
        }
    }
    cout << x << endl;
}