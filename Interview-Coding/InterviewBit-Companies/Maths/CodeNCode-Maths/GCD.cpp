#include <bits/stdc++.h>
using namespace std;

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

//######################################################

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int GCD_Iterative(int a, int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b= temp;
    }
    return a;
}

signed main() {
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int testCase;
    cin>>testCase;

    while(testCase--){
        int a, b;
        cin>>a>>b;
        cout<<gcd(a,b)<<"   "<<GCD_Iterative(a,b);
        cout<<endl;
    }
    
}
