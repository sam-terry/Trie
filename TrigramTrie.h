#include <memory>
#include <vector>
#include <map>
#include <iostream>


struct UnigramNode {
    char unigram;
    bool isLeaf;
    std::map<char,std::shared_ptr<UnigramNode> > progeny;
    int count;
};


class TrigramTrie {
    private:
        char lang[4]; // 3-char language code for the language model stored in the trie

        std::shared_ptr<UnigramNode> root; // root node for the tree, whose unigram member is an empty string

        // Generate a node with the specified character
        std::shared_ptr<UnigramNode> InitNode(char c); 
    public:
        // Constructor; create trigram LM trie for the language with the specified code
        TrigramTrie(char language[4]);

        // Destructor (empty with use of smart pointers)
        ~TrigramTrie();

        // Testing method used to print the language code of the trie's LM
        void PrintLanguage();

        // Inserts the specified trigram into the tree;
        void InsertTrigram(char trigram[4]);

        void PrintTrie();

        // Prunes the trie, removing less common trigrams
        void Prune(); 

};