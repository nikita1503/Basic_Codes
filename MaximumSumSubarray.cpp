//input - vector arr
//output - maxSum, maxSumL, MaxSumR
//Complexity - O(n)

int maxSum = arr[0], maxSumL = 0, MaxSumR = 0;
int sum = 0, minus_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += arr[r];
    if (sum > maxSum) {
        maxSum = sum;
        maxSumL = minus_pos + 1;
        MaxSumR = r;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
}
