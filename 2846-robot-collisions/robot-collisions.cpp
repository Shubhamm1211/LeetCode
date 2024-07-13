// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hel, string dir) {
//         vector<pair<pair<int,int>,pair<char,int>>>v;//{{pos,hel},{dir,i}}
//         int n=hel.size();
//         for(int i=0;i<n;i++){
//             v.push_back({{pos[i],hel[i]},{dir[i],i}});
//         }
//         sort(v.begin(),v.end());
//         stack<pair<int,pair<int,char>>>st;//{i,{hel,dir}}
//         for(int i=0;i<n;i++){
//             if(!st.empty() and st.top().second.second=='R' and v[i].second.first=='L'){
//                 int h1=v[i].first.second;
//                 char p1=v[i].second.first;
//                 int i1=v[i].second.second;
//                 int h2=st.top().second.first;
//                 char p2=st.top().second.second;
//                 int i2=st.top().first;
//                 if(!st.empty() and h1>h2){
//                     st.pop();
//                     h1--;
//                     st.push({i1,{h1,p1}});
//                 }
//                 else if(!st.empty() and h1<h2){
//                     st.pop();
//                     h2--;
//                     st.push({i2,{h2,p2}});
//                 }
//                 else if(!st.empty()){
//                     st.pop();
//                 }
//             }
//             else st.push({v[i].second.second,{v[i].first.second,v[i].second.first}});
//         }
//         if(st.empty())return {};
//         else{
//             vector<pair<int,int>>ans;
//             while(!st.empty()){
//                 ans.push_back({st.top().first,st.top().second.first});
//                 st.pop();
//             }
//             sort(ans.begin(),ans.end());
//             vector<int>res;
//             for(int i=0;i<ans.size();i++){
//                 res.push_back(ans[i].second);
//             }
//             return res;
//         }
//     }
// };
// Ordering is wrong, thats why hard
class Solution {
public:
    using int2=pair<int, int>;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        vector<int2> robot(n);
        for(int i=0; i<n; i++)
            robot[i]={positions[i], i};
        sort(robot.begin(), robot.end(), greater<>());

        vector<int> stack;
        for(auto& [pos, i]: robot){
            if (directions[i]=='L') stack.push_back(i);
            else{
                while(!stack.empty() && healths[i]>0){
                    int j=stack.back();
                    int x=healths[j]-healths[i];
                    if (x>0) healths[j]--, healths[i]=0;
                    else if (x<0) healths[j]=0, healths[i]--, stack.pop_back();
                    else healths[i]=healths[j]=0, stack.pop_back();
                }
            }
        }
        vector<int> ans;
        for(int x: healths)
            if (x>0) ans.push_back(x);
        return ans;
    }
};
