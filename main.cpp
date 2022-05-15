// #include "v1.h"

#include "v1.h"
#include <ranges>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  auto args = vector<string>(argv, argv + argc);
  printf("%d\n", argc);
  for(string &s: args) {
    cout << s << endl;
  }
  // ranges::for_each(s, [](string x) { printf("%s\n", x); });
  // std::vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // auto t = args | std::views::filter(check);
  // printf("%s\n", t);
  // std::cout << t << std::endl;
	return 0;
}