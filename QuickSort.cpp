//Quicksort picks one element at a time and finds its correct index in O(N) time. 
//You can use it to find the k-th largest/smallest element
//Time Complexity - Avg O(N), Worst(O^2),  Space Complexity - O(1)

template <typename T>
    class MyQuickSort{
        function<bool(const T&, const T&)> compare;

        private:
        int parition_(int l, int r, vector<T>&arr){
            int pivot = r;
            int border=l, pointer=l;

            while(pointer<r){
                if(compare(arr[pointer], arr[pivot])){
                    swap(arr[border++],arr[pointer]);
                }
                pointer++;
            }

            swap(arr[pivot], arr[border]);

            return border;
        }

        public:
        
        MyQuickSort(function<bool(const T&, const T&)> comp) : compare(comp) {}

        int run(vector<T> &arr, int find_smallest_k, int k){
            int l=0,r=arr.size()-1;
            int pivot=arr.size();

            if(find_smallest_k)k--;
            else k=arr.size()-k;

            while(pivot!=k){
                if((pivot<k && !find_smallest_k) || (pivot>k && find_smallest_k)) l=pivot+1;
                else r=pivot-1;
                pivot = parition_(l,r,arr);
            }

            return pivot;
        }
    };

------
  
//Let's say you have an array of pair<int,int> and you want to find the kth largest element or find the top k elements
 static bool compare(pair<int,int> a, pair<int,int> b){
      return a.first<b.first;
 }

MyQuickSort<pair<int,int>> q(compare);

int pivot = q.run(freq, false, k); //pivot is the index where the kth largest element is and all elements on its right (including itself) are top k elements

-------
  
//Let's say you have an array of string and you want to find the kth smallest element or find the bottom k elements
 static bool compare(string a, string b){
      return a[0]<b[0];
 }

MyQuickSort<string> q(compare);

int pivot = q.run(freq, true, k); //pivot is the index where the kth smallest element is and all elements on its left (including itself) are bottom k elements

