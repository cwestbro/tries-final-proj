#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct trie_node {
    //fixed array of pointers for entire lowercase alphabet
    trie_node* letters[26] = {};
    //mark where a word ends
    bool end_of_word = false;
};

class Trie {
    private:
    trie_node* root;
    //deltion helper function
    void delete_Trie(trie_node* node);
    //remove helper function
    bool remove_helper(trie_node* node, const string& word, int index);
    //check for children helper function
    bool node_has_children(trie_node* node);
    
    public:
    //constructor
    Trie();
    //destructor
    ~Trie();

    //will insert a word into the trie
    bool insert(string word);
    //will remove a word from the trie
    bool remove(string word);
    //will search the trie and return true if it exists
    bool search(string word);
    //will search the trie for word(s) that begin with the given prefix and return true if it exists
    bool prefix_search(string prefix);
    //will return number of instances of given word
    void word_instances(const string& filename, const string& word);
    //will replace all instances of a particular word
    void replace_all(const string& input_file, const string& output_file, const string& old_word, const string& new_word);

};
//input checker helper function
bool is_valid_input(const string& word);