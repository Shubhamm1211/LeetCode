#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<int>>adj(26,vector<int>(26,1e7));
        for(int i=0;i<26;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'][changed[i]-'a']=min(adj[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k]+adj[k][j]<adj[i][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(adj[source[i]-'a'][target[i]-'a']==1e7){
                return -1;
            }
            ans=ans+adj[source[i]-'a'][target[i]-'a'];
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<26;j++){
        //         cout<<adj[source[i]-'a'][target[i]-'a']<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};

