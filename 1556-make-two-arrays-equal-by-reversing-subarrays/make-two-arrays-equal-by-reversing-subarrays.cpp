class Solution {
public:
    bool canBeEqual(vector<int>& tar, vector<int>& arr) {
        // sort(tar.begin(),tar.end());
        // sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++){
        //     if(tar[i]!=arr[i])return false;
        // }
        // return true;
        priority_queue< int , vector<int> , greater<int> >pq1(tar.begin(),tar.end());
        priority_queue< int , vector<int> , greater<int> >pq2(arr.begin(),arr.end());
        while(!pq1.empty() and !pq2.empty()){
            if(pq1.top()!=pq2.top()){
                return false;
            }
            pq1.pop();
            pq2.pop();
        }
        return true;
    }
};