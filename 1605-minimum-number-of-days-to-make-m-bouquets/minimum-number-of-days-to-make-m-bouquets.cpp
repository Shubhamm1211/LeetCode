class Solution {
public:
    bool solve(vector<int>&v,int m,int k,long long int day){
        int ans=0;
        for(int i=0;i<v.size();i++){
            int cnt=0;
            while(i<v.size() and cnt<k and v[i]<=day){
                cnt++;
                i++;
            }
            if(cnt==k){
                ans++;
                i--;
            }
            if(ans>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        if((long long)m*k>v.size())return -1;
        int low=*min_element(v.begin(),v.end());
        int high=*max_element(v.begin(),v.end());
        while(low<high){
            long long int mid=low+(high-low)/2;
            if(solve(v,m,k,mid)){
                high=mid;
            }
            else{
            low=mid+1;
            }
        }
        return low;
    }
};
// class Solution {
// public:
//     int canMakeBouqe(vector<int>&bloomDay,int mid,int k){
//         int bouqeCount=0;
//         int consequtiveFlowers=0;

//         for(int i=0; i<bloomDay.size();i++)
//         {
//             if(bloomDay[i]<=mid)
//             {
//                 consequtiveFlowers++;
//             }
//             else{
//                 consequtiveFlowers=0;
//             }
//             if(consequtiveFlowers==k){
//                 bouqeCount++;
//                 consequtiveFlowers=0;
//             }
//         }
//         return bouqeCount;
//     }
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//       int n = bloomDay.size();

//       int startDay=0;
//       int endDay=*max_element(bloomDay.begin(),bloomDay.end()); // max_day
//       int minDays=-1;

//       // Binary Search implementation below
//       // O(n * log(max_day))
//       while(startDay<=endDay) // O(log(max_day))
//       {
//             int mid = startDay + (endDay-startDay)/2;

//             if(canMakeBouqe(bloomDay,mid,k)>=m) // O(n) time complexicity
//             {
//                 minDays=mid;
//                 endDay=mid-1;
//             }
//             else{
//                 startDay= mid+1;
//             }
//       }  
//       return minDays;
//     }
// };

// //tc->O(n*log(max_day))
// //sc->O(1)