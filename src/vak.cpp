#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iterator>

#include <lexer.hpp>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <file>\n";
    return EXIT_FAILURE;
  }

  std::ifstream file(argv[1]);

  if (!file) {
    std::cerr << "Error opening file: " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  std::string cont{
    std::istreambuf_iterator<char>(file),
    std::istreambuf_iterator<char>()
  };

#ifdef DEBUG
  std::cout << cont << std::endl;
#endif

  return EXIT_SUCCESS;
}
