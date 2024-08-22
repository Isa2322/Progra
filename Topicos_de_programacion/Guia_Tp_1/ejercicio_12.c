int suma_de_n_pares_menores(int num)
{
    int i, res=0;

    for(i=2;i<=num;i+=2)
        res+=i;

    return res;
}
