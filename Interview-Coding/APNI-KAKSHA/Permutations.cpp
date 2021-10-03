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


void solve(vector<int> arr,int n, vector<int> temp={}){
    if(n==0){
        print(temp);
        return;
    }

    vector<int> tempArr =arr;
    for(int i=0;i<n;i++){
        tempArr = arr;
        temp.pb(arr[i]);
        tempArr.erase(tempArr.begin()+i);
        solve(tempArr,n-1,temp);
        temp.erase(temp.end()-1);
    }
}

void solve2(vector<int> arr,int start, int end){
    if(start==end){
        print(arr);
        return;
    }


    for(int i=start;i<end;i++){
        if(arr[i]==arr[start] and i!=start){
            continue;
        }
        swap(arr[i], arr[start]);
        solve2(arr,start+1,end);
        swap(arr[i], arr[start]);
    }
}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &i:arr){
        cin>>i;
    }

    // arr.erase(arr.end()-1);
    // print(arr);

    //  solve(arr,n);
    // solve2(arr,0, n);

    sort(arr.begin(),arr.end());
    do{
        print(arr);
    }while(next_permutation(all(arr)));

}
