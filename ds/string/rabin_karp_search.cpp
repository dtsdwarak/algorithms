# include <iostream>
# include <string>
# include <cmath>
# include <climits>

typedef long long int big;

using namespace std;

int prime=13;


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

void RabinKarpSearch(string text, string pattern) {

  if (pattern.length() > text.length()) {
    cout<<"Pattern longer than text length";
    return;
  }

  int n = pattern.length();
  big patternHash = computeHash(pattern);
  
  big previousHash = INT_MIN, currentHash = INT_MIN;

  for(int i = 0;i+n<=text.length();i++) {
  
    string subtext = text.substr(i,n);
    previousHash = currentHash;
    currentHash = (previousHash==INT_MIN) ? computeHash(subtext) : computeRollingHash(text.substr(i-1,n),subtext,previousHash);
    
    if (patternHash == currentHash && pattern == subtext)
      cout<<"\n Pattern found at -> "<<i;
  }

}


int main() {

  string text = "ABABABABCABABDABACDABABCABAB";
  string pattern = "ABABCABAB";

  RabinKarpSearch(text, pattern);
    
}
