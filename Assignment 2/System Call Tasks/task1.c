#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]) {
    FILE *fp;
    char name[1000],str[1000];
    if (argc<2) {
        printf("Provide filename as a command line argument.\n");
        exit(1);
    }
    strcpy(name,argv[1]);
    //write mode
    fp =fopen(name, "w");
    if (fp ==NULL) {
        printf("Unable to open file %s.\n",name);
        exit(1);
    }
    //input
    printf("Enter a string to write to the file:\n");
    scanf("%s", str);
    while (strcmp(str,"-1") !=0) {
        fprintf(fp, "%s\n", str);
        printf("Enter another string:\n");
        scanf("%s", str);
    }
    fclose(fp);

    printf("File %s has been written to.\n",name);
    return 0;
}