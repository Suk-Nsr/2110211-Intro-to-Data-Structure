#include <iostream>
#include <vector>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    //write some code here
    //don’t forget to return something
    vector<string> temp(v);
    int start = max(0, int(it - v.begin() - k));
    int stop = min(int(v.size()), int(it - v.begin() + k + 1));
    temp.erase(temp.begin() + start, temp.begin() + stop);
    return temp;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}