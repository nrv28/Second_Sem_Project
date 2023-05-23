#include <bits/stdc++.h>
using namespace std;

string polybius_encode(string plaintext) {
    map<char, string> polybius_map{
        {'A', "11"}, {'B', "12"}, {'C', "13"}, {'D', "14"}, {'E', "15"},
        {'F', "21"}, {'G', "22"}, {'H', "23"}, {'I', "24"}, {'J', "24"},
        {'K', "25"}, {'L', "31"}, {'M', "32"}, {'N', "33"}, {'O', "34"},
        {'P', "35"}, {'Q', "41"}, {'R', "42"}, {'S', "43"}, {'T', "44"},
        {'U', "45"}, {'V', "51"}, {'W', "52"}, {'X', "53"}, {'Y', "54"},
        {'Z', "55"}
    };
    
    string ciphertext;
    for (char c : plaintext) {
        if (isalpha(c)) {
            ciphertext += polybius_map[toupper(c)];
        }
    }
    return ciphertext;
}

string polybius_decode(string ciphertext) {
    map<string, char> polybius_map{
        {"11", 'A'}, {"12", 'B'}, {"13", 'C'}, {"14", 'D'}, {"15", 'E'},
        {"21", 'F'}, {"22", 'G'}, {"23", 'H'}, {"24", 'I'}, {"25", 'K'},
        {"31", 'L'}, {"32", 'M'}, {"33", 'N'}, {"34", 'O'}, {"35", 'P'},
        {"41", 'Q'}, {"42", 'R'}, {"43", 'S'}, {"44", 'T'}, {"45", 'U'},
        {"51", 'V'}, {"52", 'W'}, {"53", 'X'}, {"54", 'Y'}, {"55", 'Z'}
    };
    
    string plaintext;
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        string substr = ciphertext.substr(i, 2);
        if (polybius_map.find(substr) != polybius_map.end()) {
            plaintext += polybius_map[substr];
        }
    }
    return plaintext;
}

string vigenere_encrypt(string plaintext, string key) {
    string ciphertext = "";
    int key_len = key.length();
    for (int i = 0; i < plaintext.length(); i++) {
        char plain_char = plaintext[i];
        char key_char = key[i % key_len];
        char cipher_char = 'a' + ((plain_char - 'a' + key_char - 'a') % 26);
        ciphertext += cipher_char;
    }
    return ciphertext;
}

string vigenere_decrypt(string ciphertext, string key) {
    string plaintext = "";
    int key_len = key.length();
    for (int i = 0; i < ciphertext.length(); i++) {
        char cipher_char = ciphertext[i];
        char key_char = key[i % key_len];
        char plain_char = 'a' + ((cipher_char - 'a' - key_char + 'a' + 26) % 26);
        plaintext += plain_char;
    }
    return plaintext;
}