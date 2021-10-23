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


void multipleMat(int **mat1 , int **mat2, int dim)
{
    int **temp = new int*[dim+1];
        for(int i=0;i<dim+1;i++){
            temp[i] = new int[dim+1];
        }


    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            temp[i][j] = 0;
            for(int k=0;k<dim;k++){
                temp[i][j] = (temp[i][j]%mod +  (mat1[i][k]%mod * mat2[k][j]%mod)%mod)%mod;
            }
        }
    }


     for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
               mat1[i][j] = temp[i][j];
            }
     }


    for(int i=0;i<dim;i++){
            delete [] temp[i];
        }

        delete [] temp;
}


// Brute or Naive
void powerMatrix(int **arr, int dim, int n){
    int **I = new int*[dim];
        for(int i=0;i<dim;i++){
            I[i] = new int[dim];
            for(int j=0;j<dim;j++){
                if(i==j){
                    I[i][j] = 1; 
                }else{
                    I[i][j] = 0;
                }
            }
        }



    for(int i=0;i<n;i++){
        multipleMat(I,arr,dim);
    }

    for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
               arr[i][j] = I[i][j];
            }
    }

    for(int i=0;i<dim;i++){
            delete [] I[i];
        }

        delete [] I;
}

// M^3 + log(n)
void powerMatrix2(int **arr, int dim, int n){
    int **I = new int*[dim];
        for(int i=0;i<dim;i++){
            I[i] = new int[dim];
            for(int j=0;j<dim;j++){
                if(i==j){
                    I[i][j] = 1; 
                }else{
                    I[i][j] = 0;
                }
            }
        }


    while(n>0){

        if(n%2==1){
            multipleMat(I,arr,dim);
            n-=1;
        }else{
            multipleMat(arr,arr,dim);
            n/=2;
        }

    }



    for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
               arr[i][j] = I[i][j];
            }
    }

    for(int i=0;i<dim;i++){
            delete [] I[i];
        }

        delete [] I;
}




void printMatrix(int **arr, int dim){
    for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                cout<<arr[i][j]%mod<<" ";           
            }
            br;
    }
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
        int dim, n;
        cin>>dim>>n;

        int **arr = new int*[dim];
        for(int i=0;i<dim;i++){
            arr[i] = new int[dim];
            for(int j=0;j<dim;j++){
                cin>>arr[i][j];
            }
        }

        // powerMatrix(arr, dim, n);
        powerMatrix2(arr, dim , n);
        printMatrix(arr,dim);


        for(int i=0;i<dim;i++){
            delete [] arr[i];
        }

        delete [] arr;

    }
}
