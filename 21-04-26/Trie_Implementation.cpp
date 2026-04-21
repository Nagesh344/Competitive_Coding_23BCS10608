```cpp
#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char c) {
        ch = c;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string str) {
        // Base Case
        if (str.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = str[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // Absent
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertUtil(child, str.substr(1));
    }

    void insertWord(string str) {
        insertUtil(root, str);
    }

    bool searchUtil(TrieNode* root, string str) {
        // Base Case
        if (str.size() == 0) {
            return root->isTerminal;
        }

        int index = str[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        return searchUtil(child, str.substr(1));
    }

    bool searchWord(string str) {
        return searchUtil(root, str);
    }

    bool startsWithUtil(TrieNode* root, string str) {
        if (str.size() == 0) {
            return true;
        }

        int index = str[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        return startsWithUtil(child, str.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

void solve() {
    Trie t;

    t.insertWord("HELLO");
    t.insertWord("HEY");
    t.insertWord("DOG");
    t.insertWord("CAT");

    cout << t.searchWord("HELLO") << endl;   // 1
    cout << t.searchWord("HEY") << endl;     // 1
    cout << t.searchWord("HEL") << endl;     // 0
    cout << t.searchWord("DOG") << endl;     // 1
    cout << t.searchWord("COW") << endl;     // 0

    cout << t.startsWith("HE") << endl;      // 1
    cout << t.startsWith("DO") << endl;      // 1
    cout << t.startsWith("CA") << endl;      // 1
    cout << t.startsWith("XY") << endl;      // 0
}

int32_t main() {
    jack420;

    int t = 1;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
