// **************BFS***************
// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         vector<int>col(graph.size(),-1);
//         int n=graph.size();
//         for(int i=0;i<n;i++){
//             if(col[i]==-1){
//                 queue<int>q;
//                 q.push(i);
//                 col[i]=0;
//                 while(!q.empty()){
//                     int node=q.front();
//                     q.pop();
//                     for(auto adj:graph[node]){
//                         if(col[adj]==-1){
//                             col[adj]=!col[node];
//                             q.push(adj);
//                         }
//                         else if(col[adj]==col[node])return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

//************************DFS*************************8
class Solution {
public:
    bool dfs(int node,int c,vector<vector<int>>&graph,vector<int>&col){
        col[node]=c;
        for(auto nei:graph[node]){
            
            if(col[nei]==-1){
                if(dfs(nei,!c,graph,col)==false)return false;
            }
            else if(col[nei]==col[node])return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(graph.size(),-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,graph,col)==false)return false;
            }
        }
        return true;
    }
};