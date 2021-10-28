#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

#define pi (3.141592653589)
#define mod 1000000007
#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<", ";}br;
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

#define int long long int

int n,tot;
void helper(vector<int> A)
{   
    int N= n*n;
     for(int i=0;i< N-3;i++){
         for(int j=i+1;j<N-2;j++){
            for(int k=j+1;k<N-1;k++){
                for(int l = k+1;l<N;l++){
                    if(A[i]+ A[j] +A[k]+A[j] <= tot){
                        cout<<A[i] <<" "<< A[j]<<" "<<A[k]<<" "<<A[j];
                        br;
                    }
                }
            }
        }     
    }
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
        cin>>n>>tot;

        vector<vector<int> > v;
        vector<int> total;

        for(int i=0;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                cin>>temp[i];
                total.pb(temp[i]);
            }
            v.pb(temp);
        }
        sort(all(total));
         print(total);

        int med = (n+1)/2;
        int start = n*(med);

        int sum = 0;

        for(int i=start; i< start+n;i++){
            sum += total[i];
        }

        // cout<<total[start];
        // br;

        // int start = 0;
        // int end = n-1;
        // int sum = 0;
        // int sol = total[0];
        // for(int i=0;i<=end;i++){
        //     sum+=total[i];
        // }

        // if(sum>k){
        //     cout<<-1;
        //     br;
        //     continue;
        // }

        // end+=1;
        // while( (sum + total[end] - total[start])  <= k){
        //     sum = (sum + total[end] - total[start]) ;
        //     end+=1;
        //     start+=1;
        //     sol = total[start];
        // }

       // cout<<sol <<" "<< sum;br;
    }
}
