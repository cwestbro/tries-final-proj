#include "tries.h"

using namespace std;

bool valid_word(const string& word);
vector<string> find_words(const string& letters);

int main() {
    cout << "=== Testing Scrabble Functions ===" << endl;

    //test valid word checker
    cout << "valid_word('cat'): " << valid_word("cat") << endl;
    cout << "valid_word('anemone'): " << valid_word("anemone") << endl;
    cout << "valid_word('grool'): " << valid_word("grool") << endl;
    cout << "valid_word('BONE'): " << valid_word("BONE") << endl;

    //test find words function
    //2-letter words
    cout << "words from 'ab': " << endl;
    vector<string> ab = find_words("ab");
    for(const string& word : ab) {
        cout << " " << word << endl;
    }

    //3-letter words
    cout << "words from 'pto': " << endl;
    vector<string> pto = find_words("pto");
    for(const string& word : pto) {
        cout << " " << word << endl;
    }

    //longer words with many anagrams
    cout << "words from 'aegilnrt': " << endl;
    vector<string> aegilnrt = find_words("aegilnrt");
    for(const string&word : aegilnrt) {
        cout << " " << word << endl;
    }

    cout << "All tests complete!" << endl;
    return 0;
}