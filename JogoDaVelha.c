#include <stdio.h>
#include <stdlib.h>

/*funcao para preencher a matriz com espacos vazios*/
void limpar(char matriz[3][3]){
	
	int i, j;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriz[i][j] = ' ';
			
		}
	}
	
}

/*funcao para imprimir a tabela do jogo da velha, feita com caracteres em hexadecimal da tabela ASCII*/	
void imprimir(char matriz[3][3]){

	int i, j;
	
	printf("   0    1    2\n\n");
	printf("0   %c \xBA %c \xBA %c\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("   ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
	printf("1   %c \xBA %c \xBA %c\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("   ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
	printf("2   %c \xBA %c \xBA %c\n\n", matriz[2][0], matriz[2][1], matriz[2][2]);

}

/*funcao que analisa todas as possibilidades de se ganhar no jogo da velha*/


/*funcao da primeira opcao digitada, player vs player*/
int primeira(){
	
	int l=0, c=0, i, j, cont=0;
	int um = 0;
	char matriz[3][3];
	
	system("cls");
	printf("\n");
	printf(" === Jogo Player Vs Player === \n\n");
	printf(" Jogador %d - X (xis)\n Jogador %d - O (bolinha)\n\n");
	
	/*chamando a funcao imprimir e limpar e passando a matriz 3 por 3 para imprimir e limpar*/
	limpar(matriz);
	imprimir(matriz);
	
	
	/*for para rodar 9 vezes, ou seja, a quantidade de espacos vazios do jogo da velha*/
	for(cont=0;cont<9;cont++){
		
		/*if de controle para repetir se digitarem algum numero errado ou o lugar estiver ocupado (variavel booleana)*/
		if(um == 1){
				cont--;
				um = 0;
			}
		
		/*if para o jogador 1 escolher a linha e a coluna*/
		if(cont%2 == 0){
			printf("Jogador 1 (X) escolha a linha e a coluna:\n");
			scanf("%d %d", &l, &c);
			
			/*if para verificar se o numero digito é diferente de 0, 1 ou 2 (numero descrito para linhas e colunas)*/
			if(l == 0 || l == 1 || l == 2 && c == 0 || c == 1 || c == 2){
				
			/*if para verificar se o lugar escolhido pelo usuario esta preenchido por algum X ou O*/
			if(matriz[l][c] != 'X' && matriz[l][c] != 'O'){
				matriz[l][c] = 'X';
				
				imprimir(matriz); 
				if(matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X'){
		
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	
	if(matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X'){
		
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	
	if(matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X'){
	
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	
	
	/*analisando possibilidades de ganhar transversalmente com xis*/
	if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){
		
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;	
	}
	
	if(matriz[0][2] == 'X' && matriz[1][1] == 'X'&& matriz[2][0] == 'X'){ 
	
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	

	/*analisando possibilidades de ganhar pela coluna com xis*/	
	if(matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X'){
		
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	
	if(matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X'){
		
			printf("\n === Parabens o Jogador 1 ganhou! === \n");
			return 0;
	}
	
	if(matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){
	
		printf("\n === Parabens o Jogador 1 ganhou! === \n");
		return 0;
	}
				
			}else{
				printf("Lugar ocupado!\n\n");
				um = 1;
				/*Se o lugar ja estiver ocupado, entra no else, imprimi essa mensagem e atribui o valor 1 para a varivel um*/
				
			}
			
		}else{
			printf("Numero invalido!\nDigite novamente!\n");
			um = 1;
			/*Se o numero for invalido, diferente de 0, 1 ou 2, imprimi essa mensagem e atribui o valor 1 para a varivel booleana*/
		}
		
		}
		
		/*if para o jogador 2 escolher a linha e a coluna*/
		 if(cont%2 == 1){
			printf("Jogador 2 (O) escolha a linha e a coluna:\n");
			scanf("%d %d", &l, &c);
			
			if(l == 0 || l == 1 || l == 2 && c == 0 || c == 1 || c == 2){
		
			if(matriz[l][c] != 'X' && matriz[l][c] != 'O'){
				matriz[l][c] = 'O';
				
				imprimir(matriz);
	/*analisando possibilidades de ganhar pela linha com bolinha*/
	if(matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O'){
		
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	if(matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O'){
		
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	if(matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'){
	
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	/*analisando possibilidades de ganhar transversalmente com bolinha*/
	if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O'){
		
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;	
	}
	
	if(matriz[0][2] == 'O' && matriz[1][1] == 'O'&& matriz[2][0] == 'O'){ 
	
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	
	/*analisando possibilidades de ganhar pela coluna com bolinha*/
	if(matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O'){
		
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	if(matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O'){
		
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
	
	if(matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'){
	
			printf("\n === Parabens o Jogador 2 ganhou! === \n");
			return 0;
	}
				
					
			}else{
				printf("Lugar ocupado!\n\n");
				um = 1;
			}
	
		}else{
			printf("Numero invalido!\nDigite novamente!\n");
			um = 1;
		}
		
		}
		
			/*if para verificar se deu velha*/
			if(cont == 8){
			printf("Perderam! Deu velha! hehehehh");
			}
		
			}

}

void computador(){
	
	int l=0, c=0, i, j, cont;
	int um = 0, controlePC=0;
	char matriz[3][3];
	
	system("cls");
	printf("\n");
	printf(" === Jogo Player Vs Computador === \n\n");
	printf(" Jogador 1 - Voce - X (xis)\n Jogador 2 - Computador - O (bolinha)\n\n");
	
	limpar(matriz);
	imprimir(matriz);
	
	for(cont=0;cont<9;cont++){
		
		if(um == 1){
				cont--;
				um = 0;
			}
		
		if(cont%2 == 0){
			printf("Jogador 1 - voce - (X) escolha a linha e a coluna:\n");
			scanf("%d %d", &l, &c);
			
			if(l == 0 || l == 1 || l == 2 && c == 0 || c == 1 || c == 2){
			
			if(matriz[l][c] != 'X' && matriz[l][c] != 'O'){
				matriz[l][c] = 'X';
				imprimir(matriz);
				
				
			}else{
				printf("Lugar ocupado!\n\n");
				um = 1;
			}
			
		}else{
			printf("Numero invalido!\nDigite novamente!\n");
			um = 1;
		}
		
		}
		
		 if(cont%2 == 1){
			printf("Jogador 2 - Computador - (O) escolheu a linha e a coluna:\n\n");
			
				
				for(l=0;l<3;l++){
					for(c=0;c<3;c++){
						
						if(matriz[l][c] != 'X' && matriz[l][c] != 'O'){
							
							matriz[l][c] = 'O';
							imprimir(matriz);
							
							
							/*variavel para fazer o computador jogar somente uma vez*/
							controlePC = 1; 
							break;
						}
					
					}
					
					/*Faz a comparacao para sair do primeiro for*/
					if(controlePC == 1){
						break;
					}
				
				}
			
				/*atribui novamente a variavel com o valor zero para */
				controlePC = 0;
	
			}

		}		
	
}

void torneio(){
	
	int l=0, c=0, i, j, cont=0;
	int um = 0, n = 0;
	char matriz[3][3];
	
	FILE* f;
	
	f = fopen("Ganhadores.txt", "a");
	
	system("cls");
	printf("\n");
	printf(" === Torneio de Jogo da Velha === \n\n");
	printf(" Jogador 1 - X (xis)\n Jogador 2 - O (bolinha)\n\n");
	
	printf("Digite o numero de jogadores:");
	scanf("%d", &n);
	if(n%2==0){
        n = n/2;
         
   }else{
      n = n-1;
	}
	
	int *vet = (int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
	
	/*chamando a funcao imprimir e limpar e passando a matriz 3 por 3 para imprimir e limpar*/
	limpar(matriz);
	imprimir(matriz);
	primeira(matriz);
	
	}
}

int main(){
	
	int menu;
	char matriz[3][3];
	
	/*estrutura de repeticao para repetir se o usuario digitar um numero errado*/	
	do{
		
		printf("\n===== BEM VINDO(A) AO JOGO DO VELHA:  =====\n");
		printf("\n");
		printf("             === Menu ===\n");
		printf("       1. Jogar com outra pessoa\n");
		printf("       2. Jogar com o computador\n");
		printf("       3. Torneio de Jogo da Velha\n");
		printf("       4. Sair\n");
		printf("\n");
		printf("Digite o numero da opcao desejada:");
		scanf("%d", &menu);
		
		/*dependendo do numero escolhido no menu, se entra em uma estrutura de decisao e chama a funcao a ser executada*/
		if(menu == 1){
		
			primeira();
		
		}else if(menu == 2){
		
			computador();
		
		}else if(menu == 3){
		
			torneio();
		
		}else{
		
			exit(1);
		
		}
		
	}while(menu<=0 || menu>3);

	
	return 0;
}
