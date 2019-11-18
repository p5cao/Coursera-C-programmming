#include "cards.h"
#include <stdio.h>
int main(void) {

  card_t c;
  card_t c1;

  c.value = 2;
  c.suit = SPADES;
  c1.value = 4;
  c1.suit = DIAMONDS;

  assert_card_valid(c);
  assert_card_valid(c1);

  char suit_c = suit_letter(c1);
  printf("%s", &suit_c);

  char value_c = value_letter(c1);
  printf("%s", &value_c);

  //print_card(c);
  //print_card(c1);
  return 0;
}
