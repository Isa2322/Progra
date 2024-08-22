#ifndef SIM_FUNCIONES_H_INCLUDED
#define SIM_FUNCIONES_H_INCLUDED

#define VALOR_ABSOLUTO(a) (a)>0 ? a : a*(-1)
#define PARTE_ENTERA(a) ((a)-(int)(a))==0 ? (int)a : (int)a
#define PARTE_DECIMAL(a) ((a)-((int)(a)))==0 ? 0 : ((a)-((int)(a))
#define ES_LETRA(a) ((a)>=65 && (a)<=90) || ((a)>=97 && (a)<=122) ? 1 : 0
#define ES_MAYUSCULA(a) ((a)>=65 && (a)<=90) ? 1 : 0
#define ES_MINUSCULA(a) ((a)>=97 && (a)<=122) ? 1 : 0
#define ES_BLANCO(a) (a)==9 || (a)==10 || (a)==32 ? 1 : 0
#define ES_NUMERO(a) ((a)>=48 && (a)<=57) ? 1 : 0


#endif // SIM_FUNCIONES_H_INCLUDED
