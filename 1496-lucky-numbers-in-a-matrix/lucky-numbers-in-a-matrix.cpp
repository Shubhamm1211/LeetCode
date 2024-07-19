class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int maxi=*min_element(matrix[i].begin(),matrix[i].end());
            mp[maxi]++;
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                if(matrix[j][i]>maxi){
                    maxi=matrix[j][i];
                }
            }
            mp[maxi]++;
        }
        for(auto m:mp){
        cout<<m.first<<" "<<m.second<<endl;
        if(m.second==2)ans.push_back(m.first);
        }
        return ans;


    }
};