#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "k.hpp"
using namespace std;

int main(){
    cout<<"Welcome to Universal Cipher Decoder\n"; //Enter name of program
    int op=0;
    cout<<"1.Polybius square cipher\n";
    cout<<"2.Vigenere cipher\n";
    //Add your code here
    cout<<"Select one of the above number(for exiting press -1) : ";
    cin>>op;
    cout<<"1.Encode\n 2.Decode\n Select one of the above: ";
    int met;
    cin>>met;
    switch(op){
        case 1:
            if(met==1){
                cout<<"Enter Message: ";
                string input_message,encoded_output;cin>>input_message;
                encoded_output=polybius_encode(input_message);
                cout<<encoded_output<<endl;
                break;
            }
            else{
                cout<<"Enter Message: ";
                string input_message,decoded_output;cin>>input_message;
                decoded_output=polybius_decode(input_message);
                cout<<decoded_output<<endl;
                break;
            }
            
        case 2:
            if(met==1){
                string key;cout<<"Enter Key: ";cin>>key;cout<<"Enter Message: ";
                string input_message,encoded_output;cin>>input_message;
                encoded_output=vigenere_encrypt(input_message,key);
                cout<<encoded_output<<endl;
                break;
            }
            else{
                string key;cout<<"Enter Key: ";cin>>key;cout<<"Enter Message: ";
                string input_message,decoded_output;cin>>input_message;
                decoded_output=vigenere_decrypt(input_message,key);
                cout<<decoded_output<<endl;
                break;
            }
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
    }
    return 0;
}