

vector<int> xdir,ydir;
const int ways=8;


int Solution::knight(int A, int B, int C, int D, int E, int F) {
    if(C==E and D==F){
        return 0;
    }
    xdir = {2,2,-2,-2,1,-1,1,-1};
    ydir = {-1,1,1,-1,2,2,-2,-2};

    queue<pair<int,int>> q;
    map<int,map<int,bool>> mp;
    q.push({C,D});

    int moves=1;
    bool found = false;
    int cur=1, next=0;
    
    while(!q.empty()){
        pair<int,int> up = q.front();
        q.pop();
        mp[up.first][up.second] = true;

        for(int i=0;i<ways;i++){
            int x=up.first + xdir[i] ;
            int y=up.second + ydir[i];
            if(x>0 and y>0 and x<=A and y<=B and !mp[x][y]){
              //  cout<<x<<" "<<y<<endl;
                if(x==E and y==F){
                    found=true;
                    break;
                }

                next+=1;
                mp[x][y]=true;
        //        mp[y][x]=true;

                q.push({x,y});
            }
        }

        if(found){
            break;
        }
        cur-=1;
        if(cur==0){
            cur=next;
            next=0;
            moves+=1;
        }

        
    }

    if(!found){
        return -1;
    }

    return moves;

}