/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   <turma> - <nome do professor>                                 **/
/**     02      Luciano Digiampietri                                **/
/**   Segundo Exercício-Programa                                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <número USP>          **/
/**     Gustavo Tsuyoshi Ariga                  11857215            **/
/**   <data de entrega>  06/05/20                                   **/
/*********************************************************************/

/*
	Cálculo para raiz quadrada
*/
public class Raiz {

	/*
		Para fazer o programa, a primeira dificuladade seria implementar o conceito do 'i' dado no enunciado, 
		por isso foi utilizado o recurso 'while', uma vez que 'i = 0 => x = a / 2', e os próximos valores para 'i' implicam em chamar 
		a mesma variável 'x' atribuindo um novo valor. Depois disso, a condição para a repetição do 'while' foi determinada a partir de
		manipulação algébrica (algumas vezes o programa demorava muito para calcular então a constante da fórmula foi removida) para chegar 
		apenas nas variáveis 'a' e 'x'. E por fim, foi utilizado a fórmula para a aproximação do valor da raiz quadrada de 'a' dentro do 'while'.
	*/

	static double raizQuadrada(double a, double epsilon) {

		// Retorna o valor -1, caso a < 0, epsilon <= 0 ou epsilon >= 1.
		if (a < 0 || epsilon <= 0 || epsilon >= 1) return -1;
		
		// Declarar a variável.
		double x = a / 2;

		// Como não era possível usar o método Math.abs(), foi utilizada a definição de módulo.            
		while ( a / x - x  > epsilon || a / x - x  < - epsilon )   

		// Cálculo para definir o novo valor de 'x'.
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
