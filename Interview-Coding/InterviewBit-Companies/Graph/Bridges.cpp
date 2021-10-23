// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=1
int timer;
vector<int> in,low;
vector<bool> vis;


void dfs(vector<vector<int>> &adj,vector<vector<int>> &sol, int cur=0, int parent=-1){
	  	vis[cur] = true;
      	in[cur] = low[cur] =timer;
      	timer+=1;
    	
    	for(int i:adj[cur]){
            if(i==parent){
                continue;
            }
            
            if(vis[i]){
               low[cur] = min(low[cur], in[i]); 
            }else{
                dfs(adj,sol,i,cur);
                if(low[i] > in[cur]){
                   if(i<=cur)
                   		sol.push_back({i,cur});
                   else
                   		sol.push_back({cur,i});
               }
               low[cur] = min(low[cur], low[i]); 
            }
        }
    
}


void bridges(vector<vector<int>> &adj, int v ,vector<vector<int>> &sol){
	timer =0;
    
    in.clear();
    low.clear();
    vis.clear();
    in.resize(v,0);
    low.resize(v,0);
    vis.resize(v,false);
    
    dfs(adj,sol);
     
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
	vector<vector<int>> adj(v);
    vector<vector<int>> sol;
    
    
    if(e==0){
        return sol;
    }
    
    for(int i=0;i<e;i++){
        int e1=edges[i][0];
        int e2=edges[i][1];
        adj[e1].push_back(e2);
        adj[e2].push_back(e1); 
    }
  
    bridges(adj,v,sol);
    
    return sol;
}