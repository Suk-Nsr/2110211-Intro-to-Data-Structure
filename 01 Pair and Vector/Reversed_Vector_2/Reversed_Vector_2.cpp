#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
    //write your code only in this function
    int i = a - v.begin();
    int j = b - v.begin() - 1;

    while (i < j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i = i + 1;
        j = j - 1;
    }
}
int main() 
{
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;

    //call function
    reverse(v,v.begin()+a,v.begin()+b+1);

    //display content of the vector
    for (auto &x : v)
    {
    cout << x << " ";
    }
    cout << endl;
}