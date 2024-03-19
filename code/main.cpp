#include "Huffman/Huffman.cpp"
#include "Arithmetic/Arithmetic.cpp"
#include "RunLength/RLE.cpp"
#include <iostream>
#include <chrono>  // For measuring time


/*
    * Compress the input data using Huffman coding
    * @param data The input data to compress
    * 
*/
void HuffmanCompressEvaluate(std::string data){
    Huffman huffman;
    std::cout << "Huffman: Start compressing data" << std::endl;
    // compress the data and start the timer
    auto startTime = std::chrono::steady_clock::now();
    std::string compressedData = huffman.compress(data);
    auto endTime = std::chrono::steady_clock::now();
    std::cout << "Huffman: Finish compressing data" << std::endl;
    std::cout << "Huffman: Compressing time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // decompress the data and start the timer
    std::cout << "Huffman: Start decompressing data" << std::endl;
    startTime = std::chrono::steady_clock::now();
    std::string decompressedData = huffman.decompress(compressedData);
    endTime = std::chrono::steady_clock::now();
    std::cout << "Huffman: Finish decompressing data" << std::endl;
    std::cout << "Huffman: Decompress time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // get the size of the compressed data file
    std::cout << "Huffman: Compressed data size: " << compressedData.size() << " bits" << std::endl;
    std::cout << "Huffman: The compress ratio: " << (double)compressedData.size() / (double)data.size() / 8 * 100 << "%" << std::endl;
}

/*
    * Compress the input data using Arithmetic coding
    * @param data The input data to compress
    * 
*/

void ArithmeticCompressEvaluate(std::string data){
    ArithmeticEncoder arithmeticEncoder;
    std::cout << "Arithmetic: Start compressing data" << std::endl;
    // compress the data and start the timer
    auto startTime = std::chrono::steady_clock::now();
    std::string compressedData = arithmeticEncoder.encode(data);
    auto endTime = std::chrono::steady_clock::now();
    std::cout << "Arithmetic: Finish compressing data" << std::endl;
    std::cout << "Arithmetic: Compressing time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // decompress the data and start the timer
    std::cout << "Arithmetic: Start decompressing data" << std::endl;
    startTime = std::chrono::steady_clock::now();
    std::string decompressedData = arithmeticEncoder.decode(compressedData);
    endTime = std::chrono::steady_clock::now();
    std::cout << "Arithmetic: Finish decompressing data" << std::endl;
    std::cout << "Arithmetic: Decompress time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // get the size of the compressed data file
    std::cout << "Arithmetic: Compressed data size: " << compressedData.size() << " bits" << std::endl;
    std::cout << "Arithmetic: The compress ratio: " << (double)compressedData.size() / (double)data.size() / 8 * 100 << "%" << std::endl;
}

void RunLengthCompressEvaluate(std::string data){
    std::cout << "Run-length: Start compressing data" << std::endl;
    // compress the data and start the timer
    auto startTime = std::chrono::steady_clock::now();
    std::vector<unsigned char> input;
    for (int i = 0; i < data.size(); i++) {
        input.push_back(data[i]);
    }
    std::vector<unsigned char> compressedData = runLengthEncode(input);
    // print the compressed data
    // for (int i = 0; i < compressedData.size(); i++) {
    //     std::cout << (int)compressedData[i] << " ";
    // }
    auto endTime = std::chrono::steady_clock::now();
    std::cout << "Run-length: Finish compressing data" << std::endl;
    std::cout << "Run-length: Compressing time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // decompress the data and start the timer
    std::cout << "Run-length: Start decompressing data" << std::endl;
    startTime = std::chrono::steady_clock::now();
    std::vector<unsigned char> decompressedData = runLengthDecode(compressedData);
    std::string result;
    for (int i = 0; i < decompressedData.size(); i++) {
        result += decompressedData[i];
    }
    endTime = std::chrono::steady_clock::now();
    std::cout << "Run-length: Finish decompressing data" << std::endl;
    std::cout << "Run-length: Decompress time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    std::cout << "----------------------------------"<< std::endl;
    // get the size of the compressed data file
    std::cout << "Run-length: Compressed data size: " << compressedData.size() << " bits" << std::endl;
    std::cout << "Run-length: The compress ratio: " << (double)compressedData.size() / (double)data.size() * 100 << "%" << std::endl;
}

int main() {
    std::string data = "hello";
    //HuffmanCompressEvaluate(data);
    //ArithmeticCompressEvaluate(data);
    RunLengthCompressEvaluate(data);
    return 0;
}

