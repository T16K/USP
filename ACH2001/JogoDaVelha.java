/*********************************************************************/
/**   ACH2001 - Introdu��o � Programa��o                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <turma> - <nome do professor>                                 **/
/**     02      Luciano Digiampietri                                **/
/**   Segundo Exerc�cio-Programa                                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <n�mero USP>          **/
/**     Gustavo Tsuyoshi Ariga                  11857215            **/
/**   <data de entrega>  01/06/20                                   **/
/*********************************************************************/

/*
	Jogo da Velha - programa para verificar o status de um jogo.
	
	Lista de Status calculado:
    0 - Jogo n�o iniciado: o tabuleiro est� 'vazio', isto � sem pe�as X e O;
    1 - Jogo encerrado1: o primeiro jogador (que usa as pe�as X) � o ganhador;
    2 - Jogo encerrado2: o segundo jogador (que usa as pe�as O) � o ganhador;
    3 - Jogo encerrado3: empate - todas as casas do tabuleiro est�o preenchidas com X e O, mas nenhum dos jogadores ganhou;
    4 - Jogo j� iniciado e em andamento: nenhuma das alternativas anteriores.	
*/

public class JogoDaVelha {
	static final char pecaX = 'X';
	static final char pecaY = 'O';
	static final char espacoVazio = ' ';

	/*
		Determina o status de uma partida de Jogo da Valha
		
		Entrada:
			tabuleiro - matriz 3x3 de caracteres representando uma partida valida de Jogo da Velha
			
		Sa�da:
			um inteiro contendo o status da partida (valores v�lidos de zero a quatro)
	*/

	/* 
	   O programa foi pensado de forma que ele primeiro avalie a situa��o atual do tabuleiro, e em seguida caso 
	   o jogo estiver terminado e haja um vencedor, diclare o vencedor por meio do "status 1" ou "status 2";
	   caso contr�rio determine a situa��o pelos "status 0", "status 3" ou "status 4"
	*/

	static int verificaStatus(char[][] tabuleiro) {
	    
	    // Op��o do jogo j� iniciado e em andamento, nenhuma das op��es foram v�lidas
            int status = 4;
            
  for(int i = 0; i < 3; i++){  
     
    // Op��o de empate	 
    if(tabuleiro[i][0] != espacoVazio && tabuleiro[i][1] != espacoVazio && 
       tabuleiro[i][2] != espacoVazio && tabuleiro[0][i] != espacoVazio &&
       tabuleiro[1][i] != espacoVazio && tabuleiro[2][i] != espacoVazio) status = 3;
      
    // Op��o de vit�ria pelas linhas do tabuleiro
    if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
      if(tabuleiro[i][0] == pecaX) status = 1;
      if(tabuleiro[i][0] == pecaY) status = 2;
    }
    
    // Op��o de vit�ria pelas colunas do tabuleiro
    if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]){
      if(tabuleiro[0][i] == pecaX) status = 1;
      if(tabuleiro[1][1] == pecaY) status = 2;
    }
    
    // Op��o caso o jogo n�o tenha sido iniciado
    if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && 
       tabuleiro[i][0] == tabuleiro[0][i] && tabuleiro[0][i] == tabuleiro[1][i] &&
       tabuleiro[1][i] == tabuleiro[2][i]){
      if(tabuleiro [0][0] == espacoVazio) status = 0;    
    }
     
}
                      
    // Op��o de vit�ria pelas diagonais do tabuleiro       
    if((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) || 
       (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])){
       if(tabuleiro[1][1] == pecaX) status = 1;
       if(tabuleiro[1][1] == pecaY) status = 2;
    }
  
  return status;
 
}
	
	/*
		Apenas para seus testes. ISSO SER� IGNORADO NA CORRE��O
	*/

	public static void main(String[] args) {

		// escreva seu c�digo (para testes) aqui

		char[][] tab0 = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
		char[][] tab1 = {{'X','O',' '},{'X','O',' '},{'X',' ',' '}};
		char[][] tab2 = {{'O','X','X'},{'X','O','O'},{' ',' ','O'}};
		char[][] tab3 = {{'O','X','X'},{'X','O','O'},{'O','X','X'}};
		char[][] tab4 = {{' ',' ',' '},{'X','O','X'},{' ',' ',' '}};

		System.out.println("Status calculado: " + verificaStatus(tab0));
		System.out.println("Status esperado para o tabuleiro0: 0\n");

		System.out.println("Status calculado: " + verificaStatus(tab1));
		System.out.println("Status esperado para o tabuleiro1: 1\n");

		System.out.println("Status calculado: " + verificaStatus(tab2));
		System.out.println("Status esperado para o tabuleiro2: 2\n");
		
		System.out.println("Status calculado: " + verificaStatus(tab3));
		System.out.println("Status esperado para o tabuleiro1: 3\n");
		
		System.out.println("Status calculado: " + verificaStatus(tab4));
		System.out.println("Status esperado para o tabuleiro4: 4\n");
		
	} 

}