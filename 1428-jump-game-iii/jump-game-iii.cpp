class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int an = arr.size();
        vector<int> vis (an, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1 ;
        while( !q.empty() ){
            int n = q.size();
            for(int i = 0 ; i < n ; i++ ){
                int node = q.front();
                q.pop();
                vis[node] = 1 ;
                if( arr[node] == 0 ) return true ;
                if( node-arr[node] >= 0 and !vis[node-arr[node]]){
                    q.push( node-arr[node] );
                }
                if(node+arr[node] < an and !vis[node+arr[node]] ){
                    q.push(node+arr[node]);
                }
            }
        }
        return false;
    }
};