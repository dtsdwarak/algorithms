/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;


int get2ndHalfBits(int number, int bitLength) {
    
    number >>= bitLength/2;
    int ans = 0;
    while(number > 0) {
        ans <<= 1;
        ans |= number & 1;
        number >>= 1;
    }
    return ans;
}

int NthPalindromeBinary(int n) {

    int count=0, len=0;
    
    while(count < n) {
        len++;
        int elementsForThisLen = 1 << (len - 1)/2;
        count += elementsForThisLen;
    }
    
    count -= 1 << (len - 1)/2;
    int offset = n - count - 1;
    int ans = (1 << (len - 1));
    ans |= (offset << len/2);
    
    int secondHalfBits = get2ndHalfBits(ans, len);
    
    return ans | secondHalfBits;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 9;
    int ans = NthPalindromeBinary(n);
    cout<<n<<"th palindrome is = "<<bitset<8>(ans)<<" the actual value of which is = "<<ans;
}
