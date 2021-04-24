# include <iostream>
# include <string>
# include <vector>

using namespace std;

vector<int> computeLPS(string& pattern) {

  vector<int> lps(pattern.length());
  lps[0] = 0;
  
  int i=1,j=0; //i -> Tracking the characters in array. j -> to track the pattern  
  
  while(i < pattern.length()) {
    if (pattern[i] == pattern[j]) {
      lps[i] = ++j;
      i++;
    }
    else { // Pattern mismatch
      if (j != 0)
        j = lps[j-1];
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
  
  return lps;
}


void KMPSearch(string& text, string& pattern) {
  
  
  vector<int> lps = computeLPS(pattern);
  int i=0,j=0; //i -> text, j -> pattern.
  
  while(i < text.length()) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      if (j != 0)
        j = lps[j-1];
      else
        i++;
    }
    
    if (j == pattern.length()) {
      cout<<"Text found at -> "<<i-j;
      j = lps[j-1];
    }
    
  } 
  
}

int main() {

  string text = "ABABDABACDABABCABAB";
  string pattern = "ABABCABAB";
  
  KMPSearch(text, pattern);
  
  
}
