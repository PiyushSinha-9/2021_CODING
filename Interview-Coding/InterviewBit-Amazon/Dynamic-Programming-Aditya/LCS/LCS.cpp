
////////////////////   Recusrion + Memo  (TLE) map and 2d int both TLE

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    
    map<int,map<int,int>> dp;
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        if(x==0 or y==0){
            return 0;
        }
        
        if(dp[x][y]!=0){
            return dp[x][y];
        }
        
        
        if(s1[x-1] == s2[y-1]){
            return dp[x][y]=1+lcs(x-1,y-1,s1,s2);
        }
        
        return dp[x][y] = max(lcs(x,y-1,s1,s2),lcs(x-1,y,s1,s2));
        
    }
};




////////////////////   Bottom-UP
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
        memset(dp,-1, sizeof(dp));
        
        
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                    continue;
                }
                
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        
        
        return dp[x][y];
    }
};