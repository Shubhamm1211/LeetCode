class Solution {
public:
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>ind;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i]))ind.push_back(i);
        }
        int maxi=*max_element(ind.begin(),ind.end());
        int mini=*min_element(ind.begin(),ind.end());
        return maxi-mini;
    }
};