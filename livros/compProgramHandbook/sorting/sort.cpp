#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int (&array)[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j],array[j+1]);
            }
        }
    }
}
/*
MERGE SORT >>>>
1. If a = b, do not do anything, because the subarray is already sorted.
2. Calculate the position of the middle element: k = b(a + b)/2c.
3. Recursively sort the subarray array[a . . . k].
4. Recursively sort the subarray array[ k + 1 . . . b].
5. Merge the sorted subarrays array[a . . . k] and array[ k + 1 . . . b] into a sorted
subarray array[a . . . b].
*/

/*
COUTING SORT
Counting sort is a very efficient algorithm but it can only be used when the
constant c is small enough, so that the array elements can be used as indices in
the bookkeeping array.
*/

int main(){
    /*
    It is almost never a good idea to use a home-made sorting algorithm in a contest,
    because there are good implementations available in programming languages.
    */
    int array[] = {5,4,3,2,1};
    bubble_sort(array, 5);
    for(int x : array) cout << x << " ";
    cout << endl;
    return 0;
}

/*User-defined structs do not have a comparison operator automatically. The
operator should be defined inside the struct as a function operator<, whose
parameter is another element of the same type. The operator should return true
if the element is smaller than the parameter, and false otherwise.
For example, the following struct P contains the x and y coordinates of a point.
*/

struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

/*
An alternative method to implement binary search is based on an efficient way to
iterate through the elements of the array. The idea is to make jumps and slow
the speed when we get closer to the target element.
The search goes through the array from left to right, and the initial jump
length is n/2. At each step, the jump length will be halved: first n/4, then n/8,
n/16, etc., until finally the length is 1. After the jumps, either the target element
has been found or we know that it does not appear in the array.
The following code implements the above idea:
*/

void binarySearch2(int (&array)[], int n){
    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && array[k+b] <= x) k += b;
    }
    if (array[k] == x) {
    // x found at index k
    }
}

// equal_range returns both above pointers(upper and lower bound)

void c++Functions(int (&array)[], int n, int x){
    auto k = lower_bound(array,array+n,x)-array;
    if (k < n && array[k] == x) {
        // x found at index k
    }

    auto a = lower_bound(array, array+n, x);
    auto b = upper_bound(array, array+n, x);
    cout << b-a << "\n";

    auto r = equal_range(array, array+n, x);
    cout << r.second-r.first << "\n";
    
    /*
    Finding the smallest solution
    An important use for binary search is to find the position where the value of a
    function changes. Suppose that we wish to find the smallest value k that is a
    valid solution for a problem. We are given a function ok( x) that returns true if x
    is a valid solution and false otherwise. In addition, we know that ok( x) is false
    when x < k and true when x ≥ k. The situation looks as follows:

    Now, the value of k can be found using binary search:
    */
    int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (!ok(x+b)) x += b;
    }
    int k = x+1;

    /*
    The search finds the largest value of x for which ok( x) is false. Thus, the next
    value k = x + 1 is the smallest possible value for which ok( k) is true. The initial
    jump length z has to be large enough, for example some value for which we know
    beforehand that ok( z) is true.
    The algorithm calls the function ok O (log z) times, so the total time complexity
    depends on the function ok. For example, if the function works in O ( n) time, the
    total time complexity is O ( n log z).
    */

   /*Binary search can also be used to find the maximum value for a function that is
    first increasing and then decreasing. Our task is to find a position k such that
    • f ( x) < f ( x + 1) when x < k, and
    • f ( x) > f ( x + 1) when x ≥ k.
    The idea is to use binary search for finding the largest value of x for which
    f ( x) < f ( x + 1). This implies that k = x + 1 because f ( x + 1) > f ( x + 2). The following
    code implements the search:
    */
    int x = -1;
    for (int b = z; b >= 1; b /= 2) {
    while (f(x+b) < f(x+b+1)) x += b;
    }
    int k = x+1;
    /*
    Note that unlike in the ordinary binary search, here it is not allowed that
    consecutive values of the function are equal. In this case it would not be possible
    to know how to continue the search.
    */
}