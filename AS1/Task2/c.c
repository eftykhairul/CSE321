#include <stdio.h>
#include <string.h>

int main() {
    char pass[100];
    int lent,x,low=0,upp=0,digit=0,special=0;
    printf("Enter your new pass: ");
    scanf("%s",pass);
    lent=strlen(pass);
    
    // pass Check
    for (x=0; x < lent; x++) {
         
        if (pass[x]=='_'||pass[x]==','||pass[x]== '$'||pass[x]=='#'||pass[x] =='@') {
            special = 1;
        }
        else if (pass[x]>='0' && pass[x]<='9') {
            digit = 1;
        } 
        else if (pass[x]>='A' && pass[x]<='Z') {
            upp = 1;
        }
        else if (pass[x] >= 'a' && pass[x]<='z') {
            low = 1;
        } 
        
    }
    if (low==0) {
        printf("Lowercase character missing\n");
    }
    if (upp==0) {
        printf("Uppercase character missing\n");
    }
    if (digit==0) {
        printf("Digit missing\n");
    }
    if (special==0) {
        printf("Special character missing\n");
    }
    if (low && upp && digit && special) {
        printf("OK\n");
    }
    return 0;
}