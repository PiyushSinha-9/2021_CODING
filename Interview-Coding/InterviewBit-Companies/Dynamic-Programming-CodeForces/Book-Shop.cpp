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

int dp[100007][1007];

int knapsack(int n, int k, vector<int> price, vector<int> page){
    if(n<1){
        return 0;
    }

    if(k <= 0){
        return 0;
    }
    
    if(dp[n][k]!=0){
        return dp[n][k];
    }

    int sol = 0;

    if(k >= price[n-1]){
        sol = max(knapsack(n-1,k,price,page), page[n-1] + knapsack(n-1,k-price[n-1],price,page));
    }else{
        sol = knapsack(n-1,k,price,page);
    }   

    return dp[n][k] = sol;
}


int knapsackTable(int n, int k, vector<int> price, vector<int> page){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i >= price[j-1]){
                dp[i][j] = max(dp[i][j-1], page[j-1] + dp[i-price[j-1]][j-1]);
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[k][n];
}

void helper(){
    int n, x;
  cin >> n >> x;
  vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if (left >= 0) {
	dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
}

signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

//     int n, k;
//     cin>>n>>k;

//     memset(dp,0,sizeof(dp));

//     vector<int> price(n), page(n);
//     for(int &i:price){
//         cin>>i;
//     }

//     for(int &i:page){
//         cin>>i;
//     }

//   //  cout<< knapsack(n,k,price,page);

//    cout<<knapsackTable(n,k,price,page);
//     br; br;
//    for(int i=0;i<=11;i++){
//         for(int j=0;j<=7;j++){
//             cout<<dp[i][j]<<" ";
//         }
//         br;
//    }

helper();

}
