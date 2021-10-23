#include<bits/stdc++.h>
using namespace std;
 
#define br cout<<"\n"

const int SIZE = 500001;
const int MOD = 1e9+7;


vector<int> adj[SIZE];
vector<int> vis(SIZE); 


void dfs(int start, int &count){
    vis[start]=1;
    count+=1;

    for(int i: adj[start]){
        if(!vis[i]){
            dfs(i,count);
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int testCase;
    cin>>testCase;
    while(testCase--){
        int n,v;
        cin>>n>>v;

        for(int i=1;i<n+1;i++){
            adj[i].clear();
            vis[i]=0;
        }

        int x,y;
        for(int i=0;i<v;++i){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int ans1 =0,count=0; 
        long long int ans2 =1;

        for(int i=1;i<n+1;i++){
            
            if(!vis[i]){
                ans1+=1;
                count=0;
                dfs(i,count);
                ans2=(ans2* count)%MOD;
            }
        }

        cout<<ans1<<" "<<ans2<<"\n";

    }


}