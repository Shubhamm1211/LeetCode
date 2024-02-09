class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=INT_MIN;
        while(i<=j){
            int area=(j-i)*(min(height[i],height[j]));
            maxi=max(maxi,area);
            if(height[i]<height[j]){
                i++;
            }
            else j--;
        }
        return maxi;
    }
};