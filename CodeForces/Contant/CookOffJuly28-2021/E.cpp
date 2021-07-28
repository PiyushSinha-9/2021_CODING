//https://www.codechef.com/COOK131C/problems/MODEQUAL/

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
        ll n;
        cin>>n;

        ll mini = LONG_MAX;

        vector<ll> arr(n);
        int count1= 0;
        for(int i=0;i<n;i++){
            cin>>arr[i]; 
            mini = min(mini, arr[i]);
        }

        int sol =0;
        bool flag =true;
        for(int i: arr){
            if(i != mini){
                if(i-mini > 1 and i-mini > mini){
                    sol+=1;
                }else{
                    flag=false;
                    break;
                }
            }
        }

        if(flag){
            cout<<sol;
        }else{
            cout<<n;
        }
        br;

       


    }
    
}