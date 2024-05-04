class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mini = INT_MAX;
        for (int i = 0; i < n1; i++) {
            for (int j = i + 1; j < n1; j++) {
                vector<int> up;
                for (int k = 0; k < n1; k++) {
                    if (k == i || k == j) continue;
                        up.push_back(nums1[k]);
                    
                }
                int diff = nums2[0] - up[0];
                bool flag = true;
                for (int l = 1; l < up.size(); l++) {
                    if (nums2[l] - up[l] != diff)
                        flag = false;
                }
                if (flag) {
                    mini = min(mini, nums2[0] - up[0]);
                }
            }
        }
        return mini;
    }
};