#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <locale.h>

 

int geraValorAleatorio(int divisor){ //Cada vez que essa função for chamada ela retona um valor aleatório entre [0 e 2[
	int valorAleatorio;
	valorAleatorio = rand()%divisor; 
	return valorAleatorio;
}


int verificaResultado(char tabuleiro[3][3],int quantJogadas){
	int resultado = 0;
	/*	
	-------
	|(0,0)|(0,1)|(0,2)|
	|(1,0)|(1,1)|(1,2)|
	|(2,0)|(2,1)|(2,2)|
	-------
	*/

	//primeira linha
	if(tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2]){
		printf("\n %c Ganhou na primeira linha",tabuleiro[0][0]);
		resultado = 1;
	}
	//segunda linha
	else if( tabuleiro[1][0] != ' ' && tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2]){
		printf("\n %c Ganhou na segunda linha",tabuleiro[1][0]);
		resultado = 1;
	}
	// terceira linha
	else if( tabuleiro[2][0] != ' ' && tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2]){
		printf("\n %c Ganhou na terceira linha",tabuleiro[2][0]);
		resultado = 1;
	}

	/*	
	-------
	|(0,0)|(0,1)|(0,2)|
	|(1,0)|(1,1)|(1,2)|
	|(2,0)|(2,1)|(2,2)|
	-------
	*/
	//verificar na primeira coluna
	else if( tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0]){
		printf("\n %c Ganhou na primeira coluna", tabuleiro[0][0]);
		resultado = 1;
	}
	//verificando a segunda coluna
	else if ( tabuleiro[0][1] != ' ' &&  tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1]){
		printf("\n %c Ganhou na segunda coluna",tabuleiro[1][1]);
		resultado = 1;
	}
	else if( tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2]){
		printf("\n %c Ganhou na terceira coluna!", tabuleiro[1][2]);
		resultado = 1;
	}


	/* Vamos verificar as diagonais.. COMO??	
	-------
	|(0,0)|(0,1)|(0,2)|
	|(1,0)|(1,1)|(1,2)|
	|(2,0)|(2,1)|(2,2)|
	-------
	*/
	else if( tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro[1][1] == tabuleiro[0][0]){
		printf("\n %c Ganhou na diagonal principal",tabuleiro[1][1]);
		resultado = 1;
	}
	else if( tabuleiro[0][2] != ' ' && tabuleiro[0][2]==  tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
		printf("\n %c Ganhou na diagonal inversa",tabuleiro[1][1]);
		resultado = 1;
	}
	else if(quantJogadas == 9){
		printf("\n DEU VELHA!!!!");
		resultado = 2;
	}
	return resultado;
}


void imprimeTabuleiro(char tabuleiro[3][3]){
	printf("\n\n");
	int linha,coluna;
	for (linha=0;linha<3;linha++){
		
		if(linha==0)
				printf("     | 1 | 2 | 3 |");
		printf("\n (%d) |",linha+1);
		
		for (coluna=0;coluna<3;coluna++){
						
			printf(" %c |",tabuleiro[linha][coluna]);
		}
	}
	printf("\n\n\n");
	return;
}

void inicializaMatriz(char tabuleiro[3][3]){
int linha;
int coluna;
	// -------
	// |(0,0)|(0,1)|(0,2)|
	// |(1,0)|(1,1)|(1,2)|
	// |(2,0)|(2,1)|(2,2)|
	// -------

for (linha =0; linha<3;linha++){
	for(coluna=0;coluna<3;coluna++){
		tabuleiro[linha][coluna] = ' ';
	}
	
}

}

