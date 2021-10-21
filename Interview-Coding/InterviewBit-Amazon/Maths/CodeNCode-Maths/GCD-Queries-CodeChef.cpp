
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

int GCD_Iterative(int a, int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b= temp;
    }
    return a;
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
        int n, q;
        cin>>n>>q;
        vector<int> arr(n), left(n), right(n);
        
        int ind  = 0, sol1 = 0, sol2 =0;
        for(int &i:arr){
            cin>>i;
        }

        for(int i=0;i<n;i++){
            sol1 = GCD_Iterative(sol1, arr[i]);
            sol2 = GCD_Iterative(sol2, arr[n-i-1]);
            left[i] = sol1;
            right[n-i-1] = sol2;
        }


        while(q--){
            int l,r;
            cin>>l>>r;
            int ans = 0;
            int g1 = 0, g2 =0;
            l-=1;
            r-=1;
            if(l>0){
                g1 = left[l-1];
            }

            if(r<n-1){
                g2 = right[r+1];
            }

            ans =GCD_Iterative(g1,g2);

            cout<<ans<<"\n";
        }
    }
}



/*--------------------------------------------------------------------    TLE Solution
int GCD_Iterative(int a, int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b= temp;
    }
    return a;
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
        int n, q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int &i:arr){
            cin>>i;
        }

        while(q--){
            int l,r;
            cin>>l>>r;
            int ans = 0;
            for(int i=0;i<n;i++){
                if(i+1 >= l and i+1<=r){
                    continue;
                }

                ans =GCD_Iterative(ans,arr[i]);
            }

            cout<<ans<<"\n";
        }
    }
}
*/