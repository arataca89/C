/********************************************************************
Arquivo  : a89template.c
Descricao: Cria arquivos template para programacao em C.
Data	 : 2023-10-30 15:21:00

Ultima atualizacao: 2023-11-02 17:30:00

Uso: a89template FILENAME

FILENAME deve ter extensao .c ou .h

arataca89@gmail.com
Aulas particulares de programacao C/C++
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef enum{false,true} Bool;

// Pega a data/hora atual e armazena em char* dst no formato YYYY-MM-DD HH:MM:SS
void get_time(char* dst){
  	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
	sprintf(dst, "%d-%02d-%02d %02d:%02d:%02d\n",
          tm.tm_year + 1900,
          tm.tm_mon + 1,
          tm.tm_mday,
          tm.tm_hour,
          tm.tm_min,
          tm.tm_sec
   	);

}	

// Escreve o cabecalho do template.
void print_header(FILE* stream, char* filename){
	char dh[20];
	get_time(dh);
	fprintf(stream,"/");
	for(int i=2; i<=70; i++){
		fprintf(stream,"*");
	}
	fprintf(stream,"\n");
	fprintf(stream,"Arquivo  : %s\n",filename);
	fprintf(stream,"Descricao:\n");
	fprintf(stream,"Data     : %s\n\n",dh);
	fprintf(stream,"\n");
	fprintf(stream,"arataca89@gmail.com\n");
	fprintf(stream,"Aulas particulares de programacao C/C++.\n");
	for(int i=1; i<=69; i++){
		fprintf(stream,"*");
	}
	fprintf(stream,"/\n");
}

// Escreve o rodape do template.
void print_footer(FILE* stream){
	fprintf(stream,"/");
	for(int i=2; i<=70; i++){
		fprintf(stream,"*");
	}
	fprintf(stream,"\n");
	fprintf(stream,"arataca89@gmail.com\n");
	fprintf(stream,"Aulas particulares de programacao C/C++.\n");
	for(int i=1; i<=69; i++){
		fprintf(stream,"*");
	}
	fprintf(stream,"/\n");
}

// Converte char* src para maiusculas e armazena em char* dst.
void str_to_upper(char* dst, char* src){
	while(*src){
		*dst = toupper(*src);
		dst++;
		src++;
	}
}

// Escreve o template de header file.
void write_template_h(FILE* stream, char* filename){
	char label[64];
	str_to_upper(label,filename);
	label[strlen(label)-1] = 'H';
	label[strlen(label)-2] = '_';
	print_header(stream,filename);
	fprintf(stream,"#ifndef %s\n",label);
	fprintf(stream,"#define %s\n",label);
	fprintf(stream,"\n");
	fprintf(stream,"void check(int n);\n");
	fprintf(stream,"\n");
	fprintf(stream,"#endif\n");
	print_footer(stream);
}

// Escreve o template de um arquivo .c .
void write_template_c(FILE* stream, char* filename){
	print_header(stream,filename);
	fprintf(stream,"#include <stdio.h>\n");
	fprintf(stream,"#include <stdlib.h>\n");		
	fprintf(stream,"#include <math.h>\n");
	fprintf(stream,"#include <string.h>\n");
	fprintf(stream,"#include <ctype.h>\n");
	fprintf(stream,"#include <time.h>\n");

	char headerfile[64];
	strcpy(headerfile,filename);
	headerfile[strlen(headerfile)-1] = 'h';
	fprintf(stream,"#include \"%s\"\n",headerfile);
	fprintf(stream,"\n\n");
	fprintf(stream,"void check(int n){\n");
	fprintf(stream,"    printf(\"\\n>>> checkpoint %c%c <<<\\n\",n);\n",'%','d');
	fprintf(stream,"}\n");
	fprintf(stream,"\n");
	print_footer(stream);
}

// Exibe mensagem de uso da tela e encerra o programa.
void uso(char* str){
	printf("Uso: %s FILENAME\n\n",str);
	printf("FILENAME deve ter extensao .c ou .h\n");
	exit(EXIT_FAILURE);
}

// Verifica se a extensao de char* filename confere com ponto(.) seguido de char ch.
Bool check_extension(char* filename, char ch){
	char ultimo = filename[strlen(filename)-1];
	char penultimo = filename[strlen(filename)-2];
	if(ultimo == ch && penultimo == '.') return true;
	return false; 
}

// Escreve o template de nome char* filename conforme a opcao char o.
void writefile(char* filename, char o){
	FILE* fp = fopen(filename,"w");
	switch(o){
		case 'c': write_template_c(fp,filename);break;
		case 'h': write_template_h(fp,filename);break;
	}
	fclose(fp);
}

int main(int argc,char* argv[]){
	if(argc != 2){
		uso(argv[0]);
	}

	if(check_extension(argv[1],'c')){
			writefile(argv[1],'c');
	}
	else if(check_extension(argv[1],'h')){
			writefile(argv[1],'h');
	}
	else{
		printf("Extensao de arquivo invalida!\n");
		uso(argv[0]);
	}

	return 0;
}

/********************************************************************
arataca89@gmail.com
Aulas particulares de programacao C/C++
********************************************************************/
