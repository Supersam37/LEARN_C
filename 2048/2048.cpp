#include <stdio.h>
#include <stdlib.h>     
#include <time.h>             
#include <windows.h>
#include <conio.h>
#define MAXN 11
int MAX; 
int FLAG;  
int a[MAXN][MAXN];
int NUM;
int score_now;

int score(){
	int sum = 0;
	for(int i = 0;i<MAXN;i++){
		for(int j = 0;j<MAXN;j++){
			sum+=a[i][j];
		}
	}
	return sum;
} 
int start() {
	for(int i = 0;i<MAX;i++)
		for(int j = 0;j<MAX;j++) 
			a[i][j] = 0;
	NUM = MAX*MAX-1;
    srand(time(0));
    int x = rand()%MAX;
    int y = rand()%MAX;        
    a[x][y] = 2;
    score_now+=2;
    return 0;
}  
    
int print() {
    int i, j;
    for(i = 0; i < MAX; i++) {          
        for(j = 0; j < MAX; j++){
        	printf("|    ");
		}    
        printf("|\n");
        for(j = 0; j < MAX; j++) {    
            if(a[i][j] == 0)
                printf("|    ");
            else
                printf("|%-4d", a[i][j]);
        } 
        printf("|\n"); 
        for(j = 0; j < MAX; j++){
        	printf("|----");
		}     
        printf("|\n");
    }
    printf("Your score : %d\n",score_now);
}       

int move_up() {
	int result = 0;
	for(int j = 0;j<MAX;j++){
		for(int i = 0;i<MAX;i++){
			if(a[i][j]!=0){
				for(int k = i+1;k<MAX;k++){
					if(a[i][j]==a[k][j]){
						a[i][j]*=2;
						a[k][j] = 0;
						NUM++;
						i = k;
						result = 1;
						break;
					}
				}
			}
		}
		
		for(int i = 1;i<MAX;i++){
			if(a[i][j]!=0){
				for(int k = i;k>0&&a[k-1][j]==0;k--){
					a[k-1][j] = a[k][j];
					a[k][j] = 0;
					result = 1;
				}
			}
		}
	}
	return result;
}
int move_down() {
	int result = 0;	
	for(int j = 0;j<MAX;j++){
		for(int i = MAX-1;i>=0;i--){
			if(a[i][j]!=0){
				for(int k = i-1;k>=0;k--){
					if(a[i][j]==a[k][j]){
						a[i][j]*=2;
						a[k][j] = 0;
						NUM++;
						i = k;
						result = 1;
						break;
					}
				}
			}
		}
		
		for(int i = MAX-2;i>=0;i--){
			if(a[i][j]!=0){
				for(int k = i;k<MAX-1&&a[k+1][j]==0;k++){
					a[k+1][j] = a[k][j];
					a[k][j] = 0;
					result = 1;
				}
			}
		}
	}   
	return result;  
}

int move_left() {
	int result = 0;
	for(int j = 0;j<MAX;j++){
		for(int i = 0;i<MAX;i++){
			if(a[j][i]!=0){
				for(int k = i+1;k<MAX;k++){
					if(a[j][i]==a[j][k]){
						a[j][i]*=2;
						a[j][k] = 0;
						NUM++;
						i = k;
						result = 1;
						break;
					}
				}
			}
		}
		
		for(int i = 1;i<MAX;i++){
			if(a[j][i]!=0){
				for(int k = i;k>0&&a[j][k-1]==0;k--){
					a[j][k-1] = a[j][k];
					a[j][k] = 0;
					result = 1;
				}
			}
		}
	}
	return result;
}

