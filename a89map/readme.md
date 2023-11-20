# a89map (em construção)

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

### Interface
<pre>
Map* map_create(int n);
void map_delete(Map* m);
void map_print(const Map* m); // {KEY:VALUE}
void map_push(Map* m, int k, const char* v); 
Bool map_keycheck(const Map* m, int k);

Map* map_copy(const Map* src);

Bool map_empty(const Map* m);
Bool map_full(const Map* m);

int map_size(const Map* m);
int map_cap(const Map* m);

void map_report(const Map* m);
void check(int n);
</pre>


