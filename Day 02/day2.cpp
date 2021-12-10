#include <bits/stdc++.h>
using namespace std;

int main(){
    long X=0, Y=0, n;
    string s;

    while(cin >> s){
        cin >> n;

        if(s == "forward") X += n;
        else if(s == "up") Y -= n;
        else if(s == "down") Y += n;
    }

    cout << X*Y << endl;
}