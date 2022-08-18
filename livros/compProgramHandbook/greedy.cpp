#include<bits/stdc++.h>
using namespace std;

/*
A greedy algorithm constructs a solution to the problem by always making a
choice that looks the best at the moment. A greedy algorithm never takes back
its choices, but directly constructs the final solution. For this reason, greedy
algorithms are usually very efficient.
*/

/*
asks and deadlines
Let us now consider a problem where we are given n tasks with durations and
deadlines and our task is to choose an order to perform the tasks. For each task,
we earn d − x points where d is the task’s deadline and x is the moment when we
finish the task. What is the largest possible total score we can obtain?

Surprisingly, the optimal solution to the problem does not depend on the
deadlines at all, but a correct greedy strategy is to simply perform the tasks
sorted by their durations in increasing order.

*/


/*
Minimizing sums
We next consider a problem where we are given n numbers a 1 , a 2 , . . . , a n and our
task is to find a value x that minimizes the sum
| a1 − x| ^ c + | a2 − x| ^ c + · · · + | an − x| ^ c .
We focus on the cases c = 1 and c = 2.

Case c = 1
The median is an optimal choice, because if x is smaller than the median, the
sum becomes smaller by increasing x, and if x is larger then the median, the
sum becomes smaller by decreasing x. Hence, the optimal solution is that x is
the median. If n is even and there are two medians, both medians and all values
between them are optimal choices.

Case c = 2
In the general case, the best choice for x is the average of the numbers. In the
example the average is (1 + 2 + 9 + 2 + 6)/5 = 4. This result can be derived by
presenting the sum as follows:
nx² − 2x(a1 + a2 + · · · + an ) + (a1² + a2² + · · · + an² )

The last part does not depend on x, so we can ignore it. The remaining parts
form a function nx2 − 2 xs where s = a 1 + a 2 + · · · + a n . This is a parabola opening
upwards with roots x = 0 and x = 2 s/ n, and the minimum value is the average of
the roots x = s/ n, i.e., the average of the numbers a 1 , a 2 , . . . , a n .
*/



/*

*/


/*

*/

/*

*/