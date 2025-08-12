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

//check for children helper function
bool Trie::node_has_children(trie_node* node) {
    for(int i = 0; i < 26; i++) {
        //trace all possible paths for children
        if(node->letters[i] != nullptr) {
            return true;
        }
    }
    return false;
}

//remove helper function
bool Trie::remove_helper(trie_node* root, const string& word, int index) {
    if(index == word.length()) {
        root->end_of_word = false;
        return (!node_has_children(root));
    }

    char current_letter = word[index];
    int letter_index = current_letter - 'a';

    //if path does not exist
    if(root->letters[letter_index] == nullptr) {
        return false;
    }
    //check if safe to remove
    bool can_delete_child = remove_helper(root->letters[letter_index], word, index + 1);

    if(can_delete_child) {
        delete root->letters[letter_index];
        root->letters[letter_index] = nullptr;
    }
    //can only delete if no children and not the end of another word
    return (!node_has_children(root)) && (!root->end_of_word);
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

// __________________________________________________ //

//count instances of a given word
int Trie::word_instances(const string& filename, const string& word) {
    //open and read a text file
    ifstream text(filename);

    //instance count
    int count = 0;
    string line;

    while(getline(text, line)) {
        stringstream ss(line);
        string current_word;

        //read through the file line by line, word by word
        while(ss >> current_word) {
            //increment count if a match is found
            if(search(current_word) && current_word == word) {
                count ++;
            }
        }
    }
    text.close();
    cout << word << ": " << count;
    return count;
}

//replace all instances of a given word
void Trie::replace_all(const string& input_file, const string& output_file,
const string& old_word, const string& new_word) {
    ifstream original_text(input_file);
    ofstream new_text(output_file);

    string line;
    while(getline(original_text, line)) {
        stringstream ss(line);
        string current_word;

        string new_line;
        while(ss >> current_word) {
            if(current_word == old_word) {
                current_word = new_word;
            }
            new_line += current_word + " ";
        }
        new_text << new_line << endl;
    }
}