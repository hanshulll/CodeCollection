#include <stdio.h>

void main () {
// Making variabel with char
  char name[100], link[100];

  printf("Welcome to hacktoberfest event!\n\n");
  printf("Enter your name: ");
  scanf(" %[^\n]s", &name); //You can add 1 or more name. example, <rahul anjay sakinah>

  printf("Hello %s! put your github link here: ", name);
  scanf(" %s", &link);

  printf("\n\n\n---------------\n");
  printf("Your name: %s\n", name);
  printf("Your github profile: %s\n\n", link);

  printf("Happy hacking!\n");


  }
