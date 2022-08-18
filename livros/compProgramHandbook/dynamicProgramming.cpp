#include<bits/stdc++.h>
using namespace std;

/*
Dynamic programming is a technique that combines the correctness of com-
plete search and the efficiency of greedy algorithms. Dynamic programming can
be applied if the problem can be divided into overlapping subproblems that can
be solved independently.
There are two uses for dynamic programming:
• Finding an optimal solution: We want to find a solution that is as large
as possible or as small as possible.
• Counting the number of solutions: We want to calculate the total num-
ber of possible solutions.
*/

/*
The dynamic programming algorithm
is based on a recursive function that goes through all possibilities how to form
the sum, like a brute force algorithm. However, the dynamic programming
algorithm is efficient because it uses memoization and calculates the answer to
each subproblem only once
*/

//coin problem
//recursive
int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    return best;
}

// Using memoization
bool ready[N];
int value[N];

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1); // +1 eh de mais uma moeda e o valor da moeda seria x, estaria entao pegando o minimo das funcoes recursivas e guardando no array
    }
    value[x] = best;
    ready[x] = true;
    return best;
}

value[0] = 0;
for (int x = 1; x <= n; x++) {
    value[x] = INF;
    for (auto c : coins) {
        if (x-c >= 0) {
            value[x] = min(value[x], value[x-c]+1);
        }
    }
}

// Constructing a solution
// Sometimes we are asked both to find the value of an optimal solution and to give
// an example how such a solution can be constructed. In the coin problem, for
// example, we can declare another array that indicates for each sum of money the
// first coin in an optimal solution:
int first[N];
//Then, we can modify the algorithm as follows:
value[0] = 0;
for (int x = 1; x <= n; x++) {
    value[x] = INF;
    for (auto c : coins) {
        if (x-c >= 0 && value[x-c]+1 < value[x]) {
            value[x] = value[x-c]+1;
            first[x] = c;
        }
    }
}

// after this, the following code can be used to print the coins that appear in an
// optimal solution for the sum n:

while (n > 0) {
    cout << first[n] << "\n";
    n -= first[n];
}

// Counting the number of solutions
//recursive

count[0] = 1;
for (int x = 1; x <= n; x++) {
    for (auto c : coins) {
        if (x-c >= 0) {
            count[x] += count[x-c];
        }
    }
}

/*
Often the number of solutions is so large that it is not required to calculate the
exact number but it is enough to give the answer modulo m where, for example,
m = 109 + 7. This can be done by changing the code so that all calculations are
done modulo m. In the above code, it suffices to add the line
*/

count[x] %= m;
//after the line
count[x] += count[x-c];

// Longest increasing subsequence

// Our first problem is to find the longest increasing subsequence in an array
// of n elements. This is a maximum-length sequence of array elements that goes
// from left to right, and each element in the sequence is larger than the previous
// element. For example, in the array

// nessa questao a subsequencia tem q obrigatoriamente acabar naquele index

TEM COMO FAZER EM N LOG N MATHEUS, PENSA MAIS AI, UM DIA VC CONSEGUE

/*
Paths in a grid
Our next problem is to find a path from the upper-left corner to the lower-right
corner of an n × n grid, such that we only move down and right. Each square
contains a positive integer, and the path should be constructed so that the sum of
the values along the path is as large as possible.
*/

//sum( y, x) = max(sum( y, x − 1), sum( y − 1, x)) + value[ y][ x]
/*
Thus, we select the direction that maximizes the sum. We assume that
sum( y, x) = 0 if y = 0 or x = 0 (because no such paths exist), so the recursive
formula also works when y = 1 or x = 1.
Since the function sum has two parameters, the dynamic programming array
also has two dimensions.
*/

int sum[N][N];
for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
        sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
    }
}

//The time complexity of the algorithm is O ( n2 ).

Knapsack problems
The term knapsack refers to problems where a set of objects is given, and
subsets with some properties have to be found. Knapsack problems can often be
solved using dynamic programming.

In this section, we focus on the following problem: Given a list of weights
[w1 , w2 , . . . , wn ], determine all sums that can be constructed using the weights.

Nao pode repetir o peso 
Let possible( x, k) = true if we can construct a sum x
using the first k weights, and otherwise possible( x, k) = false. The values of the
function can be recursively calculated as follows:
possible( x, k) = possible( x - wk , k - 1) OR(V) possible( x, k - 1)

As the base cases,
possible( x, 0) =

true if x = 0
false if x # 0

After calculating those values, possible( x, n) tells us whether we can con-
struct a sum x using all weights.
Let W denote the total sum of the weights. The following O ( nW ) time dynamic
programming solution corresponds to the recursive function:

possible[0][0] = true;
for (int k = 1; k <= n; k++) {
    for (int x = 0; x <= W; x++) {
        if (x-w[k] >= 0) possible[x][k] |= possible[x-w[k]][k-1];
        possible[x][k] |= possible[x][k-1];
    }
}

However, here is a better implementation that only uses a one-dimensional
array possible[ x] that indicates whether we can construct a subset with sum x.
The trick is to update the array from right to left for each new weight:

possible[0] = true;
for (int k = 1; k <= n; k++) {
    for (int x = W; x >= 0; x--) {
        if (possible[x]) possible[x+w[k]] = true;
    }
}

Note that the general idea presented here can be used in many knapsack
problems. For example, if we are given objects with weights and values, we can
determine for each weight sum the maximum value sum of a subset.