#include<iostream>
#include<algorithm>

using namespace std;

/*这道题注意要用long 整形，防止中途溢出*/

long sumDivBy(int N, int p) {
    long cnt = N / p;
    long  sum  = 0;
    if(N == 3)
        return 3;
    if ( cnt % 2 == 0 )
        sum = p * cnt / 2L * (cnt + 1);
    else
        sum = p * (cnt + 1) / 2L * cnt;
    return sum;
}

int main(){
    int T, N;

    cin>>T;
    for(int i = 1; i <= T; i++){
        cin>>N;
        long sum = 0;
        sum = sumDivBy(N -1, 3) - sumDivBy(N - 1, 15) + sumDivBy(N - 1, 5);
        cout<<sum<<endl;
    }
}
