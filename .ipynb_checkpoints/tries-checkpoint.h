#include <memory>
#include <string>
#include <vector>

using namespace std;

struct trie_node {
    trie_node* letters[26] = {};
    bool end_of_word = false;
};

class Trie {
    public:
    //constructor
    Trie();
    //destructor
    ~Trie();

    private:
    
}