#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

void partOne(vector<queue<string>>&, int, int, int);
void partTwo(vector<queue<string>>&, int, int, int);

int main() {

    string line;
    vector<queue<string>> cratesQueue(10);

    while (getline(cin, line)) {
        
        stringstream ss(line);
        string crate;
        char ch;
        int index = 0;
        int colCount = 0;
        queue<string> colQueue;

        if(line[1] == '1') {
            // Useless col numbering
            break;
        } else {
            while(ss >> noskipws >> ch) {
                crate.push_back(ch);
                index++;

                if(index == 4) {
                    crate.pop_back();
                    if(crate != "   ") {
                        colQueue = cratesQueue[colCount];
                        colQueue.push(crate);
                        cratesQueue[colCount] = colQueue;
                    }
                    crate.clear();
                    index = 0;
                    colCount++;
                }
            }
        }
    }

    getline(cin, line); // Garbage line
    
    while (getline(cin, line)) {
        int moveCount   = stoi(line.substr(5, line.find_first_of('f') - 5));
        int source      = stoi(line.substr(line.find_first_of('f') + 5, line.find_first_of('t') - 12)) - 1;
        int destination = stoi(line.substr(line.find_first_of('t') + 3, line.size() - line.find_first_of('t') + 2)) - 1;

        //partOne(cratesQueue, moveCount, source, destination);
        partTwo(cratesQueue, moveCount, source, destination);
        
        for (int i = 0; i < 10; i++) {
            cout << cratesQueue[i].front() << ' ';
        }
        cout << endl;

    }
    
    return 0;
}

void partTwo(vector<queue<string>> &cratesQueue, int moveCount, int source, int destination) {
    
    queue<string> newQueue;
    for (int i = 0; i < moveCount; i++) {
        newQueue.push(cratesQueue[source].front());
        cratesQueue[source].pop();
    }

    while (!cratesQueue[destination].empty()) {
        newQueue.push(cratesQueue[destination].front());
        cratesQueue[destination].pop();
    }
    cratesQueue[destination] = newQueue;
}

void partOne(vector<queue<string>> &cratesQueue, int moveCount, int source, int destination) {

    for (int i = 0; i < moveCount; i++) {
        queue<string> newQueue;

        newQueue.push(cratesQueue[source].front());
        cratesQueue[source].pop();

        while (!cratesQueue[destination].empty()) {
            newQueue.push(cratesQueue[destination].front());
            cratesQueue[destination].pop();
        }
        cratesQueue[destination] = newQueue;
    }
}