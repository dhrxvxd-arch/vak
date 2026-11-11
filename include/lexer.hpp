
#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <token.hpp>

namespace lexer {
struct lexer_t {
public:
  explicit lexer_t(std::string source);
  std::vector<token::token_t> scan_tokens();

  operator std::string() const;
  operator const char*() const;
  operator std::vector<char>() const;
private:
  std::string source;
  std::vector<token::token_t> tokens;

  std::size_t start = 0;
  std::size_t current = 0;

  std::size_t line = 1;
  std::size_t column = 1;

  std::size_t start_line = 1;
  std::size_t start_column = 1;

  bool src_end(void) const;
  
  char advance(void);
  bool match(char exp);

  char peek(void) const;
  char peek_next(void) const;

  void scan_token(void);
  void add_token(token::token_type_t type);

  void identifier(void);
  void number(void);
  void string_lit(void);
};
}

