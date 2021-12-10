#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector <string> v;
    stack <string> pilha;
    vector <unsigned long long> results;    

    while(cin >> s){
        v.push_back(s);
    }

    for(int i = 0; i < v.size(); i++){

        unsigned long long cont = 0;
        bool flag = false;
        
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == '(') pilha.push("(");
            else if (v[i][j] == '[') pilha.push("[");
            else if (v[i][j] == '{') pilha.push("{");
            else if (v[i][j] == '<') pilha.push("<");
            else if (v[i][j] == ')'){
                if(pilha.top() == "(") pilha.pop();
                else {
                    flag = true;
                    break;
                }
            }
            else if (v[i][j] == ']'){
                if(pilha.top() == "[") pilha.pop();
                else{ 
                    flag = true;
                    break;
                }
            }
            else if (v[i][j] == '}'){
                if(pilha.top() == "{") pilha.pop();
                else {
                    flag = true;
                    break;
                }
            }
            else if (v[i][j] == '>'){
                if(pilha.top() == "<") pilha.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) while(!pilha.empty()) pilha.pop();
        else{
            while(!pilha.empty()){
                if (pilha.top() == "("){
                    cont*=5;
                    cont+=1;
                }
                else if(pilha.top() == "["){
                    cont*=5;
                    cont+=2;
                }
                else if(pilha.top() == "{"){
                    cont*=5;
                    cont+=3;
                }
                else if(pilha.top() == "<"){
                    cont*=5;
                    cont+=4;
                }
                pilha.pop();
            }
            results.push_back(cont);
            cout<< "i: " << i << " cont: " << cont << endl;
        }
    }
    sort(results.begin(), results.end());
    cout << results[results.size()/2] << endl;
}