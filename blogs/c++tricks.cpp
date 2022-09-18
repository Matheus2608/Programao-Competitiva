#include<bits/stdc++.h>
using namespace std

1. Assign value by a pair of {} to a container

pair<int, int> p;
// ...
p = {3, 4};

even a more complex pair

pair<int, pair<char, long long> > p;
// ...
p = {3, {'a', 8ll}};
What about vector, deque, set and other containers?


vector<int> v;
v = {1, 2, 5, 2};
for (auto i: v)
    cout << i << ' ';
cout << '\n';
// prints "1 2 5 2"


deque<vector<pair<int, int>>> d;
d = {{{3, 4}, {5, 6}}, {{1, 2}, {3, 4}}};
for (auto i: d) {
    for (auto j: i)
        cout << j.first << ' ' << j.second << '\n';
    cout << "-\n";
}
// prints "3 4
//         5 6
//         -
//	   1 2
//	   3 4
//	   -"


set<int> s;
s = {4, 6, 2, 7, 4};
for (auto i: s)
    cout << i << ' ';
cout << '\n';
// prints "2 4 6 7"


list<int> l;
l = {5, 6, 9, 1};
for (auto i: l)
    cout << i << ' ';
cout << '\n';
// prints "5 6 9 1"


array<int, 4> a;
a = {5, 8, 9, 2};
for (auto i: a)
    cout << i << ' ';
cout << '\n';
// prints "5 8 9 2"


tuple<int, int, char> t;
t = {3, 4, 'f'};
cout << get<2>(t) << '\n';
Note that it doesn't work for stack and queue.

2. Name of argument in macros
You can use '#' sign to get exact name of an argument passed to a macro:

#define what_is(x) cerr << #x << " is " << x << endl;
// ...
int a_variable = 376;
what_is(a_variable);
// prints "a_variable is 376"
what_is(a_variable * 2 + 1)
// prints "a_variable * 2 + 1 is 753"

4. Hidden function (not really hidden but not used often)
one)

__gcd(value1, value2)
You don't need to code Euclidean Algorithm for a gcd function, from now on we can use. This function returns gcd of two numbers.

e.g. __gcd(18, 27) = 9.

two)

__builtin_ffs(x)
This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.

e.g. __builtin_ffs(10) = 2 because 10 is '...10 1 0' in base 2 and first 1-bit from right is at index 1 (0-based) and function returns 1 + index.

three)

__builtin_clz(x)
This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_clz(16) = 27 because 16 is ' ... 10000'. Number of bits in a unsigned int is 32. so function returns 32 — 5 = 27.

four)

__builtin_ctz(x)
This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_ctz(16) = 4 because 16 is '...1 0000 '. Number of trailing 0-bits is 4.

five)

__builtin_popcount(x)
This function returns number of 1-bits of x. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

e.g. __builtin_popcount(14) = 3 because 14 is '... 111 0' and has three 1-bits.

Note: There are other __builtin functions too, but they are not as useful as these ones.

Note: Other functions are not unknown to bring them here but if you are interested to work with them, I suggest this website.

Variadic Functions and Macros
We can have a variadic function. I want to write a sum function which gets a number of ints, and returns sum of them. Look at the code below:

int sum() { return 0; }

template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

int main() { cout << sum(5, 7, 2, 2) + sum(3, 4); /* prints "23" */ }

I can even define a any-type sum function:

int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

int main() { cout << sum(5, 7, 2, 2) + sum(3.14, 4.89); /* prints "24.03" */ }
Here, I just changed int to T and added typename T to my template.

In C++14 you can also use auto sum(T a, Args... args) in order to get sum of mixed types. (Thanks to slycelote and Corei13)

We can also use variadic macros:

#define a_macro(args...) sum(args)

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }

int main() { cout << a_macro(5, 7, 2, 2) + a_macro(3.14, 4.89); /* prints "24.03" */ }
Using these 2, we can have a great debugging function: (thanks to Igorjan94) — Updated!

#include <bits/stdc++.h>

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main() {
	int a = 4, b = 8, c = 9;
	error(a, b, c);
}
Output:

a = 4
b = 8
c = 9


Variadic functions also belong to C++11 or C++0x, In this section I want to show you some great features of C++11.
also x.begin() and x.end() now are accessible using begin(x) and end(x).

this code:

for(i = 1; i <= n; i++) {
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " ";
    cout << "\n";
}
is equivalent to this:

for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " \n"[j == m];

Usage of tie and emplace_back:

#define mt make_tuple
#define eb emplace_back
typedef tuple<int,int,int> State; // operator< defined

