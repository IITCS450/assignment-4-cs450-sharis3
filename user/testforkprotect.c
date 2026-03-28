#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  char *addr = sbrk(4096);
  mprotect(addr, 1);

  printf(1, "=== Test 3: fork inherits protection ===\n");
  int pid = fork();
  if (pid == 0) {
    // child
    addr[0] = 'x';  // should fault in child
    printf(1, "UNEXPECTED: child write succeeded\n");
    exit();
  } else {
    // parent
    wait();
    printf(1, "PASS: child was killed by page fault\n");
    exit();
  }
}