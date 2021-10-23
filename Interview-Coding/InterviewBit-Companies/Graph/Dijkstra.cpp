//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    const int inf = 1e9+7;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int> dist(V,inf);
        vector<int> parent(V);
        vector<bool> vis(V,false);
        set<pair<int,int>> s;   // {weight, edge}
        
        s.insert({0,S});
        dist[S] = 0;
        
        while(!s.empty()){
            auto up = *(s.begin());
            s.erase(up);

            int w = up.first;
            int u=up.second;
            vis[u] = true;

            
            for(auto i:adj[u]){
                if(vis[i[0]]){
                   continue; 
                }
                int v=i[0];
                
                if(dist[v] > i[1] + dist[u]){
                    s.erase({dist[v],v});
                    s.insert({i[1]+dist[u] , v});
                    parent[v] = u;
                    dist[v] = i[1] + dist[u];
                }
            }
            
            
        }
        
        return dist;
        
                
    }
};
