#include "Huffman.h"
#include <iostream>
#include <sstream>
#include <fstream>

Huffman::Huffman() {}

Huffman::~Huffman() {
    // Destroy the Huffman tree
    destroyHuffmanTree(root);
}

std::string Huffman::compress(const std::string& data) {
    // Build the frequency table, Huffman tree, and code table
    buildFrequencyTable(data);
    root = buildHuffmanTree();
    buildCodeTable(root, "");
    // make the string input to the Huffman.out
    std::ofstream outputFile("Huffman.out", std::ios::binary);
    std::string compressedData = encode(data);
    outputFile << compressedData;
    outputFile.close();
    return compressedData;
}

std::string Huffman::decompress(const std::string& data) {
    return decode(data);
}

void Huffman::buildFrequencyTable(const std::string& data) {
    // Clear the frequency table
    frequencyTable.clear();
    // Build the frequency table
    for (char c : data) {
        frequencyTable[c]++;
    }
    // print frequency table
    // for (const auto& pair : frequencyTable) {
    //     std::cout << pair.first << " " << pair.second << std::endl;
    // }
}

HuffmanNode* Huffman::buildHuffmanTree() {
    // Lambda function to compare the frequency of two nodes
    auto compare = [](HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    };

    // Create a priority queue to store the nodes
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, decltype(compare)> pq(compare);

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencyTable) {
        HuffmanNode* node = new HuffmanNode();
        node->data = pair.first;
        node->frequency = pair.second;
        node->left = nullptr;
        node->right = nullptr;
        pq.push(node);
    }

    // Create an internal node by combining the two nodes with the lowest frequency
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode();
        parent->data = '\0';  // Internal node has no character
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // The remaining node is the root of the Huffman tree
    HuffmanNode* root = pq.top();
    pq.pop();

    return root;
}

void Huffman::buildCodeTable(HuffmanNode* root, std::string code) {
    // Traverse the tree to build the code table
    if (root == nullptr) {
        return;
    }

    // Leaf node
    if (root->data != '\0') {  // Leaf node
        codeTable[root->data] = code;
    }

    // Internal node
    buildCodeTable(root->left, code + "0");
    buildCodeTable(root->right, code + "1");

}

void Huffman::destroyHuffmanTree(HuffmanNode* node) {
    // Post-order traversal to delete the tree
    if (node == nullptr) {
        return;
    }
    // delete left and right children
    destroyHuffmanTree(node->left);
    destroyHuffmanTree(node->right);

    delete node;
}

std::string Huffman::encode(const std::string& data) {
    // Encode the input data using the code table
    std::stringstream encodedData;
    for (char c : data) {
        encodedData << codeTable[c];
    }
    return encodedData.str();
}

std::string Huffman::decode(const std::string& data) {
    std::string decodedString;
    HuffmanNode* currentNode = root;

    for (char bit : data) {
        if (bit == '0') {
            // Traverse to the left child
            currentNode = currentNode->left;
        } else if (bit == '1') {
            // Traverse to the right child
            currentNode = currentNode->right;
        }

        // Check if the current node is a leaf node
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            // Found a leaf node, append the character to the decoded string
            decodedString += currentNode->data;

            // Reset the current node to the root for the next character
            currentNode = root;
        }
    }

    return decodedString;
}