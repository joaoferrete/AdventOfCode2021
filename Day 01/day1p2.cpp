#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int n;
    while(cin >> n){
        v.push_back(n);
    }

    long sum = 0, atual = 0, qt=0;

    sum = v[0] + v[1] + v[2];
    atual = sum;
    for(int i = 3; i < v.size(); i++){
        atual = atual + v[i] - v[i-3];
        if(atual > sum){
            qt++;
        }
        sum = atual;
    }

    cout << qt << endl;

}