#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <sstream>

using namespace std;

void partOne();
void partTwo();

int main() {
    
    //partOne();
    partTwo();

    return 0;
}

void partTwo() {
    string line;
    int pairs = 0;

    while(getline(cin, line)) {
        stringstream ss(line);
        string section;
        bool overlap = false;
        int oneStartElf, oneEndElf, twoStartElf, twoEndElf;
        vector<bool> oneElf(100, false);
        vector<bool> twoElf(100, false);

        while (getline(ss, section, '-')) {
            oneStartElf = stoi(section);

            getline(ss, section, ',');
            oneEndElf = stoi(section);

            getline(ss, section, '-');
            twoStartElf = stoi(section);

            getline(ss, section);
            twoEndElf = stoi(section);

            for(int i = oneStartElf; i <= oneEndElf; i++) {
                oneElf[i] = true;
            }
            for(int i = twoStartElf; i <= twoEndElf; i++) {
                twoElf[i] = true;
            }

            for(int i = 0; i <= 100; i++) {
                if(oneElf[i] & twoElf[i]) {
                    overlap = true;
                }
            }
        }
        if(overlap) {
            pairs++;
        }
        overlap = false;
    }
    cout << pairs << endl;
}

void partOne() {
    string line;
    int pairs = 0;

    while(getline(cin, line)) {
        stringstream ss(line);
        string section;

        int oneStartElf, oneEndElf, twoStartElf, twoEndElf;

        vector<bool> oneElf(100, false);
        vector<bool> twoElf(100, false);

        vector<bool> answer(100);

        while (getline(ss, section, '-')) {
            oneStartElf = stoi(section);

            getline(ss, section, ',');
            oneEndElf = stoi(section);

            getline(ss, section, '-');
            twoStartElf = stoi(section);

            getline(ss, section);
            twoEndElf = stoi(section);

            for(int i = oneStartElf; i <= oneEndElf; i++) {
                oneElf[i] = true;
            }
            for(int i = twoStartElf; i <= twoEndElf; i++) {
                twoElf[i] = true;
            }

            for(int i = 0; i <= 100; i++) {
                answer[i] = oneElf[i] & twoElf[i];
            }

            if(answer == oneElf || answer == twoElf) {
                pairs++;
            }
        }
    }
    cout << pairs << endl;
}