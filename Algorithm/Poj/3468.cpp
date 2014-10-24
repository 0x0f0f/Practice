#include<iostream>

using namespace std;

int ans[100002] = {0};
int sum[100002] = {0};

int main() {
    int N, Q, a,b,c;
    char query;

    cin>>N>>Q;
    for(int i = 0; i<N; i++) {
        cin>>ans[i];

        if(i == 0 ){
            sum[i] = ans[i];
        } else {
            sum[i] = sum[i-1] + ans[i];
        }
    }

    for(int j = 0; j < Q; j++){
        cin>>query;
        if( query == 'Q' ){
            cin>>a>>b;
            cout<<sum[b-1] - sum[a-2]<<endl;
        } else if( query == 'C' ) {
            cin>>a>>b>>c;
            for(int i = a -1; i < b - 1; i ++){
                ans[i] += c;
            }
            for(int i = a - 1; i < N; i++){
                sum[i] = sum[i - 1] + ans[i];
            }
        }
    }
}
