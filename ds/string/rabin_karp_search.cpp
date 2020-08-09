# include <iostream>
# include <string>
# include <cmath>

typedef long long int big;

using namespace std;

int prime=10111;


big computeRollingHash(string previousText, string currentText, big previousHash) {

  big currentHash = previousHash - previousText[0];
  currentHash /= prime;
  currentHash += currentText[currentText.length() - 1]*pow(prime,currentText.length()-1); 
  return currentHash;
}

big computeHash(string value) {
  
  big hash=0;
  
  for(int i=0;i<value.length();i++) {
    hash += value[i] * pow(prime, i);
  }
  
  return hash;
}

bool compareStrings(string a, string b) {
  return (a == b) ? true: false;
}

void RabinKarpSearch(string text, string pattern) {

  if (pattern.length() < text.length()) {
    cout<<"Pattern longer than text length";
    return;
  }

  int n = pattern.length();
  big patternHash = computeHash(pattern);
  big textHash = computeHash(text.substr(0,n));
  
  if (patternHash == textHash && pattern == text.substr(0,n)) {
    cout<<"\n Pattern found at -> "<<0;
  }
  
  for(int i = 1;i+n<text.length();i++) {
    
  }
 
  
  

  
  
}


int main() {

  string text = "ABABDABACDABABCABAB";
  string pattern = "ABABCABAB";

  RabinKarp(text, pattern);
    
}
