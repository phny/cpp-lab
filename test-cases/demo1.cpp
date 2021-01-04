#include <array>
#include <atomic>
#include <iostream>
#include <vector>

#include "kestrel.h"
#include "kestrel_core/kestrel_aspect.h"

using namespace std;

#define PROFILER_BEGIN(name)                                                   \
  kestrel_pointcut(KESTREL_ASPECT_TYPE_BEGIN, KESTREL_ASPECT_SCOPE_DEFAULT,    \
                   "kestrel_tutorial", (uint64_t)((intptr_t)(1)), name)

#define PROFILER_END(name)                                                     \
  kestrel_pointcut(KESTREL_ASPECT_TYPE_END, KESTREL_ASPECT_SCOPE_DEFAULT,      \
                   "kestrel_tutorial", (uint64_t)((intptr_t)(1)), name)

int main(int argc, char *argv[]) {
  k_err r = kestrel_init("Kestrel");
  k_err err = kestrel_license_add_from_file(
      "/home/SENSETIME/heyulin/dev/search_engine/unit_tests/KESTREL.lic", NULL);

  PROFILER_BEGIN("rough_search");

  cout << " test " << endl;

  PROFILER_END("rough_search");

  kestrel_deinit();

  return 0;
}