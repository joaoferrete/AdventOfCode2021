#include <bits/stdc++.h>
using namespace std;

int main(){
    long X=0, Y=0;
    unsigned long long aim=0,  n;
    string s;

    while(cin >> s){
        cin >> n;

        if(s == "forward") {
            X += n;
            Y += n * aim;
        }
        else if(s == "up") aim -= n;
        else if(s == "down") aim += n;
    }

    cout << X*Y << endl;
}