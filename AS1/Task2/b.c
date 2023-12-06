#include <stdio.h>
#include <string.h>

void remove_spaces(char *str)
{
    int y=0;
    for (int x=0;str[x] != '\0';x++)
    {
        if (str[x] != ' '||(str[x] == ' ' && str[x-1] != ' '))
        {
            str[y]=str[x];
            y++;
        }
    }
    str[y]='\0';
}

int main()
{
    char str[1000];
    printf("Sentence with extra spaces:\n");
    scanf("%[^\n]s",str);
    
    getchar();
    remove_spaces(str);
    
    printf("Sentence without extra spaces:\n%s\n",str);
    return 0;
}