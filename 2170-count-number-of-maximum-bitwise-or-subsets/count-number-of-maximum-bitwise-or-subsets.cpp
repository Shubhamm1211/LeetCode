class Solution {
public:
    vector<vector<int>>sub;
    vector <int> bitwise;
    void calc(vector<vector<int>>sub){
        for(auto x: sub){
            int temp = 0;
            for(auto e: x){
                temp |= e;
            }
            bitwise.push_back(temp);
        }
    }
    void generate(vector <int> &nums,vector <int> &temp,int ind){
        if(ind == nums.size()){
            sub.push_back(temp);
            if(temp.size() == 0){
                sub.pop_back();
            }
            return ;
        }
        
        generate(nums,temp,ind + 1);
        temp.push_back(nums[ind]);
        generate(nums,temp,ind + 1);
        temp.pop_back();
       
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector <int> temp;
        generate(nums,temp,0);
        calc(sub);
        int maxi = *max_element(begin(bitwise),end(bitwise));
        int ans = 0;
        for(auto x: bitwise){
            if(x == maxi) ans++;
            // cout << x << " ";
        }
        return ans;
    }
};