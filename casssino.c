#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int nApostado,nSorteado,lucro,prejuizo,vGanho,cPagou ,jogaPerdeu;
 int qtdKwanza;
  int inversa,numJogada;
//Criando o gerador de n aleatorios
srand(time(NULL));
for(int i=1;numJogada<=7;i++)
{
    printf("digite o numero de jogadas");
    scanf("%d",&numJogada);
    printf("Jogada:%d",numJogada);
    printf("\n Digite o valor da aposta em kwanza(Digite 0 para sair do jogo):");
    scanf("%d", &qtdKwanza);

       
     if (qtdKwanza== 0) 
     {
            printf("Obrigado por jogar. Até a próxima!\n");
            break;
        }
        
        printf("\n Digite o numero da aposta(entre 1 a 50):");
        scanf("%d",&nApostado);
        nSorteado=rand() %51;
         if (nApostado < 0 || nApostado > 50) 
         {
            printf("Número inválido. Tente novamente.\n");
            continue;
        }
         // Verifica se o valor apostado é positivo
        if (qtdKwanza <= 0) {
            printf("Valor inválido. Tente novamente.\n");
            continue;
        }

        //se nAostado=nSorteado=>qtdKwanza * 5
        if (nApostado==nSorteado)
        {
            cPagou=qtdKwanza*5;
            lucro=cPagou-qtdKwanza;
            printf("\n----------------------------------------------------------------------------------------------");

            printf("\n Quantia Apostada:kz %d \n Numero Apostado: %d \n  Numero Sorteado:%d \n",qtdKwanza,nApostado,nSorteado);
              printf("\n o jogador tem um lucro de:kz %d \n cassino pagou:kz %d \n",lucro, cPagou );
                 printf("\n----------------------------------------------------------------------------------------------");

                  printf("Parabéns! Você acertou na igualdade!");
         }
         //se acertar na ordem inversa =>qtdkwanza*3
          else if (nApostado == inversa) {
            
          inversa=(nSorteado % 10 * 10 + nSorteado / 10);
             cPagou=qtdKwanza * 3;
              lucro=cPagou-qtdKwanza;
            printf("\n----------------------------------------------------------------------------------------------");

                 printf("\n Quantia Apostada:kz %d \n Numero Apostado:%d \n   Numero Sorteado:%d \n",qtdKwanza,nApostado,nSorteado);
                    printf("O cassino pagou:kz %d\n O jogador teve um lucro de:kz %d \n  ",cPagou,lucro);
                      printf("\n----------------------------------------------------------------------------------------------");

                          printf("Você acertou na ordem inversa! Ganhou Kz %d!\n", cPagou);
          }
//se acertar na dezena=>qtdkwanza*2
          else if (nApostado / 10 == nSorteado / 10 ) {
            cPagou=qtdKwanza * 2;
             lucro=cPagou-qtdKwanza;
       printf("\n----------------------------------------------------------------------------------------------");

            printf("\n Quantia Apostada:kz %d \n Numero Apostado:%d \n  Numero Sorteado:%d \n",qtdKwanza,nApostado,nSorteado);
                    printf("O cassino pagou:kz %d\n O jogador teve um lucro de:kz %d \n  ",cPagou,lucro);
                     printf("\n----------------------------------------------------------------------------------------------");

                        printf("Você acertou na dezena! Ganhou Kz %d!\n",cPagou);
          }
          //se acertar na unidade=>qtdkwanza *2
           else if ( nApostado % 10 == nSorteado % 10)
            {
              cPagou=qtdKwanza * 2;
               lucro=cPagou-qtdKwanza;
          printf("\n----------------------------------------------------------------------------------------------");

              printf("\n Quantia Apostada:kz %d \n Numero Apostado:%d \n  Numero Sorteado:%d  \n",qtdKwanza,nApostado,nSorteado);
                     printf("O cassino pagou:kz %d\n O jogador teve um lucro de:kz %d \n  ",cPagou,lucro);
                      printf("\n----------------------------------------------------------------------------------------------");

                        printf("Você acertou na  unidade! Ganhou Kz %d!\n",cPagou );
            }
              //se soma de digi for igual ao nsorteado=>qtdkanza *2
            else if ((nApostado / 10 + nApostado % 10) == (nSorteado / 10 + nSorteado % 10))
             {
                cPagou=qtdKwanza * 2;
                  lucro=cPagou-qtdKwanza;
                 printf("\n----------------------------------------------------------------------------------------------");

                         printf(" Quantia Apostada:kz %d \n Numero Apostado:%d \n  Numero Sorteado: %d \n",qtdKwanza,nApostado,nSorteado);
                           printf("O cassino pagou:kz %d\n O jogador teve um lucro de:kz %d \n  ",cPagou,lucro);
                             printf("\n----------------------------------------------------------------------------------------------");

                                 printf("Você acertou na soma dos dígitos! Ganhou Kz %d!\n", cPagou);
             }
             //se paridade =>qtdkwanza*1

              else if (nApostado % 2 == nSorteado % 2) {
                cPagou= qtdKwanza;
                  lucro=cPagou-qtdKwanza;
                printf("\n----------------------------------------------------------------------------------------------");

                    printf("\n Quantia Apostada:kz %d \n Numero Apostado:%d \n  Numero Sorteado: %d \n",qtdKwanza,nApostado,nSorteado);
                         printf("\nO cassino pagou:kz %d\n O jogador teve um lucro de: kz %d \n  ",cPagou,lucro);
                             printf("\n----------------------------------------------------------------------------------------------");

                             printf("\nVocê acertou na paridade! Ganhou Kz %d!\n", cPagou);

              }
              //perdeu
            else {
                  cPagou=qtdKwanza-qtdKwanza;
        printf("\n----------------------------------------------------------------------------------------------");

            printf("\n UPS!! VOCE ERROU TENTA DE NOVO...\n");
                 printf("\n Quantia Apostada:kz %d \n Numero Apostado:%d \nNumero Sorteado:%d \n",qtdKwanza,nApostado,nSorteado);
                 printf("\n----------------------------------------------------------------------------------------------");

                               printf("\n O cassino pagou:kz %d\n O jogador perdeu:kz %d \n  ",cPagou,qtdKwanza);

        }
       


}

return 0;
}