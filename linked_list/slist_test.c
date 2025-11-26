#include "slist.h"

int main()
{
    int n;
    char c;
    slist *numbers = malloc(sizeof(slist));
    initiate(numbers, 2);
    numbers
    // append(numbers, 3);
    // insert(numbers,0, 8);
    // head_insert(numbers, 7);
    // tail_insert(numbers, 10);
    print_list(numbers);
}