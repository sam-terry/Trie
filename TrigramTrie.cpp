#include "TrigramTrie.h"



TrigramTrie::TrigramTrie(char language[4]) {
    // Create root node for trie; its unigram is an empty C-string, and it is not a leaf
    std::shared_ptr<UnigramNode> rt(new UnigramNode);
    rt->unigram = '\0';
    rt->isLeaf = false;

    // Set root for the trie
    this->root = rt;

    // Set lang for the tree
    strcpy(this->lang,language);
}

TrigramTrie::~TrigramTrie() {}

void TrigramTrie::PrintLanguage() {
    std::cout << this->lang << std::endl;

}

std::shared_ptr<UnigramNode> TrigramTrie::InitNode(char c) {
    std::shared_ptr<UnigramNode> newnode(new UnigramNode);

    newnode->unigram = c;
    newnode->isLeaf = false;
    newnode->count = 0;
    return newnode;
}

void TrigramTrie::InsertTrigram(char trigram[4]) {
    std::shared_ptr<UnigramNode> current = this->root;

    // Position of character in trigram to be added
    int trigram_pos = 0;

    while (trigram_pos < 3) {

        auto it = (current->progeny).find(trigram[trigram_pos]);

        // If the character is not already a child of the current node, add it
        if (it == (current->progeny).end()) {

            // Create new unigram node with the character at the specified position
            std::shared_ptr<UnigramNode> newnode = InitNode(trigram[trigram_pos]);

            // Insert the new character/node into the progeny map
            (current->progeny).insert({trigram[trigram_pos],newnode});

            // Move to the newly created node
            current = newnode;
        }

        // If the character is already a child of the current node, move to that child
        else {
            current = it->second;
        }

        // Insert the next character from the trigram
        ++trigram_pos;
    }

    // Incremenent the count of the leaf node, which represents the count for that trigram
    ++(current->count);
    (current->isLeaf) = true;

}

void TrigramTrie::PrintTrie() {
    std::shared_ptr<UnigramNode> current = this->root;

    std::cout << "root -> " << std::endl;

    auto it = (current->progeny).find('s');
    std::cout << it->first << " -> ";

    current = it->second;
    it = (current->progeny).find('a');
    std::cout << it->first << " -> ";

    current = it->second;
    it = (current->progeny).find('m');
    std::cout << it->first << std::endl;

    current = it->second;
    std::cout << current->unigram << " count: " << current->count << std::endl;

    if (current->isLeaf) {
        std::cout << current->unigram << " is a leaf node." << std::endl;
    }
}