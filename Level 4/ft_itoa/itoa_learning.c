int nbr_len(int nbr)
{
    int len = 1;

    if(nbr < 0)
    {
        len++;
        nbr = -nbr;
    }
    while (nbr >= 10)
    {
        nbr /= 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int nbr)
{
    char *res;
    int nbrlen = nbr_len(nbr);

    res = malloc(sizeof(char) * nbrlen);
    if(nbr < 0)
    {    
        res[0] = '-';
        nbr = -nbr;
    }
    res[nbrlen] = '\0';
    while(nbrlen-- > 0 && res[nbrlen] != '-')
    {
        res[nbrlen] = (nbr % 10) + '0';
        nbr /= 10;
    }
    
    return res;
}

int main (void)
{
    printf("%s", ft_itoa(-42));
}