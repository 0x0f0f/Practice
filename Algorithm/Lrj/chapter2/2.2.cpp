#include<iostream>

using namespace std;

void doffodil(){
    int sum = 0;

    for(int i=100; i<=999; i++){
        sum = 0;
        int start = i;
        while(start > 0){
            int digit = start % 10;
            sum += digit * digit * digit;
            start = start / 10;
        }
        if( i == sum )
            cout<<i<<endl;
    }
}

int main() {
    doffodil();
}
