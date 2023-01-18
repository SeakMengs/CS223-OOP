#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    // int a[1];
    // int *a;
    // a = new int[10];
    // a[0] = 0;
    // a[1] = 1;
    // a[2] = 2;
    // // int a[5] = {0};
    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // cout << a[2] << endl;

    // // check fixed array size not array size
    // cout << sizeof(a) / sizeof(int) << endl;
    
    // cout << sizeof(a[0]) / sizeof(int);
    // int a[10];
    // cout << a[0];
    vector<int> a;
    a.reserve(2);

    a.push_back(2);
    a.push_back(2);

    // a.resize(50);
    a.push_back(2);

    for (auto i : a) {
        cout << i << " ";
    }
    return 0;
}