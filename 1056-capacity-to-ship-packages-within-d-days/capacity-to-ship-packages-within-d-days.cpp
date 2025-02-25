class Solution {
public:
    int solve(vector <int> &arr, int k, int mid){
        int sum = arr[0], cnt = 1;
        for(int i = 1; i < arr.size(); i++){
            sum += arr[i];
            if(sum > mid){
                cnt++;
                sum = arr[i];
            }
        }
        return cnt <= k;
    }
    int shipWithinDays(vector<int>& arr, int k) {
        int low = *max_element(begin(arr), end(arr));
        int high = accumulate(begin(arr), end(arr), 0);
        int ans = -1;
        while(low <= high){
            int mid = high - ((high - low) / 2);
            if(solve(arr,k,mid)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};