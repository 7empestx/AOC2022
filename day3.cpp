#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

void fillMap(unordered_map<char, int> &);
void partOne(unordered_map<char, int> &);
void partTwo(unordered_map<char, int> &);

int main() {
    
    unordered_map<char, int> p;
    
    fillMap(p);
    partOne(p);
    partTwo(p);

    return 0;
}

void partTwo(unordered_map<char, int> &p) {
    int score = 0;
    string one;
    string two;
    string three;
    vector<int> m(128, 0);

    while (getline(cin, one)) {
        getline(cin, two);
        getline(cin, three);

        for(int i = 0; i < one.size(); i++) {
            if(two.find(one[i]) != string::npos && three.find(one[i]) != string::npos) {
                m[one[i]] = true;
            }
        }
        for(int i = 0; i < m.size(); i++) {
            if(m[i]) {
                score += p.at(i);
                m[i] = false;
            }
        }
    }
    cout << score << endl;
}

void partOne(unordered_map<char, int> &p) {
    string s;
    int score = 0;

    while (getline(cin, s)) {
        string l  = s.substr(0, s.size() / 2);
        string r = s.substr(s.size() / 2, s.size());
        vector<bool> m(128, false);

        for(int i = 0; i < l.size(); i++) {
            m[l[i]] = true;
        }

        for(int i = 0; i < r.size(); i++) {
            if(m[r[i]]) {
                score += p.at(r[i]);
                m[r[i]] = false;
            }
        }
    }

    cout << score << endl;
}

void fillMap(unordered_map<char, int> &p) {
    for(char a = 'a'; a <= 'z'; a++) {
        p[a] = a - 'a' + 1;
    }
    for(char A = 'A'; A <= 'Z'; A++) {
        p[A] = A - 65 + 27;
    }
}