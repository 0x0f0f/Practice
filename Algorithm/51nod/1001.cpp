#include<iostream>
#include<algorithm>


using namespace std;

int ans[50005];

int main(){
    
    int k,n;
    int low,high;
    int flag = 0;
    cin>>k>>n;

    for(int i = 0; i<n; i++) {
        cin>>ans[i];
    }
    sort(ans, ans+n);
    low = 0;
    high = n -1;
    while(low < high) {
        if(ans[low] + ans[high] == k){
            cout<<ans[low]<<" "<<ans[high]<<endl;
            flag = 1;
            low++;
            high--;
        } else if( ans[low] + ans[high] > k ) {
            high--;
        } else if(ans[low] + ans[high] < k){
            low++;
        }
    }
    if(flag == 0) {
        cout<<"No Solution"<<endl;
    }

}
