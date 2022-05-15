// #include "v1.h"

#include "schema.hpp"
#include <ranges>
#include <iostream>
#include <fstream>

#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include "utils.hpp"

using namespace std;

int main(int argc, char **argv)
{
  auto args = vector<string>(argv, argv + argc);
  auto file_names = args
    | std::views::filter([](string s) { return s.ends_with(".log"); });

  for(auto s: file_names) {
    cout << s << endl;
  }
  
  auto jsons = file_names
    | std::views::transform([](string fileName) {
      ifstream file(fileName);
      std::stringstream buffer;
      buffer << file.rdbuf();
      const auto jsonContents = buffer.str();
      auto sanitizedJsonContents = CP1252_to_UTF8(jsonContents);
      auto parsedJson = nlohmann::json::parse(sanitizedJsonContents);
      darklight::LogFile *data = new darklight::LogFile;
      nlohmann::from_json(parsedJson, *data);
      return data;
    });

  auto first = jsons.front();
  // auto size = jsons.size(); 

  return 0;
}