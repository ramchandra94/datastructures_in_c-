#include "TrieNode.h"
#include<string>

class Trie {
	TrieNode *root;

	public:

	Trie() {
		root = new TrieNode('\0');
	}
	
	void insert(TrieNode * root, string word){
		if(word.size() == 0){
			root -> isTerminal = true;
			return;
		}
		
		TrieNode *child;
		int index = word[0] - 'a'
		if(root->children[index] != NULL){
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		insert(child, word.substr(1));
	}

	void insert(string word){
		insert(root, word);
	}
}


