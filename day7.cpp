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
    
    partOne();
    partTwo();

    return 0;
}

void partTwo() {

}

void partOne() {
    string line;
    unordered_map<string, vector<pair<int, string>>> mapDirectory; // key: directory, value: files in directory
    string currentDirectory = "/";
    vector<pair<int, string>> arrayDirectory;
    int fileSize;
    string fileName;

    while(getline(cin, line)) {
        stringstream ss(line);
        string look;

        ss >> look; // $, dir, or file expected
        if(look == "$") {
            ss >> look; // cd or ls expected
            if(look == "cd") {
                ss >> look; // directory name expected
                if(look == "..") {
                    // Go back to parent directory
                    
                } else {
                    // Go to child directory

                }
            } else if(look == "ls") {

            }
            
        } else if(look == "dir") {
            ss >> look; // directory name expected
            mapDirectory.insert({look, arrayDirectory});

        } else {
            fileSize = stoi(look);
            ss >> fileName; // file size and name expected
            cout << fileSize << " " << fileName << endl;

            // Add file to current directory
            arrayDirectory.push_back({fileSize, fileName});
            mapDirectory.insert({currentDirectory, arrayDirectory});

            

        }


    }
    // Iterate over map directory
    for(auto it = mapDirectory.begin(); it != mapDirectory.end(); it++) {
        cout << it.operator->()->first << endl;

        // Iterate over vector of files in directory
        for(auto it2 = it.operator->()->second.begin(); it2 != it.operator->()->second.end(); it2++) {
            cout << it2.operator->()->first << " " << it2.operator->()->second << endl;
        }
    }
    
}