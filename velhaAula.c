#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void  verificaVitoria (char tabuleiro[][]){
	
// //codigo da função .. ação..tarefa...

// 	return;
// }


	// % resto da divisão

	// 1  % 5 =1
	// 2  % 5 =2
	// 3  % 5 =3
	// 4  % 5 =4
	// 5  % 5 =0
	// 6  % 5 =1
	// 7  % 5 =2

int geraValorAleatorio(int divisor){ //Cada vez que essa função for chamada ela retona um valor aleatório entre [0 e 2[
	int valorAleatorio;
	valorAleatorio = rand()%divisor; 
	return valorAleatorio;
}


int verificaVitoria(char tabuleiro[3][3], int numjogadas){
	
	// #verificação das linhas
	if(tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][0] == tabuleiro[0][2] && tabuleiro[0][0] !=' '){
		printf("\n %c ganhou na primeira linha", tabuleiro[0][1]);
		return 1;
	}
	else if(tabuleiro[1][0] !=' ' && tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][0] == tabuleiro[1][2]){
		printf("\n %c ganhou na segunda linha", tabuleiro[1][1]);
			return 1;
	}
	else if(tabuleiro[2][0] !=' ' && tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][0] == tabuleiro[2][2]){
		printf("\n %c ganhou na terceira linha", tabuleiro[2][1]);
		return 1;
	} 

	//verificação das colunas
	else if(tabuleiro[0][0] !=' ' && tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[0][0] == tabuleiro[2][0]){
		printf("\n %c ganhou na primeira coluna", tabuleiro[0][0]);
		return 1;
	} 
	//segunda coluna
	else if(tabuleiro[0][1] !=' '  && tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[0][1] == tabuleiro[2][1]){
		printf("\n %c ganhou na segunda coluna", tabuleiro[2][1]);
		return 1;
	}
	//terceira coluna
	else if(tabuleiro[0][2] !=' '  &&tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[0][2] == tabuleiro[2][2]){
		printf("\n %c ganhou na terceira coluna", tabuleiro[0][2]);
		return 1;
	}
	//diagonal principal
	else if(tabuleiro[0][0] !=' '  && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
		printf("\n %c ganhou na diagonal principal", tabuleiro[2][2]);
		return 1;
	}
	//diagonal secundária
	else if(tabuleiro[0][2] !=' '  && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
		printf("\n %c ganhou na diagonal inversa", tabuleiro[2][0]);
		return 1;
	}
	else if(numjogadas == 8) {
		printf("\n DEU VELHA!!!!");
		return 0;
	}
	return 0;
}


void mostrarJogada(char tabuleiro[3][3]){

	for(int linha =0; linha <3; linha++){
			printf("\n|");
			
			for(int coluna = 0; coluna <3 ; coluna++){
				printf(" %c |",tabuleiro[linha][coluna]);
			}//fim do for colunas
		} //fim do for linhas

	return;
}



