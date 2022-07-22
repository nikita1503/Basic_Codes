//TC - O(N x M)
//SC - O(N x M)
//Range Sum Query over 2D using prefix sum
 typedef int ll;
class RangeSumQuery2D { //0-indexed
        public:
        //matrix is the prefix sum 2d array of grid
          vector<vector<ll>> matrix;
          int rows, cols;
          //grid is the input 2d array
          RangeSumQuery2D(vector<vector<ll>> &grid) { //O(m*n)
              rows = grid.size(); cols = grid[0].size();
              matrix.resize(rows, vector<int>(cols, 0));
              for (int i = 0; i < grid.size(); ++i) {
                  for (int j = 0; j < grid[0].size(); ++j) {
                      matrix[i][j] = grid[i][j];
                  }
              }

              for (int i = 0; i < rows; ++i) 
                  for (int j = 0; j < cols; ++j) 
                      matrix[i][j] = (i>0?matrix[i-1][j]:0) + (j>0?matrix[i][j-1]:0) - (i>0 and j>0?matrix[i-1][j-1]:0) + matrix[i][j];
          }

          //get sum of all cells from (a,b) to (x,y) both inclusive
          ll RangeSum(int a, int b, int x, int y) { //O(1)
              return matrix[x][y] - (b>0? matrix[x][b-1]:0) - (a>0 ? matrix[a-1][y]:0) + (a > 0 and b > 0? matrix[a-1][b-1]: 0);
          }
    };

main(){
   RangeSumQuery2D rangeSum(grid);
  cout<<rangeSum.RangeSum(x1, y1, x2, y2);
}
 
