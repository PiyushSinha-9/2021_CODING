const int SIZE = 1e5+10;

vector<int> in(SIZE), low(SIZE);
vector<bool> vis(SIZE), sta(SIZE);
int timer;
stack<int> s;
vector<vector<int>> sol;


void dfs(vector<int> adj[], int cur){
     vis[cur] = sta[cur] = true;
     in[cur] = low[cur] = timer;
     timer+=1;
     s.push(cur);
     
     for(int i: adj[cur]){
         if(vis[i] and sta[i]){
            low[cur] = min(low[cur], in[i]);    
         }else if(!vis[i]){
             dfs(adj,i);
            
             if(sta[i]){
                 low[cur] = min(low[cur], low[i]);   
             }
             
         }
     }
     
     if(in[cur] == low[cur]){
         vector<int> temp;
         while(1){
            int up = s.top();
            s.pop();
            temp.push_back(up);
            sta[up]=false;
            if(up==cur) break;
         }
         sort(temp.begin(), temp.end());
         sol.push_back(temp);
         
     }
     
     
}


class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        timer=0;
        stack<int> temps;
        s=temps;
        sol.clear();
        for(int i=0;i<V;i++){
            in[i] = low[i] = 0;
            vis[i]=false;
            sta[i]=false;
        }
        
        for(int i=0;i<V;i++)
        if(!vis[i])    dfs(adj,i);
    
        sort(sol.begin(), sol.end());
        return sol;
    }
};
