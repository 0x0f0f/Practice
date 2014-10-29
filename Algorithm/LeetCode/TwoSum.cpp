#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct node{
    int index;
    int value;
};

static bool nodeBigger(node a, node b){
    return a.value < b.value;
}


vector<int> twoSum(vector<int> vec, int target){
    int start=0, iend=vec.size()-1;
    vector<node> tmp;
    vector<int> result;

    for(int i = 0; i <= iend; i++){
        node n = {i, vec[i]};
        //cout<<n.index<<" "<<n.value<<endl;
        tmp.push_back(n);
    }

    sort(tmp.begin(), tmp.end(), nodeBigger);

    while(start < iend) {
        if(tmp[start].value + tmp[iend].value == target) {
            if(tmp[start].index > tmp[iend].index){
                result.push_back(tmp[iend].index + 1);
                result.push_back(tmp[start].index + 1);
            }else {
                result.push_back(tmp[start].index + 1);
                result.push_back(tmp[iend].index + 1);
            }
            break;
        } else if( tmp[start].value + tmp[iend].value > target ) {
            iend--;
        }else {
            start++;
        }
    }
    return result;
}

int main() {
    vector<int> vec = {2,5,11,13};
    vector<int> result1;
    vector<int> result2;
    vector<int> unsorted = {3,2,4};
    vector<int> result3;
    vector<int> unsorted1 = {3,75,25};
    vector<int> result4;

    result1 = twoSum(vec, 7);
    cout<<result1[0]<<" "<<result1[1] <<endl;
    result2 = twoSum(vec, 13);
    cout<<result2[0]<<" "<<result2[1] <<endl;
    result3 = twoSum(unsorted, 6);
    cout<<result3[0]<<" "<<result3[1] <<endl;
    result4 = twoSum(unsorted1, 100);
    cout<<result4[0]<<" "<<result4[1] <<endl;

}


