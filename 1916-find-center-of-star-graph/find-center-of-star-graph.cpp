class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>v(n+2,0);
        for(auto ed:edges){
            for(auto e:ed){
                v[e]++;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==n)return i;
        }
        return -1;
    }
};