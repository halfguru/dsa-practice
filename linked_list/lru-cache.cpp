// In this question we have to keep track of the most least recently used item in the
// cache.I have designed the cache using list and map in
// C++.We do it by following the steps below
// : -
//
//   When we access an item in the cache it moves to the front of the list as it is the most recently used item
//   .When we want to remove an item we remove it from the last of the list as it
//   is the least recently used item in the cache
//   .When we insert an item we insert it into the front of the list as it is the most recently used item.The
//   idea is to store the keys in the map and its corrosponding values into the list... Note
// : splice() function here takes the element at the m[key]
// 	and places it at the beginning of the list...

#include <unordered_map>

using namespace std;

// Solution is to use a combination of hash map and doubly linked list.
// Hash map provides constant O(1) access to cache entries and doubly linked list maintains
// the order of usage
class LRUCache
{
public:
	LRUCache(int capacity): m_capacity(capacity) {}

	int get(int key)
	{
		// check if key exists in cache
		if (m_cache.find(key) == m_cache.end())
		{
			return -1;
		}
		// Key found, move key-pair value to front of list
		m_list.splice(m_list.begin(), m_list, m_cache[key].second);
		// return associated key
		return m_cache[key].first;
	}

	void put(int key, int value)
	{
		// if key exist, update value and move to front
		if (get(key) != -1)
		{
			m_cache[key].first = value;
			return;
		}
		// if cache is full, remove LRU element
		if (m_cache.size() == m_capacity)
		{
			const int lastKey = m_list.back();
			m_list.pop_back();
			m_cache.erase(lastKey);
		}

		// Insert key-value pair to front of list
		m_list.push_front(key);
		// Update hash map with the iterator the new element in the list
		m_cache[key].second = m_list.begin();
	}

private:
	int m_capacity;
	// maintain order of key usage
	list<int> m_list;
	// hash map to access list elements by key
	// map value is iterator pointing to element in the list
	// use iterator to use splice which is O(1) for moving node to front
	unordered_map<int, pair<int, list<int>::iterator>> m_cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
