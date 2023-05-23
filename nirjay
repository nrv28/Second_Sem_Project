
//Code by Nirjay kumar
//Roll-2201AI26

string encodeString(const string& input) {
    string encodedString = "";
    for (char ch : input) {
        if (isalpha(ch)) {
            encodedString += bitset<8>(ch - 'a' + 2).to_string();
        } else if (isdigit(ch)) {
            encodedString += to_string(ch - '0' - 45);
        } else {
            encodedString += ch;
        }
    }
    return encodedString;
}

string decodeString(const string& input) {
    string decodedString = "";
    for (size_t i = 0; i < input.size(); i += 8) {
        string binaryChunk = input.substr(i, 8);
        if (binaryChunk == "00000000") {
            break;
        }
        if (binaryChunk.find('1') != string::npos) {
            char ch = static_cast<char>(stoi(binaryChunk, nullptr, 2) + 'a' - 2);
            decodedString += ch;
        } else {
            int digit = stoi(binaryChunk) + 45;
            decodedString += to_string(digit);
        }
    }
    
}


