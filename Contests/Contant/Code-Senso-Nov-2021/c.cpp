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

const int SIZE = 1e5+2;

int n; // number of nodes
vector<int> adj[SIZE] ; // adjacency list of graph

vector<bool> visited(SIZE);
vector<int> tin(SIZE), low(SIZE);
vector<int> prices(SIZE);
int timer;

set<int> sol;

void IS_CUTPOINT(int num){
    sol.insert(num);
}


void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;

    for(int i=0;i<=n;i++){
        visited[i] = false;
        tin[i] = -1;
        low[i] =-1;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}


vector<int> parent(SIZE);
vector<int> ranking(SIZE);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ranking[v] = 0;
}

void union_sets(int a, int b) {
    // a = find_set(a);
    // b = find_set(b);
        parent[a] = b;
    
}

void dfs2(int cur, int par = -1){
    visited[cur] = true;
    for(int i:adj[cur]){
        if(i!=par and !visited[i]){
            union_sets(i, cur);
            dfs2(i, cur);
        }
    } 
}

int gcd2(int a, int b)
{
    if (b == 0)
        return a;
    return gcd2(b, a % b);
     
}

int solgcd = INT_MIN;
int solpoint;

int helper(int cur,int &tempGCD, int par=-1){
    visited[cur] =true;
    
    if(adj[cur].size() == 1){
        return prices[cur];
    }

    int tempsol = 0;
    int tempAllSol = 0;

    for(int i: adj[cur]){
        if(!visited[i]  and i!=par){
            tempsol += helper(i, tempAllSol ,cur);

            if(tempsol > solgcd){
                solgcd = tempsol;
                solpoint =cur;
            }
        }
    }

    tempGCD = gcd2(tempGCD, tempAllSol);
    return tempsol;
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
        cin>>n;
        sol.clear();
        for(int i=0;i<=n;i++){
            adj[i].clear();
            make_set(i);
        }

        int e1,e2;
        for(int i=0;i<n-1;i++){
            cin>>e1>>e2;
            adj[e1].pb(e2);
            adj[e2].pb(e1);
        }   

        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            prices[i] =temp;
        }

        // all(sol)
        // helper(1,)


        for(int i=0;i<=n;i++){
            visited[i] = false;
        }

        int allSolution;
        helper(1, allSolution);

        cout<<allSolution<<" "<<solgcd<<" "<<solpoint;

        // find_cutpoints();
        // dbg(sol)


        // for(int i=0;i<=n;i++){
        //     visited[i] = false;
        // }

        // dfs2(1);

        // for(int i=0;i<=n;i++){
        //     cout<<parent[i]<<" ";
        // }
        

   }
    
}
