double factorial(int num)
{
    int i;
    double fact=1;

    for(i=1;i<=num;i++)
    {
        fact*=i;
    }

    return fact;
}
