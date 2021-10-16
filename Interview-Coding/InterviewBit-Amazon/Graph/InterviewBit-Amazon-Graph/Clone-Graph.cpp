

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *src) {
   map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
   map<UndirectedGraphNode*, bool> vis;
   
   queue<UndirectedGraphNode *> q;
   q.push(src);
   vis[src] =true;

   mp[src] = new UndirectedGraphNode(src->label);

   while(!q.empty()){
        UndirectedGraphNode* up = q.front();
        q.pop();
        for(UndirectedGraphNode * temp : up->neighbors){

            if(vis[temp]){
                mp[up]->neighbors.push_back(mp[temp]);
            }else{
                if(mp.find(temp) == mp.end()){
                    mp[temp] = new UndirectedGraphNode(temp->label);
                }
                vis[temp]=true;
                q.push(temp);
                mp[up]->neighbors.push_back(mp[temp]);
            }

        }
      

   }


   return mp[src];

}


///////////////////////////////////////////   use mp.find() as vis
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *src) {
   map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
   //map<UndirectedGraphNode*, bool> vis;
   
   queue<UndirectedGraphNode *> q;
   q.push(src);


   mp[src] = new UndirectedGraphNode(src->label);

   while(!q.empty()){
        UndirectedGraphNode* up = q.front();
        q.pop();
        for(UndirectedGraphNode * temp : up->neighbors){
                if(mp.find(temp) == mp.end()){
                    mp[temp] = new UndirectedGraphNode(temp->label);
                    q.push(temp);
                }
                mp[up]->neighbors.push_back(mp[temp]);
        }
   }


   return mp[src];

}