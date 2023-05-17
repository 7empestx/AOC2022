#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void partOne();
void partTwo();

int main() {
    
    partTwo();

    return 0;
}

void partTwo() {
    string line;
    int x   = 0;
    int max = 0;
    vector<int> snacks;

    while (getline(cin, line)) {

        if(line == "") {
            snacks.push_back(x);
            x = 0;
        }
        else {
            x += stoi(line);
        }
    }

    sort(snacks.begin(), snacks.end());
    int n = snacks.size();
    max = snacks[n - 1] + snacks[n - 2] + snacks[n - 3];
    cout << max << endl;
}

void partOne() {
    string line;
    int x   = 0;
    int max = 0;

    while (getline(cin, line)) {

        if(line == "") {
            if(x > max) {
                max = x;
            }
            x = 0;
        }
        else {
            x += stoi(line);
        }
    }
    cout << max << endl;
}