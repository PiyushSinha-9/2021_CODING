//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F

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

struct _stack{
    vector<ll> s,smin = {LLONG_MAX},smax = {LLONG_MIN};

    void _push(ll x){
        s.push_back(x);
     //   cout<<min(smin.back(), x);br;
        smin.push_back(min(smin.back(), x));
        smax.push_back(max(smax.back(), x));
    }

    ll _pop(){
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }

    bool _empty(){
        return s.empty();
    }

    ll _min(){
        return smin.back();
    }

    ll _max(){
        return smax.back();
    }
};

_stack s1, s2;

void add(ll x){
  //  cout<<x<<" ";
    s2._push(x);
}

void remove(){
    if(s1._empty()){
        while(!s2._empty()){
            s1._push(s2._pop());
        }
    }
    s1._pop();
}


ll k;

bool good(){
    ll mn = min(s1._min(), s2._min());
    ll mx = max(s1._max(), s2._max());

    //cout<<mx<<" "<<mn;br;
    return mx-mn <=k ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    long long n;
    cin>>n>>k;

    vector<long long > arr(n);

    for(long long  i=0;i<n;i++){
        cin>>arr[i];
    }

    
    long long  l=0, ans=0;

    for(long long  r=0;r<n;r++){    
       add(arr[r]);
       while(l<=r and !good()){
           remove();
           l++;
       }
      // cout<<r<<" "<<l;br;
       ans += r-l+1;
    }

    cout<<ans;

    return 0;
}