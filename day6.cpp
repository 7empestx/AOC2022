#include <iostream>
#include <vector>

#define PART_ONE 4
#define PART_TWO 14

using namespace std;

int main() {
    
    string line;
    
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            vector<bool> lookup(128, false);
            
            bool start      = true;
            lookup[line[i]] = true;
            int marker = 0;

            for (int j = i + 1; j < i + PART_ONE; j++) {
                if(lookup[line[j]]) {
                    start = false;
                    break;
                } else {
                    lookup[line[j]] = true;
                    marker = j;
                }
            }
            if(start) {
                cout << marker + 1 << ' ';
                break;
            }
        }
        cout << endl;
    }
    return 0;
}