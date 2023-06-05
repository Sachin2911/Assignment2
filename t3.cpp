#include <iostream>
using namespace std;
#include <vector>

void setter(int row, int col, vector<vector<int>> vec, int value){
    vec[row][col] = value;
}

int main(){
    int cols;
    int rows;

    //snake
    int shx;
    int shy;
    int sbx;
    int sby;
    int stx;
    int sty;

    //apple
    int xapp;
    int yapp;
    cin >> cols >> rows;
    cin >> xapp >> yapp;

    vector<vector<int>> vect(rows,vector<int>(cols, 0));
    vect[yapp][xapp] = 5;

    int numsnakes;
    cin >> numsnakes;
    for(int i=1; i<numsnakes+1; i++){
        cin >> shx >> shy >> sbx >> sby >> stx >> sty;
        vect[shy][shx] = i;
        vect[sby][sbx] = i;
        vect[sty][stx] = i;
    }
    for(int i = 0; i<vect.size(); i++){
       for(int j = 0; j<vect[0].size(); j++){
        cout << vect[i][j] << " ";
    } 
        cout << endl;
    }

    return 0;
}