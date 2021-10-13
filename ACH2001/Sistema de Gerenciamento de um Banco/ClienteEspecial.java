
public class ClienteEspecial extends Cliente{
	static final int dividaMaxima = 50000;
	static final String tipo = "CE";
	
	/* Construtor da Classe ClienteEspecial
	 * Este construtor invoca o construtor da classe Cliente.
	 */
	ClienteEspecial(String nome, int cpf, int valor){
		super(nome, cpf, valor);
	}
	
	/* Metodo que retorna o valor do atributo tipo do objeto atual */
	String retornaTipo() {
		return tipo;
	}
	
	/*
	Sera necessario sobrescrever o metodo obterEmprestimo da classe Cliente,
	pois a constante dividadeMaxima possui um novo valor
	*/
	public boolean obterEmprestimo(int valor) {
		
		// Caso o valor do parametro seja menor ou igual a zero, o metodo deve retornar false
		if(valor <= 0) return false;
		
		/*
		Se o valor do parametro mais o valor do atributo valorDaDivida for maior do
	        que o valor da constante dividaMaxima, o metodo deve retornar false
		*/
		if(valor + this.getValorDaDivida() > ClienteEspecial.dividaMaxima) return false;
		
		/*
 		Caso contrario, o atributo valorDaDivida deve ser incrementado em valor, o atributo
	        valorContaCorrente deve ser incrementado em valor e o metodo deve retornar true
		*/	
		else {
			this.setValorDaDivida(this.getValorDaDivida() + valor);
			this.setValorContaCorrente(this.getValorContaCorrente() + valor);
			return true;
		}

	}
	
}
