// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
public:

    const int inf = 1e9+7;

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   
	   vector<int> dist(n,inf); 
	   int starting =0;
	   dist[starting] = 0;
	   int edgeCount = edges.size();
	   
	   for(int i=0;i<n-1;i++){
	       for(int j=0;j<edgeCount;j++){
	           int u = edges[j][0];
	           int v = edges[j][1];
	           int w = edges[j][2];
	           if(dist[v] > dist[u] + w){
	              dist[v] = dist[u] + w ;
	           }
	       }
	   }
	   
	   bool flag = false;
	    for(int j=0;j<edgeCount;j++){
	           int u = edges[j][0];
	           int v = edges[j][1];
	           int w = edges[j][2];
	           if(dist[v] > dist[u] + w){
	             flag=true;
	             break;
	           }
	   }
	   
	   if(flag)
	   return 1;
	   
	   return 0;
	    
	}
};
