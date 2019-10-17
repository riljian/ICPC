#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_LINE_LEN 1000000

int main() {
  char inputLine[MAX_LINE_LEN], outputLine[MAX_LINE_LEN];
  int quoteNum = 0, len;
  while (fgets(inputLine, MAX_LINE_LEN, stdin)) {
    len = strlen(inputLine);
    outputLine[0] = '\0';
    for (int i = 0, j; i < len; i = j + 1) {
      for (j = i; j < len; ++j) {
        if (inputLine[j] == '"') {
          ++quoteNum;
          strncat(outputLine, inputLine + i, j - i);
          if (quoteNum % 2) {
            strncat(outputLine, "``", 2);
          } else {
            strncat(outputLine, "''", 2);
          }
          break;
        }
      }
      if (j >= len) {
        strncat(outputLine, inputLine + i, j - i);
        break;
      }
    }
    printf("%s", outputLine);
  }
  return 0;
}
