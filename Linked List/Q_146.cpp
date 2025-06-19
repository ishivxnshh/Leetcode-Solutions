#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->prev = this->next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deletionOfNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertionAfterHead(Node* node)
    {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
        {
            return -1;
        }

        Node* node = mpp[key];
        deletionOfNode(node);
        insertionAfterHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            node->val = value;
            deletionOfNode(node);
            insertionAfterHead(node);
        }
        else
        {
            if (mpp.size() == cap)
            {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                deletionOfNode(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertionAfterHead(node);
        }
    }
};

// ---------------------------------------------
// Driver Code
// ---------------------------------------------

int main()
{
    LRUCache* lru = new LRUCache(2); // Capacity = 2

    lru->put(1, 1);        // Cache: {1=1}
    lru->put(2, 2);        // Cache: {2=2, 1=1}

    cout << lru->get(1) << endl;  // Returns 1, Cache: {1=1, 2=2}

    lru->put(3, 3);        // Evicts key 2, Cache: {3=3, 1=1}

    cout << lru->get(2) << endl;  // Returns -1 (not found)

    lru->put(4, 4);        // Evicts key 1, Cache: {4=4, 3=3}

    cout << lru->get(1) << endl;  // Returns -1 (not found)
    cout << lru->get(3) << endl;  // Returns 3
    cout << lru->get(4) << endl;  // Returns 4

    return 0;
}