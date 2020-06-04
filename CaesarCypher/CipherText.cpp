#include <cstdlib> 
#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>
#include "CaesarCypher.hpp"

using namespace std;

int main(){
    //Get input for the cipher text
    cout << "Enter a string: ";
    string aString;
    getline(cin, aString);
    //Get input for the key
    cout << "Enter a Key: ";
    int key;
    cin >> key;

    //Create a CaesarCypher
    CaesarCypher cypher(key);
    //CaesarCypher cypher(key);

    //Encrypt then Decrypt string
    string encryptStr = cypher.encrypt(aString);
    string decryptedStr = cypher.decrypt(encryptStr);

    //Display results
    cout << "Encrypted: " << encryptStr << endl;
    cout << "Decrypted: " << decryptedStr << endl;

    return 0;
}
