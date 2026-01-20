int is_space(char c)
{
    return (c == ' ' || c == '\t');
}
#include <unistd.h>

static void put_word(const char *s, int start, int end) // [start, end)
{
    while (start < end)
        write(1, &s[start++], 1);
}

int main (int argc, char **argv)
{
    
    // if(argc == 1)
    //     return 0;
        
    char *str = argv[1];
    int i = 0;
    char res[100];
    int j = 0;
    while(is_space(str[i])&& str[i])
        i++;
    while(!is_space(str[i])&& str[i])
    {
        res[j] = str[i];
        j++;
        i++;
    }
    res[j] = '\0';
    int start = 0;
    int end = 0;
    int printed = 0;
    while(str[i] != '\0')
    {
        while (is_space(str[i]) && str[i])
            i++;
        start = i;
        while(!is_space(str[i]) && str[i])
            i++;
        end = i;
        if (printed)
            write(1, " ", 1);
        put_word(str, start, end);
        printed = 1;
    }
    j = 0;
    while (res[j] != '\0')
    {
        write(1, &res[j], 1);
        j++;
    }
   write(1, "\n", 1);
}