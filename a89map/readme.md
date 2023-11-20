# a89map

A lib a89map implementa um contêiner do tipo `[chave:valor]` onde a chave é um `int` e o valor é uma string com 70 caracteres. Essa lib foi escrita para ser utilizada em um projeto de interpretador `BASIC`. Um objeto `Map` irá armazenar as linhas do código fonte do programa `BASIC`. 

### Tipos de dados 
<pre>
typedef enum{false, true} Bool;

typedef struct{
	int key;
	char value[71];
}Elemento;

typedef struct{
	int size;
	int cap;
	Elemento* elementos;
}Map;
</pre>
