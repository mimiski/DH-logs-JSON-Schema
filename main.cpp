// #include "v1.h"

#include "v1.h"
#include <ranges>
#include <iostream>
#include <fstream>

#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include "utils.h"

using namespace std;

int main(int argc, char **argv)
{
  std::ios::sync_with_stdio(false);

  auto file_names = vector<string>(argv, argv + argc);
  
  auto jsons = file_names
    | std::views::filter([](string s) { return s.ends_with(".log"); })
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