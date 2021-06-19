# a89stack.h

## teste1.c

Este arquivo executa o primeiro teste da bilbioteca. São testadas as funções:
- <tt>create()</tt>
- <tt>isVoid()</tt>
- <tt>isFull()</tt>
- <tt>push()</tt>
- <tt>pop()</tt>
- <tt>destroy()</tt>


Observe que ao usar a função <tt>push()</tt>:

<pre>
void push(Tipo n, Stack pilha)
</pre>

o membro correto da estrutura <tt>Tipo</tt> deve ser setado, exemplo:

<pre>
Tipo n1, n2, n3;
n1.i = 1;
n2.i = 2;
n3.i = 3;
</pre>

Neste caso foi setado o membro <tt>i</tt>, relativo ao tipo <tt>int</tt>, pois deseja-se trabalhar com inteiros.
Isto é usado neste teste. Ajusta-se o membro da união <tt>Tipo</tt> conforme o tipo de dado a ser processado. 

## Saída do arquivo teste1.c após compilado em ambiente Windows 10.

<img src="https://github.com/arataca89/C/blob/main/a89stack/teste1.PNG">

<hr>

## teste2.c

Além das funções testadas em teste1.c aqui testa-se também as funções:

<pre>
pushInt()
pushFloat()
pushChar()
</pre>

Observe que conforme o tipo a ser processado a função correta deve ser chamada. Lembrando que ao criar uma pilha de inteiros não devemos inserir um dado de outro tipo. Isto causará resultados inesperados.

## Saída do aruqivo teste2.c após compilado em ambiente Windows 10

<img src="https://github.com/arataca89/C/blob/main/a89stack/teste2.PNG">

<hr>

aaa


