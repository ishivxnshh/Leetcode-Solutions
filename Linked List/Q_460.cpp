#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
private:
    struct Node
    {
        int key, value, freq;
        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity, size;

    unordered_map<int, list<vector<int>>::iterator> mpp; // key -> address (iterator to vector in freq list)
    map<int, list<vector<int>>> freq;                    // freq -> list of {key, value, counter}

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    void makeMostFrequentlyUsed(int key)
    {
        auto &vec = (*(mpp[key]));

        int value = vec[1];
        int f = vec[2];

        freq[f].erase(mpp[key]);

        if (freq[f].empty())
        {
            freq.erase(f);
        }

        f++;

        freq[f].push_front({key, value, f});
        mpp[key] = freq[f].begin();
    }

    int get(int key)
    {
        if (!mpp.contains(key))
        {
            return -1;
        }

        auto vec = (*(mpp[key]));
        int value = vec[1];

        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }

        if (mpp.contains(key))
        {
            auto &vec = (*(mpp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if (size < capacity)
        {
            size++;
            freq[1].push_front({key, value, 1});
            mpp[key] = freq[1].begin();
        }
        else
        {
            auto &konsi_list = freq.begin()->second;
            int key_to_delete = (konsi_list.back())[0];

            konsi_list.pop_back();

            if (konsi_list.empty())
            {
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front({key, value, 1});
            mpp.erase(key_to_delete);
            mpp[key] = freq[1].begin();
        }
    }
};

// ---------------- DRIVER CODE ----------------

int main()
{
    LFUCache *lfu = new LFUCache(2);

    lfu->put(1, 1);
    lfu->put(2, 2);
    cout << lfu->get(1) << endl; // returns 1
    lfu->put(3, 3);              // evicts key 2
    cout << lfu->get(2) << endl; // returns -1 (not found)
    cout << lfu->get(3) << endl; // returns 3
    lfu->put(4, 4);              // evicts key 1
    cout << lfu->get(1) << endl; // returns -1
    cout << lfu->get(3) << endl; // returns 3
    cout << lfu->get(4) << endl; // returns 4

    return 0;
}