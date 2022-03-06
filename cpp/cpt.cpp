/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

/** === Preprocessor Tokens === **/

#define priority_queue pq;
#define make_pair mp;
#define push_back pb;

/** === Compiler Tokens === **/

typedef long long ll;
typedef pair<int, int> pii;

/** === Vector output template === **/

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

/** === Program Logic === **/
