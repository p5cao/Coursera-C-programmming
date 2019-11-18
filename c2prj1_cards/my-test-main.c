#include "cards.h"
#include <stdio.h>
int main(void) {

  card_t c;
  card_t c1;
  card_t c2;
  card_t c3;
  card_t c4;
  card_t c5;
  card_t c6;
  card_t c7;
  card_t c8;
  card_t c9;
       
  c.value = 2;
  c.suit = SPADES;
  c1.value = 3;
  c1.suit = DIAMONDS;
  c2.value = 4;
  c3.value = 5;
  c4.value = 6;
  c5.value = 7;
  c6.value = 8;
  c7.value = 10;
  c8.value = 11;
  c9.value = 12;

  c2.suit = DIAMONDS;
  c3.suit = SPADES;
  c4.suit = SPADES;
  c5.suit = DIAMONDS;
  c6.suit = DIAMONDS;
  c7.suit = DIAMONDS;
  c8.suit = CLUBS;
  c9.suit = HEARTS;
  
  assert_card_valid(c);
  assert_card_valid(c1);

  char suit_c = suit_letter(c1);
  printf("%s", &suit_c);

  char value_c = value_letter(c1);
  printf("%s", &value_c);
  printf("\n");
  print_card(c);
  printf("\n");
  print_card(c1);
  printf("\n");
  print_card(c2);
  printf("\n");
   print_card(c3);
  printf("\n");
   print_card(c4);
  printf("\n");
   print_card(c5);
  printf("\n");
   print_card(c6);
  printf("\n");
   print_card(c7);
  printf("\n");
   print_card(c8);
  printf("\n");
   print_card(c9);
  printf("\n");
  return 0;
}
