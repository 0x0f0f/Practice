#include<iostream>

using namespace std;

int ansHash[100];

int main() {
    int N,ans;
    string str;

    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>ans>>str;
        ansHash[ans] +=1;
    }
    for(int i = 1; i < 99; i++){
        ansHash[i] += ansHash[i-1];
    }

    for(int i = 0; i< 99; i++) {
        cout<<ansHash[i]<<" ";
    }
    cout<<endl;
}