int main(int argc, char const *argv[]){
	srand(time(0)); //garante que não existam repetições nos números aleatórios 

	// char tabuleiro[3][3] = {'x','x','o',
	// 			 'o','o','x',
	// 			 'x','o','x'};


		// -------tabuleiro
		// |(0,0)|(0,1)|(0,2)|
		// |(1,0)|(1,1)|(1,2)|
		// |(2,0)|(2,1)|(2,2)|
		// -------
	int ganhou = 0;
	int numjogadas = 0;
	int linha=0;
	int coluna = 0;
	char tabuleiro[3][3];
	int jogadaValida =0;
	char jogadaAnterior = ' ';
	char jogadaAtual = ' ';
	int quemInicia;


	//Inserindo valores:

	for (int linha = 0; linha < 3; linha++){
			for (int coluna = 0; coluna < 3; coluna++)		{
				tabuleiro[linha][coluna] = ' ';
		}
		/* code */
	}

	mostrarJogada(tabuleiro);

	char simbolosJogadores[2];
	// simbolosJogadores[0] //HUMANO
	// simbolosJogadores[1] // COMPUTADOR


	do{
		printf("\n Por favor, indique se você deseja jogar com 'X' ou 'O'");
		scanf(" %c",&simbolosJogadores[0]);
		if(simbolosJogadores[0] == 120 || simbolosJogadores[0] == 'X') //X e x na ascii
		{
			simbolosJogadores[0] = 'X';
			simbolosJogadores[1] = 'O';

		}else if(simbolosJogadores[0] == 'o' || simbolosJogadores[0] =='O'){
			simbolosJogadores[0] = 'O';
			simbolosJogadores[1] = 'X';
		}
		else if(simbolosJogadores[0] != 'x' && simbolosJogadores[0] != 'X' && simbolosJogadores[0] != 'o' && simbolosJogadores[0] != 'O'){
			printf("\n Simbolo inválido, por favor informe X ou O");
		}

	}while(simbolosJogadores[0] != 'x' && simbolosJogadores[0] != 'X' && simbolosJogadores[0] != 'o' && simbolosJogadores[0] != 'O');

	quemInicia = geraValorAleatorio(2);// resultado 0 ou 1

	if(quemInicia == 0) //humano começa jogar
		jogadaAtual = simbolosJogadores[0]; //humano
	else //computador começa jogar
		jogadaAtual = simbolosJogadores[1]; //computador




//OU OR
// Só vou ser feliz se eu tiver dinheiro OU morar nas filipinas
// (V ou V) = V
// (V ou F) = V
// (F ou V) = V
// (F ou F) = F


//E AND
// Só vou ser feliz se eu tiver dinheiro EE morar nas filipinas
//(V E V) = V
//(V E F) = F
//(F E V) = F
//(F e F) = F



	//começa o jogo
		while(numjogadas <= 8 && ganhou == 0){

			// printf("\n\n Quem joga agora é %c ",jogadaAtual);

			//resto da divisão (%) para ver se é par ou ímpar
				if(numjogadas%2 == 0){ //numero par == humano
					printf("\n\n Quem joga agora é o humano\n\n");
					jogadaAtual = simbolosJogadores[0];
				}else{
					printf("\n\n Quem joga agora é o COMPUTADOR\n\n");

					jogadaAtual = simbolosJogadores[1];
				}

			if(jogadaAtual == simbolosJogadores[0]){//humano
			do{

					printf("\n Por favor, informe a linha que deseja jogar");
					scanf("%d",&linha);

					printf("\n Por favor, informe a coluna que deseja jogar");
					scanf("%d",&coluna);
					if(linha <= 3 && coluna <= 3 && linha > 0 && coluna > 0 && tabuleiro[linha-1][coluna-1]==' '){
						printf("\n Posição válida");
						jogadaValida = 1;
					}else{
						printf("\n Posição inválida");
						jogadaValida = 0;
					}
			}
			while(jogadaValida == 0);
		}else if(jogadaAtual == simbolosJogadores[1]){ //jogada do computador
			// ..jogada do computador...
			do{
				linha 	= geraValorAleatorio(3)+1; //tem que gerar um valor de 1 até 3
				coluna 	= geraValorAleatorio(3)+1; //0, 1, 2 

				if(tabuleiro[linha-1][coluna-1] == ' ')
					jogadaValida = 1;
				else
					jogadaValida = 0;

			}while(jogadaValida == 0);

		}

			tabuleiro[linha-1][coluna-1] = jogadaAtual;
			jogadaAnterior = jogadaAtual;

			if(jogadaAtual == simbolosJogadores[0]) //HUMANO
				jogadaAtual = simbolosJogadores[1]; //COMPUTADOR
			else
				jogadaAtual =simbolosJogadores[0]; // HUMANO


			// system('cls');
			system("clear");
			mostrarJogada(tabuleiro);	
			ganhou = verificaVitoria(tabuleiro,numjogadas);
			numjogadas++;

		} //fim do laço while

	



	
	return 0;
}