/*********************************************************************/
/**   ACH2001 - Introdu��o � Programa��o                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <turma> - <nome do professor>                                 **/
/**     02      Luciano Digiampietri                                **/
/**   Segundo Exerc�cio-Programa                                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <n�mero USP>          **/
/**     Gustavo Tsuyoshi Ariga                  11857215            **/
/**   <data de entrega>  06/05/20                                   **/
/*********************************************************************/

/*
	C�lculo para raiz quadrada
*/
public class Raiz {

	/*
		Para fazer o programa, a primeira dificuladade seria implementar o conceito do 'i' dado no enunciado, por isso foi utilizado o recurso 'while', uma vez que 'i = 0 => x = a / 2', e os pr�ximos valores para 'i' implicam em chamar a mesma vari�vel 'x' atribuindo um novo valor. Depois disso, a condi��o para a repeti��o do 'while' foi determinada a partir de manipula��o alg�brica (algumas vezes o programa demorava muito para calcular ent�o a constante da f�rmula foi removida) para chegar apenas nas vari�veis 'a' e 'x'. E por fim, foi utilizado a f�rmula para a aproxima��o do valor da raiz quadrada de 'a' dentro do 'while'.
	*/

	static double raizQuadrada(double a, double epsilon) {

		// Retorna o valor -1, caso a < 0, epsilon <= 0 ou epsilon >= 1.
		if (a < 0 || epsilon <= 0 || epsilon >= 1) return -1;
		
		// Declarar a vari�vel.
		double x = a / 2;

		// Como n�o era poss�vel usar o m�todo Math.abs(), foi utilizada a defini��o de m�dulo.            
		while ( a / x - x  > epsilon || a / x - x  < - epsilon )   

		// C�lculo para definir o novo valor de 'x'.
		x = (a/x + x) / 2;         

		// Retornar o valor de 'x'.
		return x;

	}

	public static void main(String[] args) {

		double valor = 101;
		double precisao = 0.00001;
		System.out.println("Raiz de : "+valor+" = "+raizQuadrada(valor, precisao));

	}

}