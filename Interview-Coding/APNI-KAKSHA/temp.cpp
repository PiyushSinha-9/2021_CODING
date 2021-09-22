#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
typedef pair<long long,long long> pll;

#define int long long

#define pi (3.141592653589)
#define mod 1000000007
#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<endl
#define pb(a) push_back(a)
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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int> opp(n,0), same(n,0);

        int leftb =0 ,leftw=0;

        leftb=k/2;
        leftw=k/2;
        
        if(k%2!=0){
            if(s[0]=='1'){
                leftb+=1;
            }else{
                leftw+=1;
            }
        }

        int countw=0, countb=0;
        bool swap=false;
        for(int i=n-1;i>=0; i--){
            if(s[i]=='1'){
                opp[i]= countb;
                same[i]=countw;
                if(!swap){
                    countw+=1;
                    swap=true;
                }
            }else{
                opp[i]= countw;
                same[i]=countb;
                if(swap){
                    countb+=1;
                    swap=false;
                }
            }
        }

        print(opp);
        print(same);
       cout<<leftb<<" "<<leftw;br;

        int ind=0;
        bool flag=true;
        while(k>0 and ind<n){
            cout<<ind;br;
            int tempi = n-1;
            bool flag2=true;
            char cur = s[ind];
            while(tempi>ind){
                if(s[tempi] != s[ind]){
                    if(cur=='1' and (opp[tempi])>=leftw and (same[tempi]+1)>=leftb ){
                        flag2=false;
                        ind=tempi;
                        k-=1; 
                        leftb-=1;
                    }
                    else if(cur=='0' and (opp[tempi])>=leftb and (same[tempi]+1)>=leftw ){
                        flag2=false;
                        ind=tempi;
                        k-=1; 
                        leftw-=1;
                    }
                }
                tempi--;                
            }
            if(flag2){
                flag=false;
                break;
            }
        }

        if(flag){
            cout<<ind+1;
        }else{
            cout<<-1;
        }
        br;
    }
}
