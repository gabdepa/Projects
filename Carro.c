#include<stdio.h>
#define aliquota 4/100;

void gastos_mensais(int *verify, int mes_consulta)
{
    float valor,prestacao,seguro,tanque,total,ipva;
    char modelo[20];
    printf("Digite o modelo do carro: ");
    __fpurge(stdin);
    scanf ("%20[^\n]", modelo);
    printf("\nDigite o valor da prestação mensal: ");
    scanf("%f", &prestacao);
    printf("\nDigite o valor do seguro mensal: ");
    scanf("%f", &seguro);
    printf("\nDigite o valor de gasto com abastecimento mensal: ");
    scanf("%f",&tanque);
    if (mes_consulta == 12)
        {
            printf("\nDigite o valor do carro de acordo com a tabela FIPE: ");
            scanf("%f",&valor);
            ipva = valor * aliquota;
            printf("Devido ao valor de R$%.2f o valor a ser pago pelo IPVA do carro ficou em R$%.2f.", valor,ipva);
            total = prestacao + seguro + tanque + ipva;
        }
    else
        {
            total = prestacao + seguro + tanque;
        }
    printf("\n\nO gasto mensal com o carro %s, no mês %d fica em R$%.2f\n", modelo,mes_consulta,total);
    printf("\nSE DESEJA PARAR DIGITE '0', CASO QUEIRA FAZER UMA NOVA CONSULTA DIGITE '1'. ");   
    scanf("%d",&*verify);
    printf("\n");
}

int main ()
{
    int mes_consulta,v;
    int *verify;
    v = 1;
    verify = &v;
    do
        {            
            /*fgets(modelo,sizeof(modelo),stdin);  --> armazena o enter quando digitado ao final da string*/
            printf("Qual mês de consulta do custo mensal do carro? ");
            scanf("%d",&mes_consulta);
            while ((mes_consulta > 12) || (mes_consulta < 1))
                {
                    printf("O mês %d NÃO é válido, favor digite novamente um mês válido: ", mes_consulta);
                    scanf("%d",&mes_consulta);
                }
            gastos_mensais(verify,mes_consulta);  
        }
    while ((v != 0));
    return 0;    
}