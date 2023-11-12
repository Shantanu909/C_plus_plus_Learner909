#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNode {
    bool operator()(Node* const& a, Node* const& b) {
        return a->freq > b->freq;
    }
};

Node* buildHuffmanTree(map<char, int> frequencies) {
    priority_queue<Node*, vector<Node*>, CompareNode> minHeap;

    for (const auto& pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

void generateHuffmanCodes(Node* root, const string& code, map<char, string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->data] = code;
        return;
    }

    if (root->left) {
        generateHuffmanCodes(root->left, code + '0', codes);
    }

    if (root->right) {
        generateHuffmanCodes(root->right, code + '1', codes);
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    map<char, int> frequencies;
    for (char c : input) {
        frequencies[c]++;
    }

    Node* root = buildHuffmanTree(frequencies);

    map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
