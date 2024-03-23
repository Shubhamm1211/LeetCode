class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        int n=co.size();
        
        int y =(co[0][1]-co[1][1]);
        int x =(co[0][0]-co[1][0]);
        
        for(int i=2;i<n;i++){
           if(y*(co[i][0]-co[0][0]) !=x*(co[i][1]-co[0][1]))return 0;
        }
        return 1;
    }
};