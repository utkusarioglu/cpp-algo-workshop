#ifndef ARRAY_PRINTER_ARRAY_PRINTER_CC
#define ARRAY_PRINTER_ARRAY_PRINTER_CC

#include <string>
#include <fmt/core.h>
#include <vector>
#include <sstream>
#include <spdlog/spdlog.h>
#include "./array-printer.hh"

void ArrayPrinter::print(const std::vector<int> &response)
{
  int responseLength = response.size();
  std::string message = fmt::format("Response has {} entries:", responseLength);
  spdlog::info(message);

  std::ostringstream oss;
  for (int i = 0; i < responseLength; i++)
  {
    oss << response[i];
    if (i < responseLength - 1)
    {
      oss << " ";
    }
  }
  spdlog::info(oss.str());
}

#endif
