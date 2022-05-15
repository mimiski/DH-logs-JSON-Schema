// #include "v1.h"

#include "v1.h"
#include <ranges>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  auto file_names = vector<string>(argv, argv + argc);
  auto jsons = file_names 
    | std::views::drop(1) // the name of the program
    | std::views::transform([](string fileName) { 
      ifstream file(fileName);
      std::stringstream buffer;
      buffer << file.rdbuf();
      auto jsonContents = buffer.str();
      auto parsedJson = nlohmann::json::parse(jsonContents); 
      darklight::LogFile *data = new darklight::LogFile;
      nlohmann::from_json(parsedJson, *data);
      return data;
    });

  auto first = jsons.front(); 

  return 0;
}