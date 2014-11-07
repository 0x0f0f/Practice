#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct value{
    int mina;
    int minb;
};

bool lesser(value a, value b) {
    return a.mina < b.minb;
}

void ClosestNum(vector<int> ans, int sz) {
    int mina,minb;
    map<int, vector<value>> result;

    sort(ans.begin(), ans.end());
    mina = ans[0];
    minb = ans[1];
    for(int i =1; i < sz; i++){
        int tmpdiff = abs(minb - mina);
        if( abs(ans[i] - ans[i - 1]) <= tmpdiff) { // z注意保存相同的节点对
            int newkey = abs(ans[i] - ans[i - 1]);
            result[newkey].push_back({min(ans[i], ans[i-1]), max(ans[i], ans[i-1]) } );
        }/* else if(abs(ans[i] - ans[i-1] == tmpdiff)) {
            value tmpvalue;
            if(!result[tmpdiff].empty()){
                tmpvalue = result[tmpdiff].front();
            }
        }*/
    }

    /*可以优化，只保存最小的diff值，以及对应的vector, 这样就节约了一个map*/ 

    map<int, vector<value>>::iterator itr = result.begin();
    vector<value> x = itr->second;
    sort(x.begin(), x.end(), lesser);
    for(vector<value>::iterator it = x.begin(); it!= x.end(); it++) {
        cout<<(*it).mina<<" "<<(*it).minb<<" ";
    }
    cout<<endl;

}

int main() {
    int N;
    int tmp;
    vector<int> ans;

    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>tmp;
        ans.push_back(tmp);
    }

    ClosestNum(ans, N);

}
