class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int x= str.size();
		    int y=x;
		    
		    int dp[x+1][y+1];
            memset(dp,-1, sizeof(dp));
            
            
            for(int i=0;i<x+1;i++){
                for(int j=0;j<y+1;j++){
                    if(i==0 or j==0){
                        dp[i][j]=0;
                        continue;
                    }
                    
                    if(str[i-1] == str[j-1] and i!=j){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                    
                }
            }
            
            
            return dp[x][y];
		    
		    
		}

};