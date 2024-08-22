int suma_de_n_pares(int num)
{
    int i, res=0;

    for(i=2;i<=(num*2);i+=2)
        res+=i;

    return res;
}
