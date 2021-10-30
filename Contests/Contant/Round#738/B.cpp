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

ll solve(string s, ll n){
    ll sol=0;

    for(ll i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            sol+=1;
        }
    }

    return sol;
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################


    ll testcase;
    cin>>testcase;
    while(testcase--){
       ll n;
       cin>>n;

       string s, sr,olds, oldsr;
       cin>> s;
       sr= s;
       reverse(sr.begin(), sr.end());
        olds=s;
        oldsr=sr;
       ll val1=0, val2=0;

       for(ll i=0;i<n;i++){
           if(s[i]=='?' and i!=n-1){
               if(i!=0){
                 if(s[i+1]=='B'){
                     s[i]='R';
                 }else if(s[i+1]=='R'){
                     s[i]='B';
                 }
                 else{
                     if(s[i-1]=='B'){
                         s[i]='R';
                     }else{
                         s[i]='B';
                     }
                 }
               }
                else if(i==0){
                     if(s[i+1]=='B'){
                     s[i]='R';
                    }else if(s[i+1]=='R'){
                        s[i]='B';
                    }else{
                        s[i]='B';
                    }    
                }

           }else if (s[i]=='?'){
                if(s[i-1]=='B'){
                    s[i]='R';
                }else{
                    s[i]='B';
                }
           }
       }

        val1 = solve(s,n);
        string s1=s;

        s=sr;
        for(ll i=0;i<n;i++){
           if(s[i]=='?' and i!=n-1){
               if(i!=0){
                 if(s[i+1]=='B'){
                     s[i]='R';
                 }else if(s[i+1]=='R'){
                     s[i]='B';
                 }
                 else{
                     if(s[i-1]=='B'){
                         s[i]='R';
                     }else{
                         s[i]='B';
                     }
                 }
               }
                else if(i==0){
                     if(s[i+1]=='B'){
                     s[i]='R';
                    }else if(s[i+1]=='R'){
                        s[i]='B';
                    }else{
                        s[i]='B';
                    }    
                }

           }else if (s[i]=='?'){
                if(s[i-1]=='B'){
                    s[i]='R';
                }else{
                    s[i]='B';
                }
           }
       }

         val2 = solve(s,n);
        string s2=s;
        reverse(s2.begin(),s2.end());

        s=olds;

         for(ll i=0;i<n;i++){
           if(s[i]=='?' and i!=n-1){
               if(i!=0){
                 if(s[i+1]=='B'){
                     s[i]='R';
                 }else if(s[i+1]=='R'){
                     s[i]='B';
                 }
                 else{
                     if(s[i-1]=='B'){
                         s[i]='R';
                     }else{
                         s[i]='B';
                     }
                 }
               }
                else if(i==0){
                     if(s[i+1]=='B'){
                     s[i]='R';
                    }else if(s[i+1]=='R'){
                        s[i]='B';
                    }else{
                        s[i]='R';
                    }    
                }

           }else if (s[i]=='?'){
                if(s[i-1]=='B'){
                    s[i]='R';
                }else{
                    s[i]='B';
                }
           }
       }

        ll val3 = solve(s,n);
        string s3=s;

         s=oldsr;

         for(ll i=0;i<n;i++){
           if(s[i]=='?' and i!=n-1){
               if(i!=0){
                 if(s[i+1]=='B'){
                     s[i]='R';
                 }else if(s[i+1]=='R'){
                     s[i]='B';
                 }
                 else{
                     if(s[i-1]=='B'){
                         s[i]='R';
                     }else{
                         s[i]='B';
                     }
                 }
               }
                else if(i==0){
                     if(s[i+1]=='B'){
                     s[i]='R';
                    }else if(s[i+1]=='R'){
                        s[i]='B';
                    }else{
                        s[i]='R';
                    }    
                }

           }else if (s[i]=='?'){
                if(s[i-1]=='B'){
                    s[i]='R';
                }else{
                    s[i]='B';
                }
           }
       }

        ll val4 = solve(s,n);
        string s4=s;

        reverse(s4.begin(),s4.end());

        ll miniv = min(val1,min(val2,min(val3,val4)));

        if(miniv==val1){
            cout<<s1;
        }else if(miniv==val2){
            cout<<s2;
        }else if(miniv==val3){
            cout<<s3;
        }else{
            cout<<s4;
        }

        br;
       
        
    }
    

     

    return 0;
}