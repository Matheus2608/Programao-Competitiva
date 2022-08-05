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

    return 0;
}