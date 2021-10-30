#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

#define pi (3.141592653589)
#define mod 1000000007
#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<endl
#define pb push_back
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define ff first
#define ss second
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

#pragma GCC target("popcnt")

//############################################################

pair<int,bool> lcs(int x, int y, string s1, string s2)
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
        
        char sol='#';
        int g= 0, h=0;
        bool flag = true;
        while(g!=x and h!=com.size()){
            if(s1[g] != com[h]){
                if(sol=='#'){
                    sol=s1[g];
                }else{
                    if(sol != s1[g]){
                        flag=false;
                        break;
                    }
                }
                g+=1;
            }else{
                g+=1;
                h+=1;
            }
        }

      //  cout<<flag; br;
        
        return {dp[x][y],flag};
    }

signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int testCase;
    cin>>testCase;

    while(testCase--){
        int n;
        cin>>n;

        string s2;
        cin>>s2;

        string s1 = s2;
        reverse(all(s2));

        pair<int,bool>  value =  lcs(n,n,s1,s2);
        
        if(value.second){
            cout<<n- value.first;
        }else{
            cout<<-1;
        }

        br;
    }
}