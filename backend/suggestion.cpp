#include "graph.cpp"

class FriendSuggestion {
public:
    static vector<string> suggestFriends(Graph& g, const string& user) {
        unordered_set<string> suggestions;
        unordered_set<string> currentFriends(g.getFriends(user).begin(), g.getFriends(user).end());
        currentFriends.insert(user);

        for (auto& friendName : g.getFriends(user)) {
            for (auto& friendOfFriend : g.getFriends(friendName)) {
                if (currentFriends.find(friendOfFriend) == currentFriends.end()) {
                    suggestions.insert(friendOfFriend);
                }
            }
        }
        return vector<string>(suggestions.begin(), suggestions.end());
    }
};
