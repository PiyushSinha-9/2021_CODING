
const int DIRECTIONS = 4;
int xdir[] = {1,-1,0,0};
int ydir[] = {0,0,1,-1};
int n,l,h;
bool found;
map<int,map<int,bool>> vis;

void dfs(vector<string> A,string B, int x, int y, int ind){
    
    if(found){
        return;
    }

    if(ind==n){
        found=true;
    }
    
    vis[x][y] =true;

    for(int i=0 ;i< DIRECTIONS;i++){
        int newx = x + xdir[i];
        int newy = y + ydir[i];

        if(newx < 0 or newx >= h or newy<0 or newy >=l){
            continue;
        }

        if(A[newx][newy] == B[ind]){
            dfs(A,B,newx,newy,ind+1);
        }

    }
}

int Solution::exist(vector<string> &A, string B) {
    n = B.size();
    found =false;
    h = A.size();
    if(h==0 and B==""){
        return 1;
    }
    if(h==0){
        return 0;
    }
    l =A[0].size();

    for(int i=0;i<h and !found;i++){
        for(int j=0;j<l and !found;j++){
            if(A[i][j] == B[0]){
                vis.clear();
                dfs(A,B,i,j,1);
            }
        }
    }

    return found;

}