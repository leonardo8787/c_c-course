#include "tasks.h"

//void TaskMoveDiskToMemory(){

	
//}

void TasksInitialize(){
	const char sep[6] = "PA,<> ";
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	int size;
	DiskBlock aux, rem;
	

	//DISK INITIALIZATION
	DiskParams dpms;
	DiskGetParameters(&dpms);
	DiskBlock disk_blocks[dpms.maxrows][dpms.maxcols];
	DiskPointers pilhas[dpms.maxrows];
	DiskInitialize(dpms.maxrows, dpms.maxcols, disk_blocks, pilhas);
	DiskLoad(dpms.maxrows, dpms.maxcols, disk_blocks, pilhas);

	//MEMORY INITIALIZATION
	MemoryParams mpms;
	MemoryGetParameters(&mpms);
	DiskBlock memory_blocks[mpms.maxrows][MEMORYMAXCOLS];
	MemoryPointers filas[mpms.maxrows];
	MemoryInitialize(mpms.maxrows, memory_blocks, filas);

	//SWAP INITIALIZATION
	SwapParams spms;
	spms.maxcols = mpms.maxcols - MEMORYMAXCOLS;
	spms.maxrows = mpms.maxrows;
	DiskBlock swap_blocks[spms.maxrows][spms.maxcols];
	SwapPointers listas[spms.maxrows];
	SwapInitialize(spms.maxrows, spms.maxcols, swap_blocks, listas);

	
	//DATA ANALYSIS VARIABLES
	int page_miss[mpms.maxrows];
	for(int i=0; i<mpms.maxrows; i++)
		page_miss[i] = 0;
	int files_request[dpms.maxrows];
	for(int i=0; i<dpms.maxrows; i++)
		files_request[i] = 0;
	
	
	fp = fopen(MEMORYPATH, "r");
	if (fp == NULL){
		printf("[ERROR]: Fail to open file!\n");
		return;
	}

	//PROCESSING MEMORY REQUESTS
	int toks[mpms.maxcols];
	bool memoryIsFull = false;
	bool inMemory     = false;
	bool inDisk       = false;
	
	while ((read = getline(&line, &len, fp)) != -1){
		size = GetTokens(line, sep, toks);
		for(int i=1; i<size-1; i+=2){
			aux.file = toks[i];
			aux.segment = toks[i+1];
			if(aux.file <= dpms.maxrows && aux.segment <= dpms.maxcols){
				inMemory = MemoryLookAt(mpms.maxrows, memory_blocks, aux);
				
				if(!inMemory){
					inDisk = Pop(disk_blocks[aux.file-1], &pilhas[aux.file-1], dpms.maxcols, &aux);
					page_miss[toks[0]-1] ++;
				}

				if(inDisk || inMemory){
					printf("WORKING WITH: P%d -> <%d,%d> IN MEMORY (%d) OR IN DISK (%d)\n", toks[0], aux.file, aux.segment, inMemory, inDisk);
					files_request[aux.file-1] ++;
					memoryIsFull = MemoryQueue(memory_blocks[toks[0]-1], aux, &filas[toks[0]-1]);
					if(memoryIsFull)
						SendToSwap(swap_blocks[toks[0]-1], aux, &listas[toks[0]-1], spms.maxcols);
				}

				memoryIsFull = false;
				inMemory     = false;
				inDisk       = false;
			}
		}

	}

	fclose(fp);

	//PROCESSING SWAP REQUESTS
	bool swapIsEmpty   = false;
	bool memoryIsEmpty = false;
	inDisk             = false;
	inMemory           = false;

	for(int j=0; j<spms.maxcols; j++)
		for(int i=0; i<spms.maxrows; i++){
			swapIsEmpty   = SwapToMemory(swap_blocks[i], &aux, &listas[i]);
			memoryIsEmpty = MemoryDequeue(memory_blocks[i], &rem, &filas[i]);
			
			if(!memoryIsEmpty)
				Push(disk_blocks[rem.file-1], &pilhas[rem.file-1], dpms.maxcols, rem);
			
			if(!swapIsEmpty){
				inMemory = MemoryLookAt(mpms.maxrows, memory_blocks, aux);
				
				if(!inMemory){
					Pop(disk_blocks[aux.file-1], &pilhas[aux.file-1], dpms.maxcols, &aux);
					page_miss[toks[0]-1] ++;
				}

				printf("WORKING WITH: P%d -> <%d,%d> IN SWAP\n", i, aux.file, aux.segment);
				MemoryQueue(memory_blocks[i], aux, &filas[i]);
				files_request[aux.file-1] ++;	
			}

			swapIsEmpty   = false;
			memoryIsEmpty = false;
			inMemory      = false;

		}


	//MEMORY EMPTYING
	for(int j=0; j<MEMORYMAXCOLS; j++)
		for(int i=0; i<mpms.maxrows; i++){
			memoryIsEmpty = MemoryDequeue(memory_blocks[i], &rem, &filas[i]);
			if(!memoryIsEmpty)
				Push(disk_blocks[rem.file-1], &pilhas[rem.file-1], dpms.maxcols, rem);
		}

	
	//SHOW RESULTS
	printf("SHOW RESULTS:\n");
	printf("PAGE MISS:\t");
	for(int i=0; i<mpms.maxrows; i++)
		printf("P%d:%d \t", i+1, page_miss[i]);
	printf("\n");
	printf("FILE REQUEST:\t");
	for(int i=0; i<dpms.maxrows; i++)
		printf("A%d:%d \t", i+1, files_request[i]);
	printf("\n");

	printf("SHOW FILES IN DISK:\n");
	for(int i=0; i<dpms.maxrows; i++){
		printf("FILE:A%d\t", i+1);
		for(int j=0; j<pilhas[i].top; j++)
			printf("<%d,%d>\t", disk_blocks[i][j].file, disk_blocks[i][j].segment);
		printf("\n");
	}
	

}



