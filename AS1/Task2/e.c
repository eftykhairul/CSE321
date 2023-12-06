#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int x, length;
    int initial = 1;
	
    printf("Give a string: ");
    scanf("%s", str);

    length = strlen(str);
	
    char *first_pointer = str;
    char *last_pointer = str + length - 1;

    for (x=0;x < length/2;x++) {
        if (*first_pointer != *last_pointer) {
            initial = 0;
            break;
        }
        first_pointer++; 
        last_pointer--;
    }
	
    if (initial) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}