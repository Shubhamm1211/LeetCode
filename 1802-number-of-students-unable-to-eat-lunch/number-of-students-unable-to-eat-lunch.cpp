class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        // stack<int>sand;
        for(auto x:students){
            q.push(x);
        }
        // for(auto x:sandwiches){
        //     sand.push(x);
        // }
        int cnt=0,i=0;
        while(!q.empty()&&cnt!=q.size()){
            if(q.front()==sandwiches[i]){
                cnt=0;
                q.pop();
                i++;
            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
                cnt++;
            }
        }
        return q.size();
    }
};