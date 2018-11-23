#include<bits/stdc++.h>
using namespace std;

 int main() {
    int a,b;
    cin>>a;
    for(int i =a; i > 0; i--) {
        for(int j =0; j < i-1; j++) {
            cout<<" ";
        }
        for(int j = 1; j < 2*(a-i+1);j++ )cout<<"*";
        for(int j =0; j < i-1; j++) {
            cout<<" ";
        }
        cout<<"\n";
    }


}
