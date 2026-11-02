/*#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char data;
    int freq;
    Node *left, *right;
    
    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator for priority queue (min-heap based on frequency)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Store Huffman codes in a map
map<char, string> huffmanCode;

// Generate Huffman codes recursively
void generateCodes(Node* root, string code) {
    if (root == NULL) return;
    
    // Leaf node - store the code
    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
    }
    
    // Traverse left (add 0) and right (add 1)
    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

// Build Huffman Tree using greedy strategy
void buildHuffmanTree(string text) {
    // Count frequency of each character
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    
    // Create priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    // Create leaf nodes and add to priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    
    // Build Huffman Tree by combining nodes with lowest frequency
    while (pq.size() > 1) {
        // Extract two nodes with minimum frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        // Create new internal node with combined frequency
        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;
        
        // Add back to priority queue
        pq.push(newNode);
    }
    
    // Root of Huffman Tree
    Node* root = pq.top();
    
    // Generate Huffman codes
    generateCodes(root, "");
    
    // Display Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // Display encoded string
    cout << "\nEncoded String:\n";
    string encodedString = "";
    for (char c : text) {
        encodedString += huffmanCode[c];
    }
    cout << encodedString << endl;
}

int main() {
    string text;
    
    cout << "Enter the text to encode: ";
    getline(cin, text);
    
    if (text.empty()) {
        cout << "Please enter some text." << endl;
        return 0;
    }
    
    cout << "\nOriginal Text: " << text << endl;
    buildHuffmanTree(text);
    
    // Complexity Analysis
    cout << "\nComplexity Analysis:" << endl;
    cout << "Time Complexity: O(n log n) where n is number of unique characters" << endl;
    cout << "Space Complexity: O(n) for storing the tree and codes" << endl;
    
    return 0;
}*/


#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator class for min-heap
class Compare {
public:
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Store Huffman codes in a map
map<char, string> huffmanCode;

// Generate Huffman codes recursively
void generateCodes(Node* root, string code) {
    if (root == NULL)
        return;

    // Leaf node - store the code
    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
    }

    // Traverse left (add 0) and right (add 1)
    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

// Build Huffman Tree using greedy strategy
void buildHuffmanTree(string text) {
    // Count frequency of each character
    map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    // Create priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes and add to priority queue
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        // Extract two nodes with minimum frequency
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create internal node with combined frequency
        int sum = left->freq + right->freq;

        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Generate Huffman codes
    generateCodes(root, "");

    // Display Huffman codes
    cout << "Huffman Codes:\n";

    for (auto p : huffmanCode) {
        cout << p.first << " : " << p.second << endl;
    }

    // Display encoded string
    cout << "\nEncoded String:\n";

    string encodedString = "";

    for (char c : text) {
        encodedString += huffmanCode[c];
    }

    cout << encodedString << endl;
}

int main() {
    string text;

    cout << "Enter the text to encode: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Please enter some text." << endl;
        return 0;
    }

    cout << "\nOriginal Text: " << text << endl;

    buildHuffmanTree(text);

    // Complexity Analysis
    cout << "\nComplexity Analysis:" << endl;
    cout << "Time Complexity: O(n log n), where n is the number of unique characters" << endl;
    cout << "Space Complexity: O(n) for storing the tree and codes" << endl;

    return 0;
}