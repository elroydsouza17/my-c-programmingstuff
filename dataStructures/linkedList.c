#include <stdio.h>

int main()  {

  struct Node {
    int value;
    struct Node* next;
  };

  struct Node n1, n2, n3;

  n1.value = 5;
  n1.next = &n2;

  n2.value = 6;
  n2.next = &n3;

  n3.value = 7;
  n3.next = NULL; // last node;

  struct Node* head;
  head = &n1;

  struct Node* temporary_ptr;
  temporary_ptr = head;

  while (temporary_ptr != NULL) {
    printf("value is %d\n", temporary_ptr->value);
    temporary_ptr = temporary_ptr->next;
  }



  return 0;
}