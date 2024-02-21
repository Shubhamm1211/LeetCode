class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0,cnt=0;
        for(auto x:nums){
            if(x%2==0 && x%3==0){
                sum+=x;
                cnt++;
            }
        }
        int avg;
        if(cnt!=0){
        avg=sum/cnt;
        }
        else{
            return 0;
        }
        return avg;
    }
};