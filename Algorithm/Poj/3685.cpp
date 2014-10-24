#include<iostream>

using namespace std;

int buildMatrix(int ans[][11], int m,  int n){
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                ans[i][j] = i * i + 100000 * i + j * j - 100000 * j + i * j;
            }
        }
        return 1;
}

void print(int ans[][11], int x, int y) {
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int ans[11][11] = {0};

    buildMatrix(ans, 10, 10);
    print(ans, 10, 10);

}
