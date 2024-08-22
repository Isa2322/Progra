double potencia(int num, int exp)
{
    int i;
    double pot=1;

    for(i=1;i<=exp;i++)
    {
        pot*=num;
    }

    return pot;
}
