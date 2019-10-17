#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_LEN 1000000

int main() {
  char inputLine[MAX_LEN];
  while (fgets(inputLine, MAX_LEN, stdin)) {
    int len = strlen(inputLine);
    for (int i = 0; i < len && inputLine[i] != '\n'; ++i) {
      inputLine[i] = inputLine[i] - 7;
    }
    printf("%s", inputLine);
  }
  return 0;
}
