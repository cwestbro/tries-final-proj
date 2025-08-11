#include "tries.h"

Trie::Trie() {
    root = new trie_node;
}

Trie::~Trie() {
    delete_Trie(root);
}

//deletion helper function
void Trie::delete_Trie(trie_node* node) {
    if(node == nullptr) {
        return;
    }
    else {
        for(int i = 0; i < 26; i++) {
            if(node->letters[i] != nullptr) {
                delete_Trie(node->letters[i]);
            }
        }
    }
    delete node;
}
//insert word function
void Trie::insert(string word) {
    trie_node* current = root;
    
    //process the given word by letter
    for(int i = 0; i < word.length(); i++) {
        char current_letter = word[i];
        int index = current_letter - 'a';

        //if the letter does not yet exist in the trie
        if(current->letters[index] == nullptr) {
            //create a new node
            current->letters[index] = new trie_node;    
        }
        //if the letter already exists, move on
        current = current->letters[index];
    }
    //mark the end of the word
    current->end_of_word = true;
}
//search function
bool Trie::search(string word) {
    trie_node* current = root;

    //process the given word by letter
    for(int i = 0; i < word.length(); i++) {
        char current_letter = word[i];
        int index = current_letter - 'a';

        //if the letter doesn't exist in the trie
        if(current->letters[index] == nullptr) {
            return false;
        }
        else {
            //continue to move the cursor variable
            current = current->letters[index];
        }
    }
    //check for end of the word
    if(current->end_of_word) {
        return true;
    }
    else {
        return false;
    }
}

