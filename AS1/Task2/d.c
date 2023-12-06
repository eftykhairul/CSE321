#include <stdio.h>
#include <string.h>



int email_updated(char* email_add) {
    char* find_at = strchr(email_add, '@');
    if (find_at == NULL) {
        return 0;
    }
    else if (strcmp(find_at + 1, "kaaj.com") == 0) {
        return 0;
    }
    else if (strcmp(find_at + 1, "sheba.xyz") == 0) {
        return 1;
    }
    
    return 0;
}


int main() {
    char email_add[100];
    printf("Enter an email address: ");
    scanf("%s", email_add);

    if (email_updated(email_add)) {
        printf("The email address is okay\n");
    } else {
        printf("The email address is outated\n");
    }

    return 0;
}