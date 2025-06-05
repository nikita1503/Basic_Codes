//At arr[x] there should be element x, if x exists in arr
//Inplace operation
//Time Complexity - O(n), Space Complexity - O(1)

void cyclic_sort(vector<int>& arr){
      int ind=0;
      while(ind<arr.size()){
          if(arr[ind]<=0) { ind++; continue; }
        
          int correct_ind = arr[ind]-1;

          if(correct_ind<arr.size() && correct_ind>=0 && arr[correct_ind]!=arr[ind]) swap(arr[ind], arr[correct_ind]);
          else ind++;
      }
}

