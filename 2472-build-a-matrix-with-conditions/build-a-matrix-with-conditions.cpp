// class Solution {
// public:
//     void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
//         vis[node]=1;
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 dfs(it,adj,vis,st);
//             }
//         }
//         st.push(node);
//     }
//     void topo(vector<int>adj[],vector<int>&v,int k){
//         vector<int>vis(k+1,0);
//         stack<int>st;
//         for(int i=1;i<=k;i++){
//             if(!vis[i]){
//                 dfs(i,adj,vis,st);
//             }
//         }
//         while(!st.empty()){
//             v.push_back(st.top());
//             st.pop();
//         }
       
//     }
//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
//         vector<int>adj1[k+1];
//         vector<int>adj2[k+1];
//         for(auto v:rowC){
//             adj1[v[0]].push_back(v[1]);
//         }
//         for(auto v:colC){
//             adj2[v[0]].push_back(v[1]);
//         }
//         vector<int>trow,tcol;
//         topo(adj1,trow,k);
//         topo(adj2,tcol,k);
//         cout<<trow.size()<<" "<<tcol.size()<<endl;
//         for(int i=0;i<trow.size();i++)cout<<trow[i]<<" ";
//         cout<<endl;
//         for(int i=0;i<tcol.size();i++)cout<<tcol[i]<<" ";
//         if(trow.size()!=rowC.size() || tcol.size()!=colC.size())return {};
//         vector<vector<int>> result(k, vector<int>(k, 0));
//         unordered_map<int, int> rowMap, colMap;
        
//         for (int i = 0; i < k; ++i) {
//             rowMap[trow[i]] = i;
//             colMap[tcol[i]] = i;
//         }
        
//         for (int i = 1; i <= k; ++i) {
//             result[rowMap[i]][colMap[i]] = i;
//         }
        
//         return result;

//     }
// };
class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& recStack, stack<int>& st) {
        vis[node] = 1;
        recStack[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, recStack, st)) {
                    return true; // Cycle detected
                }
            } else if (recStack[it]) {
                return true; // Cycle detected
            }
        }
        recStack[node] = 0;
        st.push(node);
        return false;
    }
    
    bool topo(vector<int> adj[], vector<int>& v, int k) {
        vector<int> vis(k + 1, 0);
        vector<int> recStack(k + 1, 0);
        stack<int> st;
        for (int i = 1; i <= k; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, recStack, st)) {
                    return false; // Cycle detected
                }
            }
        }
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        return true;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector<int> adj1[k + 1];
        vector<int> adj2[k + 1];
        for (auto v : rowC) {
            adj1[v[0]].push_back(v[1]);
        }
        for (auto v : colC) {
            adj2[v[0]].push_back(v[1]);
        }
        vector<int> trow, tcol;
        if (!topo(adj1, trow, k) || !topo(adj2, tcol, k)) {
            return {}; // Return empty matrix if a cycle is detected
        }
        vector<vector<int>> result(k, vector<int>(k, 0));
        unordered_map<int, int> rowMap, colMap;
        
        for (int i = 0; i < k; ++i) {
            rowMap[trow[i]] = i;
            colMap[tcol[i]] = i;
        }
        
        for (int i = 1; i <= k; ++i) {
            result[rowMap[i]][colMap[i]] = i;
        }
        
        return result;
    }
};



