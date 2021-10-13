/*********************************************************************/
/**   ACH2001 - Introdu��o � Programa��o                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <turma> - <nome do professor>                                 **/
/**   Turma 02 - Luciano Antonio Digiampietr                        **/
/**   Primeiro Exerc�cio-Programa                                   **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <n�mero USP>          **/
/**   Gustavo Tsuyoshi Ariga                    11857215            **/
/**   <data de entrega>  15/04/2020                                 **/
/*********************************************************************/


/*
	Caixa eletr�nico das Ilhas Weblands, com estoque ilimitado de c�dulas
	de B$50,00, B$10,00, B$5,00 e B$1,00.
*/

public class CaixaEletronico {
  
    	// N�mero de c�dulas de B$50,00
	static int n50;
	
	// N�mero de c�dulas de B$10,00
	static int n10;

	// N�mero de c�dulas de B$5,00
	static int n5;
	
	// N�mero de c�dulas de B$1,00
	static int n1;

        	/*
		Determina a quantidade de cada nota necess�ria para totalizar
		um determinado valor de retirada, de modo a minimizar a quantidade
		de c�dulas entregues.
		
		Abastece as vari�veis globais n50, n10, n5 e n1 com seu respectivo
		n�mero de c�dulas.
		
		Par�metro:
			valor - O valor a ser retirado
                */
        
        	static void fazRetirada(int valor) {
                    
                    // Verificar se o "valor" � positivo
                    if (valor >= 0){ 
                        
                        // n50 = quociente da divis�o "valor" por 50
                        n50 = valor / 50;
                        
                        // n10 = quociente da divis�o (valor mod 50) por 10
                        n10 = (valor % 50) / 10;
                        
                        // n5 = quociente da divis�o (("valor" mod 50) mod 10) por 5
                        n5 = ((valor % 50) % 10) / 5;
                        
                        // n1 = resto 
                        n1 = (((valor % 50) % 10) % 5);  
                        
                    }
                    
                    // Se o "valor" for negativo as vari�veis s�o abastecidas com -1
                    else n50 = n10 = n5 = n1 = -1;
                    
	}

    public static void main(String[] args) {

		fazRetirada(876543);
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);
                
    }
    
}