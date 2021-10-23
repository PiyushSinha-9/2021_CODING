

int power (int a, int n, int p){
    int res =1;
    while(n){
        if(n%2==1){
            res = (res*a)%p;
            n-=1;
        }else{
            a= (a*a)%p;
            n/=2;
        }
    }

    return res;
}