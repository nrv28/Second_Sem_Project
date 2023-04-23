#include <iostream>
using namespace std;

//Add functions for program here

int main(){
    cout<<"Welcome to ....\n"; //Enter name of program
    cout<<"1.\n";
    //Add your code here
    cout<<"Select one of the above number : ";
    int op;
    cin>>op;
    cout<<"1.Encode\n 2.Decode\n Select one of the above: ";
    int met;
    cin>>met;
    switch(op){
        case 1:
            if(met==1)
                //Enter function call for encode here
            else
                //Enter function call for decode here
            break;
        case 2:
            if(met==1)
                //Enter function call for encode here
            else
                //Enter function call for decode here
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
    }
    
    return 0;
}
