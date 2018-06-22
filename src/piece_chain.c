#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef BUFFR_SIZE
#define BUFFER_SIZE 1024
#endif

/* Piece Chain Definition
 * ----------------------
 * Summary:
 *	Comprising of three seperate buffers. The first
 *	holds the original text, read in at launch. This
 *	buffer is read-only. The second holds any inserts
 *	made to the file. This is append only. Finally,
 *	the last is a table containing which buffer the
 *	piece is in, its start index, and its length.
 *
 * Typdef:
 *	pieceChain
 *
 * Values:
 *	char *original;
 *		-A buffer holding the original text
 *		-Read only
 *	char *add:
 *		-A buffer holding all additions to the
 *		 current file
 *		-Append only
 *	int *pieces:
 *		-A 1024 by 3 matrix where each row represnts
 *		 one piece.
 *		-pieces[n][0] holds which matrix is being used
 *		-pieces[n][1] states the start of the current piece
 *		-pieces[n][2] states the length of the current piece
 *
 *
 * Visual Example:
 *
 *				BEFORE ANY EDITS
 *				----------------
 *	
 *	Original file buffer (read only):
 *
 *	-----------------------------------------
 *	|A| |l|a|r|g|e| |s|p|a|n| |o|f| |t|e|x|t|
 *	-----------------------------------------
 *
 *	Add buffer (append only):
 *
 *	-----------------------------------------
 *	|										|
 *	-----------------------------------------
 *
 *	Piece Table:
 *
 *	BUFFER 	   |  START INDEX  | PIECE LENGTH
 *	------------------------------------------
 *	| original | 			 0 |		   19|
 *	------------------------------------------
 *
 *	Text:
 *
 *	A large span of text
 *	------------------------------------------
 *
 *				  AFTER EDITS
 *				----------------
 *	
 *	Original file buffer (read only):
 *
 *	-----------------------------------------
 *	|A| |l|a|r|g|e| |s|p|a|n| |o|f| |t|e|x|t|
 *	-----------------------------------------
 *
 *	Add buffer (append only):
 *
 *	-----------------------------------------
 *	|E|n|g|l|i|s|h|							|
 *	-----------------------------------------
 *
 *	Piece Table
 *
 *	BUFFER 	   |  START INDEX  | PIECE LENGTH
 *	-------------------------------------------
 *  | original | 			 0 |		    2 |
 *	| original |			 8 |		   	8 |
 *	| add  	   |			 0 |		    8 |
 *	| original |			16 |			4 |
 *  -------------------------------------------
 *
 * 	Text:
 *
 * 	A span of English text
 */
