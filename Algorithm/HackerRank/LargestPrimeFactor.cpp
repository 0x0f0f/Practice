#include<iostream>
#include<cmath>


using namespace std;

bool isPrime(long n) {
    long sqrt_n = sqrt(n);
    if(n <=1)
        return false;
    for(long i = 2; i <= sqrt_n; i++ ) {
        if( n % i == 0 ) {
            return false;
        }
    }
    return true;
}

long LargestPrime(long n) {
    if(isPrime(n)) // if n is prime then itself is the largest prime
        return n;

    long sqrt_n = sqrt(n);
    for(long i = sqrt_n; i>1; i--) { // to reduce the iteration depth. For n = a * b, we can calculate a and b at same time
        if( n % i == 0 && (isPrime(i) || isPrime(n / i))) {
            if(isPrime(i) && isPrime(n / i))
                return max(i, n /i);
            else if(isPrime(n / i) && ( n / i > i ))
                return n / i;
            else 
                return i;
        }
    }
    return 0;
}

int main() {
    long N, T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cout<<LargestPrime(N)<<endl;
    }
}
