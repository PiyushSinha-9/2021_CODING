/* Auther -: Piyush Sinha */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i=0; i<(n); i++)
#define repa(i, a, n) for(int i=(a); i<=(n); i++)
#define br cout<<"\n"
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define FILE_READ freopen("input.txt","r",stdin), freopen("output.txt","w",stdout), freopen("error.txt","w",stderr);


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define dbg(x...)
#endif


//############################################################

// #define int long long




signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ
    #endif

    //######################

   int testCase;
   cin>>testCase;

   while(testCase--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int count = 1;
        vector<int> store;
        int i=1;
        char cur = s[0];
        while(i < n){
            if(cur != s[i]){
                store.pb(count);
                count=0;
                cur = s[i];
            }else{
                count+=1;
            }
            i+=1;
        }
        store.pb(count);
        dbg(store)


        if(store.size()==1 or store.size()==3 or store.size()==4){
            cout<<"SAHID";
            br;
            continue;
        }else if(store.size() ==2 or store.size() ==5){
            cout<<"RAMADHIR";
            br;
            continue;
        }else{
            int temp = store.size();
            temp -= 5;
            if(temp % 3 == 0){
                cout<<"RAMADHIR";
            }else{
                cout<<"SAHID";
            }
            br;
        }
   }
    
}
