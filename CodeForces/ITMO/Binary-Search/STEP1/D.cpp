//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

// binary search proper left and right and done here

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

const int MV = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################
vector<int> arr(MV);
int n,k,mid,temp1, temp2;

int binarySearch_LeftClosest(){
    int l = -1;
    int r = n;

    while(r>l+1){
        mid = (l+r)/2;
        if(arr[mid] >= temp1){
            r=mid;
         }else{
            l=mid;
        }
    }
    return r;
}



int binarySerach_RightClosest(){
    int l = -1;
    int r = n;

    while(r>l+1){
        mid = (l+r)/2;
        if(arr[mid] > temp2){
            r=mid;
        }else{
            l=mid;
        }
    }

    return r;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

   cin>>n;
   vector<int> tempArr(n);
   for(int i=0;i<n;i++){
       cin>>tempArr[i];
   }
    cin>>k;
    int left,right;
    sort(tempArr.begin(),tempArr.end());
   // print(tempArr);
    for(int i=0;i<n;i++){
       arr[i]=tempArr[i];
    }
    

   for(int i=0;i<k;i++){
       cin>>temp1>>temp2;
       left = binarySearch_LeftClosest();
       right = binarySerach_RightClosest();
       cout<<right-left<<" ";
   }
    
}