#include <bits/stdc++.h>
using namespace std;

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);



///  1 1 2 5 14

///  c4 = c0c3 + c1c2 + c2c1 + c3c0

/// (2n)!/[(n+1)!n!]


//######################################################


// Worst Solution

map<int,int> dp;

int catalanNum(int n){

    if(dp[n]!=0)
    return dp[n];

    if(n==1 or n==0){
        return 1;
    }
    int sol=0;
    for(int i=0;i<n;i++){
        sol += catalanNum(i) * catalanNum(n-i-1);
    }

    dp[n]=sol;

    return sol;
}



signed main() {
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################
    
    for(int i=0;i<20;i++){
        cout<<catalanNum(i)<<" ";
    }

}
