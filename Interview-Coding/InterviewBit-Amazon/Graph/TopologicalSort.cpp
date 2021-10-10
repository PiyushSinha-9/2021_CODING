//https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	
	void dfs(int cur, vector<bool> &vis, stack<int> &s, vector<int> adj[]){
	    vis[cur]=true;
	    for(int i:adj[cur]){
	        if(!vis[i]){
	            dfs(i,vis,s,adj);
	        }
	    }
	    s.push(cur);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> sol;
	    stack<int> s;
	    vector<bool> vis(V, false);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i, vis, s, adj);
	        }
	    }
	    
	    
	    while(!s.empty()){
	        sol.push_back(s.top());
	        s.pop();
	    }
	    
	    
	    return sol;
	    
	}
};