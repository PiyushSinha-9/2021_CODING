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


vector<int> level(SIZE);
int branch = INT_MIN;

set<int> sol;

int gcd2(int a, int b)
{
    if (b == 0)
        return a;
    return gcd2(b, a % b);
     
}


void bfs(int cur){
    int lev = 0;

    int curLev = 1;
    int next =0;
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        level[top] =lev;

        branch = max(branch, level[top]);

        for(int i:adj[top]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                next+=1;
            }
        }

        curLev-=1;
        if(curLev==0){
            curLev = next;
            next=0;
            lev+=1;
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
        cin>>n;
        sol.clear();
        for(int i=0;i<=n;i++){
            adj[i].clear();
            level[i] = 0;
            visited[i] = false;
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

        int valkk = INT_MAX;
        int startpoint;

        for(int i=1;i<=n;i++){
            if(prices[i] < valkk){
                valkk=prices[i] ;
                startpoint = i;
            }
        }


        bfs(startpoint);

        dbg(branch)

        int lastSol = 0;
        int tempSol = 0;

        int t1=-1, t2=-1,tt;

        for(int i=1;i<=n;i++){
            if(level[i] < branch-1){
                tempSol = gcd2(tempSol, prices[i]);
            }
        }

        for(int i=1;i<=n;i++){
            if(level[i] == branch-1){

                int templastSol = 0;
                int tempt1=-1;
                int tempt2=-1;
                for(int j:adj[i]){
                    if(level[j] == branch){
                        templastSol += prices[j];
                    }
                    if(tempt1==-1){
                        tempt1 = j;
                    }else{
                        tempt2 = j;
                    }
                }

                if(lastSol < templastSol){
                    lastSol = templastSol;
                    t1 = tempt1;
                    t2 = tempt2;
                    tt = i;
                }

            }
        }

        for(int i=1;i<=n;i++){
            if(level[i]==branch-1 and i!=tt){
                tempSol = gcd2(tempSol, prices[i]);
            }

            if(level[i]==branch and i!=t1 and i!=t2){
                tempSol = gcd2(tempSol, prices[i]);
            }
        }   

        dbg(level)
        dbg(lastSol)
        dbg(tempSol)
        dbg(t1)
        dbg(t2)
        dbg(tt)


        cout<<lastSol+tempSol;
        br;




   }
    
}
