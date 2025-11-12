#include <iostream>
using namespace std;
//Write a program that inputs a string and searches within the string a sequence of 3 characters, which is also entered by the user. Use null-terminated strings.
int main(){
    string a,b;
    cout<<"Enter the sentence: ";
    cin.ignore();
    getline (cin,a);
    cout<<"Enter the 3 letter string to be searched: ";
    cin>>b;
    for(int i=0;i<a.length()-3;i++){
        if(b==a.substr(i,3))
        {
            cout<<"found at index "<<i;
            return 0;
        }
    }
    cout<<"not found";
    return 0;

}
