#include<bits/stdc++.h>
using namespace std;

// Generating subsets
void search(int k) {
    if (k == n) {
    // process subset
    } else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }

    // outro jeito com manipulacao de bit
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(i);
        }
    }
}

// Gererating permutations

void search() {
    if (permutation.size() == n) {
    // process permutation
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }

    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }
    do {
    // process permutation
    } while (next_permutation(permutation.begin(),permutation.end()));
}

// Backtracking 
/*A backtracking algorithm begins with an empty solution and extends the
solution step by step. The search recursively goes through all different ways how
a solution can be constructed.
*/

void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

/*
Meet in the middle
Meet in the middle is a technique where the search space is divided into two
parts of about equal size. A separate search is performed for both of the parts,
and finally the results of the searches are combined.

A simple algorithm to the problem is to go through all subsets of the elements
and check if the sum of any of the subsets is x. The running time of such an
algorithm is O (2n ), because there are 2n subsets. However, using the meet in the
middle technique, we can achieve a more efficient O (2n/2 ) time algorithm

For example, suppose that the list is [2, 4, 5, 9] and x = 15. First, we divide
the list into A = [2, 4] and B = [5, 9]. After this, we create lists S A = [0, 2, 4, 6]
and S B = [0, 5, 9, 14]. In this case, the sum x = 15 is possible to form, because S A
contains the sum 6, S B contains the sum 9, and 6 + 9 = 15. This corresponds to
the solution [2, 4, 9].
We can implement the algorithm so that its time complexity is O (2n/2 ). First,
we generate sorted lists S A and S B , which can be done in O (2n/2 ) time using a
merge-like technique. After this, since the lists are sorted, we can check in O (2n/2 )
time if the sum x can be created from S A and S B .

*/
