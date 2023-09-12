#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// my types

typedef struct nounou {
    char mat[9][9];
}nounou;
typedef struct nou {
    char table[90];
    int index;
}nou;
typedef struct cordo
{
    int i;
    int j;
}cordo;
typedef struct board_infos {
    nounou my_mat;
    char sols[24];
    int n;
    int index;
    cordo cur;
}board_infos;
typedef struct cellule *pile;
typedef struct cellule {
    board_infos info;
    pile svt;
}cellule;

// end my types

// my functions

void allouer(pile *nouv){
    *nouv=(pile)malloc(sizeof(cellule));
}
void push(pile *p ,board_infos src){
    pile nouv;
    allouer(&nouv);
    nouv->info=src;
    nouv->svt=*p;
    *p=nouv;
}
void pop(pile *p,board_infos *dest){
    if (*p ==NULL)
    {
        printf("\nla pile est vide :");
    }
    else{
        *dest=(*p)->info;
        pile tmp=*p;
        *p=(*p)->svt;
        free(tmp);
    }
}
bool pile_vide(pile p){
    if(p==NULL){
        return(true);
    }
    else{return(false);}
}
void copy(char dest[][9], char src[][9]){
    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            dest[i][j]=src[i][j];
        }
    }
}
int possible_numbers(char mat[][9], int n, cordo cur,char table[90]){
    // load impossibles numbers
    char cont[240];
    int c = 0;
    // row numbers
    for(int co = 0; co<n; co++){
        if(co==cur.j){co++;}
        if(co<n){
            cont[c]=mat[cur.i][co];
            c++;
        }
    }
    // col numbers
    for(int l =0; l<n; l++){
        if(l==cur.i){l++;}
        if(l<n){
            cont[c]=mat[l][cur.j];
            c++;
        }
    }
    // box numbers
    if((cur.i>=0 && cur.i<=2) && (cur.j>=0 && cur.j<=2)){
        for(int i=0 ; i<=2 ; i++){
            for(int j=0; j<=2; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=2){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=0 && cur.i<=2) && (cur.j>=3 && cur.j<=5)){
        for(int i=0 ; i<=2 ; i++){
            for(int j=3; j<=5; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=5){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=0 && cur.i<=2) && (cur.j>=6 && cur.j<=8)){
        for(int i=0 ; i<=2 ; i++){
            for(int j=6; j<=8; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=8){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=3 && cur.i<=5) && (cur.j>=0 && cur.j<=2)){
        for(int i=3 ; i<=5 ; i++){
            for(int j=0; j<=2; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=2){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=3 && cur.i<=5) && (cur.j>=3 && cur.j<=5)){
        for(int i=3 ; i<=5 ; i++){
            for(int j=3; j<=5; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=5){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=3 && cur.i<=5) && (cur.j>=6 && cur.j<=8)){
        for(int i=3 ; i<=5 ; i++){
            for(int j=6; j<=8; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=8){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=6 && cur.i<=8) && (cur.j>=0 && cur.j<=2)){
        for(int i=6 ; i<=8 ; i++){
            for(int j=0; j<=2; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=2){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=6 && cur.i<=8) && (cur.j>=3 && cur.j<=5)){
        for(int i=6 ; i<=8 ; i++){
            for(int j=3; j<=5; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=5){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    if((cur.i>=6 && cur.i<=8) && (cur.j>=6 && cur.j<=8)){
        for(int i=6 ; i<=8 ; i++){
            for(int j=6; j<=8; j++){
                if(j==cur.j && i==cur.i){
                    j++;
                }
                if(j<=8){
                    cont[c]=mat[i][j];
                    c++;
                }
            }
        }
    }
    // find the possible numbers
    int total=c-1;                                                         //hada houwa x.n;
    c=0;
    char pos_num[9]={'1','2','3','4','5','6','7','8','9'};
    int p=0;
    char tab[90];
    int cpt=0;
    tab[cpt]='0';
    bool existe=false;
    while((p<9)&&(existe==false)){
        c=0;
        while((c<total)&&(existe==false)){
            if(cont[c]==pos_num[p]){
                existe=true;                                               //hna dit tchmita
            }
            else{
                c++;
            }
        }
        if(existe==false){
            tab[cpt]=pos_num[p];
            cpt++;
        }
        else if(existe==true){
        existe=false;
        }
        p++;
    }
    for(int i =0;i<=cpt;i++){
        table[i] =tab[i];
    }
    cpt--;
    return (cpt);
}

// end my functions

// start sudoku solver 
void solveSudoku(char board[][9], int boardSize, int* boardColSize){
    // inputs rendering
    int n = boardSize;
    // inputs rendering end
    pile p=NULL;
    int cpt=0;
    board_infos x;
    bool full =false;           //ida khdmt biha ana mrid
    while(full==false){
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.'){
                    x.cur.i=i;
                    x.cur.j=j;
                    x.index=0;
                    x.n=possible_numbers(board,n,x.cur,x.sols);
                    if(x.sols[0]!='0' ){
                        board[i][j]=x.sols[x.index];
                        x.index++;
                        copy(x.my_mat.mat,board);
                        push(&p,x);
                        // printf("\n");
                        // for(int mouh=0;mouh<=x.n;mouh++){
                        //     printf("sols[%d]=%c",mouh,x.sols[mouh]);
                        // }
                        // printf("\n");
                    }
                    else{
                        i=9;
                        j=9;
                    }
                }
            }
        }
        // copy(x.my_mat.mat,board);
        int k=0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.' ||board[i][j]=='0' ){
                    k++;
                }
            }
        }
        if(k==0){full=true;}
        while(full==false){
            
            while(x.index>x.n || x.sols[0]=='0'){//hna small tric
                pop(&p,&x);
            }
            
            x.my_mat.mat[x.cur.i][x.cur.j]=x.sols[x.index];
            x.index++;
            push(&p,x);
            copy(board,x.my_mat.mat);
            for(int i =0;i<9;i++){
                for(int j =0;j<9;j++){
                    if(board[i][j]=='.'|| board[i][j]=='0'){
                        x.cur.i=i;
                        x.cur.j=j;
                        x.index=0;
                        x.n=possible_numbers(board,n,x.cur,x.sols);
                        if(x.sols[0]!='0'){
                            board[i][j]=x.sols[x.index];
                            x.index++;
                            copy(x.my_mat.mat,board);
                            push(&p,x);   
                        }
                        else{
                            i=9;
                            j=9;
                        }
                        
                    }
                }
            }
            int k=0;
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    if(board[i][j]=='.' ||board[i][j]=='0' ){
                        k++;
                    }
                }
            }
            // printf("\nk=%d\n",k);
            if(k==0){full=true;}
        }

    }
}
// end sudoku solver






int main(){

    char board[9][9] = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

    printf("\nbefore solving\n");
    for(int i =0;i<9;i++){
        for(int  j =0;j<9;j++){
            printf("\t%c",board[i][j]);
        }
        printf("\n\n");
    }
    int p=9;
    solveSudoku(board,9,&p);
    printf("\nafter solving\n");
    for(int i =0;i<9;i++){
        for(int  j =0;j<9;j++){
            printf("\t%c",board[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}
