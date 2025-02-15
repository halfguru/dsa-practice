// Design a time-based key-value data structure that can store multiple values for the same key at different time stamps
// and retrieve the key's value at a certain timestamp.
//
// Implement the TimeMap class:
//
// TimeMap() Initializes the object of the data structure.
// void set(String key, String value, int timestamp) Stores the key key with the value value at the given time
// timestamp. String get(String key, int timestamp) Returns a value such that set was called previously, with
// timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest
// timestamp_prev. If there are no values, it returns "".

#include <string>
#include <unordered_map>

using namespace std;

// Time complexity: O(1) set O(logn) get
// Space complexity: O(n)
class TimeMap
{
public:
	TimeMap() {}

	void set(string key, string value, int timestamp) { mpp[key].push_back({timestamp, value}); }

	string get(string key, int timestamp)
	{
		// cant find key
		if (mpp.find(key) == mpp.end())
		{
			return "";
		}

		int left = 0;
		int right = static_cast<int>(mpp[key].size() - 1);
		int maxTimeStamp = -1;

		while (left <= right)
		{
			const int mid = left + (right - left) / 2;
			// target is on the right side
			if (mpp[key][mid].first <= timestamp)
			{
				maxTimeStamp = max(maxTimeStamp, mid);
				left = mid + 1;
			}
			else
			{
				left = mid - 1;
			}
		}

		if (maxTimeStamp == -1)
		{
			return "";
		}
		return mpp[key][maxTimeStamp].second;
	}

private:
	unordered_map<string, vector<pair<int, string>>> mpp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
