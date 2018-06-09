#include <stdio.h>
#include <stdlib.h>     
#include <time.h>             
#include <windows.h>
#include <conio.h>
int MAX; 
int FLAG;  
int a[11][11];
int NUM;
int start() {
	for(int i = 0;i<MAX;i++)
		for(int j = 0;j<MAX;j++) 
			a[i][j] = 0;
	NUM = MAX*MAX-1;
    srand(time(0));
    int x = rand()%MAX;
    int y = rand()%MAX;        
    a[x][y] = 2;
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
        	printf("|____");
		}     
        printf("|\n");
    }
}       

int move_up() {
    int x, y, i;
    for(y = 0; y < MAX; y++) {     
        for(x = 0; x < MAX; x++) {
            if(a[x][y] != 0){
                for(i = x + 1; i < MAX; i++) {
                    if(a[i][y] == 0)
                        ;
                    else if(a[x][y] == a[i][y]) {
                        a[x][y] += a[i][y];
                        a[i][y] = 0;
                        NUM++;
                        x = i;
                        break;
                    }
                    else {
                        break;
                    }
                } 
            }
        }
    }

    for(y = 0; y < MAX; ++y)   
        for(x = 0; x < MAX; ++x) {
            if(a[x][y] != 0) {
                for(i = x; (i > 0) && (a[i - 1][y] == 0); i--) {
                    a[i - 1][y] = a[i][y];
                    a[i][y] = 0;
                }
            }
        }
}
int move_down() {
    int x, y, i;
    
    for(y = 0; y < MAX; ++y) 
        for(x = MAX-1; x >= 0; --x) {
            if(a[x][y] != 0){
                for(i = x - 1; i >= 0; --i) {
                    if(a[i][y] == 0)
                        ;
                    else if(a[x][y] == a[i][y]) {
                        a[x][y] += a[i][y];
                        a[i][y] = 0;
                        NUM++;
                        x = i;
                        break;
                    }
                    else
                        break;
                }
            }
        }
        
    for(y = 0; y < MAX; ++y)  
        for(x = MAX-1; x >= 0; --x) {
           	if(a[x][y] != 0) {
                for(i = x; (i < MAX-1) && (a[i + 1][y] == 0); ++i) {
                    a[i + 1][y] = a[i][y];
                    a[i][y] = 0;
                }
            }
        }        
}

int move_left() {
    int x, y, i;
    
    for(x = 0; x < MAX; ++x)  
        for(y = 0; y < MAX; ++y) {
            if(a[x][y] != 0){
                for(i = y + 1; i < MAX; ++i) {
                    if(a[x][i] == 0)
                        ;
                    else if(a[x][y] == a[x][i]) {
                        a[x][y] += a[x][i];
                        a[x][i] = 0;
                        NUM++;
                        y = i;
                        break;
                    }
                    else
                        break;
                }
            }
        }
        
    for(x = 0; x < MAX; ++x)  
        for(y = 0; y < MAX; ++y) {
            if(a[x][y] != 0){
                for(i = y; (i > 0) && (a[x][i - 1] == 0); --i) {
                    a[x][i - 1] = a[x][i];
                    a[x][i] = 0;
                }
            }
        }
}

int move_right() {
    int x, y, i;
    
    for(x = 0; x < MAX; ++x)  
        for(y = MAX-1; y >= 0; --y) {
            if(a[x][y] != 0){
                for(i = y - 1; i >= 0; --i) {
                    if(a[x][i] == 0)
                        ;
                    else if(a[x][y] == a[x][i]) {
                        a[x][y] += a[x][i];
                        a[x][i] = 0;
                        NUM++;
                        y = i;
                        break;
                    }
                    else
                        break;
                }
            }
        } 
        
    for(x = 0; x < MAX; ++x)   
        for(y = MAX-1; y >= 0; --y) {
            if(a[x][y] != 0){
                for(i = y; (i < MAX-1) && (a[x][i + 1] == 0); ++i) {
                    a[x][i + 1] = a[x][i];
                    a[x][i] = 0;
                }
            }
        }
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
        if(set == 1)   
            a[x][y] = 2; 
        if(set == 0) 
            a[x][y] = 4;
        NUM--;
    }

}

int play() {
    int move;
    char choise;
    move = getch();
    switch(move) {
        case 'w': case 'W':
            move_up(); 
            system("cls");
            gen(); 
            print();
            if(NUM==0) {
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
            move_down();
            system("cls");
            gen(); 
            print(); 
            if(NUM==0) {
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
            move_left();
            system("cls");
            gen(); 
            print();
            if(NUM==0) {
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
            move_right();
            system("cls");
            gen(); 
            print();
            if(NUM==0) {
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
    A:FLAG = 0; 
    printf("____________________________________________________________________________\n"); 
    printf("                                    2048                                    \n"); 
    printf("____________________________________________________________________________\n");
    printf("Rules: enter W/w  A/a  S/s  D/d to move or E/e to exit\n");
    printf("____________________________________________________________________________\n"); 
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



