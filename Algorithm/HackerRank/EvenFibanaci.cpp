#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

long FibSum(long N){
    long sum  = 0;
    long a = 1,b = 2;
    
    if(N == 1 )
        return 0;
    if(N == 2)
        return 2;
    sum = 2;
    while( a + b <= N ) {
        if( ( a + b ) % 2 == 0)
            sum += a + b;

        long tmp = a;
        a = b;
        b = tmp + b;
    }
    return sum;
}

int main() {
    long T, N;

    cin>>T;
    for(int i = 1; i <= T; i++) {
        cin>>N;
        cout<<FibSum(N)<<endl;
    }
}
