binary_search(A, target):
  lo = 1, hi = size(A)
while lo <= hi:
  mid = lo + (hi - lo) / 2
if A[mid] == target:
  return mid
else if A[mid] < target:
  lo = mid + 1
else :
  hi = mid - 1 // target was not found

// Metodo 2 do livro

int k = 0;
for (int b = n/2; b >= 1; b /= 2) {
while (k+b < n && array[k+b] <= x) k += b;
}
if (array[k] == x) {
// x found at index k
}

// podemos abstrair esse algoritmo para um conjunto de elementos onde
// p(x) implica que p(y) para todos y > x
// not(p(x)) implica not(p(y)) para todos y < x

// onde p(x) avalia para true ou falso

// IMPLEMENTING THE DISCRETE ALGORITHM

binary_search(lo, hi, p):
  while lo < hi:
  mid = lo + (hi - lo) / 2
if p(mid) == true:
  hi = mid
else :
  lo = mid + 1
if p(lo) == false:
  complain // p(x) is false for all x in S!

return lo // lo is the least x for which p(x) is true

When p(mid) is true, we can discard the second half of the search space, since the predicate is true for all elements in it (by the main theorem). However, we can not discard mid itself, since it may well be the first element for which p is true. This is why moving the upper bound to mid is as aggressive as we can do without introducing bugs.


If we wanted to find the last x for which p(x) is false, we would devise (using a similar rationale as above) something like:
// warning: there is a nasty bug in this snippet!
binary_search(lo, hi, p):
  while lo < hi:
  mid = lo + (hi - lo) / 2 // note: division truncates
if p(mid) == true:
  hi = mid - 1
else :
  lo = mid

if p(lo) == true:
  complain // p(x) is true for all x in S!

return lo // lo is the greatest x for which p(x) is false



// do livro
int x = -1;
for (int b = z; b >= 1; b /= 2) {
while (!ok(x+b)) x += b;
}
int k = x+1; // se vc quer o primeiro que retorna true
int k = x // se vc quer o ultimo que retorna falso


However, we can quickly find some x such that f(x) is within some tolerance of the border between no and
yes. We have two ways of deciding when to terminate: terminate when the search space gets smaller than
some predetermined bound (say 10-12) or do a fixed number of iterations. On Topcoder, your best bet 
is to just use a few hundred iterations, this will give you the best possible precision without too 
much thinking. 100 iterations will reduce the search space to approximately 10-30 of its initial size,
which should be enough for most (if not all) problems.

If you need to do as few iterations as possible, you can terminate when the interval gets small, but 
try to do a relative comparison of the bounds, not just an absolute one. The reason for this is that do
ubles can never give you more than 15 decimal digits of precision so if the search space contains large 
numbers (say on the order of billions), you can never get an absolute difference of less than 10-7.

EXAMPLE
At this point I will show how all this talk can be used to solve a Topcoder problem. For this I have chosen a moderately difficult problem, FairWorkload, which was the division 1 level 2 problem in SRM 169.

In the problem, a number of workers need to examine a number of filing cabinets. The cabinets are not all of the same size and we are told for each cabinet how many folders it contains. We are asked to find an assignment such that each worker gets a sequential series of cabinets to go through and that it minimizes the maximum amount of folders that a worker would have to look through.

After getting familiar with the problem, a touch of creativity is required. Imagine that we have an unlimited number of workers at our disposal. The crucial observation is that, for some number MAX, we can calculate the minimum number of workers needed so that each worker has to examine no more than MAX folders (if this is possible). Let’s see how we’d do that. Some worker needs to examine the first cabinet so we assign any worker to it. But, since the cabinets must be assigned in sequential order (a worker cannot examine cabinets 1 and 3 without examining 2 as well), it’s always optimal to assign him to the second cabinet as well, if this does not take him over the limit we introduced (MAX). If it would take him over the limit, we conclude that his work is done and assign a new worker to the second cabinet. We proceed in a similar manner until all the cabinets have been assigned and assert that we’ve used the minimum number of workers possible, with the artificial limit we introduced. Note here that the number of workers is inversely proportional to MAX: the higher we set our limit, the fewer workers we will need.

Now, if you go back and carefully examine what we’re asked for in the problem statement, you can see that we are really asked for the smallest MAX such that the number of workers required is less than or equal to the number of workers available. With that in mind, we’re almost done, we just need to connect the dots and see how all of this fits in the frame we’ve laid out for solving problems using binary search.

With the problem rephrased to fit our needs better, we can now examine the predicate Can the workload be spread so that each worker has to examine no more than x folders, with the limited number of workers available? We can use the described greedy algorithm to efficiently evaluate this predicate for any x. This concludes the first part of building a binary search solution, we now just have to prove that the condition in the main theorem is satisfied. But observe that increasing x actually relaxes the limit on the maximum workload, so we can only need the same number of workers or fewer, not more. Thus, if the predicate says yes for some x, it will also say yes for all larger x.

To wrap it up, here’s an STL-driven snippet which solves the problem:

int getMostWork(vector folders, int workers) {
  int n = folders.size();
  int lo = * max_element(folders.begin(), folders.end());
  int hi = accumulate(folders.begin(), folders.end(), 0);

  while (lo < hi) {
    int x = lo + (hi - lo) / 2;

    int required = 1, current_load = 0;
    for (int i = 0; i < n; ++i) {
      if (current_load + folders[i] <= x) {
        // the current worker can handle it
        current_load += folders[i];
      } else {
        // assign next worker
        ++required;
        current_load = folders[i];
      }
    }

    if (required <= workers)
      hi = x;
    else
      lo = x + 1;
  }

  return lo;
}

Note the carefully chosen lower and upper bounds: you could replace the upper bound with any sufficiently large integer, but the lower bound must not to be less than the largest cabinet to avoid the situation where a single cabinet would be too large for any worker, a case which would not be correctly handled by the predicate. An alternative would be to set the lower bound to zero, then handle too small x’s as a special case in the predicate.

To verify that the solution doesn’t lock up, I used a small no/yes example with folders={1,1} and workers=1.

The overall complexity of the solution is O(n log SIZE), where SIZE is the size of the search space. This is very fast.

As you see, we used a greedy algorithm to evaluate the predicate. In other problems, evaluating the predicate can come down to anything from a simple math expression to finding a maximum cardinality matching in a bipartite graph.