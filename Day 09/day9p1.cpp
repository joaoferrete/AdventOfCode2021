#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> s;
    string str;

    while(cin >> str){
        s.push_back(str);
    }

    unsigned long long sum = 0, qt = 0;

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].size(); j++){
            if(i > 0 && i < s.size() - 1 && j>0 && j < s[i].size() - 1
            && s[i][j] < s[i-1][j] && s[i][j] < s[i+1][j] && s[i][j] < s[i][j-1] 
            && s[i][j] < s[i][j+1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == 0 && j == 0 && s[i][j] < s[i+1][j] && s[i][j] < s[i][j+1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == 0 && j == s[i].size() - 1 && s[i][j] < s[i+1][j] && s[i][j] < s[i][j-1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == s.size() - 1 && j == 0 && s[i][j] < s[i-1][j] && s[i][j] < s[i][j+1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == s.size() - 1 && j == s[i].size() - 1 && s[i][j] < s[i-1][j] && s[i][j] < s[i][j-1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == 0 && j != 0 && j != s[i].size() - 1 && s[i][j] < s[i][j-1] && s[i][j] < s[i][j+1]
            && s[i][j] < s[i+1][j]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(i == s.size() - 1 && j != 0 && j != s[i].size() - 1 && s[i][j] < s[i][j-1] && s[i][j] < s[i][j+1]
            && s[i][j] < s[i-1][j]){
                sum += s[i][j] - '0';
                qt++;    
            }
            else if(j == 0 && i != 0 && i != s.size() - 1 && s[i][j] < s[i-1][j] && s[i][j] < s[i+1][j]
            && s[i][j] < s[i][j+1]){
                sum += s[i][j] - '0';
                qt++;
            }
            else if(j == s[i].size() - 1 && i != 0 && i != s.size() - 1 && s[i][j] < s[i-1][j] && s[i][j] < s[i+1][j]
            && s[i][j] < s[i][j-1]){
                sum += s[i][j] - '0';
                qt++;
            }
        }
    }
    cout << sum + qt << endl;
}