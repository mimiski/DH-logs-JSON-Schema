#include <ranges>
#include "utils.hpp"
#include "schema.hpp"

using namespace std;

auto getJsonData = [](string fileName) {
  auto file = new ifstream(fileName);
  stringstream buffer;
  buffer << file->rdbuf();
  const auto jsonContents = buffer.str();
  auto sanitizedJsonContents = CP1252_to_UTF8(jsonContents);
  auto parsedJson = nlohmann::json::parse(sanitizedJsonContents);
  darklight::LogFile *data = new darklight::LogFile;
  nlohmann::from_json(parsedJson, *data);
  return data;
};

int main(int argc, char **argv)
{
  auto args = vector<string>(argv, argv + argc);
  
  auto jsons = args
    | std::views::filter([](string s) { return s.ends_with(".log"); })
    | std::views::transform(getJsonData);

  return 0;
}