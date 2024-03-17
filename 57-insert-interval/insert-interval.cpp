class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto ci:intervals){
        if(ci[1]<newInterval[0]){
            ans.push_back(ci);
            }
        else if(newInterval[1]<ci[0]){
                    ans.push_back(newInterval); 
                    newInterval = ci;
        }
        else{
            newInterval[0]=min(ci[0],newInterval[0]);
            newInterval[1]=max(ci[1],newInterval[1]);
        }
        }
        ans.push_back(newInterval);
        return ans;

        
    }
};