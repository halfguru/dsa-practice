// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
// sequence of one or more dictionary words.
//
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// time: O(N * L)
// space: O(M) for queue
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

	void insert(const string& word)
	{
		TrieNode* node = root;
		for (char c: word)
		{
			int index = c - 'a';
			if (!node->children[index])
			{
				node->children[index] = new TrieNode();
			}
			node = node->children[index];
		}
		node->isEnd = true;
	}

	TrieNode* getRoot() { return root; }

	bool search(const string& word)
	{
		TrieNode* node = root;
		for (char c: word)
		{
			int index = c - 'a';
			if (!node->children[index])
			{
				return false;
			}
			node = node->children[index];
		}
		return node->isEnd;
	}

	bool startsWith(const string& prefix)
	{
		TrieNode* node = root;
		for (char c: prefix)
		{
			int index = c - 'a';
			if (!node->children[index])
			{
				return false;
			}
			node = node->children[index];
		}
		return true;
	}
};

class Solution
{
public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		Trie trie;
		for (const string& word: wordDict)
		{
			trie.insert(word);
		}

		queue<int> q;
		unordered_set<int> visited;
		q.push(0);

		// use BFS to travers string s to see all possible segmentations
		// Start from index 0 to find prefixes in s that exist in Trie.
		// For each valid prefix, enqueue the position just after the prefix as
		// starting point for the next potnetial prefix
		while (!q.empty())
		{
			const auto start = q.front();
			q.pop();

			if (visited.find(start) != visited.end())
			{
				continue;
			}
			visited.insert(start);

			TrieNode* node = trie.getRoot();
			for (int end = start; end < s.size(); ++end)
			{
				const int index = s[end] - 'a';
				if (!node->children[index])
				{
					break;
				}
				node = node->children[index];
				if (node->isEnd)
				{
					if (end == s.size() - 1)
					{
						return true;
					}
					q.push(end + 1);
				}
			}
		}
		return false;
	}
};
