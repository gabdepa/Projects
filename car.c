#include<stdio.h>
#include<curl/curl.h>

#define aliquota 4/100;

void fipe_http ()
{
    CURL *curl = curl_easy_init();
    char marca[15];
    if(curl)
        {
            CURLcode answer;
            printf("Digite a marca do carro: ");
            __fpurge(stdin);
            scanf ("%15[^\n]", marca);        
            curl_easy_setopt(curl, CURLOPT_URL, "http://fipeapi.appspot.com/api/1/carros/veiculo/21/2111s.json");
            answer = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
}

void gastos_mensais(int *verify, int mes_consulta)
{
    float valor,prestacao,seguro,tanque,total,ipva;
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
    printf("\n\nO gasto mensal com o carro, no mês %d fica em R$%.2f\n",mes_consulta,total);
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