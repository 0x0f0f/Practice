#include<iostream>
#include<vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int max3(int x, int y, int z ) {
    return max(x, max(y,z));
}

int min(int x, int y) {
    return x > y ? y : x;
}

int min3(int x, int y, int z) {
    return min(min(x, y), z);
}


int FindMaxProduct(int A[], int n) {
    int imin,imax,zmax = 0;
    imin = imax = A[0];
    zmax = A[0];
    for(int i = 1; i < n; i++) {
        int tMax = imax * A[i];
        int tMin = imin * A[i];
        imax = max3(tMax, tMin, A[i]);
        imin = min3(tMax, tMin, A[i]);
        zmax = max(zmax, imax);
    }
    return zmax;
}

int main() {
    int A[] = { 2,3,-3,3 };
    int B[] = { 2,-3,-3,3 };
    int C[] = { 2 };

    cout << FindMaxProduct(A, 4) <<endl;
    cout << FindMaxProduct(B, 4) <<endl;
    cout << FindMaxProduct(C, 1) <<endl;
}

