#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include <string>


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

        // Number of different trigrams which occur in the language's tree
        int trigramCount;
    public:
    
        // Constructor; create trigram LM trie for the language with the specified code
        TrigramTrie(char language[4]);

        // Destructor (empty with use of smart pointers)
        ~TrigramTrie();

        // Testing method used to print the language code of the trie's LM
        void PrintLanguage();

        // Testing method used to print all trigrams in the trie with their corresponding counts
        void PrintTrieContents(std::shared_ptr<UnigramNode> start = nullptr, std::string gram = "");

        // Inserts the specified trigram into the tree;
        void InsertTrigram(char trigram[4]);

        /*
         * Prunes the tree, removing less common trigrams
         * @param start (optional) -- the starting point for the trie traversal
            * The optional argument allows the function to be called recursively on particular nodes in the trie
            * If such a starting node is not specified, the function instead begins at the root
         * @return true if the starting node is to be pruned, false otherwise
         */
        // bool Prune(std::optional <std::shared_ptr<UnigramNode> > start);
        bool Prune(std::shared_ptr<UnigramNode> start = nullptr);

        // Return the number of trigrams stored in the trie
        int GetOverallCount() {return this->trigramCount;}


        // Recursively update the log prob scores of each trigram in the trie
        // void UpdateProbs(std::optional <std::shared_ptr<UnigramNode> > start);
};