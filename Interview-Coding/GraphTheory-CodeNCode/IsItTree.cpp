//https://www.spoj.com/problems/PT07Y/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;



#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define check_ cout<<"yo\n";

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

const int MV = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################

#define MAXNODES 100000

vector<int> adj[MAXNODES];
vector<int> vis(MAXNODES,0);
vector<int> dis(MAXNODES,0);


void dfs(int start, int dist=1){
    vis[start]=1;
    for(int i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    int n,e;
    cin>>n>>e;

    int e1,e2;
    for(int i=0;i<e;i++){
        cin>>e1>>e2;
        adj[e1].pb(e2);
        adj[e2].pb(e1);
    }

    bool check = true;
    if(e!=n-1){
        cout<<"NO";
    }else{
         int sol=0;
         int start=1;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i), sol+=1;
                if(sol>1){
                    cout<<"NO";
                    return 0;
                }
            }
        }

        cout<<"YES";
        return 0;
    }


}