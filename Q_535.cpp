#include <iostream>
using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string originalUrl = "https://www.example.com";
    string encodedUrl = solution.encode(originalUrl);
    string decodedUrl = solution.decode(encodedUrl);

    cout << "Original URL: " << originalUrl << endl;
    cout << "Encoded URL: " << encodedUrl << endl;
    cout << "Decoded URL: " << decodedUrl << endl;

    return 0;
}
