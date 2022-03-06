/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

// Preprocessor Tokens

#define priority_queue pq;
#define make_pair mp;

// Compiler Tokens

typedef long long ll;
typedef pair<int, int> pii;


// Vector output template
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = vector<int>{10, 20, 30};
    //cout<<v;
    
}

