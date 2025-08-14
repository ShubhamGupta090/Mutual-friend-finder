#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> adj;

    void addUser(const string& user) {
        if (adj.find(user) == adj.end()) {
            adj[user] = {};
        }
    }

    void addFriendship(const string& user1, const string& user2) {
        adj[user1].push_back(user2);
        adj[user2].push_back(user1);
    }

    vector<string> getFriends(const string& user) {
        return adj[user];
    }
};
