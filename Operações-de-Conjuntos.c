/*  TRABALHO - PROGRAMA��O ESTRUTURADA.
    COMPONENTES:
    �LEF SENA ARA�JO FRANCA;
    JO�O PEDRO SOUSA ANDRADE;
    K�TSON DOS SANTOS SOUZA;
    LUCAS FERNANDES APOLIN�RIO GOMES;

    TAREFA:
    Robervaldo deseja ensinar ao seu filho os conceitos b�sicos e opera��es sobre conjuntos. Para isso
    ele solicitou a voc� que implementasse um programa para ajud�-lo nessa tarefa. Seu programa
    deve implementar as seguintes opera��es sobre conjuntos:

    1. Inserir um elemento em um conjunto;
    2. Remover um elemento de um conjunto;
    3. Verificar se um elemento pertence a um conjunto;
    4. Verificar se um conjunto � subconjunto de outro;
    5. Realizar a uni�o de dois conjuntos;
    6. Realizar a interse��o entre dois conjuntos;
    7. Realizar a diferen�a entre dois conjuntos;
    8. Realizar o produto cartesiano de dois conjuntos;
    9. Imprimir os elementos de um conjunto.

    Para os itens 1, 2 e 3, seu programa deve perguntar qual � o conjunto e o valor a serem trabalhados.
    Para os itens 4 a 8 o seu programa deve solicitar os conjuntos na ordem que a respectiva opera��o
    deve ser realizada.

    Seu programa deve implementar tr�s conjuntos de n�meros inteiros cuja capacidade m�xima
    de cada um � de 100 elementos. Lembre-se que o usu�rio n�o precisa ter exatamente 100 elementos
    em cada conjunto. Sobre esses conjuntos, as opera��es listadas devem ser executadas.

    Para todos os itens, a impress�o do resultado da opera��o � obrigat�ria.
    Seu programa deve implementar um menu de op��es, onde cada item listado � uma op��o
    que o usu�rio poder� escolher. Al�m disso, o menu dever� conter a op��o Sair, e o programa
    ir� terminar somente se o usu�rio escolher tal op��o. Caso a op��o escolhida seja alguma das
    opera��es listadas, ap�s a conclus�o da opera��o, o programa dever� imprimir o menu novamente.

    v2.9

*/

// CONSTANTES.
#define NUM 100

// BIBLIOTECAS.
#include <stdio.h>
#include <locale.h>


