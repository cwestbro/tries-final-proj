#include "tries.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Testing All Trie Functions ===" << endl;
    
    Trie test_trie;

    //test insertions
    cout << "Insert 'cat': " << test_trie.insert("cat") << endl;
    cout << "Insert 'car': " << test_trie.insert("car") << endl;
    cout << "Insert 'card': " << test_trie.insert("card") << endl;
    cout << "Insert invalid '': " << test_trie.insert("") << endl;
    
    //test searches
    cout << "Search 'cat': " << test_trie.search("cat") << endl;
    cout << "Search 'dog': " << test_trie.search("dog") << endl;
    
    //test prefix search
    cout << "Prefix search 'ca': " << test_trie.prefix_search("ca") << endl;
    cout << "Prefix search 'do': " << test_trie.prefix_search("do") << endl;
    
    //test remove
    cout << "Remove 'cat': " << test_trie.remove("cat") << endl;
    cout << "Search 'cat' after remove: " << test_trie.search("cat") << endl;
    cout << "Search 'car' still there: " << test_trie.search("car") << endl;

    //test word instance search
    test_trie.word_instances("sample.txt", "tree");

    //test replace
    test_trie.replace_all("input.txt", "output.txt", "cat", "hamster");
    //read the new file
    ifstream output_file("output.txt");
    string line;
    while(getline(output_file, line)) {
        cout << line << endl;
    }
    output_file.close();
    
    cout << "All tests complete!" << endl;
    return 0;
}

