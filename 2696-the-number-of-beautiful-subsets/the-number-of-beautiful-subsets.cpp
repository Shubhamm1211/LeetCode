#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    void solve(int i, vector<int>& ds, vector<int>& nums, int& count, int k) {
        if (i == nums.size()) {
            if (ds.size() > 0) {
                bool flag = true;
                for (int i = 0; i < ds.size(); i++) {
                    for (int j = i + 1; j < ds.size(); j++) {
                        if (abs(ds[j] - ds[i]) == k) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) count++;
            }
            return;
        }
        
        
        ds.push_back(nums[i]);
        solve(i + 1, ds, nums, count, k);
        ds.pop_back();
        

        solve(i + 1, ds, nums, count, k);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        vector<int> ds;
        solve(0, ds, nums, count, k);
        return count;
    }
};


