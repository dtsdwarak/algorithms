# include <iostream>
# include <set>

using namespace std;

int main() {
  set<int> v = {10,20,30};
  set<int> r{40,50,60};
  
  for( const int &i : v)
    cout<<i<<" ";
    
  cout<<endl;
  for(const int &i : r)
    cout<<i<<" ";
}

