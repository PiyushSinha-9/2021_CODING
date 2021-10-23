const int SIZE = 1e5;
vector<int> tadj[SIZE];
stack<int> s;
vector<bool> vis(SIZE);

class Solution
{
	public:
	
	void dfs1(int cur, vector<int> adj[]){
        vis[cur]=true;
        
        for(int i:adj[cur]){
            if(!vis[i]){
                dfs1(i,adj);
            }
        }
            
            s.push(cur);
    }
    
    
    
    void dfs2(int cur){
        vis[cur]=true;
         for(int i:tadj[cur]){
            if(!vis[i]){
                dfs2(i);
            }
        }
        
    }

	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        for(int i=0;i<V;i++){
            tadj[i].clear();
            vis[i] =false;
        }
        
        
        for(int i=0;i<V;i++){
            int e1 = i;
            for(int e2:adj[i]){
                tadj[e2].push_back(e1);
            }
        }
        
        stack<int> temp;
        s = temp;
        
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs1(i, adj);
        }
        
        
        int sol=0;
        
        for(int i=0;i<V;i++){
            vis[i] =false;
        }
        
        
        while(!s.empty()){
            int up = s.top();
            s.pop();
            
            if(!vis[up]){
                sol+=1;
                dfs2(up);
            }
            
        }
        
        
        return sol;
        
    }
};
