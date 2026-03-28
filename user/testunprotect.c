#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  char *addr = sbrk(4096);
  printf(1, "=== Test 2: munprotect restores write ===\n");
  mprotect(addr, 1);
  munprotect(addr, 1);
  addr[0] = 'x';  
  printf(1, "PASS: write succeeded after munprotect\n");
  exit();
}