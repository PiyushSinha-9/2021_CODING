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

bool check(vector<int> arr, int n, int k, int val){

    int sum=0, studentrequied=1;
  
    for(int i=0;i<n;i++){
       if(arr[i]> val){
            return false;
       }

       if(sum+arr[i] > val){
           studentrequied+=1;
           sum=arr[i];

           if(studentrequied>k){
               return false;
           }
       }else{
           sum+=arr[i];
       }
    }

    return true;

}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int n,k;
    cin>>n>>k;

    int sumPages=0;
    vector<int> arr(n);
    for(int &i:arr){
        cin>>i;
        sumPages+=i;
    }

    int low=1;
    int high=sumPages;
    int result = INT_MAX;
    int epoch =100;

    while(low <= high){
        cout<<high<<" "<<low;br;
        int mid = (low+high)/2;
        if(check(arr, n, k, mid)){
            result =min(result,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    cout<<result;
    
}
