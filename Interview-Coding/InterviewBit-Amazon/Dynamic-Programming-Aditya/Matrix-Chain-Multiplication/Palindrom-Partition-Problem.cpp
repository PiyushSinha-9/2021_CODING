//2 Solutions 
/////////////////////////////////////////////////////  Good Solution will run in GFG and InterviewBit but not on LeetCode
const int SIZE = 1e3;
const int INF = INT_MAX;


int dp[SIZE][SIZE];
class Solution{
public:


    bool checkPal(string s, int left, int right){
        while(left<=right){
            if(s[left] != s[right]){
                return false;
            }
            left+=1;
            right-=1;
        }
        return true;
    }

    int solve(string str, int left, int right){
    
        if(left>=right){
            return 0;
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        if(checkPal(str,left,right)){
            return 0;
        }
        
        int val = INF;
        
        for(int k=left; k<right ;k++){
            if(checkPal(str,left,k)){
                val = min(val, 1+ solve(str, k+1,right));
            }
        }
        
        return dp[left][right]=val;
    }



    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int left=0;
        int right = str.size() - 1;
        
        return solve(str, left, right);
        
        
    }
};


/////////////////////////////////////////////////////  Best Solution checkPal in n^2 only

const int SIZE = 2001;
const int INF = INT_MAX;


int dp[SIZE][SIZE];
int pal[SIZE][SIZE];

class Solution {
public:
     void checkPal(string s, int left, int right){    
        for(int g=0; g< right+1;g++){
            for(int i=0, j=g; j < right +1 ;i++,j++){
                if(g==0)        // len 1
                    pal[i][j]=1;
                else if(g==1)   // len 2
                    pal[i][j] = (s[i]==s[j]);
                else{
                    if((s[i]==s[j]) and (pal[i+1][j-1]==1))  // len more than 2
                        pal[i][j]=1;
                    else
                        pal[i][j]=0;
                }
            }
        }
    }

    int solve(string str, int left, int right){
    
        if(left>=right){
            return 0;
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        if(pal[left][right]==1){
            return 0;
        }
        
        int val = INF;
        
        for(int k=left; k<right ;k++){
            if(pal[left][k]==1){
                val = min(val, 1+ solve(str, k+1,right));
            }
        }
        
        return dp[left][right]=val;
    }
    int minCut(string str) {
        memset(dp, -1, sizeof(dp));
        memset(pal, -1, sizeof(pal));
        int left=0;
        int right = str.size() - 1;
        checkPal(str,left,right);
        return solve(str, left, right);
    }
};