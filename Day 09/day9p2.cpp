#include <bits/stdc++.h>
using namespace std;

vector <long long> v;
long basin = -1;

bool isSafe(int i, int j, vector <string> s, vector<vector<bool>> &visited)
{
    return (i >= 0 && i < s.size() && j >= 0 && j < s[0].size() && s[i][j] != '9' && visited[i][j] == false);
}

void DFS(vector <string> &s, int i, int j, vector<vector<bool>> &visited)
{
    static int row[] = {-1, 0, 0, 1};
    static int col[] = {0, -1, 1, 0};

    visited[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        if (isSafe(i + row[k], j + col[k], s, visited))
        {
            DFS(s, i + row[k], j + col[k], visited);
            v[basin]++;
        }
    }
}

int main(){
    vector <string> s;
    string str;

    while(cin >> str){
        s.push_back(str);
    }
    
    vector <vector <bool> > dp(s.size(), vector <bool> (s[0].size(), false));

    unsigned long long sum = 0, qt = 0;

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].size(); j++){
            if(s[i][j] != '9' && dp[i][j] == false){
                qt++;
                basin++;
                v.push_back(1);
                DFS(s, i, j, dp);
            }
        }
    }
    sort(v.begin(), v.end(), greater<long long>());
    cout << v[0] * v[1] * v[2] << endl;
    
}