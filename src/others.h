#ifndef _OTHERS_H
#define _OTHERS_H

// Verifica S.O. e inclui libs
#ifdef __unix__         
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h>

#endif // Fim da verificação

#include <stdbool.h>

// Limpa a sujeira do buffer  
void fflush_stdin() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Limpa a tela
void clear(){
#ifdef OS_Windows
    system("cls");
#else // GNU/Linux
    system("clear");
#endif    
}

void indent(int *cacheBits){
	for(int i=0; i<*cacheBits; i++){
		printf(" ");
	}
}

void decToBin(bool **bin, const int line, int amountOfBits, const int dec){

	int q; // Quociente

	if(dec > 1){ // Para números positivos
		
		q = dec;
		do{ // Converte o numero decimal para binario
			amountOfBits--;
			if(q != 0){ 
				bin[line][amountOfBits] = q % 2; // Divide o decimal por 2 e atribui o resto (que pode ser 0 ou 1) em bin[line][amountOfBits]
				q /= 2; // Divide o decimal por 2 e atribui em q para ser usado no próximo loop
			}else{ // Quando o quociente der 0 são adicionados zeros a esquerda
				bin[line][amountOfBits] = 0;
			}
		}while(amountOfBits != 0); // Quando o contador de bits der 0 a operação acaba
        
   }else if(dec == 1){
		
		for(int i = 0; i<amountOfBits-1; i++){
			bin[line][i] = 0;
		}
		bin[line][amountOfBits-1] = 1; // Adiciona o bit 1 no final
        
	}else{ //Se o numero for igual a 0
	
		for(int i = 0; i<amountOfBits; i++){
			bin[line][i] = 0;
		}
	
	}
}

#endif
