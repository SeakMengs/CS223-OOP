#include <bits/stdc++.h>
using namespace std;

int main() {
    // int age;
    string age;
    string line = "5,test2,test3";
    cout << line << endl;

    cout << line.find(",") << endl;

    // age = stoi(line.substr(0, line.find(",")));
    age = line.substr(0, line.find(","));
    cout << age << endl;

    line.erase(0, line.find(",") + 1);
    cout << line;

    return 0;
}