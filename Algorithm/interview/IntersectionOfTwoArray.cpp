#include<iostream>
#include<queue>

using namespace std;

void intersection(int ans[], int asz, int bns[], int bsz, queue<int> &result) {
    int i = 0, j = 0;
    while( i< asz && j < bsz ) {
        if(ans[i] == bns[j]) {
            result.push(ans[i]);
            i++;
            j++;
        }else if (ans[i] < bns[j]) {
            i++;
        } else {
            j++;
        }
    }
}

void binarySearchIntersaction(int ans[], int asz, int bns[], int bsz, queue<int>& reuslt) {
    int i = asz -1 ;
    int j = bsz -1 ;
}

int main() {
    int ans[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int bns[4] = { 2,4,6,8 };
    queue<int> result;
    
    intersection(ans, 10, bns, 4, result);
    
    while( !result.empty() ) {
        cout<<result.front() <<endl;
        result.pop();
    }
    
}
