#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector <string> v;
    stack <string> pilha;
    
    while(cin >> s){
        v.push_back(s);
    }
    long cont = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == '(') pilha.push("(");
            else if (v[i][j] == '[') pilha.push("[");
            else if (v[i][j] == '{') pilha.push("{");
            else if (v[i][j] == '<') pilha.push("<");
            else if (v[i][j] == ')'){
                if(pilha.top() == "(") pilha.pop();
                else {
                    cont+=3;
                    break;
                }
            }
            else if (v[i][j] == ']'){
                if(pilha.top() == "[") pilha.pop();
                else {
                    cont+=57;
                    break;
                }
            }
            else if (v[i][j] == '}'){
                if(pilha.top() == "{") pilha.pop();
                else {
                    cont+=1197;
                    break;
                }
            }
            else if (v[i][j] == '>'){
                if(pilha.top() == "<") pilha.pop();
                else {
                    cont+=25137;
                    break;
                }
            }
        }
        while(!pilha.empty()) pilha.pop();
    }
    cout << cont << endl;
}