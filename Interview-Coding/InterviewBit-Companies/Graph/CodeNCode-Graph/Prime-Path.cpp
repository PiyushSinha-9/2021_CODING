
#include <bits/stdc++.h>
typedef long  ll;
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
 
#define max_val 11000
 
bool prime[max_val];
 
void sieve(){
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i<sqrt(max_val)+1;i++){
        for(ll j=i*i;j<max_val;j+=i){
            prime[j]=false;
        }
    }
}
 
ll s,g;
queue<ll> q;
ll ans,cur_level,next_level;
unordered_map<ll,bool> dp;
bool flag;
 
vector<ll> split_no(ll x){
    vector<ll> v;
    ll temp;
    while(x>0){
        temp=x%10;
        x=x/10;
        v.pb(temp);
    }
    reverse(v.begin(),v.end());
    return v;
}
 
ll join_no(vector<ll> v){
    ll temp=0;
    for(ll i:v){
        temp+=i;
        temp*=10;
    }
    temp/=10;
    return temp;
}
 
void add(ll up)
{
    vector<ll> v=split_no(up);
    vector<ll> store=split_no(up);
    for(ll i=0;i<4;i++){
        v=store;
        for(ll j=0;j<=9;j++){
            v[i]=j;
            ll val=join_no(v);
            if(val>=1000 and val<=10000) {
                if (prime[val] and !dp[val]) {
                    q.push(val);
                    next_level += 1;
                    dp[val] = true;
                }
            }
        }
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    memset(prime,true,sizeof(prime));
    sieve();
 
 
    ll test;
    cin>>test;
    while(test--){
        queue<ll> temp;
        ans=0;
        cur_level=1;
        next_level=0;
        flag=false;
        dp.clear();
 
        q=temp;
        cin>>s>>g;
 
        q.push(s);
        ll up;
 
        while(!q.empty()){
            up=q.front();
            q.pop();
            cur_level--;
            if(up==g){
                flag=true;
                break;
            }
            dp[up]=true;
            add(up);
            if(cur_level==0){
                cur_level=next_level;
                next_level=0;
                ans+=1;
            }
 
        }
 
        if(flag){
            cout<<ans;br;
        }else{
            cout<<"Impossible";br;
        }
 
    }
 
 
}