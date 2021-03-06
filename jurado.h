#ifndef SRC_JURADO_H_
#define SRC_JURADO_H_

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


class sessao;

/**
 * @class jurado
 * @brief classe com as informacoes relativas a um jurado
 */

class jurado {
	string nome; ///< nome do jurado
	string morada; ///< morada do jurado
	string telemovel; ///< telemovel do jurado
	string arte; ///< arte perfomativa do jurado
	vector<sessao*> sessoes; ///< vetor com as sessoes em que o jurado esta

public:
	/**
	* @brief construtor de um objecto da class jurado
	*
	*/
	jurado();
	/**
	* @brief construtor de um objecto da class jurado
	* @param nome nome do jurado
	* @param morada morada do jurado
	* @param telemovel telemovel do jurado
	* @param arte arte em que o jurado e especialista
	*/
	jurado (string nome , string morada , string telemovel , string arte);
	/**
	 * @brief construtor de um objeto da class jurado
	 * @param info string com a informacao toda de um jurado
	 */
	jurado(string info);

	/**
	* @brief destrutor de um objecto da class jurado
	*
	*/
	~jurado();
	/**
	* @brief funcao que altera o nome do jurado
	* @param nome nome do jurado
	*/
	void setNome (string nome);
	/**
	* @brief funcao que altera a morada do jurado
	* @param morada morada do jurado
	*/
	void setMorada (string morada);
	/**
	* @brief funcao que altera o telemovel do jurado
	* @param telemovel telemovel do jurado
	*/
	void setTelemovel (string telemovel);
	/**
	* @brief funcao que altera a arte do jurado
	* @param arte arte do jurado
	*/
	void setArte (string arte);
	/**
	* @brief funcao que devolve o nome do jurado
	* @return nome do jurado
	*/
	string getNome () const;
	/**
	* @brief funcao que devolve a morada do jurado
	* @return morada do jurado
	*/
	string getMorada() const;
	/**
	* @brief funcao que devolve o numero de telemovel do jurado
	* @return telemovel do jurado
	*/
	string getTelemovel() const;
	/**
	* @brief funcao que devolve a arte do jurado
	* @return arte do jurado
	*/
	string getArte() const;

	/**
	 * @brief funcao que devolve as sessoes do jurado
	 * @return sessoes do jurado
	 */
	vector<sessao*> getSessoes() const;

	/**
	 * @brief funcao que adiciona as sessoes ao jurado
	 * @param s vetor de sessoes a adicionar
	 */
	void setSessoes(vector<sessao*> s);

	/**
	 * @brief funcao que adiciona uma sessao às sessoes ao jurado
	 * @param s sessao a adicionar
	 */
	void adicionaSessao(sessao* s);

	/**
	 * @brief funcao que remove uma sessao das sessoes do jurado
	 * @param s sessao a remover
	 */
	void removeSessao(sessao* s);

	/**
	 * @brief overload do operador << para a classe jurado (ostream)
	 */
	friend ostream & operator<<(ostream & o, const jurado * j);

	/**
	 * @brief overload do operador << para a classe jurado (fstream)
	 */
	friend ofstream & operator<<(ofstream & o, const jurado * j);

	/**
	 * @brief verifica se o jurado ja tem alguma sessao naquele dia
	 * @return true se sim, false se nao;
	 */
	bool juradoOcupado(vector<int> data);
};


/**
 * @class JuradoNaoExiste
 * @brief excepcao para quando um objeto da classe jurado nao existe
 */
class JuradoNaoExiste {


public :
	string nome; ///< nome do jurado
	/**
	 * @brief constructor da excepcao JuradoNaoExiste
	 *
	 * @param nome nome do jurado
	 */
	JuradoNaoExiste(string nome) {this->nome = nome;}

};


std::ostream & operator<<(std::ostream &out, const JuradoNaoExiste &c);

/**
 * @class JuradoJaExiste
 * @brief excepcao para quando um objeto da classe jurado ja existe
 */
class JuradoJaExiste {


public:
	string nome; ///< nome do jurado
	/**
	 * @brief constructor da excepcao JuradoJaExiste
	 *
	 * @param nome nome do jurado
	 */
	JuradoJaExiste (string nome) {this->nome = nome;}
};


std::ostream & operator<<(std::ostream &out, const JuradoJaExiste &c);

/**
 * @class juradoOcupado
 * @brief excepcao para quando um objeto da classe jurado ja se encontra ocupado num determinado dia
 */
class juradoOcupado {

public:
	string nome; ///< nome do jurado
	vector<int> data; ///< data em que este esta ocupado
	/**
	 *  @brief constructor da excepcao juradoOcupado
	 *  @param nome nome do jurado
	 *  @param data data em que esta ocupado
	 */
	juradoOcupado(string nome, vector<int> data) {this->nome = nome; this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const juradoOcupado &c);











#endif /* SRC_JURADO_H_ */
