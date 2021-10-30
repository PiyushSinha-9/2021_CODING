//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A


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

const int MAXVAL = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################
vector<int> arr(MAXVAL);
int n,k,mid;
bool binarySearch(int val){
    int l = 0;
    int r = n-1;

    while(r-l+1 >=1){
         mid = (l+r)/2;
         if(arr[mid] < val){
            l=mid+1;
         }else if(arr[mid] > val){
             r=mid-1;
         }else{
             return true;
         }
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        if(binarySearch(temp)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        br;
    }

    
}