#include<iostream>

using namespace std;
/*precision ：*/
double harmony(int n){
    double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += 1.0/i;
    }
    return sum;
}

int main(){
    int n = 3;
    cout.precision(3);
    cout<< fixed << harmony(n)<<endl;
}
