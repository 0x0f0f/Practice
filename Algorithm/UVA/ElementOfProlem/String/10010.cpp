#include<iostream>

using namespace std;

char ans[100][100];

int length(char arr[]){
    int len = 0;
    while(arr[len] != '\0')
        len++;
    return len;
}

void solve(int x, int y, int len){
}

int main(){
    int cases;
    int m,k,z;
    int x,y;
    char query[100];
    cin>>cases;

    for(int i = 0; i < cases; i++){

        for(int mm = 0; mm < 100; mm++){
            for(int nn = 0; nn < 100; nn++){
                ans[mm][nn] = '\0';
            }
            query[mm] = '\0';
        }
        cin>>x>>y;
        for(int j = 0; j < x; j++){
            for(int k = 0; k < y; k++){
                cin>>ans[j][k];
            }
        }

        cin>>z;
        for(int kk = 0; kk < z; kk++){
            cin>>query;
            int len = length(query);
            for( int mm = 0; mm < x; mm++){
                for(int nn = 0; nn < y; nn++){
                    for(int zz=0; zz <len; zz++){
                        if(query[zz] == ans[mm][nn]){

                        }
                    }
                }
            }
        }
    }
}
