// Solution - https://www.youtube.com/watch?v=Om47LiGTy8o

//////////////////////////////////////////////////////  Actual Solution

string Solution::multiple(int A) {
    if(A==1) return "1";
    queue<int> q;
    vector<char> str(A, '2');
    vector<int> par(A, -1);
    q.push(1); 
    set<int> st;
    str[1] = '1';

    while(!q.empty()){
        int rem = q.front();
        q.pop();
        if(rem == 0){
            break;
        }
        int r0 = (rem * 10 + 0) % A;
        int r1 = (rem * 10 + 1) % A;

        if(str[r0] == '2'){
            str[r0] = '0';
            par[r0] = rem;
            q.push(r0);
        }

         if(str[r1] == '2'){
            str[r1] = '1';
            par[r1] = rem;
            q.push(r1);
        }
    }


    string sol = "";
    int rem = 0;
    while( rem != -1){
        sol += str[rem];
        rem = par[rem];
    }
  
    reverse(sol.begin(), sol.end());
    return sol;
}



//////////////////////////////////////////////////////  TLE  but close Solution
int divide(string up, int A){
    int val = 0;
    for(char i:up){
        val*=10;
        val+= (i-'0');
        val = val % A;
    }

    return val;
}



string Solution::multiple(int A) {

    queue<string> q;
    q.push("1");
    set<int> st;
    while(!q.empty()){
        string up = q.front();
        q.pop();

        int rem = divide(up, A);
        if(rem == 0){
            return up;
        }else if(st.find(rem) == st.end()){
            st.insert(rem);
            q.push(up+'0');
            q.push(up+'1');
        }
    }   

    return "";
}



//////////////////////////////////////////////////////  TLE  My Approch with Partitial Understanding


int divide(string up, int A){
    int val = 0;
    for(char i:up){
        val*=10;
        val+= (i-'0');
        val = val % A;
    }

    return val;
}


string Solution::multiple(int A) {

    queue<pair<string,string>> q;
    map<string, string> dp;
    q.push(make_pair("1","1")); 
    set<int> st;
    while(!q.empty()){
        pair<string,string> temp = q.front();
        q.pop();

        string up=temp.first;
        string str = temp.second;

        int rem = divide(up, A);
        if(rem == 0){
            return str;
        }else if(st.find(rem) == st.end()){
            st.insert(rem);
            string tp = to_string(rem)+'0';
            q.push(make_pair(tp , str + '0'));
            q.push(make_pair(to_string(rem)+'1',str+'1' ));
        }
    }   

    return "";
}

