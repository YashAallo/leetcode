class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();
          
        //transpose ,means every row is column and every column is row
        //swap around daigonal  
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }

       
        
    }
};