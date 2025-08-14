#include "suggestion.cpp"

void loadData(Graph &g) {
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user;
        ss >> user;
        g.addUser(user);

        string friendName;
        while (ss >> friendName) {
            g.addUser(friendName);
            g.addFriendship(user, friendName);
        }
    }
    file.close();
}

void saveData(Graph &g) {
    ofstream file("data.txt");
    for (auto &p : g.adj) {
        file << p.first;
        for (auto &f : p.second) {
            file << " " << f;
        }
        file << "\n";
    }
    file.close();
}

int main() {
    Graph g;
    loadData(g);

    int choice;
    while (true) {
        cout << "\n1. Add User\n2. Add Friendship\n3. Suggest Friends\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter user name: ";
            cin >> name;
            g.addUser(name);
            saveData(g);
            cout << "User added.\n";

        } else if (choice == 2) {
            string u1, u2;
            cout << "Enter first user: ";
            cin >> u1;
            cout << "Enter second user: ";
            cin >> u2;
            g.addFriendship(u1, u2);
            saveData(g);
            cout << "Friendship added.\n";

        } else if (choice == 3) {
            string name;
            cout << "Enter user name: ";
            cin >> name;
            vector<string> suggestions = FriendSuggestion::suggestFriends(g, name);
            if (suggestions.empty()) {
                cout << "No suggestions found.\n";
            } else {
                cout << "Friend suggestions: ";
                for (auto &s : suggestions) cout << s << " ";
                cout << "\n";
            }

        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}
