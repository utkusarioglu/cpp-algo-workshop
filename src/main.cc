#ifndef CAW_MAIN_CC_
#define CAW_MAIN_CC_

#include "./main.h"

#include <spdlog/spdlog.h>

#include <memory>

#include "./array_printer/array_printer.h"
#include "./sorting_algorithms/counting_sort.h"

int main(int argc, const char *argv[])
{
#ifdef NDEBUG
  spdlog::info("Starting release config…");
#else
  spdlog::info("Starting debug config…");
#endif

  auto countingSort = std::make_unique<CountingSort::CountingSort>();
  const std::vector<int> params = std::vector<int>{3, 2, 1, 0, 100, 4, 3};
  const std::vector<int> response = countingSort->loop(params);

  auto arrayPrinter = std::make_unique<ArrayPrinter>();
  arrayPrinter->print(response);

  return 0;
}

#endif /* CAW_MAIN_CC_ */
