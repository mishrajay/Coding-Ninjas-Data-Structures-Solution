#include<iostream>
#include<cstring>
#include"Trie.cpp"
using namespace std;

class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    //insertion
    void insertWord(TrieNode* root, string word){
        //base case
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        //small calc
        TrieNode* child;
        int index = word[0] - 'a';
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //recursive call
        insertWord(child, word.substr(1));

    }

    //for user
    void insertWord(string word){
        insertWord(root, word);
    }

    //searching
    bool searchWord(TrieNode* root, string word){
        if(word.size() == 0){
            if(root -> isTerminal){
                return true;
            }
            else{
                return false;
            }
            //return root -> isTerminal = true;
        }

        int index = word[0] - 'a';
        if(root -> children[index] == NULL){
            return false;
        }

        return searchWord(root -> children[index], word.substr(1));
    }

    bool searchWord(string word){
        return searchWord(root, word);
    }

    //removing
    void removeWord(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //word not found
            return;
        }

        removeWord(child, word.substr(1));

        //remove child node if its useless
        if(!root -> isTerminal){
            for(int i = 0; i < 26; i++){
                if(root -> children[i] != NULL){
                    return;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }

    }

    void removeWord(string word){
        removeWord(root, word);
    }

};

int main() {
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1) {
        string word;
        bool ans;
        switch (choice) {
            case 1:  // insert
                cin >> word;
                t.insertWord(word);
                break;
            case 2:  // search
                cin >> word;
                cout << (t.searchWord(word) ? "true\n" : "false\n");
                break;
            default:
                return 0;
        }
        cin >> choice;
    }

    return 0;
}