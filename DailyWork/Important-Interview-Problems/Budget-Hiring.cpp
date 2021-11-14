/* Auther -: Piyush Sinha */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i=0; i<(n); i++)
#define repa(i, a, n) for(int i=(a); i<=(n); i++)
#define br cout<<"\n"
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define FILE_READ freopen("input.txt","r",stdin), freopen("output.txt","w",stdout), freopen("error.txt","w",stderr);


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define dbg(x...)
#endif


//############################################################

// #define int long long


class node{
    public:
    int num;
    int skill;
    int salary;
};

const int SIZE = 1e5+1;
vector<int> adj[SIZE];
vector<bool> vis(SIZE);


void dfs(int cur,vector<node> peo, int &skil, int &count){
    vis[cur] = true;
    count+= peo[cur-1].salary;
    skil+=peo[cur-1].skill;
    for(int i:adj[cur]){
        if(!vis[i]){
            dfs(i, peo, skil, count);
        }
    }
}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ
    #endif

    //######################

   int testCase;
   cin>>testCase;

   while(testCase--){
        int n,q,b;
        cin>>n>>q>>b;


        vector<node> peo(n);

        int t1,t2;
        for(int i=0;i<n;i++){
            cin>>t1>>t2;
            peo[i].skill = t1;
            peo[i].salary =t2;
            peo[i].num = i+1;

            adj[i].clear();
            vis[i] = false;
        }
        adj[n].clear();
        vis[n] = false;
        for(int i=0;i<q;i++){
            cin>>t1>>t2;
            adj[t1].pb(t2);
            adj[t2].pb(t1);
        }

        vector<int> dp, dps;

        for(int i=1 ; i<=n;i++){
            if(!vis[i]){
                int count =0, skil = 0;
                dfs(i, peo,skil, count);
                dp.pb(count);
                dps.pb(skil);
                dbg(count);
                dbg(skil);
            }
        }


    int i, w;
    n= dp.size();
    vector<vector<int>> K(dp.size() + 1, vector<int>(b + 1));
 
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= b; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (dp[i - 1] <= w)
                K[i][w] = max(dps[i - 1] +
                                K[i - 1][w - dp[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    cout<< K[n][b];


   }
    
}
