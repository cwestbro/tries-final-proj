#include "tries.h"
#include <iostream>
using namespace std;


int main() {
    Trie test_trie;

    test_trie.insert("quick");
    test_trie.insert("joy");
    test_trie.insert("qualm");

    test_trie.search("qualm");
    test_trie.search("fox");

    test_trie.prefix_search("qu");
    test_trie.prefix_search("a");

    test_trie.remove("qualm");

    test_trie.search("qualm");

    return 0;

}