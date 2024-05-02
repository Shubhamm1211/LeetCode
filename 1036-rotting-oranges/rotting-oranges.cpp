#include<bits/stdc++.h>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int maxi=0;
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,1,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            maxi=max(maxi,t);
            for(int i=0;i<4;i++){
                int nr= r+drow[i];
                int nc= c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                q.push({{nr,nc},t+1});
                grid[nr][nc]=2;
            }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return maxi;
    }
};