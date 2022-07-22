//TC - O(N x M)
//SC - O(N x M)
//Range Update over 2D

typedef int ll;

class RangeUpdate2D {
        public:
          //matrix store the value to add to each cell, a.k.a it store the updates to each cell
          vector<vector<ll>> matrix;
          int rows, cols;
          RangeUpdate2D(int rows_, int cols_) { //O(m*n)
              matrix.resize(rows_, vector<ll>(cols_, 0));
              rows = rows_; cols = cols_;
          }
          //add 'value' to all cell between (a,b) and (x,y) inclusive
          void RangeUpdate(int a, int b, int x, int y, ll value) { // Lazy Updates O(1)
              matrix[a][b] += value;
              if (y+1 < cols) matrix[a][y+1] -= value;
              if (x+1 < rows) matrix[x+1][b] -= value;
              if (x+1 < rows and y+1 < cols) matrix[x+1][y+1] += value;
          }

          //call it before actually using the matrix
          void Gather() { //Gather all Lazy updates and consolidate O(m*n)
              for (int i = 1; i < rows; ++i) 
                  for (int j = 0; j < cols; ++j) 
                      matrix[i][j] += matrix[i-1][j];

              for (int i = 0; i < rows; ++i) 
                  for (int j = 1; j < cols; ++j) 
                      matrix[i][j] += matrix[i][j-1];
          }
    };

main(){
    vector<vector<int>>grid; //original array
    RangeUpdate2D rangeUpdate(rows, cols); //rows, cols are size of grid
    rangeUpdate.RangeUpdate(x1, y1, x2, y2, value);
    rangeUpdate.Gather();
    cout<<"New value at i,j "<<grid[i][j]+rangeUpdate.matrix[i][j];
}
