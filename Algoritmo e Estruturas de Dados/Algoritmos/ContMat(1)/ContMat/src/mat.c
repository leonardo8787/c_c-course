#include "mat.h"


void Initialize(Matrix *mat){
	
	srand(time(0)); 
	
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
            mat->m[i][j].val = rand()%100; 
}


void Imprime(Matrix *mat){
    printf("======================== MATRIX ========================\n");
	for(int i=0; i<MAXROWS; i++){
        for(int j=0; j<MAXCOLS; j++)
            printf("%d\t", mat->m[i][j].val);
        printf("\n");
    }
    printf("========================================================\n");
}

void CalcPath(Matrix *mat){
	int sum = 0;
	int row, col, t1, t2;
	int ant, prox, below;

	row = col = 0;

	//joystick para caminhada na matriz :) ant(<) | prox(>) | below (v) 
	ant   = -1;
	below = prox  = 1;

	printf("====================== MOVEMENTS =======================\n");
	while(row < MAXROWS){
		printf("ROW:%d, COL:%d, ANT:%d, PROX:%d, BELOW:%d\n", row, col, ant, prox, below);
		sum += mat->m[row][col].val;
		mat->m[row][col].val = -1;

		//permaneço ou mudo de linha
		t1   = (ant  != -1 && mat->m[below-1][ant].val != -1 && mat->m[below][col].val > mat->m[below - 1][ant].val)?below:row;
		t2   = (prox != -1 && mat->m[below-1][prox].val != -1 && mat->m[below][col].val > mat->m[below - 1][prox].val)?below:row;
		if(mat->m[t1][ant].val > mat->m[t2][prox].val)
			row   = t1;
		else
			row   = t2;

		//escolho a coluna se não mudei de linha
		if(ant != -1 && prox != -1){
			col   = (row != below && mat->m[row][ant].val > mat->m[row][prox].val)?ant:col;
			col   = (row != below && mat->m[row][prox].val > mat->m[row][ant].val)?prox:col;
		}else if(ant != -1){
			col   = (row != below && mat->m[row][ant].val != -1)?ant:col;
			row   = (row != below && mat->m[row][ant].val == -1)?below:row;
		}else{
			col   = (row != below && mat->m[row][prox].val != -1 )?prox:col;
			row   = (row != below && mat->m[row][prox].val == -1)?below:row;
		}
		
		prox  = col + 1;
		prox  = (prox < MAXCOLS)?prox:-1;
		ant   = col - 1;
		ant   = (ant >= 0)?ant:-1;

		below += (row == below)?1:0;

		if(row == MAXROWS - 1){
			for(int i = col; i<MAXCOLS; i++){
				sum += mat->m[row][i].val;
				mat->m[row][i].val = -1;
				printf("ROW:%d, COL:%d, ANT:%d, PROX:%d, BELOW:%d\n", row, i, ant, prox, below);
			}

			row = MAXROWS;
		}

	}

	printf("========================================================\n");

	printf("=================== SIZE OF PATH =======================\n");
	printf("SIZEOF PATH: %d\n", sum);
	printf("========================================================\n");
	
}








