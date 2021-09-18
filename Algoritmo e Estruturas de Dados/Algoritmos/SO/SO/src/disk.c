/*
  DISK MODEL BASED ON STACK PRINCIPLES
  
  @The operating system simulator is devoted to incorporate treating basic and static 
   linear structures studied in algorithms and data structures I.

  @author Michel Pires da Silva (michel@cefetmg.br)

  @date 2021

	@copyright GNU Public License

	@cond GNU_PUBLIC_LICENSE
    	PyMid is free software: you can redistribute it and/or modify
    	it under the terms of the GNU General Public License as published by
    	the Free Software Foundation, either version 3 of the License, or
   		(at your option) any later version.
    
    	The operating system simulator is distributed in the hope that it will be useful,
    	but WITHOUT ANY WARRANTY; without even the implied warranty of
    	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    	GNU General Public License for more details.
    
    	You should have received a copy of the GNU General Public License
    	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	@endcond

*/

#include "disk.h"

void DiskGetParameters(DiskParams *p){
	p->maxrows = 0;
	p->maxcols = 0;
	const char sep[3] = "A, ";
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	int tmp;

	fp = fopen(DISKPATH, "r");
	if (fp == NULL){
		printf("[ERROR]: Fail to open file!\n");
		return;
	}

	while ((read = getline(&line, &len, fp)) != -1){
		p->maxrows ++;
		tmp = GetSizeOf(line, sep);
		p->maxcols=(tmp>p->maxcols)?tmp:p->maxcols;	
	}

	fclose(fp);
}

void DiskInitialize(int rows, int cols, DiskBlock blocks[rows][cols], DiskPointers pilha[rows]){

	for(int i=0; i<rows; i++){
		pilha[i].top   = 0;
		pilha[i].base  = 0;
	}

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols-1; j++){
			blocks[i][j].file    = -1;
			blocks[i][j].segment = -1;
		}
}

void DiskShowFile(DiskBlock *file, DiskPointers *p, int fid){
	printf("FILE ID:%d\n", fid);
	for(int i=p->top-1; i>=p->base; i--)
		printf("%d\t", file[i].segment);
	printf("\n");
}

bool DiskLookAt(DiskBlock *file, int top, DiskBlock data){
	bool isin = false;
	
	for(int i=0; i<top; i++)
		if(file[i].segment == data.segment){
			isin = true;
			break;
		}

	return isin;
}

void Push(DiskBlock *file, DiskPointers *p, int cols, DiskBlock data){
	if (p->top >= cols){
		printf("[ERROR]:SPACE FOR THE FILE %d IN HARD DISC IS NOT ENOGH!\n", data.file);
	}else{
		if(!DiskLookAt(file, p->top, data)){
			file[p->top] = data;
			p->top ++;
		}
	}
}

bool Pop(DiskBlock *file, DiskPointers *p, int cols, DiskBlock *data){
	DiskBlock aux;
	DiskBlock track[cols];
  int i = -1;
  bool isin = false;

	if(p->top == p->base){
		printf("[ERROR]:SPACE FOR THE FILE %d IN HARD DISC IS EMPTY!\n", data->file);
	}else{
		aux.segment = -1;
		while(aux.segment != data->segment && p->top != p->base){
			p->top --;
			aux = file[p->top];
			if(aux.segment != data->segment){
				i++;
				track[i] = aux;
			}
		}

		if(aux.segment == data->segment)
			isin = true;

		for(int j=i; j>=0; j--)
			Push(file, p, cols, track[j]);
	}

	return isin;
}

void DiskLoad(int rows, int cols, DiskBlock blocks[rows][cols], DiskPointers pilha[rows]){
	const char sep[3] = "A, ";
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	int size;
	int toks[cols];	
	DiskBlock b;

	fp = fopen(DISKPATH, "r");
	if (fp == NULL){
		printf("[ERROR]: Fail to open file!\n");
		return;
	}

	while ((read = getline(&line, &len, fp)) != -1){
		size = GetTokens(line, sep, toks);
		b.file = toks[0];
		for(int i=1; i<size; i++){
			b.segment = toks[i];
			Push(blocks[b.file - 1], &pilha[b.file - 1], cols, b);
		}
	}

	fclose(fp);
}
