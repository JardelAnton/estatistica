#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int n = 0;
float media_de_n = 0;
float soma_de_n = 0;
float var = 0;
float elem = 0;
float cv = 0;

void reinicia(){
	n = 0;
	media_de_n = 0;
	soma_de_n = 0;
	var = 0;
	elem = 0;
	cv = 0;
}

//dados isolados
	void media(float * dados){
		for(int a = 0; a < n; a++){
			media_de_n += dados[a];
		}
		soma_de_n = media_de_n;
		media_de_n = media_de_n / n;
	}

	void variancia(float * dados){
		media(dados);
		for(int a = 0; a < n; a++){
			var += (dados[a] - media_de_n)*(dados[a] - media_de_n);	
		}
		var = var / n;
	}

	float * recebe(float * dados){
		dados = (float *)malloc(n*sizeof(float));
		for(int a = 0; a < n; a++){
			scanf("%f",&dados[a]);
		}	
		return dados;
	}

	void coeficiente_de_variacao(float * dados){
		variancia(dados);
		float dp = sqrt(var);
		cv = dp *100 / media_de_n;
	}
//end - dados isolados

//freq sem intervalo 
	void mediafsi(float * dados){
		for(int a = 0; a < 2*n; a++){
			elem += dados[a+1];
			media_de_n += dados[a]*dados[a+1];		
			a++;
		}
		soma_de_n = media_de_n;
		media_de_n = media_de_n/elem;

	}

	void varianciafsi(float * dados){
		mediafsi(dados);
		for(int a = 0; a < 2*n; a++){
			var += (dados[a] - media_de_n)*(dados[a] - media_de_n);
			a++;
		}
		printf("%f\n",elem );
		var = var / elem;
	}

	float * recebefsi(float * dados){
		dados = (float *)malloc(2*n*sizeof(float));
		printf("insira no formato: \n dado (espaço) frequencia\n");
		for(int a = 0; a < 2*n; a++){
			scanf("%f",&dados[a]);
			a++;
			scanf("%f",&dados[a]);
		}	
		return dados;
	}

	void coeficiente_de_variacaofsi(float * dados){
		varianciafsi(dados);
		float dp = sqrt(var);
		cv = dp *100 / media_de_n;
	}
//End - freq sem intervalo 

//freq com intervalo 
	void mediafci(float * dados){
		for(int a = 0; a < 3*n; a++){
			elem += dados[a+1];
			media_de_n += ((dados[a]+dados[a+1])/2)*dados[a+2];		
			a++;
		}
		soma_de_n = media_de_n;
		media_de_n = media_de_n/elem;

	}

	void varianciafci(float * dados){
		mediafci(dados);
		for(int a = 0; a < 2*n; a++){
			var += ((dados[a]+dados[a+1])/2 - media_de_n)*((dados[a]+dados[a+1])/2 - media_de_n);
			a++;
		}
		var = var / elem;
	}

	float * recebefci(float * dados){
		dados = (float *)malloc(3*n*sizeof(float));
		printf("%d\n",3*n );
		printf("insira no formato: \n Inicio do intervalo (espaço) Fim do internvalo (espaço) frequencia\n");
		for(int a = 0; a < 3*n; a++){
			scanf("%f",&dados[a]);
			a++;
			scanf("%f",&dados[a]);
			a++;
			scanf("%f",&dados[a]);
		}	
		return dados;
	}

	void coeficiente_de_variacaofci(float * dados){
		varianciafci(dados);
		float dp = sqrt(var);
		cv = dp *100 / media_de_n;
	}
//end - freq com intervalo 



int main(){
	float * dados;
	while(1){
		reinicia();
		printf("\t1- Dados Isolados\n");
		printf("\t2- Frequencia sem intervalo\n");
		printf("\t3- Frequencia com Intervalo\n");
		printf("\t0- Sair\n");
		scanf("%d", &n);
		system("clear");
		switch(n){
			case(0):{
				exit(1);
				break;
			}
			case(1):{
				printf("\t1- Média\n");
				printf("\t2- Variancia\n");
				printf("\t3- Coeficiente de Variacao\n");
				printf("\t0- Sair\n");
				scanf("%d", &n);
				switch(n){
					case(0):{
						exit(1);
						break;
					}
					case(1):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebe(dados);
						media(dados);
						printf("Média = %f\n",media_de_n);
						break;
					}
					case(2):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebe(dados);
						variancia(dados);
						printf("Variancia = %f\n",var);
						break;
					}
					case(3):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebe(dados);
						coeficiente_de_variacao(dados);
						printf("Coeficiente de Variacao = %f\n",cv);
						break;
					}
				}
				break;
			}
			case(2):{
				printf("\t1- Média\n");
				printf("\t2- Variancia\n");
				printf("\t3- Coeficiente de Variacao\n");
				printf("\t0- Sair\n");
				scanf("%d", &n);
				switch(n){
					case(0):{
						exit(1);
						break;
					}
					case(1):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefsi(dados);
						mediafsi(dados);
						printf("Média = %f\n",media_de_n);
						break;
					}
					case(2):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefsi(dados);
						varianciafsi(dados);
						printf("Variancia = %f\n",var);
						break;
					}
					case(3):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefsi(dados);
						coeficiente_de_variacaofsi(dados);
						printf("Coeficiente de Variacao = %f\n",cv);
						break;
					}
				}
				break;
			}
			case(3):{
				printf("\t1- Média\n");
				printf("\t2- Variancia\n");
				printf("\t3- Coeficiente de Variacao\n");
				printf("\t0- Sair\n");
				scanf("%d", &n);
				switch(n){
					case(0):{
						exit(1);
						break;
					}
					case(1):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefci(dados);
						mediafci(dados);
						printf("Média = %f\n",media_de_n);
						break;
					}
					case(2):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefci(dados);
						varianciafci(dados);
						printf("Variancia = %f\n",var);
						break;
					}
					case(3):{
						printf("Quantidade de Dados\n");
						scanf("%d",&n);
						dados = recebefci(dados);
						coeficiente_de_variacaofci(dados);
						printf("Coeficiente de Variacao = %f\n",cv);
						break;
					}
				}
				break;
			}
		}
	}
	return 0;
}