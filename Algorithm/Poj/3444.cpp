#include<iostream>

using namespace std;

int ans[260];

int log2(int n){
    if(n == 1)
       return 0;
    else 
        return 1 + log2(n>>1);
}

int main(){
    int N;

    cin>>N;
    if(N > 0) {
        for(int i = 1; i <=N; i++){
            cin>>ans[i];
        }
        int k = log2(N);
        cout<<k<<endl;
        for(int j=1; j<=k; j++ ){
            for(int i=1; i <= j; i++){
                int tmpa = (ans[i] + ans[i + (1<<(j-1))])/2;
                int tmpb = (ans[i] - ans[i + (1<<(j-1))])/2;
                ans[i] = tmpa;
                ans[i+1]  = tmpb;
                cout<<"i:"<<i<<" "<<tmpa<<" "<<tmpb<<"|";
                cout<<"j:"<<i+(1<<(j-1))<<"|";
            }
        cout<<endl;
        }

        for(int i = 1; i <= N; i++ ){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
