//https://www.spoj.com/problems/BUGLIFE/

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
vector<int> color(MAXNODES,-1);


bool dfs(int start, int col=0){
    vis[start]=1;
    color[start]=col;
    for(int i:adj[start]){
        if(!vis[i]){
            if(!dfs(i,col^1)){
                return false;
            }
        }else{
            if(color[start]==color[i]){
                return false;
            }
        }
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    int testCase;
    cin>>testCase;
    int temp =1;
    while(testCase--){
        int n,e;
        cin>>n>>e;

        for(int i=0;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
            color[i]=-1;
        }

        int e1,e2;
        for(int i=0;i<e;i++){
            cin>>e1>>e2;
            adj[e1].pb(e2);
            adj[e2].pb(e1);
        }

        cout<<"Scenario #"<<temp<<":";br;
        int start=1;

        bool flagger =true;

        for(int i=1;i<=n;++i){
            if(!vis[i]){
                if(!dfs(i)){
                    flagger=false;
                }
            }
        }

        if(flagger){
            cout<<"No suspicious bugs found!";br;
        }else{
            cout<<"Suspicious bugs found!";br;
        }

        temp+=1;
    }


}