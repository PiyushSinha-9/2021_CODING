
const int mod = 1e3+3;

class Solution{
public:

    int dp[201][201][2];
    
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    
    int solve(string str, int left, int right, bool isTrue=true){
        
        int count=0;
    
       
        if(left==right){
            if(str[left]=='T' and isTrue){
                return 1;
            }
            
            if(str[left]=='F' and !isTrue){
                return 1;
            }
            
            return 0;
            
        }
        
        if(left> right){
            return 0;
        }
        
        if(dp[left][right][isTrue] != -1){
            return dp[left][right][isTrue];
        }
       
        
        
        for(int i=left+1; i<right ;i+=2){
            
            if(str[i]=='T' or str[i]=='F' or str[i]==')' or str[i]=='('){
                continue;
            }
            
            
            int leftTrue = solve(str, left, i-1, true);
            int leftFalse = solve(str, left, i-1, false);
            int rightTrue = solve(str, i+1, right, true);
            int rightFalse = solve(str, i+1, right, false);
            
            if(str[i]=='&' and isTrue){
                count = (count%mod + (leftTrue%mod * rightTrue%mod)%mod)%mod;
            }
            
            if(str[i]=='&' and !isTrue){
                count = (count%mod + (leftFalse%mod * rightFalse%mod)%mod + 
                (leftTrue%mod * rightFalse%mod)%mod + (leftFalse%mod * rightTrue%mod)%mod)%mod;
            }
            
            
            if(str[i]=='|' and isTrue){
                count = (count%mod + (leftTrue%mod * rightTrue%mod)%mod + 
                (leftTrue%mod * rightFalse%mod)%mod + (leftFalse%mod * rightTrue%mod)%mod)%mod;
            }
            
            if(str[i]=='|' and !isTrue){
                count = (count%mod + (leftFalse%mod * rightFalse%mod)%mod)%mod;
            }
            
            
            if(str[i]=='^' and isTrue){
                count = (count%mod + (leftTrue%mod * rightFalse%mod)%mod + (leftFalse%mod * rightTrue%mod)%mod)%mod;
            }
            
            if(str[i]=='^' and !isTrue){
                count = (count%mod + (leftTrue%mod * rightTrue%mod) + (leftFalse%mod * rightFalse%mod)%mod)%mod;
            }
            
            
        }
        
        
        return dp[left][right][isTrue]  =count%mod;
        
        
        
    }



    int countWays(int N, string S){
        // code here
    
      //  dp.clear();
        int count = solve(S,0, N-1);
        
        
        return count ;
        
        
    }
};