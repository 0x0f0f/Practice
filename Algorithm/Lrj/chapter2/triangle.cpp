#include<iostream>

using namespace std;
/*this is a synmetirc problem, first conpute the left part,then the right part*/
void print(int n){
    int row,colum;
    for(row = 1; row <= n; row++){
        for(colum = 1; colum <= n ; colum++){
            if(row <= colum ) {
                cout<<"#";
            } else {
                cout<<" ";
            }
        }
        for(colum = 1; colum <= n-1; colum++){
            if(n - colum >= row)
                cout<<"#";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    print(5);
}
