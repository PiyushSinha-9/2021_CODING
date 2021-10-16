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
        
        string com = "";
        // For Printing
        int i=x, j=y;
        while(i!=0 and j!=0){
            if(s1[i-1] == s2[j-1]){
                com+=s1[i-1];
                i-=1;
                j-=1;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i-=1;
                }else{
                    j-=1;
                }
            }
        }
        reverse(all(com));
        cout<<com;br;
        
        
        return dp[x][y];
    }
