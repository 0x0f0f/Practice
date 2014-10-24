#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

int findMin(vector<int>& num) {
    int low = 0, high = num.size() - 1;
    int mid ;
    while(low <= high) { // 注意边界条件  [= 只有一个元素的时候]
        if(num[low] <= num[high])
            return num[low];
        if( high - low == 1)
            return min(num[high], num[low]);

        mid = (high + low) / 2;
        if(num[low] < num[mid] ) {
            low = mid ;
        } else if (num[low] > num[mid] ) {
            high = mid ;
        } 
    }
}

int main() {
    vector<int> case1 = {1,1,1,2,2};
    vector<int> case2 = {4,4,2,2,3};
    vector<int> case3 = {4,5,6,2,3};
    vector<int> case4 = {1};

    cout<<findMin(case1)<<endl;
    cout<<findMin(case2)<<endl;
    cout<<findMin(case3)<<endl;
    cout<<findMin(case4)<<endl;
}
