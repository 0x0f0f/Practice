#include<iostream>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x > y ? y : x;
}

int losawlc(int arr[], int sz) {
    int mn, mx, max_len = 1;
    for(int i = 0; i < sz - 1; i++) {
        mn = arr[i];
        mx = arr[i];
        for(int j = i + 1; j < sz; j++) {
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            if( mx - mn == j - i ) {
                max_len = max(max_len, j - i + 1);
            }

        }
    }
    return max_len;
}

int main() {
    int ans_a[4] = {1, 2, 3, 5};
    int ans_b[7] = {1, 2, 4, 5, 6, 7, 9 }; 

    cout<<losawlc(ans_a, 4) <<endl;
    cout<<losawlc(ans_b, 7) <<endl;
}
