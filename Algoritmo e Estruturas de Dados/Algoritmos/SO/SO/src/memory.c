/*
  MEMORY MODEL BASED ON QUEUE PRINCIPLES
  
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

#include "memory.h"


void MemoryGetParameters(MemoryParams *p){
	p->maxrows = 0;
	p->maxcols = 0;
	const char sep[6] = "PA,<> ";
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	int tmp;
	
	fp = fopen(MEMORYPATH, "r");
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


void MemoryInitialize(int rows, DiskBlock blocks[rows][MEMORYMAXCOLS], MemoryPointers filas[rows]){
	for(int i=0; i<rows; i++){
		filas[i].first = 1;
		filas[i].last  = 1;
	}

	for(int i=0; i<rows; i++)
		for(int j=0; j<MEMORYMAXCOLS; j++){
			blocks[i][j].file    = -1;
			blocks[i][j].segment = -1;
		}
}


bool MemoryQueue(DiskBlock *mem, DiskBlock b, MemoryPointers *fila){
	bool isfull = false;
	
	if (fila->last % MEMORYMAXCOLS + 1 == fila->first){
		isfull = true;
	}else{
		mem[fila->last - 1] = b;
		fila->last = fila->last % MEMORYMAXCOLS + 1;
	}

	return isfull;
}


bool MemoryDequeue(DiskBlock *mem, DiskBlock *b, MemoryPointers *fila){
	bool isempty = false;

	if(fila->last == fila->first)
		isempty = true;
	else{
		*b = mem[fila->first - 1];
		fila->first = fila->first % MEMORYMAXCOLS + 1;
	}

	return isempty;
}


bool MemoryLookAt(int rows, DiskBlock blocks[rows][MEMORYMAXCOLS], DiskBlock b){
	bool isin = false;

	for(int i=0; i<rows; i++)
		for(int j=0; j<MEMORYMAXCOLS; j++)
			if(b.file == blocks[i][j].file && b.segment == blocks[i][j].segment){
				isin = true;
				break;
			}
	
	return isin;

}

