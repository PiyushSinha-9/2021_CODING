#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

#define pi (3.141592653589)
#define mod 1000000007
#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<endl
#define pb push_back
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define ff first
#define ss second
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

#pragma GCC target("popcnt")

//############################################################


const int inf = 1e9+7;
const int N = 1e3+3;

int dp[N][N];

int MatrixChain(vector<int> arr, int l, int r){
    if(l==r){
        return 0;
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    dp[l][r]=inf;

    for(int k=l;k<=r;k++){
        dp[l][r] = min(dp[l][r], MatrixChain(arr, l,k) + MatrixChain(arr, k+1,r) + arr[l-1] *arr[k] *arr[r]);
    }

    return dp[l][r];
}


int MCMTable(vector<int> arr, int n){
    
    memset(dp,0,sizeof(dp));

    for(int len=2;len<=n;len++){
        for(int i=1;i<n-len+1; i++){
            int j = i+len-1;
            
            dp[i][j] = inf;
            for(int k=i;k<=j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        br;
    }

    return dp[1][n-1];
}   



signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i:arr){
        cin>>i;
    }

    cout<<MatrixChain(arr,1,n-1);br;
    cout<<MCMTable(arr,n);

  


}
 