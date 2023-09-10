struct Node {
    Node* links[26];
    bool flag;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void putChar(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getChar(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    Node() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->putChar(word[i], new Node());
            }
            node = node->getChar(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->getChar(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getChar(prefix[i]);
        }

        return true;
    }
};