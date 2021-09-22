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
        int n;
        cin>>n;

        string s1,s2;
        cin>>s1;
        cin>>s2;

        if(s1==s2){
            cout<<"YES";br;
            continue;
        }

       int dif=0,s11=0,s10=0;
       int d1=0,d0=0;
        
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                dif+=1;
                if(s1[i]=='0'){
                    d0+=1;
                }else{
                    d1+=1;
                }
            }else{
                if(s1[i]=='0'){
                    s10+=1;
                }else{
                    s11+=1;
                }
            }
        }

        bool flag=true;
        
        if((d1>0 and s11>0 and d0>0 and s10>0) or (d1>0 and s11>0 and d0==0) or (d0>0 and s10>0 and d1==0) 
        or (s11==0 and d1>0 and 2*d1==d0 and s10!=0 )or (s10==0 and d0>0 and 2*d0==d1 and s11!=0) or (s11==0 and s10==0 and (2*d1==d0 or 2*d0==d1)) ){
            cout<<"YES";
        }else{
            cout<<"NO";
        }

        br;
    }
}
