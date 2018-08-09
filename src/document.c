#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/document.h"

/* INITIALIZER */

Document_t* init_document(PieceChain_t* chain, char* filename, int height, int width){
	Document_t* newDocument = (Document_t *)malloc(sizeof(Document_t));
	int lineCount = get_line_count(filename);
	if(lineCount > height){
		int lineAt = 0;

	}
	char text[height][width];
	return newDocument;
}

/* UTILITY FUNCTIONS */

int get_line_count(char *filename){
	FILE *filePointer = fopen(filename, "r");
	int lineCount = 0;
	char currentCharacter;

	for(currentCharacter = getc(filePointer); currentCharacter != EOF; currentCharacter = getc(filePointer)){
		if(currentCharacter == '\n'){
			lineCount += 1;
		}
	}
	fclose(filePointer);
	return(lineCount);
}

int get_first_offscreen(char* text, int linesInFile, int height, int width){
	if(linesInFile <= height){
		return(sizeof(text)/sizeof(text[0]));
	}
	else{
		char* currentCharacter;
		int index = 0;
		int lineCount = 0;
		int columnIndex = 0;
		for(currentCharacter = text; currentCharacter != '\0'; currentCharacter += sizeof(char)){
			if(currentCharacter == '\n' || columnIndex >= width){
				lineCount += 1;
				columnIndex = 0;
			}
			if(lineCount > height){
				if(currentCharacter == '\n'){
					index += 1;
				}
				break;
			}
			index += 1;
		}
		return index;
	}
}