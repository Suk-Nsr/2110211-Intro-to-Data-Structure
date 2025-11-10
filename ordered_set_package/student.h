#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> check;

    for (auto &x : A)
    {
        if (check.insert(x).second) v.push_back(x);
    }

    for (auto &x : B)
    {
        if (check.insert(x).second) v.push_back(x);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> setB = set(B.begin(), B.end());

    for (auto &x : A)
    {
        if (setB.find(x) != setB.end()) v.push_back(x);
    }

    return v;
}
