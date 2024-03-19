#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <queue>

struct HuffmanNode {
    // The character in the node
    char data;
    // The frequency of the character
    int frequency;
    // The left and right child of the node
    HuffmanNode* left;
    HuffmanNode* right;
};

class Huffman {
public:
    // constructor and destructor
    Huffman();
    ~Huffman();

    /*
        * Compress the input data using Huffman coding
        * @param data The input data to compress
        * @return The compressed data string,which is a sequence of 0s and 1s
    */
    std::string compress(const std::string& data);
    

    /*
        * Decompress the input data using Huffman coding
        * @param data The input data to decompress
        * @return The decompressed data string, which is the original data
    */
   std::string decompress(const std::string& data);

private:
    // The root of the Huffman tree
    HuffmanNode* root;  

    /*
        * Build the frequency table based on the input data
        * @param data The input data to build the frequency table
    */
    void buildFrequencyTable(const std::string& data);

    /*
        * Build the Huffman tree based on the frequency table
        * @return The root of the Huffman tree
    */
    HuffmanNode* buildHuffmanTree();

    /*
        * Build the code table based on the Huffman tree
        * @param root The root of the Huffman tree
        * @param code The code for the current node
    */
    void buildCodeTable(HuffmanNode* root, std::string code);

    /*
        * Destroy the Huffman tree
        * @param node The root of the Huffman tree
    */
    void destroyHuffmanTree(HuffmanNode* node);

    /*
        * Encode the input data using the code table
        * @param data The input data to encode
        * @return The encoded data string
    */
    std::string encode(const std::string& data);

    /*
        * Decode the input data using the code table
        * @param data The input data to decode
        * @return The decoded data string
    */
    std::string decode(const std::string& data);

    // The frequency table
    std::unordered_map<char, int> frequencyTable;

    // The code table
    std::unordered_map<char, std::string> codeTable;
};

#endif  // HUFFMAN_H