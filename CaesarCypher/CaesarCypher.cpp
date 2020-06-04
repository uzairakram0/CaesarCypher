//////////////////////////////////////////////////////////////////////////////
//Include files and namespaces
//////////////////////////////////////////////////////////////////////////////
#include "CaesarCypher.hpp"

using namespace std;
//////////////////////////////////////////////////////////////////////////////
//public functions
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//Constructors/Destructors
//////////////////////////////////////////////////////////////////////////////
CaesarCypher::CaesarCypher(int const& newKey):_key(newKey){}


//////////////////////////////////////////////////////////////////////////////
string CaesarCypher::encrypt(string const& clearText){
    return cypher(clearText, _key * -1);
}//End encrypt()

//////////////////////////////////////////////////////////////////////////////
string CaesarCypher::decrypt(string const& cypherText) {
    return cypher(cypherText, _key);
}//End decrypt()

//////////////////////////////////////////////////////////////////////////////
//private functions
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
//////////////////////////////////////////////////////////////////////////////
//Loops thru ea char and applies the key
string CaesarCypher::cypher(string const& text, int const& key) {
    string result = "";
    int charCode = 0;
    char letter;
    //Loop thru & Encrypt/Decrypt every character
    for(char const& c: text){
        if (isalpha(c)){
            charCode = (int)c;  //convert letter to int
            charCode += key;    //Ceaser Encryption with key
            //wrap around the alphabets
            charCode = wrapAround(c, charCode);
            //add the new letter to result string
            letter = charCode;
            result += letter;
        } else {
            //add nonalphabet letters to string
            letter = c;
            result += c;
        }
    }//End for loop
    return result;
}//End cypher()

//////////////////////////////////////////////////////////////////////////////
//wraps around the alphabet to avoid the alphanumeric
int CaesarCypher::wrapAround(char const& c, int charCode){
    //For uppercase loop around
    if(isupper(c)){
        if (charCode > (int)'Z'){
            charCode -= 26;
        } else if (charCode < (int)'A'){
            charCode += 26;
        }
    //For Lowercase loop around
    } else {
        if (charCode > (int)'z'){
            charCode -= 26;
        } else if (charCode < (int)'a'){
            charCode += 26;
        }
    }
    return charCode;
}//END wrapAround()