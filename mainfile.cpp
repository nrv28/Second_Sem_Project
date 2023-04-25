#include <iostream>
#include <map>
#include <string>
#include <vector>

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


int main(){
    cout<<"Welcome to Universal Cipher Decoder\n"; //Enter name of program
    int op=0;
    while(op!=-1){
        cout<<"1.Polybius square cipher\n";
        //Add your code here
        cout<<"Select one of the above number(for exiting press -1) : ";
        cin>>op;
        if(op==-1)  break;
        cout<<"1.Encode\n 2.Decode\n Select one of the above: ";
        int met;
        cin>>met;
        switch(op){
            case 1:
                if(met==1){
                    string input_message,encoded_output;cin>>input_message;
                    encoded_output=polybius_encode(input_message);
                    cout<<encoded_output<<endl;
                }
                else{
                    string input_message,decoded_output;cin>>input_message;
                    decoded_output=polybius_decode(input_message);
                    cout<<decoded_output<<endl;
                }
                break;
            /*case 2:
                if(met==2)
                    //Enter function call for encode here
                else
                    //Enter function call for decode here
                break;*/
            default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }
    }
    return 0;
}