int main(){

    // PERMITE A APRESENTA��O DE ACENTOS NO cmd DO WINDOWS.
    setlocale(LC_ALL, "Portuguese");

    // VARI�VEIS GERAIS.
    int A[NUM],B[NUM],C[NUM];             // OS 3 CONJUNTOS PRINCIPAIS DO PROGRAMA.
    int oper=1;                           // oper SER� USADO PELO PARA ALTERNAR ENTRE AS OPERA��ES.
    int num;                              // num SER� USADO NAS OPERA��ES 1 E 2 APENAS PARA ARMAZENAR O ELEMENTO INSERIDO PELO USU�RIO.
    int i=0,j=0;                          // i E j SERAM USADOS COMO �NDICES DAS ESTRUTURAS DE REPETI��O DO PROGRAMA.
    int verif=0;                          // verif SER� UM VERIFICADOR USADO NAS OPERA��ES 4 E 5.
    int fullA=0,fullB=0,fullC=0;          // fullA, fullB E fullC SER�O USADOS POR TODO O PROGRAMA PARA VERIFICAR O N�MERO DE POSI��ES CHEIAS DE CADA CONJUNTO.
    char conj;                            // conj SER� USADO PARA ARMAZENAR O C�DIGO DO CONJUNTO Q SER� USADO NA OPERA��O, NO CASO (A, B OU C).

    //VARI�VEIS OPERA��O 1.
    int elemA,elemB,elemC;                // elemA, elemB E elemC SER�O USADOS PARA ARMAZENAR O ELEMENTO INSERIDO PELO USU�RIO NA OPERA��O 1.

    //VARI�VEIS OPERA��O 2.
    int aux;                              // aux SER� USADO EM UM for PARA REMOVER UM N�MERO DO CONJUNTO.

    // VARI�VEIS OPERA��O 4.
    char subPri,subSeg;                   // subPri E sebSeg, PRIMEIRO E SEGUNDO CONJUNTO RESPECTIVAMENTE.

    // VARI�VEIS OPERA��O 5.
    int uniConj[NUM*2];                   // uniConj[] SER� O CONJUNTO UNI�O DOS CONJUNTOS INSERIDOS PELO USU�RIO.
    int contUniA=0,contUniB=0,contUniC=0; //contUniA, contUniB E contUniC SER�O CONTADORES DO VETOR uniConj NAS RESPECTIVAS COMBINA��ES DE UNI�O.
    int q5vet[NUM];                       // q5vet[] SER� USADO PARA ARMAZENAR OS ELEMENTOS IGUAIS DOS DOIS CONJUNTOS INSERIDOS PELO USU�RIO.
    int q5cont=0;                         // q5cont SER� O CONTADOR DE ELEMENTOS CHEIOS DO VETOR q5vet[].
    int k;                                // k SER� UM �NDICE.
    char uniPri,uniSeg;                   // uniPri E uniSeg, PRIMEIRO E SEGUNDO CONJUNTO UNI�O RESPECTIVAMENTE.

    // VARI�VEIS OPERA��O 6.
    int interConj[NUM];                   // interConj[] SER� USADO PARA ARMAZENAR OS ELEMENTOS DA INTERSE��O ENTRE DOIS CONJUNTOS.
    int contInter=0;                      // contInter SER� USADO COMO CONTADOR DE ESPA�OS CHEIOS DO VETOR interConj[].
    char interPri,interSeg;               // interPri E interSeg, PRIMEIRO E SEGUNDO CONJUNTO INTERSE��O RESPECTIVAMENTE.
    // VARI�VEIS OPERA��O 7
    int difeConj[NUM];
    int contDife=0;                       //SER� USADO COMO CONTADOR DE ESPA�OS DO VETOR difeConj[].
    int verifDif=0;                       //SER� USADO PARA VERIFICAR SE UM ELEMENTO DO 1�CONJUNTO NAO EST� EM NENHUMA POSI��O DO 2� CONJUNTO
    char difePri , difeSeg;
    // VARI�VEIS OPERA��O 8.
    char carPri,carSeg;

    // VARI�VIES OPERA��O 9.
    char imprConj;

    // APRESENTA��O DO PROGRAMA.
    printf("\n----------------------------OPERA��ES COM CONJUNTOS-----------------------------");

    printf("\n\n OBS1: Considere tres conjuntos: A B e C, com capacidade maxima de 100 numeros\n inteiros.");
    printf("\n OBS2: Para evitar erros, evite inserir elementos repetidos no mesmo conjunto.");

    // INICIO DO ALGORITMO.

    /* ZERANDO TODOS OS ELEMENTOS DOS VETORES.
    for (i=0;i<NUM;i++){
        A[i]=0;
        B[i]=0;
        C[i]=0;
    } */

    /* TODO O PROGRAMA SER� RESUMIDO EM UM �NICO while, ONDE O USU�RIO PODER� ALTERNAR
       ENTRE AS OPERA��ES QUANTAS VEZES QUISER, AT� QUE UM N�MERO INTEIRO FORA DO INTERVALO 1~9 SEJA INSERIDO. */
    while((oper>=1)&&(oper<=9)){

        // MENU DO PROGRAMA.
        printf("\n\n Para realizar uma operacao, insira um dos respectivos numeros abaixo: ");
        printf("\n\n 1. Inserir um elemento em um conjunto;");
        printf("\n 2. Remover um elemento de um conjunto;");
        printf("\n 3. Verificar se um elemento pertence a um conjunto;");
        printf("\n 4. Verificar se um conjunto � subconjunto de outro;");
        printf("\n 5. Realizar a uni�o de dois conjuntos;");
        printf("\n 6. Realizar a interse��o entre dois conjuntos;");
        printf("\n 7. Realizar a diferen�a entre dois conjuntos;");
        printf("\n 8. Realizar o produto cartesiano de dois conjuntos;");
        printf("\n 9. Imprimir os elementos de um conjunto;");
        printf("\n 0. Para fechar o programa.");

        // PERGUNTAR AO USU�RIO QUAL OPERA��O DESEJA REALIZAR.
        printf("\n\n N�mero da operacao a ser realizada: ");
        scanf("%d",&oper);

        // ESTE switch SER� USADO PARA ALTERNAR ENTRE AS OP��ES DE OPERA��ES.
        switch(oper){

            // PRIMEIRA OPERA��O, INSERINDO UM N�MERO EM UM CONJUNTO.
            case 1: printf("\n 1. Inserir um elemento em um conjunto.");

                    // PERGUNTANDO AO USU�RIO QUAL CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Conjunto a ser utilizado (A,B ou C): ");
                    scanf("%s",&conj);

                    // switch PARA REALIZAR APENAS UMA OPERA��O.
                    switch(conj){
                        case 'A': printf("\n Conjunto A.");

                                  // if PARA VERIFICAR SE O CONJUNTO EST� CHEIO OU NAO.
                                  if(fullA==100){
                                    printf("\n Conjunto cheio !!");
                                    printf("\n Conjunto atual: \n");
                                    for (i=0;i<fullA;i++){
                                        printf(" %d",A[i]);
                                    }
                                  }
                                  else{

                                    /* DESTA FORMA O USU�RIO PODE INSERIR V�RIOS ELEMENTOS DE UMA VEZ, SEM PRECISAR
                                       VOLTAR AO MENU E INSERIR UM A UM. */
                                    printf("\n Quantidade de elementos a ser inserida: ");
                                    scanf("%d",&elemA);
                                    printf("\n");

                                    // ESTE for SE REPETIR� O N�MERO DE VEZES QUE O USU�RIO INSERIU.
                                    for (i=0;i<elemA;i++){
                                        printf(" Elemento a ser inserido: ");
                                        scanf("%d",&num);
                                        A[fullA]=num;
                                        fullA++;
                                    }

                                    // MOSTRANDO NA TELA O RESULTADO DO CONJUNTO AP�S A OPERA��O.
                                    printf("\n Conjunto A ap�s a modifica��o: \n");
                                    for (i=0;i<fullA;i++){
                                        printf(" %d",A[i]);
                                    }
                                  }
                                  break;
                                  // O MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                        case 'B': printf("\n Conjunto B.");
                                  if(fullB==100){
                                    printf("\n Conjunto cheio !!");
                                    printf("\n Conjunto atual: \n");
                                    for (i=0;i<fullB;i++){
                                        printf(" %d",B[i]);
                                    }
                                  }
                                  else{
                                    printf("\n Quantidade de elementos a ser inserida: ");
                                    scanf("%d",&elemB);
                                    printf("\n");
                                    for (i=0;i<elemB;i++){
                                        printf(" Elemento a ser inserido: ");
                                        scanf("%d",&num);
                                        B[fullB]=num;
                                        fullB++;
                                    }
                                    printf("\n Conjunto B ap�s a modifica��o: \n");
                                    for (i=0;i<fullB;i++){
                                        printf(" %d",B[i]);
                                    }
                                  }
                                  break;
                        case 'C': printf(" Conjunto C.");
                                  if(fullC==100){
                                    printf("\n Conjunto cheio !!");
                                    printf("\n Conjunto atual: ");
                                    for (i=0;i<fullC;i++){
                                        printf(" %d",C[i]);
                                    }
                                  }
                                  else{
                                    printf("\n Quantidade de elementos a ser inserida: ");
                                    scanf("%d",&elemC);
                                    printf("\n");
                                    for (i=0;i<elemC;i++){
                                        printf(" Elemento a ser inserido: ");
                                        scanf("%d",&num);
                                        C[fullC]=num;
                                        fullC++;
                                    }
                                    printf("\n Conjunto C ap�s a modifica��o: \n");
                                    for (i=0;i<fullB;i++){
                                        printf(" %d",C[i]);
                                    }
                                  }
                                  break;
                    }
                    break;

            // SEGUNDA OPERA��O, REMOVENDO UM ELEMENTO DE UM CONJUNTO.
            case 2: printf("\n 2. Remover um elemento de um conjunto.");

                    // PERGUNTANDO AO USU�RIO QUAL CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Conjunto a ser utilizado (A,B ou C): ");
                    scanf("%s",&conj);

                    // switch PARA REALIZAR APENAS UMA OPERA��O.
                    switch(conj){
                        case 'A': printf("\n Conjunto A.");

                                  // if PARA VERIFICAR SE O CONJUNTO EST� VAZIO OU N�O.
                                  if(fullA==0){
                                    printf("\n O conjunto est� vazio !!");
                                  }
                                  else{
                                    // PERGUNTANDO AO USU�RIO QUAL N�MERO SER� USADO NA OPERA��O.
                                    printf("\n N�mero a ser removido: ");
                                    scanf("%d",&num);

                                    // for PARA VERIFICAR SE O N�MERO INSERIDO PELO USU�RIO EST� NO CONJUNTO.
                                    for (i=0;i<fullA;i++){
                                        // CASO ESTEJA, A VARI�VEL aux RECEBER� O VALOR DO �NDICE CORRESPONDENTE A ESSE N�MERO.
                                        if(num==A[i]){
                                            aux=i;
                                            break;
                                        }
                                    }

                                    // for PARA REMOVER O N�MERO DO CONJUNTO.
                                    /* A ESTRUTURA COME�AR� NO �NDICE CORRESPONDENTE AO N�MERO QUE O USU�RIO INSERIU, E
                                       PERCORRER� TODO O RESTANTE DO CONJUNTO.*/
                                    /* ELA SUBSTITUIR� O ELEMENTO INSERIDO PELO PR�XIMO ELEMENTO, DEPOIS ESSE ELEMENTO SER�
                                       SUBSTITU�DO PELO SEU PROXIMO ELEMENTO, E ASSIM POR DIANTE.*/
                                    for(aux;aux<fullA;aux++){
                                        A[aux]=A[aux+1];
                                    }
                                    // REMOVENDO UMA UNIDADE DA VARI�VEL fullA.
                                    fullA--;
                                    printf("\n Conjunto A ap�s a modifica��o: \n");
                                    for (i=0;i<fullA;i++){
                                        printf(" %d",A[i]);
                                    }
                                  }
                                  break;
                                  // O MESMO RACIC�NIO PARA OS PROXIMOS case.
                        case 'B': printf("\n Conjunto B.");
                                  if(fullB==0){
                                    printf("\n O conjunto est� vazio !!");
                                  }
                                  else{
                                    printf("\n N�mero a ser removido: ");
                                    scanf("%d",&num);
                                    for (i=0;i<fullB;i++){
                                        if(num==B[i]){
                                            aux=i;
                                            break;
                                        }
                                    }
                                    for(aux;aux<NUM;aux++){
                                        A[aux]=A[aux+1];
                                    }
                                    fullB--;
                                    printf("\n Conjunto B ap�s a modifica��o: \n");
                                    for (i=0;i<fullB;i++){
                                        printf(" %d",B[i]);
                                    }
                                  }
                                  break;
                        case 'C': printf("\n Conjunto C.");
                                  if(fullC==0){
                                    printf("\n O conjunto est� vazio !!");
                                  }
                                  else{
                                    printf("\n N�mero a ser removido: ");
                                    scanf("%d",&num);
                                    for (i=0;i<fullC;i++){
                                        if(num==C[i]){
                                            aux=i;
                                            break;
                                        }
                                    }
                                    for(aux;aux<NUM;aux++){
                                        A[aux]=A[aux+1];
                                    }
                                    fullC--;
                                    printf("\n Conjunto C ap�s a modifica��o: \n");
                                    for (i=0;i<fullC;i++){
                                        printf(" %d",C[i]);
                                    }
                                  }
                                  break;
                    }
                    break;

            // TERCEIRA OPERA��O, VERIFICANDO SE UM ELEMENTO PERTENCE A UM CONJUNTO.
            case 3: printf("\n 3. Verificar se um elemento pertence a um conjunto.");

                    // PERGUNTANDO AO USU�RIO QUAL CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Conjunto a ser utilizado (A, B ou C): ");
                    scanf("%s",&conj);

                    // switch PARA REALIZAR APENAS UMA OPERA��O.
                    switch(conj){
                        case 'A': printf("\n Conjunto A.");

                                  // PERGUNTANDO AO USU�RIO QUAL N�MERO SER� USADO NA OPERA��O.
                                  printf("\n N�mero a ser verificado: ");
                                  scanf("%d",&num);

                                  // for PARA VERIFICAR SE O N�MERO INSERIDO PELO USU�RIO EST� NO CONJUNTO.
                                  for (i=0;i<fullA;i++){

                                    // CASO ESTEJA, SER� MOSTRADA UMA MENSAGEM NA TELA.
                                    if(num==A[i]){
                                        printf("\n O n�mero %d se encontra no conjunto A na posi��o %d",num,i+1);

                                        // A VARI�VEL verif SER� USADA NESSE CASO PARA VERIFICAR SE O N�MERO FOI ENCONTRADO OU N�O.
                                        // CASO O N�MERO FOR ENCONTRADO NO VETOR, verif RECEBER� 1 PARA N�O ENTRAR NO PR�XIMO if.
                                        verif=1;
                                    }
                                  }

                                  // CASO N�O ESTEJA, OUTRA MENSAGEM SER� MOSTRADA NA TELA.
                                  if(verif==0){
                                    printf("\n O n�mero %d n�o se encontra no conjunto A.",num);
                                  }

                                  // RESETANDO A VARIAVEL verif PARA FUTURAS UTILIZA��ES NO PROGRAMA.
                                  verif=0;
                                  break;
                                  // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                        case 'B': printf("\n Conjunto B.");
                                  printf("\n N�mero a ser verificado: ");
                                  scanf("%d",&num);
                                  for (i=0;i<NUM;i++){
                                    if(num==B[i]){
                                        printf("\n O n�mero %d se encontra no conjunto B na posi��o %d",num,i);
                                        verif=1;
                                    }
                                  }
                                  if(verif==0){
                                    printf("\n O n�mero %d n�o se encontra no conjunto B.",num);
                                  }
                                  verif=0;
                                  break;
                        case 'C': printf("\n Conjunto C.");
                                  printf("\n N�mero a ser verificado: ");
                                  scanf("%d",&num);
                                  for (i=0;i<NUM;i++){
                                    if(num==C[i]){
                                        printf("\n O n�mero %d se encontra no conjunto C na posi��o %d",num,i);
                                        verif=1;
                                    }
                                  }
                                  if(verif==0){
                                        printf("\n O n�mero %d n�o se encontra no conjunto C.",num);
                                  }
                                  verif=0;
                                  break;
                    }
                    break;

            // QUARTA OPERA��O, VERIFICANDO SE UM CONJUNTO � SUBCONJUNTO DE OUTRO.
            case 4: printf("\n 4. Verificar se um conjunto � subconjunto de outro.");

                    // PERGUNTANDO AO USU�RIO QUAL O PRIMEIRO CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Conjunto a ser verificado (A, B ou C): ");
                    scanf("%s",&subPri);

                    // switch PARA VERIFICAR QUAL O PRIMEIRO CONJUNTO INSERIDO.
                    switch(subPri){
                        case 'A':
                                  // PERGUNTANDO AO USU�RIO QUAL O SEGUNDO CONJUNTO SER� USADO NA OPERA��O.
                                  printf("\n Conjunto a qual ser� verificada a contin�ncia (A, B ou C): ");
                                  scanf("%s",&subSeg);

                                  // switch PARA VERIFICAR QUAL O SEGUNDO CONJUNTO INSERIDO.
                                  switch(subSeg){
                                      case 'A':
                                                /* CASO O USU�RIO INSIRA DOIS CONJUNTOS IGUAIS, ALGUMAS MENSAGENS SER�O MOSTRADAS
                                                   NA TELA NO CASO O CONJUNTO A[].*/
                                                printf("\n Verificando a contin�ncia de A em A.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n O conjunto A est� contido em A:");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'B': printf("\n Verificando a contin�ncia de A em B.");

                                                // RESETANDO A VARI�VEL verif PARA SER USADA NA OPERA��O.
                                                verif=0;

                                                /* for PARA VERIFICAR SE TODOS OS ELEMENTOS DO PRIMEIRO CONJUNTO EST�O CONTIDOS NO
                                                   SEGUNDO CONJUNTO.*/
                                                /* O PRIMEIRO for PERCORRER� TODO O PRIMEIRO VETOR, O SEGUNDO for PERCORRER� TODO O
                                                   SEGUNDO VETOR.*/
                                                for (i=0;i<fullA;i++){
                                                    for (j=0;j<fullB;j++){

                                                        /* SE O ELEMENTO DO PRIMEIRO CONJUNTO FOR ENCONTRADO NO SEGUNDO CONJUNTO, A
                                                           VARI�VEL verif RECEBER� +1, POIS SER� USADA EM UMA FUTURA VERIFICA��O.*/
                                                        if(A[i]==B[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }

                                                /* SE TODOS OS N�MEROS DO PRIMEIRO CONJUNTO FOREM ENCONTRADOS NO SEGUNDO, ENT�O A
                                                   VARI�VEL verif DEVER� SER IGUAL A VARI�VEL fullA.*/
                                                // SE ISSO ACONTECER, UMA MENSAGEM DE CONFIRMA��O SER� MOSTRADA NA TELA.
                                                if(verif==fullA){
                                                    printf("\n O conjunto A est� contido em B.");
                                                }

                                                /* SE ALGUM N�MERO DO PRIMEIRO CONJUNTO NAO FOR ENCONTRADO NO SEGUNDO, verif SER�
                                                   DIFERENTE DE fullA, ENT�O OUTRA MENSAGEM SER� MOSTRADA NA TELA.*/
                                                else{
                                                    printf("\n O conjunto A n�o est� contido em B.");
                                                }

                                                // MOSTRANDO NA TELA OS DOIS CONJUNTOS USADOS NA OPERA��O.
                                                printf("\n Conjunto A: \n");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                printf("\n Conjunto B: \n");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",B[i]);
                                                }
                                                break;
                                                // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                                      case 'C': printf("\n Verificando a contin�ncia de A em C.");
                                                verif=0;
                                                for (i=0;i<fullA;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(A[i]==C[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }
                                                if(verif==fullA){
                                                    printf("\n O conjunto A est� contido em C.");
                                                }
                                                else{
                                                    printf("\n O conjunto A n�o est� contido em C.");
                                                }
                                                printf("\n Conjunto A: \n");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                printf("\n Conjunto C: \n");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",C[i]);
                                                }
                                                break;
                                  }
                                  break;
                        case 'B': printf("\n Conjunto a qual ser� verificada a contin�ncia (A, B ou C): ");
                                  scanf("%s",&subSeg);
                                  switch(subSeg){
                                      case 'A': printf("\n Verificando a contin�ncia de B em A.");
                                                verif=0;
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(B[i]==A[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }
                                                if(verif==fullB){
                                                    printf("\n O conjunto B est� contido em A.");
                                                }
                                                else{
                                                    printf("\n O conjunto B n�o est� contido em A.");
                                                }
                                                printf("\n Conjunto B: \n");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",B[i]);
                                                }
                                                printf("\n Conjunto A: \n");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'B': printf("\n Verificando a contin�ncia de B em B.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n O conjunto B est� contido em B.");
                                                break;
                                      case 'C': printf("\n Verificando a contin�ncia de B em C.");
                                                verif=0;
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(B[i]==C[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }
                                                if(verif==fullB){
                                                    printf("\n O conjunto B est� contido em C.");
                                                }
                                                else{
                                                    printf("\n O conjunto B n�o est� contido em C.");
                                                }
                                                printf("\n Conjunto B: \n");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",B[i]);
                                                }
                                                printf("\n Conjunto C: \n");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",C[i]);
                                                }
                                                break;
                                  }
                                  break;
                        case 'C': printf("\n Conjunto a qual ser� verificada a contin�ncia (A, B ou C): ");
                                  scanf("%s",&subSeg);
                                  switch(subSeg){
                                      case 'A': printf("\n Verificando a contin�ncia de C em A.");
                                                verif=0;
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(C[i]==A[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }
                                                if(verif==fullC){
                                                    printf("\n O conjunto C est� contido em A.");
                                                }
                                                else{
                                                    printf("\n O conjunto C n�o est� contido em A.");
                                                }
                                                printf("\n Conjunto C: \n");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",C[i]);
                                                }
                                                printf("\n Conjunto A: \n");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'B': printf("\n Verificando a contin�ncia de C em B.");
                                                verif=0;
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullB;j++){
                                                        if(C[i]==B[j]){
                                                            verif++;
                                                        }
                                                    }
                                                }
                                                if(verif==fullC){
                                                    printf("\n O conjunto C est� contido em B.");
                                                }
                                                else{
                                                    printf("\n O conjunto C n�o est� contido em .");
                                                }
                                                printf("\n Conjunto C: \n");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",C[i]);
                                                }
                                                printf("\n Conjunto B: \n");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",B[i]);
                                                }
                                                break;
                                      case 'C': printf("\n Verificando a contin�ncia de C em C.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n O conjunto C est� contido em C.");
                                                break;                                  }
                                  break;
                    }
                    break;

            // QUINTA OPERA��O, UNI�O ENTRE CONJUNTOS.
            case 5: printf("\n 5. Realizar a uni�o de dois conjuntos;");

                    // PERGUNTANDO AO USU�RIO QUAL O PRIMEIRO CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Primeiro conjunto (A,B ou C): ");
                    scanf("%s",&uniPri);

                    // switch PARA VERIFICAR QUAL O PRIMEIRO CONJUNTO INSERIDO.
                    switch(uniPri){
                        case 'A':
                                  // PERGUNTANDO AO USU�RIO QUAL O SEGUNDO CONJUNTO SER� USADO NA OPERA��O.
                                  printf(" Segundo conjunto (A,B ou C): ");
                                  scanf("%s",&uniSeg);

                                  // switch PARA VERIFICAR QUAL O SEGUNDO CONJUNTO INSERIDO.
                                  switch(uniSeg){
                                      case 'A':
                                                /* CASO OS DOIS CONJUNTOS INSERIDOS SEJAM IGUAIS, ALGUMAS MENSAGENS SER�O MOSTRADAS
                                                   NA TELA.*/
                                                printf("\n Uni�o dos conjuntos A com A.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A uni�o ser� o pr�prio conjunto:\n");
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'B': printf(" Uni�o dos conjuntos A com B:\n");

                                                /* PREENCHENDO A PRIMEIRA PARTE DO VETOR uniConj[] COM OS ELEMENTOS DO PRIMEIRO
                                                   CONJUNTO INSERIDO PELO USU�RIO.*/
                                                for (i=0;i<fullA;i++){
                                                    uniConj[contUniA]=A[i];
                                                    contUniA++;
                                                }

                                                /* PREENCHENDO A SEGUNDA PARTE DO VETOR uniConj[] COM OS ELEMENTOS DO SEGUNDO
                                                   CONJUNTO INSERIDO PELO USU�RIO.*/
                                                for (i=0;i<fullB;i++){
                                                    uniConj[contUniA]=B[i];
                                                    contUniA++;
                                                }

                                                /* O PRIMEIRO for PERCORRER� O PRIMEIRO CONJUNTO INSERIDO, ASSIM COMO O SEGUNDO for
                                                   PERCORRER� O SEGUNDO CONJUNTO INSERIDO.*/
                                                for (i=0;i<fullA;i++){
                                                    for (j=0;j<fullB;j++){

                                                        /* O VETOR q5vet[] SER� USADO PARA ARMAZENAR OS ELEMENTOS IGUAIS DOS DOIS
                                                           CONJUNTOS INSERIDOS PELO USU�RIO.*/
                                                        if(A[i]==B[j]){
                                                            q5vet[q5cont]=B[j];

                                                            // q5cont SER� O CONTADOR DE ELEMENTOS CHEIOS DO VETOR q5vet[].
                                                            q5cont++;
                                                        }
                                                    }
                                                }

                                                // ESTE for SER� USADO PARA PERCORRER uniConj[].
                                                for (i=fullA;i<contUniA;i++){

                                                    // ESTE for SER� USADO PARA PERCORRER q5vet[].
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){

                                                            /* CASO OS ELEMENTOS DE q5vet[] E uniConj[] SEJAM IGUAIS, ESTE for SER�
                                                               ATIVADO PARA REMOVER O N�MERO DO VETOR uniConj[], COM O MESMO RACIOC�NIO
                                                               A OPERA��O 2.*/
                                                            for (k=i;k<contUniA;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }

                                                            // REMOVENDO UMA UNIDADE DA VARI�VEL contUniA.
                                                            contUniA--;
                                                        }
                                                    }
                                                }

                                                // IMPRIMINDO O VETOR CONJUNTO UNI�O RESULTADO DA OPERA��O.
                                                for (i=0;i<contUniA;i++){
                                                    printf(" %d",uniConj[i]);
                                                }

                                                // ZERANDO O CONJUNTO uniConj[] PARA FUTURAS OPERA��ES.
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }

                                                // RESETANDO A VARI�VEL contUniA PARA FUTURAS OPERA��ES.
                                                contUniA=0;

                                                // ZERANDO O CONJUNTO q5vet[] PARA FUTURAS OPERA��ES.
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }

                                                // RESETANDO A VARI�VEL q5cont PARA FUTURAS OPERA��ES.
                                                q5cont=0;
                                                break;
                                                // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                                      case 'C': printf(" Uni�o dos conjuntos A com C:\n");
                                                for (i=0;i<fullA;i++){
                                                    uniConj[contUniA]=A[i];
                                                    contUniA++;
                                                }
                                                for (i=0;i<fullC;i++){
                                                    uniConj[contUniA]=C[i];
                                                    contUniA++;
                                                }
                                                for (i=0;i<fullA;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(A[i]==C[j]){
                                                            q5vet[q5cont]=C[j];
                                                            q5cont++;
                                                        }
                                                    }
                                                }
                                                for (i=fullA;i<contUniA;i++){
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){
                                                            for (k=i;k<contUniA;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }
                                                            contUniA--;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contUniA;i++){
                                                    printf(" %d",uniConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }
                                                contUniA=0;
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }
                                                q5cont=0;
                                                break;
                                  }
                                  break;
                        case 'B': printf(" Segundo conjunto (A,B ou C): ");
                                  scanf("%s",&uniSeg);
                                  switch(uniSeg){
                                      case 'B': printf("\n Uni�o dos conjuntos B com B.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A uni�o ser� o pr�prio conjunto:\n");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",B[i]);
                                                }
                                                break;
                                      case 'A': printf(" Uni�o dos conjuntos B com A:\n");
                                                for (i=0;i<fullB;i++){
                                                    uniConj[contUniB]=B[i];
                                                    contUniB++;
                                                }
                                                for (i=0;i<fullA;i++){
                                                    uniConj[contUniB]=A[i];
                                                    contUniB++;
                                                }
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(B[i]==A[j]){
                                                            q5vet[q5cont]=A[j];
                                                            q5cont++;
                                                        }
                                                    }
                                                }
                                                for (i=fullB;i<contUniB;i++){
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){
                                                            for (k=i;k<contUniB;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }
                                                            contUniB--;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contUniB;i++){
                                                    printf(" %d",uniConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }
                                                contUniB=0;
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }
                                                q5cont=0;
                                                break;
                                      case 'C': printf(" Uni�o dos conjuntos B com C:\n");
                                                for (i=0;i<fullB;i++){
                                                    uniConj[contUniB]=B[i];
                                                    contUniB++;
                                                }
                                                for (i=0;i<fullC;i++){
                                                    uniConj[contUniB]=C[i];
                                                    contUniB++;
                                                }
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(B[i]==C[j]){
                                                            q5vet[q5cont]=C[j];
                                                            q5cont++;
                                                        }
                                                    }
                                                }
                                                for (i=fullB;i<contUniB;i++){
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){
                                                            for (k=i;k<contUniB;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }
                                                            contUniB--;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contUniB;i++){
                                                    printf(" %d",uniConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }
                                                contUniB=0;
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }
                                                q5cont=0;
                                                break;
                                  }
                                  break;
                        case 'C': printf(" Segundo conjunto (A,B ou C): ");
                                  scanf("%s",&uniSeg);
                                  switch(uniSeg){
                                      case 'C': printf("\n Uni�o dos conjuntos C com C.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A uni�o ser� o pr�prio conjunto:\n");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",C[i]);
                                                }
                                                break;
                                      case 'A': printf(" Uni�o dos conjuntos C com A:\n");
                                                for (i=0;i<fullC;i++){
                                                    uniConj[contUniC]=C[i];
                                                    contUniC++;
                                                }
                                                for (i=0;i<fullA;i++){
                                                    uniConj[contUniC]=A[i];
                                                    contUniC++;
                                                }
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(C[i]==A[j]){
                                                            q5vet[q5cont]=A[j];
                                                            q5cont++;
                                                        }
                                                    }
                                                }
                                                for (i=fullC;i<contUniC;i++){
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){
                                                            for (k=i;k<contUniC;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }
                                                            contUniC--;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contUniC;i++){
                                                    printf(" %d",uniConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }
                                                contUniB=0;
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }
                                                q5cont=0;
                                                break;
                                      case 'B': printf(" Uni�o dos conjuntos C com B:\n");
                                                for (i=0;i<fullC;i++){
                                                    uniConj[contUniC]=C[i];
                                                    contUniC++;
                                                }
                                                for (i=0;i<fullB;i++){
                                                    uniConj[contUniC]=B[i];
                                                    contUniC++;
                                                }
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullB;j++){
                                                        if(C[i]==B[j]){
                                                            q5vet[q5cont]=A[j];
                                                            q5cont++;
                                                        }
                                                    }
                                                }
                                                for (i=fullC;i<contUniC;i++){
                                                    for (j=0;j<q5cont;j++){
                                                        if(q5vet[j]==uniConj[i]){
                                                            for (k=i;k<contUniC;k++){
                                                                uniConj[k]=uniConj[k+1];
                                                            }
                                                            contUniC--;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contUniC;i++){
                                                    printf(" %d",uniConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    uniConj[i]=0;
                                                }
                                                contUniC=0;
                                                for (i=0;i<q5cont;i++){
                                                    q5vet[i]=0;
                                                }
                                                q5cont=0;
                                                break;
                                  }
                                  break;
                    }
                    break;

            // SEXTA OPERA��O, INTERSE��O ENTRE CONJUNTOS.
            case 6: printf("\n 6. Realizar a interse��o entre dois conjuntos.");

                    // PERGUNTANDO AO USU�RIO QUAL O PRIMEIRO CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Primeiro conjunto (A, B ou C): ");
                    scanf("%s",&interPri);

                    // switch PARA VERIFICAR QUAL O PRIMEIRO CONJUNTO INSERIDO.
                    switch(interPri){
                        case 'A':
                                  // PERGUNTANDO AO USU�RIO QUAL O SEGUNDO CONJUNTO SER� USADO NA OPERA��O.
                                  printf(" Segundo conjunto (A,B ou C):  ");
                                  scanf("%s",&interSeg);

                                  // switch PARA VERIFICAR QUAL O SEGUNDO CONJUNTO INSERIDO.
                                  switch(interSeg){
                                      case 'A':
                                                // CASO OS CONJUNTOS INSERIDOS SEJAM IGUAIS, ALGUMAS MENSAGENS SER�O MOSTRADAS NA TELA.
                                                printf("\n Interse��o dos conjuntos A com A.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A interse��o ser� o pr�prio conjunto:");

                                                // IMPRIMINDO O CONJUNTO INSERIDO.
                                                for (i=0;i<fullA;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'B': printf("\n Interse��o dos conjuntos A com B:");

                                                // ESTE for SER� USADO PARA PERCORRER O PRIMEIRO CONJUNTO INSERIDO.
                                                for (i=0;i<fullA;i++){

                                                    // ESTE for SER� USADO PARA PERCORRER O SEGUNDO CONJUNTO INSERIDO.
                                                    for (j=0;j<fullB;j++){

                                                        /* DESSA MANEIRA, O PRIMEIRO ELEMENTO DO PRIMEIRO CONJUNTO SER� COMPARADO COM
                                                           TODOS OS ELEMENTOS DO SEGUNDO, E ASSIM POR DIANTE.*/
                                                        /* CASO O ELEMENTO DO PRIMEIRO CONJUNTO SEJA IGUAL AO ELEMENTO DO SEGUNDO,
                                                           O VETOR interConj[] SER� USADO PARA ARMAZENAR TAL ELEMENTO. */
                                                        if(A[i]==B[j]){
                                                            interConj[contInter]=A[i];

                                                            /* A VARI�VEL contInter SER� USADA COMO CONTADOR DE ESPA�OS CHEIOS DO
                                                               VETOR interConj[]. */
                                                            // INCREMENTANDO UMA UNIDADE NA VARI�VEL contInter.
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }

                                                // IMPRIMINDO O CONJUNTO INTERSE��O RESULTANTE.
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }

                                                // ZERANDO O VETOR interConj[] PARA FUTURAS OPERA��ES.
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }

                                                // RESETANDO A VARI�VEL contInter PARA FUTURAS OPERA��ES.
                                                contInter=0;
                                                break;
                                                // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                                      case 'C': printf("\n Interse��o dos conjuntos A com C:");
                                                for (i=0;i<fullA;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(A[i]==C[j]){
                                                            interConj[contInter]=A[i];
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }
                                                contInter=0;
                                                break;
                                  }
                                  break;
                        case 'B': printf(" Segundo conjunto (A,B ou C):  ");
                                  scanf("%s",&interSeg);
                                  switch(interSeg){
                                      case 'B': printf("\n Interse��o dos conjuntos B com B.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A interse��o ser� o pr�prio conjunto:");
                                                for (i=0;i<fullB;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'A': printf("\n Interse��o dos conjuntos B com A:");
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(B[i]==A[j]){
                                                            interConj[contInter]=B[i];
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }
                                                contInter=0;
                                                break;
                                      case 'C': printf("\n Interse��o dos conjuntos B com C:");
                                                for (i=0;i<fullB;i++){
                                                    for (j=0;j<fullC;j++){
                                                        if(B[i]==C[j]){
                                                            interConj[contInter]=B[i];
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }
                                                contInter=0;
                                                break;
                                  }
                                  break;
                        case 'C': printf(" Segundo conjunto (A,B ou C):  ");
                                  scanf("%s",&interSeg);
                                  switch(interSeg){
                                      case 'C': printf("\n Interse��o dos conjuntos C com C.");
                                                printf("\n Conjuntos iguais.");
                                                printf("\n A interse��o ser� o pr�prio conjunto:");
                                                for (i=0;i<fullC;i++){
                                                    printf(" %d",A[i]);
                                                }
                                                break;
                                      case 'A': printf("\n Interse��o dos conjuntos C com A:");
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullA;j++){
                                                        if(C[i]==A[j]){
                                                            interConj[contInter]=C[i];
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }
                                                contInter=0;
                                                break;
                                      case 'B': printf("\n Interse��o dos conjuntos C com B:");
                                                for (i=0;i<fullC;i++){
                                                    for (j=0;j<fullB;j++){
                                                        if(C[i]==B[j]){
                                                            interConj[contInter]=C[i];
                                                            contInter++;
                                                            break;
                                                        }
                                                    }
                                                }
                                                for (i=0;i<contInter;i++){
                                                    printf(" %d",interConj[i]);
                                                }
                                                for (i=0;i<NUM;i++){
                                                    interConj[i]=0;
                                                }
                                                contInter=0;
                                                break;
                                  }
                                  break;
                    }
                    break;

            // S�TIMA OPERA��O, DIFEREN�A ENTRE CONJUNTOS.
            case 7: printf("\n 7. Realizar a diferen�a entre dois conjuntos.");
                    //inicia
                    // PERGUNTANDO AO USU�RIO QUAL O PRIMEIRO CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Primeiro conjunto (A,B ou C): ");
                    scanf("%s",&difePri);
                    switch(difePri){
                        case 'A':
                                  // PERGUNTANDO AO USU�RIO QUAL O SEGUNDO CONJUNTO SER� USADO NA OPERA��O.
                                  printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&difeSeg);

                                  // switch PARA VERIFICAR QUAL O SEGUNDO CONJUNTO INSERIDO.
                                  switch(difeSeg){
                                      case 'A': printf("\n Diferenca de A com A.");
                                                printf(" {");
                                                printf(" }");
                                                break;

                                      case 'B': printf("\n Diferen�a de A com B.");
                                                printf(" {");
                                                for(i=0;i<fullA;i++){
                                                    for(j=0;j<fullB;j++){
                                                        if(A[i] == B[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullB){
                                                        difeConj[contDife] = A[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");
                                                break;

                                      case 'C': printf("\n Diferen�a de A com C.");
                                                printf(" {");
                                                for(i=0;i<fullA;i++){
                                                    for(j=0;j<fullC;j++){
                                                        if(A[i] == C[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullC){
                                                        difeConj[contDife] = A[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");
                                                break;
                                  }
                                  break;
                        case 'B': printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&carSeg);
                                  switch(carSeg){
                                      case 'A': printf("\n Diferen�a de B com A.");
                                                printf(" {");
                                                for(i=0;i<fullB;i++){
                                                    for(j=0;j<fullA;j++){
                                                        if(B[i] == A[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullA){
                                                        difeConj[contDife] = B[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");
                                                break;
                                      case 'B': printf("\n Diferenca de B com B.");
                                                printf(" {");
                                                printf(" }");
                                                break;
                                      case 'C': printf("\n Diferen�a de B com C.");
                                                printf(" {");
                                                for(i=0;i<fullB;i++){
                                                    for(j=0;j<fullC;j++){
                                                        if(B[i] == C[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullC){
                                                        difeConj[contDife] = B[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");

                                                break;
                                  }
                                  break;
                        case 'C': printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&carSeg);
                                  switch(carSeg){
                                      case 'A': printf("\n Diferen�a de C com A.");
                                                printf(" {");
                                                for(i=0;i<fullC;i++){
                                                    for(j=0;j<fullA;j++){
                                                        if(C[i] == A[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullA){
                                                        difeConj[contDife] = C[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");
                                                break;
                                      case 'B': printf("\n Diferen�a de C com B.");
                                                printf(" {");
                                                for(i=0;i<fullC;i++){
                                                    for(j=0;j<fullB;j++){
                                                        if(C[i] == B[j]){
                                                            break;
                                                        }else{
                                                            verifDif ++;
                                                        }
                                                    }
                                                    if(verifDif == fullB){
                                                        difeConj[contDife] = C[i];
                                                        contDife ++;
                                                    }
                                                    verifDif = 0;
                                                }
                                                for(i = 0; i < contDife; i++){
                                                    printf(" %d", difeConj[i]);
                                                }
                                                printf(" }");
                                                break;
                                      case 'C': printf("\n Diferenca de C com C.");
                                                printf(" {");
                                                printf(" }");
                                                break;
                                  }
                                  break;
                    }
                    break;

            // OITAVA OPERA��O, PRODUTO CARTESIANO ENTRE CONJUNTOS.
            case 8: printf("\n 7. Realizar o produto cartesiano.");

                    // PERGUNTANDO AO USU�RIO QUAL O PRIMEIRO CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Primeiro conjunto (A,B ou C): ");
                    scanf("%s",&carPri);
                    switch(carPri){
                        case 'A':
                                  // PERGUNTANDO AO USU�RIO QUAL O SEGUNDO CONJUNTO SER� USADO NA OPERA��O.
                                  printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&carSeg);

                                  // switch PARA VERIFICAR QUAL O SEGUNDO CONJUNTO INSERIDO.
                                  switch(carSeg){
                                      case 'A': printf("\n Produto cartesiano de A com A.");
                                                printf(" {");

                                                /* O PRIMEIRO for SER� USADO PARA PERCORRER O PRIMEIRO CONJUNTO INSERIDO, O SEGUNDO for
                                                   SER� USADO PARA PERCORRER O SEGUNDO CONJUNTO.*/
                                                for(i=0;i<fullA;i++){
                                                    for(j=0;j<fullA;j++){

                                                        // UM SIMPLES printf PARA MOSTRAR AO USU�RIO O RESULTADO DA OPERA��O.
                                                        printf(" <%d,%d>",A[i],A[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                                // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                                      case 'B': printf("\n Produto cartesiano de A com B.");
                                                printf(" {");
                                                for(i=0;i<fullA;i++){
                                                    for(j=0;j<fullB;j++){
                                                        printf(" <%d,%d>",A[i],B[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                      case 'C': printf("\n Produto cartesiano de A com C.");
                                                printf(" {");
                                                for(i=0;i<fullA;i++){
                                                    for(j=0;j<fullC;j++){
                                                        printf(" <%d,%d>",A[i],C[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                  }
                                  break;
                        case 'B': printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&carSeg);
                                  switch(carSeg){
                                      case 'A': printf("\n Produto cartesiano de B com A.");
                                                printf(" {");
                                                for(i=0;i<fullB;i++){
                                                    for(j=0;j<fullA;j++){
                                                        printf(" <%d,%d>",B[i],A[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                      case 'B': printf("\n Produto cartesiano de B com B.");
                                                printf(" {");
                                                for(i=0;i<fullB;i++){
                                                    for(j=0;j<fullB;j++){
                                                        printf(" <%d,%d>",B[i],B[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                      case 'C': printf("\n Produto cartesiano de B com C.");
                                                printf(" {");
                                                for(i=0;i<fullB;i++){
                                                    for(j=0;j<fullC;j++){
                                                        printf(" <%d,%d>",B[i],C[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                  }
                                  break;
                        case 'C': printf(" Segundo conjunto (A, B ou C):  ");
                                  scanf("%s",&carSeg);
                                  switch(carSeg){
                                      case 'A': printf("\n Produto cartesiano de C com A.");
                                                printf(" {");
                                                for(i=0;i<fullC;i++){
                                                    for(j=0;j<fullA;j++){
                                                        printf(" <%d,%d>",C[i],A[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                      case 'B': printf("\n Produto cartesiano de C com B.");
                                                printf(" {");
                                                for(i=0;i<fullC;i++){
                                                    for(j=0;j<fullB;j++){
                                                        printf(" <%d,%d>",C[i],A[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                      case 'C': printf("\n Produto cartesiano de C com C.");
                                                printf(" {");
                                                for(i=0;i<fullC;i++){
                                                    for(j=0;j<fullC;j++){
                                                        printf(" <%d,%d>",C[i],A[j]);
                                                    }
                                                }
                                                printf(" }");
                                                break;
                                  }
                                  break;
                    }
                    break;

            // NONA OPERA��O, IMPRIMINDO UM CONJUNTO.
            case 9: printf("\n 9. Imprimir os elementos de um conjunto.");

                    // PERGUNTANDO AO USU�RIO QUAL CONJUNTO SER� USADO NA OPERA��O.
                    printf("\n Conjunto a ser impresso (A, B ou C): ");
                    scanf("%s",&imprConj);

                    // switch PARA REALIZAR APENAS UMA OPERA��O.
                    switch(imprConj){
                        case 'A': printf("\n Imprimindo o conjunto A:");

                                  // SIMPLES IMPRESS�O DE UM VETOR.
                                  for (i=0;i<fullA;i++){
                                    printf(" %d",A[i]);
                                  }
                                  break;
                                  // MESMO RACIOC�NIO PARA OS PR�XIMOS case.
                        case 'B': printf("\n Imprimindo o conjunto B:");
                                  for (i=0;i<fullB;i++){
                                    printf(" %d",B[i]);
                                  }
                                  break;
                        case 'C': printf("\n Imprimindo o conjunto C.");
                                  for (i=0;i<fullC;i++){
                                    printf(" %d",C[i]);
                                  }
                                  break;
                    }
                    break;

            // FINALIZA��O DO PROGRAMA.
            case 0: printf("\n %d inserido.",oper);
                    break;
        }
    }
    printf("\n\n--------------------------------FIM DO PROGRAMA---------------------------------\n\n");
    return 0;
}























