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

const int N = 1e5 +3;
const int inf = 1e9+7;
int n,v;
vector<vector<int>> adj[N];  // destination , weight
int cost=0;
vector<int> dist(N), parent(N);
vector<bool> vis(N);


void dijkstra(int source){
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[source]=0;
    set<vector<int>> s;
    s.insert({0,source}); // weight node
    while(!s.empty()){
        auto x= *(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];

        for(auto it: adj[u]){   // it -> dest, weight
            if(vis[it[0]]){
                continue;
            }

            if(dist[it[0]] > (it[1]+dist[x[1]])){
                s.erase({dist[it[0]], it[0]});
                s.insert({it[1]+dist[x[1]], it[0]});
                dist[it[0]]=it[1]+dist[x[1]];
                parent[it[0]] = x[1];
            }
        }

    }

}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    cin>>n>>v;
    int e1,e2,w;
    for(int i=0;i<v;i++){
        cin>>e1>>e2>>w;
        adj[e1].pb({e2,w}); // destination , weight
        adj[e2].pb({e1,w});
    }
    int source;
    cin>>source;

    dijkstra(source);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }br;
}
