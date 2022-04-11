#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    unordered_map<string, int> votes;
    string line;
    int count = 0;
    while (getline(cin, line) && line != "***") {
        if (votes.find(line) == votes.end()) votes[line] = 0;
        votes[line]++;
        count++;
    }
    
    pair<string, int> most = {"Runoff!", 0};
    for (auto vote : votes) {
        if (vote.second > most.second) {
            most = vote;
        } else if (vote.second == most.second) {
            most.first = "Runoff!";
        }
    }
    cout << most.first << endl;
}
