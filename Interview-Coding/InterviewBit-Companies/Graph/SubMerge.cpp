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

const int SIZE = 1e4+10;
vector<int> adj[SIZE];
vector<int> in(SIZE), low(SIZE);
vector<bool> vis(SIZE);
int timer; 
set<int> sol;


void dfs(int cur, int par=-1){
    vis[cur]=true;
    in[cur] = low[cur] =timer;
    timer+=1;
    
    int children = 0;

    for(int i: adj[cur]){
        if(i==par) continue;
        if(vis[i]){
            low[cur] = min(low[cur], in[i]);
        }else{
            dfs(i,cur);
            low[cur] = min(low[cur],low[i]);
            if(in[cur] <= low[i] and par!=-1){
                sol.insert(cur);
            }
            children+=1;
        }
    }

    if(par==-1 and children>1){
        sol.insert(cur);
    }

}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int t1,t2;
    t1=1, t2=1;
    while(t1!=0 and t2!=0){
        cin>>t1>>t2;
        if(t1==0 and t2==0){
            break;
        }
        timer = 0 ;
        sol.clear();
        for(int i=0;i<=t1;i++){
            adj[i].clear();
            in[i] = 0;
            low[i] = 0;
            vis[i] =false;
        }
        
        int e1,e2;
        while(t2--){
            cin>>e1>>e2;
            adj[e1].pb(e2);
            adj[e2].pb(e1);
        }

        dfs(1);

        cout<<sol.size();br;

    }
}
