#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include <string>
#include <map>

class ArithmeticEncoder {
public:
    /*
        * Set the probabilities of the symbols
        * @param probabilities The probabilities of the symbols
    */
    void setSymbolProbabilities(const std::map<char, double>& probabilities);

    /*
        * Encode the input data using arithmetic coding
        * @param input The input data to encode
        * @return The encoded data string, which is a sequence of 0s and 1s
    */
    std::string encode(const std::string& input);

    /*
        * Decode the input data using arithmetic coding
        * @param input The input data to decode
        * @return The decoded data string, which is the original data
    */
    std::string decode(const std::string& encoded);

private:
    // The probabilities of the symbols
    std::map<char, double> symbolProbabilities;
    // The cumulative probabilities of the symbols
    std::map<char, double> cumulativeProbabilities;


};

#endif  // ARITHMETIC_H