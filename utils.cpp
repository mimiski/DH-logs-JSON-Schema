#include "utils.hpp"

using namespace std;

std::string CP1252_to_UTF8(const std::string& byte_array) {

  // Byte array => Unicode.
  std::wstring unicode(byte_array.size(), ' ');
  for (size_t i = 0; i < unicode.size(); ++i)
    unicode[i] = CP1252_UNICODE_TABLE[(uint8_t)byte_array[i]];

  // Unicode => UTF8.
  std::wstring_convert<std::codecvt_utf8<wchar_t>> unicode_to_utf8;
  return unicode_to_utf8.to_bytes(unicode);
}