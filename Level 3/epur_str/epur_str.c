#include <unistd.h>

int is_space(char c)
{
    return (c == '\t' || c == ' ');
}


int main (int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
    {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0;
    char *str = argv[1];

    while (is_space(str[i]))
        i++;
    char res[1000];
    int j = 0;
    while (str[i] != '\0')
    {
        if (!is_space(str[i]))
        {
            res[j] = str[i];
            j++;
        }
        else
        {
            if(is_space(str[i]) && !is_space(str[i - 1]) && str[i + 1] != '\0')
            {
                res[j] = ' ';
                j++;
            }
        }
        i++;
    }
    res[j] = '\0';
    i = 0; 
    while (res[i] != '\0')
    {
        write(1, &res[i], 1);
        i++;
    }
    write(1, "\n", 1);

}