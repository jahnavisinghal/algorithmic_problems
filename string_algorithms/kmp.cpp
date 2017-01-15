#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  vector<int> prefix;
  string temp = pattern + "$" + text;
  int len = temp.size();
  prefix.push_back(0);
  int border = 0;
  for(int i = 1; i < len; i++) {
    while((border > 0) && (temp[i] != temp[border])) {
        border = prefix[border-1];
    }
    if(temp[border] == temp[i]) {
        border++;
    } else {
        border = 0;
    }
    prefix.push_back(border);
    if(i > pattern.size() && prefix[i] == pattern.size()) {
        result.push_back(i-2*pattern.size());
    }
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
