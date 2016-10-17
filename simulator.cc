#include <cmath>
#include <iostream>
#include <time.h>
#include <unistd.h>

int
main(int argc, char **argv) {
  if (argc != 3)
  {
    std::cerr << "simulator takes two argument." << std::endl;
    exit(1);
  }
  char *err;
  int p1 = strtol(argv[1], &err, 10);
  if (*err != 0)
  {
    std::cerr << "First argument must be a positive integer." << std::endl;
    exit(1);
  }

  int p2 = strtol(argv[2], &err, 10);
  if (*err != 0)
  {
    std::cerr << "Second argument must be a positve integer." << std::endl;
    exit(1);
  }
  std::cerr << "Busy interval is " << p1 << ", sleep interval is " << p2 << "seconds long" << std::endl;
  time_t t0 = 0, t = 0;

  while(true) {
    // Busy loop
    std::cerr << "Busy loop started" << std::endl;
    t0 = time(NULL);
    t = time(NULL);
    while(t-t0 < p1)
    {
      for(size_t i = 0; i < 10000; ++i)
        float a = exp(1);
      t = time(NULL);
    }
    std::cerr << "Sleepy loop started" << std::endl;
    // Sleepy loop
    t0 = time(NULL);
    t = time(NULL);
    while(t-t0 < p2)  {
      sleep(1);
      t = time(NULL);
    }
    // Forever
  }
}
