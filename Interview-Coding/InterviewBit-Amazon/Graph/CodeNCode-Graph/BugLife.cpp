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

const int SIZE = 1e4+3;
vector<int> adj[SIZE];
vector<int> color(SIZE);
vector<bool> vis(SIZE);
int n,e;

bool dfs(int node, int col){
    vis[node] =true;
    color[node] = col;

    for(int i: adj[node]){
        if(!vis[i]){
            if(!dfs(i,col^1)){
                return false;
            }
        }else{
            if(color[i] == color[node]){
                return false;
            }
        }
    }

    return true;
}

signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int testCase;
    cin>>testCase;
    int noOfCase = 1;
    while(testCase--){

        cin>>n>>e;

        for(int i=0;i<=n;i++){
            adj[i].clear();
            color[i] = -1;
            vis[i] = false;
        }
        int e1,e2;
        for(int i=0;i<e;i++){
            cin>>e1>>e2;
            adj[e1].pb(e2);
            adj[e2].pb(e1);
        }

        cout<<"Scenario #"<<noOfCase<<":";br;

        bool flagger =true;

        for(int i=1;i<=n;++i){
            if(!vis[i]){
                if(!dfs(i,0)){
                    flagger=false;
                }
            }
        }

        if(flagger){
            cout<<"No suspicious bugs found!";
        }else{
            cout<<"Suspicious bugs found!";
        }
        br;

        noOfCase+=1;

    }
}
