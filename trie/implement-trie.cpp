// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a
// dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
//
// Implement the Trie class:
//
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false
// otherwise. boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the
// prefix prefix, and false otherwise.

#include <string>

using namespace std;

// each node is a character and has map or an array of child nodes
// boolean flag to indicate if node represents end of a word
// time: O(m) length of word
// space: O(26 * m * n) m average length of word and n number of words
class TrieNode
{
public:
	bool isEnd;
	TrieNode* children[26];

	TrieNode()
	{
		isEnd = false;
		for (int i = 0; i < 26; ++i)
		{
			children[i] = nullptr;
		}
	}
};

class Trie
{
private:
	TrieNode* root;

public:
	Trie() { root = new TrieNode(); }

	void insert(string word)
	{
		TrieNode* node = root;
		for (char c: word)
		{
			const int index = c - 'a';
			if (!node->children[index])
			{
				node->children[index] = new TrieNode();
			}
			node = node->children[index];
		}
		node->isEnd = true;
	}

	bool search(string word)
	{
		TrieNode* node = root;
		for (char c: word)
		{
			const int index = c - 'a';
			if (!node->children[index])
			{
				return false;
			}
			node = node->children[index];
		}
		return node->isEnd;
	}

	bool startsWith(string prefix)
	{
		TrieNode* node = root;
		for (char c: prefix)
		{
			const int index = c - 'a';
			if (!node->children[index])
			{
				return false;
			}
			node = node->children[index];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
