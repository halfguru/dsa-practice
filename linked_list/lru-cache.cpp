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
		m_usage.splice(m_usage.begin(), m_usage, m_cache[key]);
		// return associated key
		return m_cache[key]->second;
	}

	void put(int key, int value)
	{
		// if key exist, update value and move to front
		if (get(key) != -1)
		{
			m_cache[key]->second = value;
			return;
		}
		// if cache is ful, remove LRU element
		if (m_usage.size() == m_capacity)
		{
			const int lastKey = m_usage.back().first;
			m_usage.pop_back();
			m_cache.erase(lastKey);
		}

		// Insert key-value pair to front of list
		m_usage.push_front({key, value});
		// Update hash map with the iterator the new element in the list
		m_cache[key] = m_usage.begin();
	}

private:
	int m_capacity;
	// maintain order of key usage
	std::list<std::pair<int, int>> m_usage;
	// hash map to access list elements by key
	// map value is iterator pointing to element in the list
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
