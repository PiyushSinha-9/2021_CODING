#include<bits/stdc++.h>
using namespace std;

#define br cout<<"\n"
#define SIZE 10001

vector<int> adj[SIZE], dist(SIZE);
vector<bool> vis(SIZE);
int v,e;

void bfs(int child){
    queue<int> q;
    q.push(child);
    vis[child]=1;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(int i:adj[top]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                dist[i] = dist[top] + 1;
                if(i==v){
                    break;
                }
            }
        }

    }

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCase;
    cin>>testCase;

    while(testCase--){
        cin>>v>>e;
        int x,y;

        for(int i=1;i<v+1;++i){
            adj[i].clear();
            vis[i] = false;
            dist[i] = 0;
        }


        for(int i=0;i<e;++i){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(1);         // starting is 3;

        cout<<dist[v];
        br;
    }


}
