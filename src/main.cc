#ifndef MAIN
#define MAIN

#include <spdlog/spdlog.h>
#include <memory>
#include "./main.hh"
#include "./sorting-algorithms/counting-sort.cc"
#include "./array-printer/array-printer.cc"

int main(int argc, const char *argv[])
{
#ifdef NDEBUG
  spdlog::info("Starting release config…");
#else
  spdlog::info("Starting debug config…");
#endif

  auto countingSort = std::make_unique<CountingSort>();
  const std::vector<int> params = std::vector<int>{3, 2, 1, 0, 100, 4, 3};
  const std::vector<int> response = countingSort->loop(params);

  auto arrayPrinter = std::make_unique<ArrayPrinter>();
  arrayPrinter->print(response);

  return 0;
}

#endif
