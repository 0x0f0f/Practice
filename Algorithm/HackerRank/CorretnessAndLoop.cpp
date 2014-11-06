#include<iostream>

using namespace std;

int ans[10005];

int insertSort(int ans[], int sz) {
    int cnt = 0;
    int j;

    for(int i = 1; i < sz ; i++) {
        if(ans[i] < ans[i - 1]){
            int tmp = ans[i];
            for( j = i-1; j >= 0 && ans[j] > tmp; j-- ) {
                ans[j+1] = ans[j];
                cnt +=1;
            }
            ans[j+1] = tmp;
        }
    }
    return cnt;
}

int main() {
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
        cin>>ans[i];
    insertSort(ans, N);
    for(int i = 0; i < N; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