int move_right() {
	int result = 0;
	for(int j = 0;j<MAX;j++){
		for(int i = MAX-1;i>=0;i--){
			if(a[j][i]!=0){
				for(int k = i-1;k>=0;k--){
					if(a[j][i]==a[j][k]){
						a[j][i]*=2;
						a[j][k] = 0;
						NUM++;
						i = k;
						result = 1;
						break;
					}
				}
			}
		}
		
		for(int i = MAX-2;i>=0;i--){
			if(a[j][i]!=0){
				for(int k = i;k<MAX-1&&a[j][k+1]==0;k++){
					a[j][k+1] = a[j][k];
					a[j][k] = 0;
					result = 1;
				}
			}
		}
	}    
	return result; 
}

int gen() {
    int num;
    int x, y;
    
    if(NUM > 0) {     
        srand(time(0));
        x = rand() % MAX;
        y = rand() % MAX;
        while(a[x][y] != 0){
        	x = rand() % MAX;
            y = rand() % MAX;
		}
        num = rand();
        int set = num % 2;
        if(set == 1){
        	a[x][y] = 2; 
        	score_now+=2;
		}    
        if(set == 0){
        	a[x][y] = 4;
        	score_now+=4; 
		} 
        NUM--;
    }

}

int play() {
    int move,result;
    char choise;
    move = getch();
    switch(move) {
        case 'w': case 'W':
            result = move_up(); 
            system("cls");
            if(result==1) gen(); 
            print();
            if(NUM==0&&result==0) {
            	C:printf("Gameover\n");
            	printf("Try again? (Y/N)\n");
            	choise = getch();
            	switch(choise){
            		case ('Y'): FLAG = 1;return 0;
            		case ('N'): FLAG = -1;return 0;
            		default: goto C;
				}
			}
            break;
        case 's': case 'S':
            result = move_down();
            system("cls");
            if(result==1) gen(); 
            print(); 
            if(NUM==0&&result==0) {
            	D:printf("Gameover\n");
            	printf("Try again? (Y/N)\n");
            	choise = getch();
            	switch(choise){
            		case ('Y'): FLAG = 1;return 0;
            		case ('N'): FLAG = -1;return 0;
            		default: goto D;
				}
			}
            break;
        case 'a': case 'A':
            result = move_left();
            system("cls");
            if(result==1) gen(); 
            print();
            if(NUM==0&&result==0) {
            	E:printf("Gameover\n");
            	printf("Try again? (Y/N)\n");
            	choise = getch();
            	switch(choise){
            		case ('Y'): FLAG = 1;return 0;
            		case ('N'): FLAG = -1;return 0;
            		default: goto E;
				}
			}
            break;
        case 'd': case 'D':
            result = move_right();
            system("cls");
            if(result==1) gen(); 
            print();
            if(NUM==0&&result==0) {
            	F:printf("Gameover\n");
            	printf("Try again? (Y/N)\n");
            	choise = getch();
            	switch(choise){
            		case ('Y'): FLAG = 1;return 0;
            		case ('N'): FLAG = -1;return 0;
            		default: goto F;
				}
			}
            break;
        case 'e': case 'E':
            FLAG = -1;
            return 0; 
        default:
            printf("Please enter W/w  A/a  S/s  D/d or E/e to exit\n");
            break;
    }
}      
 



int main() {
    char m;   
    A:FLAG = 0,score_now = 0; 
    printf("____________________________________________________________________________\n\n"); 
    printf("                                    2048                                    \n"); 
    printf("____________________________________________________________________________\n\n");
    printf("Rules: enter W/w  A/a  S/s  D/d to move or E/e to exit\n");
    printf("____________________________________________________________________________\n\n"); 
    printf("Please enter the size :(NOTE: size must be smaller than 9 and bigger than 1)\n"); 
    m = getch();
    MAX = m-'0';
    if(MAX>=10||MAX<=1) {
    	system("cls");
    	goto A;
    	
	}
    system("cls"); 
    start();
    print();
    while(1){
        play();
        if(FLAG == -1) break;
        if(FLAG == 1) {
        	system("cls");
        	goto A;
		}
  	}
    return 0;
} 



