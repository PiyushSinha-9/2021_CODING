class Solution {
public:
    bool issafe(int x,int y,int n,int m)
    {
        return x>=0 and x<n and y>=0 and y<m;
    }
    int bfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&visited)
    {
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        visited[i][j]=true;
        int arr1[]={1,-1,0,0};
        int arr2[]={0,0,-1,1};
        int ans=1;
        while(not q.empty())
        {
            auto temp=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x=temp.first+arr1[k];
                int y=temp.second+arr2[k];
                if(issafe(x,y,n,m) and visited[x][y]==false and grid[x][y]==1)
                {
                    visited[x][y]=true;
                    q.push(make_pair(x,y));
                    ans++;
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>res;
        vector<vector<bool>>visited(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] and not visited[i][j])
                {
                    int ans=bfs(i,j,n,m,grid,visited);
                    res.push_back(ans);
                }
            }
        }
        int result=INT_MIN;
        for(auto i:res)
            result=max(i,result);
        return result==INT_MIN?0:result;
        
    }
};