int main(){
  int a,b,c;
  tie(a,b,c) = mt(1,2,3); // assign
  tie(a,b) = mt(b,a); // swap(a,b)

  vector<pair<int,int>> v;
  v.eb(a,b); // shorter and faster than pb(mp(a,b))

  // Dijkstra
  priority_queue<State> q;
  q.emplace(0,src,-1);
  while(q.size()){
    int dist, node, prev;
    tie(dist, ode, prev) = q.top(); q.pop();
    dist = -dist;
    // ~~ find next state ~~
    q.emplace(-new_dist, new_node, node);
  }
}
And that's why emplace_back faster: emplace_back is faster than push_back 'cause it just construct value at the end of vector but push_back construct it somewhere else and then move it to the vector.

Also in the code above you can see how tie(args...) works. You can also use ignore keyword in tie to ignore a value:

tuple<int, int, int, char> t (3, 4, 5, 'g');
int a, b;
tie(b, ignore, a, ignore) = t;
cout << a << ' ' << b << '\n';
Output: 5 3

I use this macro and I love it:

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
First of all, you don't need to name the type you want to use. Second of all it goes forwards and backwards based on (begin > end) condition. e.g. rep(i, 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1

It works well with different types e.g.

vector<int> v = {4, 5, 6, 4, 8};
rep(it, end(v), begin(v))
    cout << *it << ' ';
// prints "8 4 6 5 4"
Also there is another great feature of C++11, lambda functions!

Lambdas are like other languages' closure. It defines like this:

[capture list](parameters) -> return value { body }
one) Capture List: simple! We don't need it here, so just put []

two) parameters: simple! e.g. int x, string s

three) return value: simple again! e.g. pair<int, int> which can be omitted most of the times (thanks to Jacob)

four) body: contains function bodies, and returns return value.

e.g.

auto f = [] (int a, int b) -> int { return a + b; };
cout << f(1, 2); // prints "3"
You can use lambdas in for_each, sort and many more STL functions:

vector<int> v = {3, 1, 2, 1, 8};
sort(begin(v), end(v), [] (int a, int b) { return a > b; });
for (auto i: v) cout << i << ' ';
Output:

8 3 2 1 1

Usage of move:

When you work with STL containers like vector, you can use move function to just move container, not to copy it all.

vector<int> v = {1, 2, 3, 4};
vector<int> w = move(v);

cout << "v: ";
for (auto i: v)
    cout << i << ' ';

cout << "\nw: ";
for (auto i: w)
    cout << i << ' ';
Output:

v: 
w: 1 2 3 4 

C++0x Strings
A raw string skips all escape characters like \n or \". e.g.

string str = "Hello\tWorld\n";
string r_str = R"(Hello\tWorld\n)";
cout << str << r_str;
Output:

Hello	World
Hello\tWorld\n

You can also have multiple line raw string:

string r_str =
R"(Dear Programmers,
I'm using C++11
Regards, Swift!)";
cout << r_str;
Output:

Dear Programmer,
I'm using C++11
Regards, Swift!

Regular Expressions (regex)

Regular expressions are useful tools in programming, we can define a regular expression by regex e.g. regex r = "[a-z]+";. We will use raw string for them because sometimes they have \ and other characters. Look at the example:

regex email_pattern(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)"); // This email pattern is not totally correct! It's correct for most emails.

string
valid_email("swift@codeforces.com"),
invalid_email("hello world");

if (regex_match(valid_email, email_pattern))
    cout << valid_email << " is valid\n";
else
    cout << valid_email << " is invalid\n";

if (regex_match(invalid_email, email_pattern))
    cout << invalid_email << " is valid\n";
else
    cout << invalid_email << " is invalid\n";
Output:

swift@codeforces.com is valid
hello world is invalid

User-defined literals

You already know literals from C++ like: 0xA, 1000ll, 3.14f and so on...

Now you can have your own custom literals! Sounds great :) So let's see an example:

long long operator "" _m(unsigned long long literal) {
	return literal;
}

long double operator "" _cm(unsigned long long literal) {
	return literal / 100.0;
}

long long operator "" _km(unsigned long long literal) {
	return literal * 1000;
}

int main() {
	// See results in meter:
	cout << 250_m << " meters \n"; // Prints 250 meters
	cout << 12_km << " meters \n"; // Prints 12000 meters
	cout << 421_cm << " meters \n"; // Prints 4.21 meters
}
Note that a literal should start with an underscore (_). We declare a new literal by this pattern:

[returnType] operator "" _[name]([parameters]) { [body] }
