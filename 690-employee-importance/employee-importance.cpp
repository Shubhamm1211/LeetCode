/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int solve(map<int,Employee*> mp, int id){
        int ap = mp[id]->importance;
        for(auto i:mp[id]->subordinates){
            ap+=solve(mp,i);
        }
        return ap;
    }
    int getImportance(vector<Employee*> emp, int id) {
        map<int,Employee*> mp;
        for(auto i:emp) mp[i->id]=i;
        int ans=solve(mp,id);
        return ans;
    }
};