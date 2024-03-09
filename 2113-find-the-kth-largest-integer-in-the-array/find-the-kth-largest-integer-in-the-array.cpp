using pis = pair<int,string> ;
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pis,vector<pis>,greater<pis>>minh;
        for(int i=0;i<nums.size();i++){
            minh.push({nums[i].size(),nums[i]});
            if(minh.size()>k){
                minh.pop();
            }
        }
        return minh.top().second;
    }
};