#include<iostream>

using namespace std;

int digit(int n){
    int cnt = 0;
    if(n == 0)
        return 1;

    while(n > 0){
        n = n/10;
        cnt +=1;
    }
    return cnt;
}

int main(){
    int a = 123;
    int b = 123456;

    cout<<(digit(a) == 3) <<endl;
    cout<<(digit(b) == 6) <<endl;
    cout<<(digit(0) == 1) <<endl;
}
