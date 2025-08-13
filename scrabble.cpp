#include "tries.h"
#include <vector>

using namespace std;

Trie scrabble_dictionary;

//load dictionary function
bool load_dictionary() {
    ifstream dictionary("twl06.txt");

    string word;
    while(getline(dictionary, word)) {
        scrabble_dictionary.insert(word);
    }
    dictionary.close();
    return true;
}

//ensure dictionary is loaded once
bool dictionary_ready = load_dictionary();

//valid word checker
bool valid_word(const string& word) {
    if(!is_valid_input(word)) {
        return false;
    }
    return scrabble_dictionary.search(word);
}

//find words helper function
void generate_combinations(string letters, string current_word, vector<string>& valid_words) {
    //check for minimum word length of 2 and if word is in dictionary
    if(current_word.length() >= 2 && valid_word(current_word))  {
        //add valid word to the list
        valid_words.push_back(current_word);
    }
    //iterate through the string of given letters
    for(int i = 0; i < letters.length(); i++) {
        char letter = letters[i];
        
        string new_word = current_word + letter;
        //use substrings to generate combinations
        string new_remaining = letters.substr(0, i) + letters.substr(i + 1);
        //recursive call
        generate_combinations(new_remaining, new_word, valid_words);
    }
}

//find words from letters function
vector<string> find_words(const string& letters) {
    vector<string> valid_words;
    string current_word;

    generate_combinations(letters, current_word, valid_words);

    return valid_words;
}
