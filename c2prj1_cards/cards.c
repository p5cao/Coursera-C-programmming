#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
#include <string.h>

void assert_card_valid(card_t c) {
  assert((c.value >= 2 && c.value <= VALUE_ACE));
  assert((c.suit >= 0  && c.suit <= 3 ));
}

const char * ranking_to_string(hand_ranking_t r) {
  char *r_s = "";
  switch(r){
  case STRAIGHT_FLUSH: strcpy(r_s, "STRAIGHT_FLUSH"); break;
  case FOUR_OF_A_KIND: strcpy(r_s,"FOUR_OF_A_KIND"); break;
  case FULL_HOUSE: strcpy(r_s,"FULL_HOUSE"); break;
  case FLUSH: strcpy(r_s,"FLUSH"); break;
  case STRAIGHT: strcpy(r_s,"STRAIGHT"); break;
  case THREE_OF_A_KIND: strcpy(r_s,"THREE_OF_A_KIND"); break;
  case TWO_PAIR:  strcpy(r_s,"TWO_PAIR"); break;
  case PAIR: strcpy(r_s,"PAIR"); break;
  case NOTHING: strcpy(r_s,"NOTHING"); break;
  default: printf("Invalid ranking for cards\n"); break;
  }
  return r_s;
}

char value_letter(card_t c) {
  char *x = "";
  switch(c.value){
  case 2: strcpy(x, "2"); break;
  case 3: strcpy(x, "3"); break;
  case 4: strcpy(x, "4"); break;
  case 5: strcpy(x, "5"); break;
  case 6: strcpy(x, "6"); break;
  case 7: strcpy(x, "7"); break;
  case 8: strcpy(x, "8"); break;
  case 9: strcpy(x, "9"); break;
  case 10: strcpy(x, "10"); break;
  case 11: strcpy(x, "J"); break;
  case 12: strcpy(x, "Q"); break;
  case 13: strcpy(x, "K"); break;
  case 14: strcpy(x, "A"); break;
  default: printf("Invalid value for cards"); break;
  }
  return 'x';
}


char suit_letter(card_t c) {
  char *x = "";
  switch(c.suit){
  case 0: strcpy(x, "s"); break;
  case 1: strcpy(x, "h");; break;
  case 2: strcpy(x, "d"); break;
  case 3: strcpy(x, "c");; break;
  default: printf("Invalid suit for cards\n");break;
  }
  return 'x'; 
}

void print_card(card_t c) {
  char * value = "";
  char * suit = "";
  char v = value_letter(c);
  char s = suit_letter(c);
  strcpy(value, &v);
  strcpy(suit, &s);
  printf("%s%s", value,suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  int v = 0;
  suit_t s;
  switch(value_let){
  case '2': v = 2; break;
  case '3': v = 3; break;
  case '4': v = 4; break;
  case '5': v = 5; break;
  case '6': v = 6; break;
  case '7': v = 7; break;
  case '8': v = 8; break;
  case '9': v = 9; break;
  case '0': v = 10; break;
  case 'J': v = 11; break;
  case 'Q': v = 12; break;
  case 'K': v = 13; break;
  case 'A': v = 14; break;
  default: printf("Invalid value letter for cards\n");
  }
  temp.value = v;
  switch(suit_let){
  case 's': s = SPADES; break;
  case 'h': s = HEARTS; break;
  case 'd': s = DIAMONDS; break;
  case 'c': s = CLUBS; break;
  default: printf("Invalid suit letters for cards\n");  
  }
  temp.suit = s;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert( c>=0 && c<52);
  int suit_num = c % 13;
  int value_num = c - suit_num * 13;
  suit_t suit;
  switch(value_num){
  case 0: suit = SPADES; break;
  case 1: suit = HEARTS; break;
  case 2: suit = DIAMONDS; break;
  case 3: suit = CLUBS; break;
  default: printf("Invalid suit for cards\n");break;
  }
  temp.value = value_num;
  temp.suit = suit;
  return temp;
}
