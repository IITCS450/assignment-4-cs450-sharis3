#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  char *addr = sbrk(4096);  

  // Test 1: mprotect then write should fault
  printf(1, "=== Test 1: write to protected page ===\n");
  mprotect(addr, 1);
  addr[0] = 'x';  // should trigger page fault and kill process
  printf(1, "UNEXPECTED: write succeeded\n");

  exit();
}