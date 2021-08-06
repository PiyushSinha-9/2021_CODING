//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C

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
#define check_ cout<<"yo\n";

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

    long long n1,n2;
    cin>>n1>>n2;

    vector<long long > arr1(n1), arr2(n2);

    for(long long  i=0;i<n1;i++){
        cin>>arr1[i];
    }

    for(long long  i=0;i<n2;i++){
        cin>>arr2[i];
    }


    long long  l=0,r=0, count=0,dup=0, ans=0;

    for(long long  i=0;i<n2;i++){
        dup=1;
        count=0;
        while(i+1<n2 and arr2[i+1]==arr2[i]){
            dup+=1;
            i+=1;
        }
        while(l<n1 and arr1[l]<arr2[i]){
            l++;
        }
        while(l<n1 and arr1[l]==arr2[i]){
            l++;
            count+=1;
        }

        ans += (dup*count);
        
    }

    cout<<ans;

    
}