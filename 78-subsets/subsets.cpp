class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int numsize=nums.size();
        int totalsub=1<<numsize;
        for(int i=0;i<totalsub;i++){
            vector<int> temp;
            for(int j=0;j<numsize;j++){
                if((i&(1<<j))!=0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;

    }
};