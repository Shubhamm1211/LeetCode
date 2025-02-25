class Solution {
public:
    int solve(vector <int> &arr, int h, int mid){
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            ans += ceil(1.0 * arr[i] / mid);
        }
        return ans <= h;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int low = 1;
        int high = *max_element(begin(arr), end(arr));
        int ans = -1;
        while(low <= high){
            int mid = high - ((high - low) / 2);
            if(solve(arr,h,mid)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};