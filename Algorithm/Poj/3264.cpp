#include<iostream>

using namespace std;

const int maxn=50;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x > y ? y : x;
}

class node {
    public:
        int nMin, nMax;
};

node tree[maxn*4];
int ans[maxn];

void build(int p, int l, int r) {
    if(l == r){
        tree[p].nMin = tree[p].nMax = ans[l];
    }
    int mid = (l + r)/2;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    tree[p].nMin = min(tree[p<<1].nMin, tree[p<<1|1].nMin);
    tree[p].nMax = max(tree[p<<1].nMax, tree[p<<1|1].nMax);
}

int findDiff(int p, int l, int r, int a, int b, bool bMin){
    if(l == a && b == r)
        return p;
    int mid = (l + r)/2;
    if(b <= mid){
        return findDiff(p<<1, l, mid, a, b, bMin);
    } else if(mid+1<=a) {
        return findDiff(p<<1|1, mid+1, r, a, b, bMin);
    } else {
        int p1  = findDiff(p<<1, l,mid, a, mid, bMin);
        int p2  = findDiff(p<<1|1, mid+1,r,mid+1,b, bMin);
        if(bMin)
            return tree[p1].nMin < tree[p2].nMin ? p1 : p2;
        else
            return tree[p1].nMax > tree[p2].nMax ? p1 : p2;
    }
}

int main(){
    int N, Q;
    int A, B;

    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>>ans[i];
    }

    build(1,1,N);
/*
    for(int j = 1; j <= Q; j++){
        cin>>A>>B;
        int pmax = findDiff(1,1,N,A,B,false);
        int pmin = findDiff(1,1,N,A,B, true);
        cout<<pmax-pmin<<endl;
    }*/
}
