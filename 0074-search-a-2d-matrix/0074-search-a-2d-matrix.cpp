class Solution {

    int lowerBound(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid][0] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
       if( target<mat[0][0])
       return false;     

        int n = mat.size();
        int m = mat[0].size();

        int lb = lowerBound(mat, target);
       
        cout<<"row lowerbound:"<<lb<<endl;
        if (lb == 0)
            return false;

        int l = 0;
        int r = m;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (mat[lb-1][mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
         
        cout<<"col lowerbound:"<<l<<endl; 
        if (l == m || mat[lb-1][l] != target)
            return false;

        return true;
    }
};