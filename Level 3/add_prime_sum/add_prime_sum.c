#include <unistd.h>

int isprime(int n)
{
    if(n < 2)
        return 0;
    int i = 2;
    while (i * i <= n)
    {
        if(n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void putnbr(int n)
{
    char c;
    if (n >= 10)
        putnbr(n/10);
    c = (n % 10) + '0';
    write (1, &c, 1);
}

int main (int argc, char **argv)
{
    
    
   if(argc < 2 || (argv[1][0] - '0') < 0)
    {
        write(1, "0", 1);
        write(1, "\n", 1);
        return 0;
    }

    int val = argv[1][0] - '0';
    int sum = 0;
    int i = 2;

    while (i <= val)
    {
        if (isprime(i))
            sum += i;
        i++;
    }
    putnbr(sum);
    write(1, "\n", 1);
    return 0;
}