int dfs(int node){
    vis[node] =1;
    int cur_size = 1;

    for(int child: adj[node]){
        if(!vis[child]){
            cur_size += dfs(child);
        }
    }

    subSize[node] =cur_size;
    return cur_size;
}