
#include <token.hpp>

token::token_t::operator std::string() const {
  return data;
}

token::token_t::operator const char*() const {
  return data.c_str();
}

token::token_t::operator std::vector<char>() const {
  return {data.begin(), data.end()};
}

