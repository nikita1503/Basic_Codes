Sort arr in descending order
sort(arr.begin(), arr.end(), greater <>())
Sort 'arr' based on the score of each element. Score is store in array 'score'
 sort(arr.begin(), arr.end(), [&](int x, int y)
  {
    return score[x] < score[y];
  });
