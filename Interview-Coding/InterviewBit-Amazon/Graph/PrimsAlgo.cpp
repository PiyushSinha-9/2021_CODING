// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    const int inf=1e5+7;    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int totalSum=0;
        vector<int> dist(V,inf);
        vector<bool> vis(V,false);
        vector<int> parent(V);
        dist[0] = 0;
        set<pair<int,int>> s;
        s.insert({0,0});    // {Weight,secondEdge }
        vis[0]=true;
        parent[0]=-1;
        
        while(!s.empty()){
            auto up = *(s.begin());
            s.erase(up);
                
            int u=up.second;
            int w=up.first;
            int v=parent[u];
            
            vis[u]=true;
            
            for(auto it: adj[u]){
                int v1= it[0] ;
                if(!vis[v1]){
                    if(dist[v1] > it[1]){
                        s.erase({dist[v1] , it[0]});
                        s.insert({it[1],it[0]});
                        dist[it[0]]=it[1];
                        parent[it[0]] = u;
                    }
                }
            }
            
        }   
        
        
        for(int i:dist){
            totalSum+=i;
        }
        
        return totalSum;
    }
};