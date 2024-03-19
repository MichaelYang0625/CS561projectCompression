#include "Arithmetic.h"

void ArithmeticEncoder::setSymbolProbabilities(const std::map<char, double>& probabilities) {
    // Set the probabilities of the symbols
    symbolProbabilities = probabilities;
    cumulativeProbabilities.clear();
    // Calculate the cumulative probabilities of the symbols
    double cumulativeProbability = 0.0;
    for (const auto& pair : symbolProbabilities) {
        char symbol = pair.first;
        double probability = pair.second;
        cumulativeProbability += probability;
        cumulativeProbabilities[symbol] = cumulativeProbability;
    }
}

std::string ArithmeticEncoder::encode(const std::string& input) {
    // Encode the input data using arithmetic coding
    double low = 0.0;
    double high = 1.0;
    double range = 1.0;
    // Encode each symbol in the input data
    for (char symbol : input) {
        double symbolLow = low + range * cumulativeProbabilities[symbol] - range * symbolProbabilities[symbol];
        double symbolHigh = low + range * cumulativeProbabilities[symbol];
        // Update the range
        low = symbolLow;
        high = symbolHigh;
        range = high - low;
    }
    // Return the encoded data string
    std::string encodedString;
    encodedString += std::to_string(low);

    return encodedString;
}

std::string ArithmeticEncoder::decode(const std::string& encoded) {
    // Decode the input data using arithmetic coding
    double value = std::stod(encoded);
    
    std::string decodedString;
    // Initialize the range
    double low = 0.0;
    double high = 1.0;
    double range = 1.0;
    // Decode each symbol in the input data
    while (true) {
        for (const auto& pair : cumulativeProbabilities) {
            char symbol = pair.first;
            double symbolLow = low + range * cumulativeProbabilities[symbol] - range * symbolProbabilities[symbol];
            double symbolHigh = low + range * cumulativeProbabilities[symbol];
            // Check if the value is within the range of the symbol
            if (value >= symbolLow && value < symbolHigh) {
                decodedString += symbol;
                low = symbolLow;
                high = symbolHigh;
                range = high - low;
                break;
            }
        }
        // Stop decoding if we encounter a null character
        if (decodedString.length() > 0 && decodedString.back() == '\0') {
            break;
        }
    }

    return decodedString;
}