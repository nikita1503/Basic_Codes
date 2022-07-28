This function returns the sum of all the values lying in a range between [first, last) with the variable sum
Syntax - accumulate(first, last, sum); OR accumulate(first, last, sum, myfun);
myfun - 
  // User defined function
  int myfun(int x, int y)
  {
    return x * y;
  }

                                                                          It is equivalent to 
template <class InputIterator, class T>
T accumulate (InputIterator first, InputIterator last, T init)
{
  while (first!=last) {
    init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
    ++first;
  }
  return init;
}

Complexity - O(n) n = distance between first, last
Eg - 
    // Initialize sum = 1
    int sum = 1;
    int a[] = { 5, 10, 15 };
 
    // Simple default accumulate function
    cout << "\nResult using accumulate: ";
    cout << accumulate(a, a + 3, sum); // = (((1+5)+10)+15)
 
    // Using accumulate function with
    // defined function
    cout << "\nResult using accumulate with"
            "user-defined function: ";
    cout << accumulate(a, a + 3, sum, myfun); = (((1*5)*10)*15)
    // Using accumulate function with
    // pre-defined function
    cout << "\nResult using accumulate with "
            "pre-defined function: ";
    cout << accumulate(a, a + 3, sum, std::minus<int>()); = (((1-5)-10)-15)
