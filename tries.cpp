#include "tries.h"

//input checker helper function
bool is_valid_input(const string& word) {
    //cannot insert empty string
    if(word == "") {
        return false;
    }
    //if word includes characters outside the range of lowercase chars
    for(int i = 0; i < word.length(); i++) {
        if(word[i] < 97 || word[i] > 122) {
            return false;
        }
    }
    return true;
}

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
bool Trie::insert(string word) {
    trie_node* current = root;
    
    //check for valid input
    if(!is_valid_input(word)) {
        return false;
    }
    
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
    return true;
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

//prefix search function
bool Trie::prefix_search(string prefix) {
    trie_node* current = root;

    //process the given word
    for(int i = 0; i < prefix.length(); i++) {
        char current_letter = prefix[i];
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
    //iteration complete; entire prefix must be present
    return true;
}

//remove helper function
bool Trie::remove_helper(trie_node* root, const string& word, int index) {
    if(index == word.length()) {
        root->end_of_word = false;
        return true;
    }
}

//remove word function
bool Trie::remove(string word) {
    
    //check for valid input
    if(!is_valid_input(word)) {
        return false;
    }
    //if word does not exist in trie
    if(!search(word)) {
        return false;
    }

    return remove_helper(root, word, 0);
    
}

