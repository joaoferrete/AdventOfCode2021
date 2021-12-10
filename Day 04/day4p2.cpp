#include <bits/stdc++.h>
using namespace std;

typedef struct num{
    int num;
    bool marcado;

    bool operator == (const struct num &n) const{
        return num == n.num;
    }

    bool operator == (const int &n) const{
        return num == n;
    }
}numeros;

typedef vector <vector<numeros>> matriz;

bool ganhou(matriz m){
    for(int i=0; i<5; i++){
        if(m[i][0].marcado && m[i][1].marcado && m[i][2].marcado && m[i][3].marcado && m[i][4].marcado)
            return true;
        if(m[0][i].marcado && m[1][i].marcado && m[2][i].marcado && m[3][i].marcado && m[4][i].marcado)
            return true;
    }
    return false;
}

void marcaNumero(matriz &m, int x){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(m[i][j].num == x){
                m[i][j].marcado = true;
            }
        }
    }
}


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

    vector<matriz> m;

    int n1, n2, n3, n4, n5;
    while(cin >> n1 >> n2 >> n3 >> n4 >> n5){
        matriz aux;
        for(int i = 0; i < 5; i++){
            vector<numeros> aux2;
            numeros l = {n1, false};
            aux2.push_back(l);
            l = {n2, false};
            aux2.push_back(l);
            l = {n3, false};
            aux2.push_back(l);
            l = {n4, false};
            aux2.push_back(l);
            l = {n5, false};
            aux2.push_back(l);
            aux.push_back(aux2);

            if(i != 4) cin >> n1 >> n2 >> n3 >> n4 >> n5;
        }
        m.push_back(aux);
    }

    bool ganha = false;
    int total = m.size();
    int posGanhou = -1;
    int ultimo = -1;
    int posUltimo = -1;
    int totalGanhou = 0;



    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < m.size(); j++){
            marcaNumero(m[j], v[i]);
            if(ganhou(m[j])){
                totalGanhou++;
                if(totalGanhou == total){
                    ganha = true;
                    posGanhou = j;
                    ultimo = v[i];
                    posUltimo = i;
                    break;
                }
                else{
                    m.erase(m.begin() + j);
                    j--;
                }
                
            }
            cout << "Ganhou: " << totalGanhou << " ATUAL: " << v[i] << endl;
        }
        if(ganha) break;
    }

    long marcados = 0;

    cout << posGanhou << " " << ultimo << endl;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!m[posGanhou][i][j].marcado) marcados+=m[posGanhou][i][j].num;
        }
    }

    cout << marcados * ultimo << endl;
    cout << marcados << " " << ultimo << endl;



}