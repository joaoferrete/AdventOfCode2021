#include <bits/stdc++.h>
using namespace std;

long long flashes = 0;



bool is_valid(int x, int y) {
    return x >= 0 && y >=0 && x < 10 && y < 10;
}

void adjacent(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &blowed){
    const int _x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int _y[8] = {1, 1, 1, 0, 0, -1, -1, -1};

    blowed[x][y] = true;

    for(int i  = 0; i < 8; i++){
        if(is_valid(_x[i] + x, _y[i] + y)){
            grid[_x[i] + x][_y[i] + y] ++;
            if(grid[_x[i] + x][_y[i] + y] > 9 && !blowed[_x[i] + x][_y[i] + y]){
                adjacent(_x[i] + x, _y[i] + y, grid, blowed);
            }
        }
    }
}


int main(){
    vector<string> v(10);
    vector<vector<bool>> blowed(10, vector<bool>(10, false));
    vector <vector<int>> grid(10, vector<int>(10, 0));

    for(int i=0;i<10;i++){
        cin >> v[i];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            grid[i][j] = v[i][j] - '0';
        }
    }

    while(true){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                grid[j][k]++;
            }
        }
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(grid[j][k] > 9 && !blowed[j][k]){
                    adjacent(j, k, grid, blowed);
                }
            }
        }

        bool flag = true;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(blowed[j][k]){
                    grid[j][k] = 0;
                    blowed[j][k] = false;
                }
                if(grid[j][k] != 0) flag = false;
            }
        }
        flashes++;
        if(flag) break;

    }
    cout << flashes << endl;

}