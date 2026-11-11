
#pragma once

#include <string>
#include <vector>
#include <cstdlib>

namespace token {
enum token_type_t {
  Identifier,
  Integer,
  Float,
  String,

  Plus,
  Minus,
  Star,
  Slash,

  Equal,
  EqualEqual,
  Bang,
  BangEqual,

  LeftParen,
  RightParen,
  LeftBrace,
  RightBrace,

  Semicolon,
  Comma,

  Let,
  Fn,
  Return,

  EndOfFile
};
struct token_t {
  token_type_t type;
  std::string data;
  std::size_t line;
  std::size_t col;
  operator std::string() const;
  operator const char*() const;
  operator std::vector<char>() const;
};
}

