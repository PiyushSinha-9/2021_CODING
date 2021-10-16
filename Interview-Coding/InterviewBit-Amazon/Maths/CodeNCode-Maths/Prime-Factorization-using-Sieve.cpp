

//PrimeSieve

const int SIZE = 1e6+1;
int ar[SIZE];


void sieve(){
    int maxN=1e6;
    for(int i=1;i<=maxN;i++){
        ar[i]=-1;
    }

    ar[0] = 1;
    ar[1] = 1;


    for(int i=2;i*i<=maxN;i++){
        if(ar[i] == -1){
            for(int j=i*i;j<=maxN;j+=i){        // not sure abour j=i*i here in video it was j=i but they said optimize it
                if(ar[j] == -1){
                    ar[j] = i;
                }
            }
        }
    }

}

int num =38;
while(num!=1){
    cout<<ar[num]<<" ";
    num/=ar[num];
}
br;