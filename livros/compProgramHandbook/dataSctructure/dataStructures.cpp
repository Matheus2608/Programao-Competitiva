#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

int main(){ sws;   
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    cout << v[0] << "\n"; // 3
    cout << v[1] << "\n"; // 2
    cout << v[2] << "\n"; // 5

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    for (auto x : v) {
        cout << x << "\n";
    }
    
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    cout << v.back() << "\n"; // 2
    v.pop_back();
    cout << v.back() << "\n"; // 5

    vector<int> v = {2,4,2,5,1};

    // size 10, initial value 0
    vector<int> v(10);

    // size 10, initial value 5
    vector<int> v(10, 5);

    string a = "hatti";
    string b = a+a;
    cout << b << "\n"; // hattihatti
    b[5] = 'v';
    cout << b << "\n"; // hattivatti
    string c = b.substr(3,4);
    cout << c << "\n"; // tiva

    //Set structures
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n"; // 1
    cout << s.count(4) << "\n"; // 0
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << "\n"; // 0
    cout << s.count(4) << "\n"; // 1

    set<int> s = {2,5,6,8};
    cout << s.size() << "\n"; // 4
    for (auto x : s) {
        cout << x << "\n";
    }

    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    cout << s.count(5) << "\n"; // 1

    multiset<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    cout << s.count(5) << "\n"; // 3

    s.erase(5);
    cout << s.count(5) << "\n"; // 0

    s.erase(s.find(5));
    cout << s.count(5) << "\n"; // 2

    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; // 3

    map<string,int> m;
    cout << m["aybabtu"] << "\n"; // 0

    if (m.count("aybabtu")) {
    // key exists
    }

    for (auto x : m) {
    cout << x.first << " " << x.second << "\n";
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    random_shuffle(v.begin(), v.end());
    
    // sort(a, a+n);
    // reverse(a, a+n);
    // random_shuffle(a, a+n);

    set<int>::iterator it = s.begin();
    auto it = s.begin();

    auto it = s.begin();
    cout << *it << "\n";

    // The following code prints the largest element in the set:
    auto it = s.end(); it--;
    cout << *it << "\n";

    // The function find( x) returns an iterator that points to an element whose
    // value is x. However, if the set does not contain x, the iterator will be end.

    // For example, the following code finds the element nearest to x:
    auto it = s.lower_bound(x);
    if (it == s.begin()) {
    cout << *it << "\n";
    } else if (it == s.end()) {
    it--;
    cout << *it << "\n";
    } else {
    int a = *it; it--;
    int b = *it;
    if (x-b < a-x) cout << b << "\n";
    else cout << a << "\n";
    }


    // Other data structures

    // Bitset -> The benefit of using bitsets is that they require less memory than ordinary
    // arrays, because each element in a bitset only uses one bit of memory.
    // The function count returns the number of ones in the bitset


    // Deque
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]

    // Stack, queue, priority queue

    // Policy-based data structures
    /*
    The g++ compiler also supports some data structures that are not part of the C++
    standard library. Such structures are called policy-based data structures.
    */
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;

    // indexed_set that is like set but can be indexed like an array

    typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
   /*
    The speciality of this set is that we have access to the indices that the elements
    would have in a sorted array. The function find_by_order returns an iterator to
    the element at a given position:
   */

    auto x = s.find_by_order(2);
    cout << *x << "\n"; // 7

    // And the function order_of_key returns the position of a given element:
    cout << s.order_of_key(7) << "\n"; // 2

    return 0;
}