#include "include/split_string.h"

int split_string(char *str, char delim, int max_tokens, int max_len,
                 char tokens[max_tokens][max_len]) {
  int count = 0;
  int char_idx = 0;

  if (!str || !tokens || max_tokens <= 0 || max_len <= 0)
    return 0;

  while (*str && count < max_tokens) {
    if (*str == delim) {
      tokens[count][char_idx] = '\0';
      count++;
      char_idx = 0;
    } else if (char_idx < max_len - 1) {
      tokens[count][char_idx++] = *str;
    }
    str++;
  }

  if (count < max_tokens) {
    tokens[count][char_idx] = '\0';
    count++;
  }

  return count;
}
