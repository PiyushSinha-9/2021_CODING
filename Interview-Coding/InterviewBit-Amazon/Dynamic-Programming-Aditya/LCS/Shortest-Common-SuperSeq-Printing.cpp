class Solution {
public:
    
    
    string helper(string s1, string s2, int l1,int l2){
        string sol="";
        
        int dp[l1+1][l2+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<l1+1;i++){
            for(int j=0;j<l2+1;j++){
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
        
        // for Printing 
        int i=l1, j=l2;
        while(i!=0 and j!=0){
            if(s1[i-1]==s2[j-1]){
                sol+=s1[i-1];
                i-=1;
                j-=1;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    sol+=s1[i-1];
                    i-=1;
                }else{
                    sol+=s2[j-1];
                    j-=1;
                }            
            }
        }
        
        while(i!=0){
            sol+=s1[i-1];
            i-=1;
        }
        
        while(j!=0){
            sol+=s2[j-1];
            j-=1;
        }
        
        reverse(sol.begin(), sol.end());
        
        return sol;
    }
    
    
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        
        return helper(str1, str2, s1,s2);
        
    }
};