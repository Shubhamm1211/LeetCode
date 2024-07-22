class Solution {
    class Comparator {
        int k;
    public:
        Comparator(int column) {
            k=column;
        }
        bool operator()(vector<int>& a, vector<int>& b)  {
            return a[k] > b[k];
        }
    };
    
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), Comparator(k));
        return score;
    }
};