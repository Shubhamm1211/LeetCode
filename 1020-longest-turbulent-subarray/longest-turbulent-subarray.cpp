class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1)return 1;
        vector<int> arr2;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                arr2.push_back(1);
            } else if (arr[i] < arr[i + 1]) {
                arr2.push_back(-1);
            } else
                arr2.push_back(0);
        }
        int i = 0;
        int maxi =0;
        while (i < arr2.size()) {
            if (arr2[i] == 0) {
                maxi = max(maxi, 1);
                i++;
                continue;
            }
            int req = arr2[i];
            int j = i;
            int len = 0;
            while (j < arr2.size()) {
                if (arr2[j] == req) {
                    len++;
                    req = req * -1;
                    j++;

                } else
                    break;
            }
            maxi = max(maxi, len + 1);
            i = j;
        }
        return maxi;
    }
};