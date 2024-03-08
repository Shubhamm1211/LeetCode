class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int,vector<long long int>,greater<long long int>>minh;
            for(auto x:nums){
                minh.push(x);
            }
            int ans=0;
            while(minh.top()<k){
                long long int x=minh.top();
                minh.pop();
                long long int y=minh.top();
                minh.pop();
                long long int temp=min(x, y) * 2 + max(x, y);
                minh.push(temp);
                ans++;
            }
            return ans;
    }
};