# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
  vector<int> v {10,20,30,40,50,60};
  
  cout<<"\n Vector => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
  cout<<"\n size before erase == "<<v.size();
  v.erase(v.begin() +3, v.begin()+4);
  cout<<"\n size after erase => "<<v.size();
  
  cout<<"\n Vector after erase => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
  v = {10,20,30,40,50,60};
  
  cout<<"\n size before remove = "<<v.size();
  auto it = remove(v.begin(), v.end(), 40);
  cout<<"\n Size after remove ="<<v.size();
  
  cout<<"\n Vector after remove => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
  v.erase(it, v.end());
  
  cout<<"\n Vector after erase with remove => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
  v = {10,20,30,40,50,60};
  
  cout<<"\n size before remove_if = "<<v.size();
  it = remove_if(v.begin(), v.end(), [](int x) {
    if (x == 40)
      return true;
    return false;
  });
  cout<<"\n Size after remove_if = "<<v.size();
  
  cout<<"\n Vector after remove_if => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
  v.erase(it, v.end());
  
  cout<<"\n Vector after erase with remove_if => ";
  for(int i: v) {
    cout<<i<<" ";
  }
  
}
