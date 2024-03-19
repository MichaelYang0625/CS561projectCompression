#ifndef RLE_H
#define RLE_H

#include <vector>

/*
    * Run-length encode the input data
    * @param input The input data to run-length encode
    * @return The run-length encoded data
*/
std::vector<unsigned char> runLengthEncode(const std::vector<unsigned char>& input);

/*
    * Run-length decode the input data
    * @param input The input data to run-length decode
    * @return The run-length decoded data
*/
std::vector<unsigned char> runLengthDecode(const std::vector<unsigned char>& input);

#endif // RLE_H