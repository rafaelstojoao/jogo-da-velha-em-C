//por Rafael Stoffalette João
//rafaelstojoao@gmail.com


// inclusão das bibliotecas necessárias para o funcionamento

#include <stdio.h>  //biblioteca de entrada de saída de dados
#include <stdlib.h>  //biblioteca de funções básicas do sistema
#include <time.h>  // biblioteca que manipula dados de tempo. Utilizada aqui para gerar um número aleatório a cada segundo
  

  
//função que sorteia um valor numérico que representa a linha que a máquina tentará fazer sua jogada
	int sorteia_linha(){ 		// int porque retorna um valor inteiro; sorteia_linha é o nome da função 
		int linha; 				// variável que armazenará o valor sorteado para a linha
		linha = rand() % 3;		// rand() é uma função que sorteia um número; %3 pois queremos pegar o resto da divisão por 3. Então o resto só pode ser 0, 1 ou 2
		return linha;			// retorna o conteúdo que está na variável linha.
	}


//função que sorteia um valor numérico que representa a coluna que a máquina tentará fazer sua jogada
	int sorteia_coluna(){
		int  coluna;
		coluna = rand()%3; 
		return coluna;
	}


//função que sorteia um valor numérico entre 0 e 1.
   int sorteia_0_ou_1(){
    	int sorteado; 
		sorteado = rand()%2; //sorteia um numero 0 ou 1. Se 1 == máquina que joga, se == 0, homem que joga 
    return sorteado;
   }


//Função que imprime os valores do tabuleiro.
  	//O retorno dela é VOID pois não será retornado nenhum valor, apenas irá percorrer as posições da matriz e imprimir o conteúdo. 
   	//O nome da função é imprimeTabulero
   	// o parâmetro passado para a função manipular é uma matriz de char  de tamanho [3]x[3].
   	// Ou seja, sempre que quisermos executar essa função temos que enviar uma matriz de char como parâmetro para a função manipular  	
  	void imprimeTabulero(char velha[3][3]){
   	int linha=0;
   	int coluna = 0; 


   	printf("\nJogadas\n");

   	for (linha = 0; linha < 3; linha++){ 				//temos um loop que percorre cada uma das linhas, de 0 até 2
   		printf("\n---------------\n");		// essa linha somente imprime uma linha na tela e depois quebra a linha

   		for (coluna =0 ; coluna <3; coluna++){			// outro loop, mas esse está dentro do loop anterior. pois assim PARA CADA LINHA, analisamos CADA COLUNA, de 0 até 2
   			printf("  %c  ", velha[linha][coluna] );	//imprime o conteúdo da "caixinha" selecionada, na posição linhaxcoluna. Ou seja, velha[linha][coluna]
   		}

   	}   	   		

   	printf("\n---------------\n");
   	return;
   }



