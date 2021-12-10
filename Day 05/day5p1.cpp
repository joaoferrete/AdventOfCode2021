#include <bits/stdc++.h>
using namespace std;

typedef struct points{
    int x1, y1, x2, y2;

    bool linear(){
        return x1 == x2 || y1 == y2;
    }

    bool vertical(){
        return x1 == x2;
    }

}linha;

int main(){
    string s;
    vector <linha> l;

    while(getline(cin,s)){
        char c [s.length()];
        char *p;
        strcpy(c,s.c_str());
        p = strtok(c," ,->");
        vector <int> v;
        while(p != NULL){
            v.push_back(atoi(p));
            p = strtok(NULL," ,->");
        }
        l.push_back({v[0],v[1],v[2],v[3]});
    }

    vector <vector<int>> v(1000, vector<int>(1000, 0));

    for(int i = 0; i < l.size(); i++){
        linha l1 = l[i];
        if(l1.linear()){
            cout << "X1: " << l1.x1 << " Y1: " << l1.y1 << " X2: " << l1.x2 << " Y2: " << l1.y2 << endl;
            if(l1.vertical()){
                int a = min(l1.y1, l1.y2); int b = max(l1.y1, l1.y2);
                for(int j = a; j<=b; j++) v[l1.x1][j]++;
            }
            else{
                int a = min(l1.x1, l1.x2); int b = max(l1.x1, l1.x2);
                for(int j = a; j<=b; j++) v[j][l1.y1]++;
            }
        }
    }

    long total = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            //cout << v[i][j] << " ";
            if(v[i][j] > 1){
                total++;
            }
        }
        //cout << endl;
    }

    cout << total << endl;

    
}