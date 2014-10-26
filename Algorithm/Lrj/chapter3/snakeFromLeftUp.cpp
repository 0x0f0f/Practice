#include<iostream>

using namespace std;

int ans[100][100] = {0};

void PrintSnakeFromLeftUp(int n){
    int total = n*n;
    int i = 1, x, y,cnt = 1;
    int m = n;
    x = 1;
    y = 1;
    while(cnt < total){
        while(y <= m){
            ans[x][y++] = cnt++; 
        }
        while(x <= m){
            ans[++x][y] = cnt++;
        }
        while(y>=1){
            ans[x][--y] = cnt++;
        }
        while(x>=1){
            ans[--x][y] = cnt++;
        }
        m = n - 1;
        x = x+1;
        y = y+1;
        if(m <=0)
            break;
    }
}

void PrintMatrix(int matrix[][100], int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 5;
    PrintSnakeFromLeftUp(n);
    PrintMatrix(ans, n);
}
