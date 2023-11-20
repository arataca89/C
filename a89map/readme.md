# a89map (em construção)

A lib a89map implementa um contêiner do tipo `[chave:valor]` onde a chave é um `int` e o valor é uma string com 70 caracteres. Essa lib foi escrita para ser utilizada em um projeto de interpretador `BASIC`. Um objeto `Map` irá armazenar as linhas do código fonte do programa `BASIC`. 
<br><br>
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
<br><br>
### Interface

| Função | Finalidade |
|------------------------|---------------|
| Map* map_create(int n) | cria um `Map` |
| void map_delete(Map* m) | deleta um `Map` |
| void map_print(const Map* m) | Imprime todos os elementos do `Map` no formato `{KEY:VALUE}` |
| void map_push(Map* m, int k, const char* v) | Insere um elemento no `Map` em sua posição correta |
| Bool map_keycheck(const Map* m, int k) | Verifica se já existe um elemento com essa chave no `Map` |
| Map* map_copy(const Map* src) | Copia um `Map` |
| Bool map_empty(const Map* m) | Verifica se o `Map` está vazio |
| Bool map_full(const Map* m) | Verifica se o `Map` está cheio |
| int map_size(const Map* m) | Retorna quantos elementos existem no `Map` |
| int map_cap(const Map* m) | Retorna a capacidade do `Map` |
| void map_report(const Map* m) | Imprime na tela um relatório do `Map` |
| void check(int n) | Função auxiliar utilizada na depuração |

---
arataca89@gmail.com

Aulas particulares de programação C/C++.



