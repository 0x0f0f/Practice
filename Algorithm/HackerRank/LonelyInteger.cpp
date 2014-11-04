#include<iostream>
#include<vector>

using namespace std;


int odd(vector<int> ans) {
    int cnt = ans[0];
    int sz = ans.size();
    for(int i = 1; i < sz; i++) {
        cnt = cnt ^ ans[i];
    }
    return cnt;
}

int main() {
    int n;
    int tmp;
    vector<int> ans;
    cin>>n;
    for(int i = 0;i < n; i++){
        cin>>tmp;
        ans.push_back(tmp);
    }

    cout<<odd(ans);
}
