//https://www.codechef.com/COOK131C/problems/CHFGCD

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;



#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define check_ cout<<"yo";

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

const int MV = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################

ll gcd2(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd2(b, a % b);
     
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    ll testCase;
    cin>>testCase;

    while(testCase--){
        ll x,y;
        cin>>x>>y;

        if(gcd2(x,y)>1){
            cout<<0;br; continue;
        }

        if(gcd2(x+1,y)>1){
            cout<<1;br; continue;
        }

        if(gcd2(x,y+1)>1){
            cout<<1;br; continue;
        }

        ll sol=0;
        if(x%2!=0){
            sol+=1;
            x+=1;
        }

        if(y%2!=0){
            sol+=1;
        }

        cout<<sol;br;

    }
    
}