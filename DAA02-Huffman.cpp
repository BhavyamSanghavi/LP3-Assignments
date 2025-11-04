#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right)
        codes[root->ch] = code;

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Build Huffman Tree and encode text
void huffmanEncode(const string& text) {
    if (text.empty()) {
        cout << "Empty input!\n";
        return;
    }

    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    // Step 2: Push all nodes into min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq)
        pq.push(new Node(p.first, p.second));

    // Step 3: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    // Step 4: Generate Huffman Codes
    Node* root = pq.top();
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    // Step 5: Print Huffman Codes
    cout << "\nHuffman Codes:\n";
    for (auto& p : codes)
        cout << p.first << ": " << p.second << endl;

    // Step 6: Encode input text
    cout << "\nEncoded string: ";
    for (char ch : text)
        cout << codes[ch];
    cout << endl;
}

// Main
int main() {
    string text;
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);

    huffmanEncode(text);
    return 0;
}
