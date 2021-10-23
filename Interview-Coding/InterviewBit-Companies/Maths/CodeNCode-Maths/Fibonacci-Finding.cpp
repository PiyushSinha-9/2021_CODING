#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


const int N = 3;
#define mod 1000000007



/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER n
 */
void matrixMulti(long long  mat1[][N], long long mat2[][N], int hei, int len){
    long long temp[N][N];

    for(int i=0;i<hei;i++){
        for(int j=0;j<len;j++){
            temp[i][j] = 0;
            for(int k=0;k<len;k++){
                temp[i][j] = (temp[i][j]%mod + (mat1[i][k]%mod * mat2[k][j])%mod)%mod;
            }
        }
    }

    for(int i=0;i<hei;i++){
        for(int j=0;j<len;j++){
            mat1[i][j] = temp[i][j];
        }
    }
    

}



void powerMat( long long  TM[][N], int n){
     long long  I[N][N];

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==j){
                I[i][j] =1;
            }else{
                I[i][j] =0;
            }
        }
    }

    while(n>0){
        if(n%2 ==1){
            matrixMulti(I, TM, 2,2);
            n-=1;
        }

        if(n%2 ==0){
            matrixMulti(TM, TM, 2,2);
            n/=2;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            TM[i][j] = I[i][j];
        }
    }


}

int solve(int a, int b, int n) {
     long long  TM[N][N];
    TM[0][0] = 0;
    TM[0][1] = 1;
    TM[1][0] = 1;
    TM[1][1] = 1;

     long long  mat[N][N];
    mat[0][0] = a;
    mat[0][1] = b;

    powerMat(TM, n);
    matrixMulti(mat, TM, 1, 2);

    return mat[0][0];
}


/////////////////////////////////////////////////////////////////////////////////  MY Compliper Solution 
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

#define int long long

const int N = 3;


void matrixMulti(int mat1[][N], int mat2[][N], int hei, int len){
    int temp[N][N];

    for(int i=0;i<hei;i++){
        for(int j=0;j<len;j++){
            temp[i][j] = 0;
            for(int k=0;k<len;k++){
                temp[i][j] = (temp[i][j]%mod + (mat1[i][k]%mod * mat2[k][j])%mod)%mod;
            }
        }
    }

    for(int i=0;i<hei;i++){
        for(int j=0;j<len;j++){
            mat1[i][j] = temp[i][j];
        }
    }
    

}



void powerMat(int TM[][N], int n){
    int I[N][N];

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==j){
                I[i][j] =1;
            }else{
                I[i][j] =0;
            }
        }
    }

    while(n>0){
        if(n%2 ==1){
            matrixMulti(I, TM, 2,2);
            n-=1;
        }

        if(n%2 ==0){
            matrixMulti(TM, TM, 2,2);
            n/=2;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            TM[i][j] = I[i][j];
        }
    }


}


int helper(int a, int b, int n){
    int TM[N][N];
    TM[0][0] = 0;
    TM[0][1] = 1;
    TM[1][0] = 1;
    TM[1][1] = 1;

    int mat[N][N];
    mat[0][0] = a;
    mat[0][1] = b;

    powerMat(TM, n);
    matrixMulti(mat, TM, 1, 2);

    return mat[0][0];
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
        int a,b,n;
        cin>>a>>b>>n;

        /*
         Transition Marix = 
         0 1
         1 1
        */

        cout<<helper(a,b,n);
        br;

    }
}
