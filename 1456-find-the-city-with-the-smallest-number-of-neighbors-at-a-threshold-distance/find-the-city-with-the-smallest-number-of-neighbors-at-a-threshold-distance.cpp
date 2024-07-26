class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)adj[i][j]=0;
            }
        }
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==1e9 || adj[k][j]==1e9)continue;
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int cnt=n;
        int ind=-1;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold and adj[i][j]!=0){
                    temp++;
                }
            }
            if(temp<=cnt){
                cnt=temp;
                ind=i;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        return ind;
    }
};