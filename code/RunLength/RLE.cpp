#include "RLE.h"

std::vector<unsigned char> runLengthEncode(const std::vector<unsigned char>& input) {
    std::vector<unsigned char> encoded;
    // The count of the current character
    unsigned char count = 1;
    for (int i = 1; i < input.size(); i++) {
        // If the current character is the same as the previous one, increase the count
        if (input[i] == input[i - 1]) {
            count++;
        } 
        // If the current character is different from the previous one, add the count and the character to the encoded data
        else {
            encoded.push_back(count);
            encoded.push_back(input[i - 1]);
            count = 1;
        }
    }
    // Add the last count and character to the encoded data
    encoded.push_back(count);
    encoded.push_back(input[input.size() - 1]);
    return encoded;
}


std::vector<unsigned char> runLengthDecode(const std::vector<unsigned char>& input) {
    std::vector<unsigned char> decoded;
    // Decode the input data
    for (int i = 0; i < input.size(); i += 2) {
        unsigned char count = input[i];
        unsigned char ch = input[i + 1];
        decoded.insert(decoded.end(), count, ch);
    }
    return decoded;
}