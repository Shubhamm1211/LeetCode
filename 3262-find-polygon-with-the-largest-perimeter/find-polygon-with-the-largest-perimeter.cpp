class Solution {
public:
    long long largestPerimeter(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long answer=-1;
        long long s=arr[0]+arr[1];
        for(int i=2;i<arr.size();i++)
        {
            if(s>arr[i]){
                s+=arr[i];
                answer=max(s,answer);
            }
            else{
                s+=arr[i];
            }
        }
        return answer;
    }
};