//Essa função retorna um valor inteiro 
   //o nome dela é verificaVitoria
   //para ela ser executada, deve-se passar uma matriz de chars com tamanho 3x3

   int verificaVitoria(char velha[3][3]){

   	//aqui são feitas verificações das possíveis formas de ganhar o jogo. 
   	//Se a linha tiver valores iguais, EE esses valores forem diferentes de 0 então há uma vitória
   	if(velha[0][0]== velha[0][1] && velha[0][1] == velha[0][2] && velha[0][0] != '0'){ //verifica vitória na linha 0
   		return 1;

   	}else if(velha[1][0]== velha[1][1] && velha[1][1] == velha[1][2] && velha[1][0] != '0'){// SENÃO verifica vitória na linha 1
   		return 1;
   	
   	}else if(velha[2][0]== velha[2][1] && velha[2][1] == velha[2][2] && velha[2][0] != '0'){// SENÃO verifica vitória na linha 2
   		return 1;
   	
   	}else if(velha[0][0]== velha[1][0] && velha[1][0] == velha[2][0] && velha[1][0] != '0'){// SENÃO verifica vitória na coluna 0
   		return 1;

   	}else if(velha[0][1]== velha[1][1] && velha[1][1] == velha[2][1] && velha[1][1] != '0'){// SENÃO verifica vitória na coluna 1
   		return 1;
   	
   	}else if(velha[0][2]== velha[1][2] && velha[1][2] == velha[2][2] && velha[1][2] != '0'){// SENÃO verifica vitória na coluna 2
   		return 1;
   	
   	}else if(velha[0][0]== velha[1][1] && velha[1][1] == velha[2][2] && velha[1][1] != '0'){// SENÃO verifica vitória na Diagonal 0
   		return 1;
   	
   	}else if(velha[0][2]== velha[1][1] && velha[1][1] == velha[2][0] && velha[2][0] != '0'){// SENÃO verifica vitória na Diagonal 1
   		return 1;
   	
   	}else{ //Se nenhuma das verificações forem verdadeiras, a função retorna o valor 0 indicando que ninguém ganhou nessa jogada. Aí o jogo continua
   		return 0;
   	}



   }


    int main() { //aqui que começa o jogo. A função main é a principal. Ela é a primeira a ser executada quando o algoritmo é executado
      	srand(time(0));  			//Essa função  inicializa o contador de tempo para gerar numeros aleatórios	
      	char velha[3][3];			//Definição da variável ue será o tabulero. é uma matriz de 3x3 chamada velha, do tipo char. 
      	
      	//definição das variáveis do tipo int
      	int tabuleiro, vitoria, posicaoLinha, posicaoColuna, jogador, linha, coluna;
      	int jogadas = 0;



      	// coloca 0  (zeros) em TODAS as posições da matriz velha, dessa forma não corre o risco de ter sujeira na memória que atrapalhe o jogo 
 	    for (linha = 0; linha <=  2; linha++){			//para cada linha da matriz
 	     	for(coluna =0; coluna <= 2; coluna++){		//para cada coluna de cada linha da matriz
 	     		velha[linha][coluna] = '0';				//marca a caixinha com 0 (zero) para indicar que ninguém jogou ainda nessa posição
 	     	}
 	     } 


 	    imprimeTabulero(velha); 	//chamada da função imprime tabulero para mostrar que ele só tem valores 0 (zeros)


      	jogador = sorteia_0_ou_1(); //Chama a função sorteia_0_ou_1()  para sortear quem vai começar jogando. VER LINHA 30

      	if(jogador ==1){	//Verifica quem começa jogando, somente para informar na tela
      		printf("\n\n Quem comeCa Jogando eH a mAquina!!!!\n\n");

      	}else{
      		printf("\n\n Quem comeCa Jogando eH o usuArio/Homem!!!!\n\n");
      	}


      	while (jogadas < 9){ 		//ENQUANTO a quantidade de jogadas não for igual a 9 (máximo de jogadas possívels) o jogo continua. Se atingir o valor 9, não há mais caixinhas para jogar, então só pode ter dado velha

	      	if(jogador == 1){ 		//Se o valor que está na variável jogador for igual a 1, significa que quem começa jogar é a máquina


	      		do{ //aqui começa o DO... WHILE que vai forçar a máquina a informar uma posição enquanto não indicar uma posição disponível. Isto é, que ningué jogou nela ainda

	      			posicaoLinha = sorteia_linha(); 	// a variável posicaoLinha recebe o retorno da função sorteia_linha() VER LINHA 11
	      			posicaoColuna = sorteia_coluna();	// a variável posicaoColuna recebe o retorno da função sorteia_coluna() VER LINHA 21
	      			
	      			printf(" A máquina quer jogar em: %d %d\n", posicaoLinha,posicaoColuna ); //Imprime na tela qual jogada o computador quer fazer

	      		}while(velha[posicaoLinha][posicaoColuna] != '0');//aqui acaba o DO... WHILE que vai forçar a máquina a informar uma posição enquanto não indicar uma posição disponível. Isto é, que ningué jogou nela ainda
	      			


/*SE a máquina sorteou uma posição disponível o do...while para de executar
 então a proxima linha  a ser executada é essa. Ela grava o valor 'o'(bolinha)
 na posição posicaoLinha posicaoColuna	da matriz chamada velha */
	      			velha[posicaoLinha][posicaoColuna] = 'o';  
 	      		
 	      			imprimeTabulero(velha); //Imprime a matriz velha para saber quais jogadas ja foram feitas.
	      		
	      			jogadas++;				//incrementa a variável que armazena quantas jogadas ja foram feitas (tanto pela maquina quanto pelo homem)
	      		
	      			vitoria = verificaVitoria(velha); //Chama a função verificaVitoria(velha) e passa como parâmetro a matriz chamada velha (onde estão as jogadas ja feitas)
	      												//O resultado/retorno da função é armazenado  na variável vitória
	      												//VER  LINHA 70


	      		if(vitoria == 1){									// Se o resultado da função for 1 (VERDADE) então há virótia e como esta parte é a máquina jogando então só pode ser vitória da máquina
	      			printf("O COMPUTADOR/MAQUINA GANHOU!!!\n Continue tentando...\n\n\n\n");		//Informa o resultado
	      			return 0;										//Fim do jogo


	      		}else if(jogadas == 9){								//SENÃO SE já foram feitas 9 jogadsa, significa que ninguém mais pode jogar, então ninguém ganhou e deu velha
	      			printf("Não há mais jogadas - DEU VELHA\n\n\n");	//Informa o resultado
	      			return  0;										//fim do jogo


	      		}else{ 					//SENÃO, SE ninguem ganhou (vitoria não é 1 e nem jogadas é == 9) o jogo continua
	      			jogador = 0;		// só que agora o jogador troca. era 1 (máquina) agora muda para zero (pois é o homem que jogará agora)
	      		}


	      	}else{ //Aqui acaba a verificação se o jogador era a máquina (variável jogador == 1). SENÃO só pode ser o homem. 

	      		do{//aqui começa o DO... WHILE que vai forçar o jogador a informar uma posição enquanto não indicar uma posição disponível. Isto é, que ninguém jogou nela ainda
	      			printf("\n\n\nINFORME UMA POSIÇÃO QUE NÃO FOI UTILIZADA AINDA\n");
	      			printf("\n Por favor, informe uma linha");
	      			scanf("%d",&posicaoLinha);

					printf("\n Por favor, informe uma coluna");
	      			scanf("%d",&posicaoColuna);

	      		}while(velha[posicaoLinha][posicaoColuna] != '0'); //aqui acaba o DO... WHILE que vai forçar o jogador a informar uma posição enquanto não indicar uma posição disponível. Isto é, que ninguém jogou nela ainda


/*SE o usuário humano indicou uma posição disponível o do...while para de executar
 então a proxima linha  a ser executada é essa. Ela grava o valor 'x'
 na posição posicaoLinha posicaoColuna	da matriz chamada velha */
	      		velha[posicaoLinha][posicaoColuna] = 'X';

      			imprimeTabulero(velha);				//Imprime a matriz velha para saber quais jogadas ja foram feitas.
	      		
	      		jogadas++;							//incrementa a variável que armazena quantas jogadas ja foram feitas (tanto pela maquina quanto pelo homem)
	      		
	      		vitoria = verificaVitoria(velha);	//Chama a função verificaVitoria(velha) e passa como parâmetro a matriz chamada velha (onde estão as jogadas ja feitas)
	      												//O resultado/retorno da função é armazenado  na variável vitória
	      												//VER  LINHA 70

	      		if(vitoria == 1){						// Se o resultado da função for 1 (VERDADE) então há virótia e como esta parte é o homem jogando então só pode ser vitória do homem/usuário
	      			printf("O USUARIO GANHOU!!!\n PARABENS.....\n\n\n"); 	//Informa o resultado
	      			return 0;							//fim do jogo

	      
	      		}else if(jogadas == 9){								//SENÃO SE já foram feitas 9 jogadsa, significa que ninguém mais pode jogar, então ninguém ganhou e deu velha
	      			printf("Não há mais jogadas - DEU VELHA\n\n\n");	//Informa o resultado
	      			return  0;										//fim do jogo


	      		}else{  			//SENÃO, SE ninguem ganhou (vitoria não é 1 e nem jogadas é == 9) o jogo continua
	      			jogador = 1;	// só que agora o jogador troca. era 0 (homem) agora muda para 1 (pois é a máquina que jogará agora)
	      		}

	      	}


		}
		if(jogadas ==9){ 									//Verifica se já fez 9 jogadas. Se chegou aqui com 9 jogadas então ninguém ganhou
			printf("Não há mais jogadas - DEU VELHA\n\n\n"); 	//Informa o resultado
	      			return  0;								//FIM DO JOGO

		}


 	     
      return 0;
    }