int main(void){
	setlocale(LC_ALL, "Portuguese"); 
	srand(time(0));  			//Essa função  inicializa o contador de tempo para gerar numeros aleatórios	

/*	
-------
|X|O|O|
|O|X|X|
|O|O|X|
-------
*/

char tabuleiro[3][3];
inicializaMatriz(tabuleiro);
int contadorDeMovimentos = 1;
int alguemGanhou = 0;//1 se alguem ganhou.
int linhaJogada,colunaJogada;
char simboloHumano,simboloComputador,jogadaPassada;

jogadaPassada = 'a';
int quemJoga = 0; //0 ou 1 onde 0 é o jogador humano, 1: computador
int quemInicia = geraValorAleatorio(2);
quemJoga = quemInicia;



printf("\n Informe se você deseja jogar com 'X' ou 'O'");
fflush(stdin); //Para prevenir buffer...
scanf(" %c",&simboloHumano);

if( simboloHumano == 'X' || simboloHumano =='x')
	simboloComputador = 'O';
else if(simboloHumano == '0' || simboloHumano == 'O' || simboloHumano == 'o')
	simboloComputador = 'X';
else{
	printf("Símbolo não válido, valor X atribuído para Player humano");
	simboloComputador = 'O';
	simboloHumano = 'X';
	fflush(stdin);
	getchar(); //atua como um pause no sistema
}

while(contadorDeMovimentos <= 9 && alguemGanhou == 0){
	
	printf("\n Quem joga agora é o:");
	if(quemJoga == 0)
		printf(" Humano");
	else
		printf(" Computador");


	do{
	    do{
	    	if(quemJoga == 1)
	    		linhaJogada = geraValorAleatorio(3);
	    	else{
				printf("\n Por favor, informe uma LINHA onde quer jogar");
				scanf("%d",&linhaJogada);
				linhaJogada -=1;
				}	
		if(linhaJogada < 0 || linhaJogada >= 3)
				printf("\nMovimento inválido!!!\n");
		

		}while(linhaJogada<0 ||linhaJogada>=3);

		do{
			if(quemJoga == 1)
				colunaJogada = geraValorAleatorio(3);
			
			else{
				printf("\n Por favor, informe uma COLUNA onde quer jogar");
				scanf("%d",&colunaJogada);
				colunaJogada -=1;
			}

			if(colunaJogada<0 || colunaJogada>=3)
				printf("\n Movimento inválido!!!\n");
		
		}while(colunaJogada<0 ||colunaJogada>=3);

		if(tabuleiro[linhaJogada][colunaJogada] != ' '){
			printf("posição já foi jogada!");
		}

	}while(tabuleiro[linhaJogada][colunaJogada] != ' ');
	

	if(quemJoga == 0){
		quemJoga = 1;
		tabuleiro[linhaJogada][colunaJogada] = simboloHumano;
		jogadaPassada = simboloHumano;
	}else{
		quemJoga = 0;
		tabuleiro[linhaJogada][colunaJogada] = simboloComputador;
		jogadaPassada = simboloComputador;
	}
	//system("clear"); //( Utilize essa linha se você usa linux)
	system("cls"); //(Utilize essa linha se você usa  windows)


	
	imprimeTabuleiro(tabuleiro);
	alguemGanhou = verificaResultado(tabuleiro,contadorDeMovimentos);
	contadorDeMovimentos++;
	
	if (alguemGanhou == 1){
		if(quemJoga == 0){
			printf("\n O vitorioso foi o Computador!!!");
		}
		else{
			printf("\n Vitória do player HUMANO!!!");
		}
	
		printf("\n CONTINUAR JOGANDO? S ou N ?");
		fflush(stdin);
		char play = getchar();
		if(play == 's' ||play == 'S' ||play == 'Y' ||play == 'y'){
			alguemGanhou == 0;
			contadorDeMovimentos = 1;
			inicializaMatriz(tabuleiro);
								
			printf("\n Informe se você deseja jogar com 'X' ou 'O'");
			fflush(stdin); //Para prevenir buffer...
			scanf(" %c",&simboloHumano);
		
			if( simboloHumano == 'X' || simboloHumano =='x')
				simboloComputador = 'O';
			else if(simboloHumano == '0' || simboloHumano == 'O' || simboloHumano == 'o')
				simboloComputador = 'X';
			else{
				printf("Símbolo não válido, valor X atribuído para Player humano");
				simboloComputador = 'O';
				simboloHumano = 'X';
				fflush(stdin);
				getchar(); //atua como um pause no sistema
			}
	
		}
	}
}
	printf("\n\n\n");
	system("pause"); //Comente essa linha caso você não utilize Windows.
	return 0;
}

