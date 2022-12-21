#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* STRUCT */
typedef struct {
    char nama[40];
    int score;
} Player;

typedef struct {
    int board;
    int status;
} Game; 

typedef struct {
	int baris;
	int kolom;
} Papan;

/* DEKLARASI MODUL */
void mainMenu();
/*Modul ini digunakan untuk menampilkan Menu Utama yang berisi pilihan menu untuk masuk ke sub program selanjutnya
I.S : Main menu tidak tampil.
F.S : Main menu tampil dengan isi tampilan judul permainan “Seirios XOX” beserta pilihan angka untuk lanjut ke section / sub program selanjutnya.
*/
int readSelectMenu(int *x);
/*Modul ini digunakan untuk membaca inputan user pada main menu untuk menentukan sub program selanjutnya
I.S : Tidak diketahui sub program mana yang dipilih oleh user dan program tidak dapat melanjutkan ke sub program selanjutnya.
F.S : Terbaca angka yang diinputkan oleh user dan program dapat melanjutkan ke section berikutnya sesuai dengan yang dipilih oleh user.
*/
void howToPlay();
/*Modul ini digunakan untuk menampilkan petunjuk program permainan (aturan dan cara bermain)
I.S: Pemain tidak mengetahui cara bermain permainan SEIRIOS XOX
F.S : Pemain mengetahui cara bermain permainan SEIRIOS XOX
*/
void playGame();
/*Modul ini digunakan untuk menjalankan permainan SEIRIOS XOX
I.S : Permainan tic tac toe tidak dapat dijalankan 
F.S : Permainan dapat tic tac toe dapat dijalankan
*/
void inputNamePlayer();
/*Modul ini digunakan untuk menampung inputan nama Player 1 dan Player 2
I.S : Belum diketahui nama Player 1 dan Player 2
F.S : Mendapatkan nama Player 1 dan Player 2 dalam bentuk string
*/
void chooseBoard(Game *main);
/*Modul ini digunakan untuk menginput board berukuran 3x3 atau 5x5 atau 7x7
 I.S: Ukuran board belum terpilih
 F.S: Ukuran board terpilih
*/
void initialBoard(Game main);
/*Modul ini digunakan untuk inisialisasi board dengan kondisi 3x3 atau 5x5 atau 7x7
 I.S: Ukuran board belum memiliki elemen
 F.S: Board dengan ukuran 3x3 atau 5x5 atau 7x7 diisi dengan karakter spasi
 */
void displayBoard(Game main);
/*Modul ini digunakan untuk menampilkan board dengan ukuran diemensi 3x3 atau 5x5 atau 7x7
 I.S: Board belum tampil
 F.S: Board dengan ukuran 3x3 atau 5x5 atau 7x7 tampil di layar
*/
void inputIndex (Papan *indeks);
/*Modul ini digunakan untuk menginput index baris dan kolom dari kotak board yg ingin diisi simbol
 I.S: Index baris dan kolom belum dipilih
 F.S: Index baris dan kolom sudah dipilih
*/
void checkValid (Papan indeks);
/*Modul ini digunakan untuk mengecek kevalidan dari inputan user
 I.S: Simbol belum muncul di board
 F.S: Setelah mengecek kevalidan dari index baris dan kolom yang dipilih, simbol akan otomatis muncul di board sesuai index yang dipilih
*/
void checkWin (Game *main);
/*Modul ini digunakan untuk mengecek beberapa kemungkinan kemenangan yang akan terbentuk (vertikal, horizontal, diagonal)
 I.S: Belum diketahui kondisi-kondisi kemenangannya
 F.S: Apabila terdapat deretan simbol sebanyak 3/5/7 secara vertikal, diagonal, atau horizontal maka itu adalah pemenangnya
*/
void tambahScore (Game game);
/*Modul ini digunakan untuk menambah score yang dimiliki oleh pemain ketika pemain menang
 I.S: Score masih 0
 F.S: Apabila pemain menang, maka score akan bertambah menjadi 1
*/
void whoIsWinner (Player player1, Player player2);
/*Modul ini digunakan untuk menampilkan nama pemain yang menang
 I.S: Pemenang belum diketahui
 F.S: Nama pemain yang menang akan tampil di layar
*/
void displayWinner();
/*Modul ini digunakan untuk menampilkan tulisan Winner saat pemenang berhasil mencetak skor
I.S : Tulisan Winner tidak tampil pada layar
F.S : Muncul tulisan Winner pada layar ketika ada pemain yang berhasil mencetak skor
*/
char selectMenu(char *back);
/*Modul ini digunakan saat permainan selesai dan user ingin menghentikan permainan 
I.S : User tidak dapat menghentikan permainan dan akan tetap diam di section tersebut 
F.S : User dapat menghentikan permainan dan keluar dari program 
*/
void displayQuit();
/*Modul ini digunakan untuk menampilkan menu Quit
I.S : Menu Quit belum tampil layar
F.S : Muncul menu Quit bertuliskan “BYE” di layar
*/
void gotoxy(int x, int y);
/*Modul ini digunakan untuk menempatkan tampilan yang di print pada layer pada koordinat yang diinginkan 
I.S :  Tampilan pada layar tidak terletak pada koordinat yang diinginkan
F.S : Tampilan pada layar terletak pada koordinat yang diinginkan
*/
int timerAwal();
/*Modul ini digunakan untuk mencatat waktu awal
I.S : Waktu awal belum tercatat
F.S : Waktu awal sudah tercatat
*/
int timerAkhir();
/*Modul ini digunakan unntuk mencatat waktu akhir, yaitu ketika player menginput index kolom
I.S : Waktu akhir input belum tercatat
f.S : Waktu akhir input tercatat
*/

/* VARIABEL GLOBAL */
Player player1;
Player player2;
Game game;
Papan indeks;
char board[7][7];
int i, j;
int turn = 1;


/* PROGRAM UTAMA */
int main () { 
	int selectMenu;
	
	system ("cls");
	mainMenu(); 
	selectMenu = readSelectMenu(&selectMenu);
	    switch(selectMenu){
	        case 1 : system ("cls");
                    playGame();
	                break;
	        case 2 : system ("cls");
	                howToPlay();
	                break;
	        case 3 : displayQuit();
	                break;
	        default : printf("\nInvalid Input");          
	    }
    return 0;
}
 
/* BODY MODUL */
void gotoxy (int x, int y) {
    COORD coord; 
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

int readSelectMenu(int *x) {
	scanf("%d", &*x);
	return *x;
}

void mainMenu() {
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x"); 
     gotoxy(32, 2); printf ("o                                                       o"); 
     gotoxy(32, 3); printf ("x     *****  *****  *****  ****   *****  *****  *****   x");
     gotoxy(32, 4); printf ("o     *      *        *    *   *    *    *   *  *       o");
     gotoxy(32, 5); printf ("x     *      *        *    *   *    *    *   *  *       x");
     gotoxy(32, 6); printf ("o     *****  *****    *    ****     *    *   *  *****   o");
     gotoxy(32, 7); printf ("x         *  *        *    **       *    *   *      *   x");
     gotoxy(32, 8); printf ("o         *  *        *    * *      *    *   *      *   o");
     gotoxy(32, 9); printf ("x     *****  *****  *****  *  *   *****  *****  *****   x");
     gotoxy(32, 10); printf ("o                                                       o");
     gotoxy(32, 11); printf ("x                                                       x");
     gotoxy(32, 12); printf ("o               *     *   ******   *     *              o");
     gotoxy(32, 13); printf ("x                *   *    *    *    *   *               x");
     gotoxy(32, 14); printf ("o                 * *     *    *     * *                o");
     gotoxy(32, 15); printf ("x                  *      *    *      *                 x");
     gotoxy(32, 16); printf ("o                 * *     *    *     * *                o");
     gotoxy(32, 17); printf ("x                *   *    *    *    *   *               x");
     gotoxy(32, 18); printf ("o               *     *   ******   *     *              o");
     gotoxy(32, 19); printf ("x                                                       x");
     gotoxy(32, 20); printf ("o x o x o x o x o x o x o x o x o x o x o x o x o x o x o");                                          
     gotoxy(32, 22); printf (">>>>>>>>>>>>>>>>>>>>>>>> MAIN MENU <<<<<<<<<<<<<<<<<<<<<<");
     gotoxy(43, 24); printf ("            1. Start                               ");
     gotoxy(43, 25); printf ("            2. How To Play                         ");
     gotoxy(43, 26); printf ("            3. Quit                                ");
     gotoxy(43, 28); printf ("            SELECT MENU : ");
}

void howToPlay() {
	 char back;
	 int selectMenu;
     gotoxy(15, 1); printf ("=========================================================================================");
     gotoxy(15, 2); printf ("||                                                                                     ||");
     gotoxy(15, 3); printf ("||   *    *  ******  *       *    *******  ******    ******  *       ******  *     *   ||");
     gotoxy(15, 4); printf ("||   *    *  *    *  *       *       *     *    *    *    *  *       *    *  *     *   ||");
     gotoxy(15, 5); printf ("||   *    *  *    *  *       *       *     *    *    *    *  *       *    *  *     *   ||");
     gotoxy(15, 6); printf ("||   ******  *    *  *   *   *       *     *    *    ******  *       ******  *******   ||");
     gotoxy(15, 7); printf ("||   *    *  *    *  *  * *  *       *     *    *    *       *       *    *     *      ||");
     gotoxy(15, 8); printf ("||   *    *  *    *  * *   * *       *     *    *    *       *       *    *     *      ||");
     gotoxy(15, 9); printf ("||   *    *  ******  *       *       *     ******    *       ******  *    *     *      ||");
     gotoxy(15, 10); printf ("||                                                                                     ||");
     gotoxy(15, 11); printf ("=========================================================================================");
     gotoxy(15, 13); printf ("Before starting the game :");
     gotoxy (22, 14); printf ("1. Start the game with input the name of Player 1 and Player 2.");
     gotoxy (22, 15); printf ("2. Input the board size (3x3 / 5x5 / 7x7).");
     gotoxy (22, 16); printf ("3. The Player 1's symbol will be an X and the Player 2's symbol will be an O.");
     gotoxy (15, 17); printf ("When playing the game :");
     gotoxy (22, 18); printf ("1. Player 1 will take the first turn in the game.");
     gotoxy (22, 19); printf ("2. Enter the row index of the board you want to fill.");
     gotoxy (22, 20); printf ("3. Enter the column index of the board you want to fill.");
     gotoxy (25, 21); printf ("You can't select the coordinates that have been choosen before.");
     gotoxy (22, 22); printf ("4. After you input the coordinates, the symbol will automaticly show in board.");
     gotoxy (22, 23); printf ("5. Repeat the step alternately until one of the player make a row that contain 3 / 5 / 7 ");
     gotoxy (25, 24); printf ("symbol sequentially horizontally, vertically and diagonally.");
     gotoxy (15, 27); printf ("Back to menu (Y : yes) : ");

     scanf("%s", &back);
     if(back=='y' || back=='Y') {
        system("cls");
        main();
     } else {
        system("cls");
        howToPlay();  
     }
}

void playGame(){
	int win;
	char selectBack;
	char back;
	
	inputNamePlayer();
    system("cls");
    chooseBoard(&game);
    system("cls");
    initialBoard(game);
    
    while (game.status == 0) {
	    displayBoard(game);
	    inputIndex (&indeks);
	    checkValid (indeks);
	    checkWin (&game);
	    tambahScore(game);
	    displayBoard(game);
	}
	system("cls");
	whoIsWinner(player1, player2);
	selectBack = selectMenu(&back);
	if(selectBack=='y' || selectBack=='Y') {
        system("cls");
        displayQuit();
    } else {
        system ("cls");
        displayWinner();
        selectMenu(&back);
    }
}

void inputNamePlayer() {
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x "); 
     gotoxy(32, 2); printf ("o                                                   o"); 
     gotoxy(32, 3); printf ("x         *   *     *   ***    *   *   *****        x");
     gotoxy(32, 4); printf ("o         *   * *   *   *  *   *   *     *          o");
     gotoxy(32, 5); printf ("x         *   *   * *   ***    *   *     *          x");
     gotoxy(32, 6); printf ("o         *   *     *   *      *   *     *          o");
     gotoxy(32, 7); printf ("x         *   *     *   *        *       *          x");
     gotoxy(32, 8); printf ("o                                                   o");
     gotoxy(32, 9); printf ("x     ***     *      ****   *   *   ****   ****     x");
     gotoxy(32, 10); printf ("o     *   *   *      *  *   *   *   *      *  *     o");
     gotoxy(32, 11); printf ("x     ***     *      ****    ***    ****   ****     x");
     gotoxy(32, 12); printf ("o     *       *      *  *     *     *      * *      o");
     gotoxy(32, 13); printf ("x     *       ****   *  *     *     ****   *   *    x");
     gotoxy(32, 14); printf ("o                                                   o");
     gotoxy(32, 15); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x");       
     gotoxy(32, 18); printf ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	 gotoxy(32, 19); printf ("\xba    Player 1     \xba                                 \xba");
     gotoxy(32, 20); printf ("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9");
	 gotoxy(32, 21); printf ("\xba    Player 2     \xba                                 \xba");
     gotoxy(32, 22); printf ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
     getchar();
     gotoxy(52, 19); scanf ("%[^\n]", player1.nama);
     getchar();
     gotoxy(52, 21); scanf ("\n%[^\n]", player2.nama);
}

void chooseBoard(Game *game) {
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x"); 
     gotoxy(32, 2); printf ("o                                                           o"); 
     gotoxy(32, 3); printf ("x         ****  *   *   ****    ****    ****   *****        x");
     gotoxy(32, 4); printf ("o        *      *   *  *    *  *    *  *       *            o");
     gotoxy(32, 5); printf ("x        *      *****  *    *  *    *   ****   *****        x");
     gotoxy(32, 6); printf ("o        *      *   *  *    *  *    *       *  *            o");
     gotoxy(32, 7); printf ("x         ****  *   *   ****    ****    ****   *****        x");
     gotoxy(32, 8); printf ("o                                                           o");
     gotoxy(32, 9); printf ("x         *****     ****    ******   *****    *****         x");
     gotoxy(32, 10); printf ("o         *    *   *    *   *    *   *    *   *    *        o");
     gotoxy(32, 11); printf ("x         *****   *      *  ******   *****    *    *        x");
     gotoxy(32, 12); printf ("o         *    *   *    *   *    *   *    *   *    *        o");
     gotoxy(32, 13); printf ("x         *****     ****    *    *   *     *  *****         x");
     gotoxy(32, 14); printf ("o                                                           o");
     gotoxy(32, 15); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x");  

     
     gotoxy(52, 18); printf ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
     gotoxy(52, 19); printf ("\xba     Choose Board    \xba");
     gotoxy(52, 20); printf ("\xba       1. 3x3        \xba");
	 gotoxy(52, 21); printf ("\xba       2. 5x5        \xba");
	 gotoxy(52, 22); printf ("\xba       3. 7x7        \xba");
     gotoxy(52, 23); printf ("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcc");
     gotoxy(52, 24); printf ("\xba     Input :         \xba");
	 gotoxy(52, 25); printf ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
     gotoxy(68, 24); scanf ("%d", &(*game).board);
}    

void initialBoard(Game game) {
	if (game.board == 1) {
		for (i = 0; i < 3; i++) {
	            for (j = 0; j < 3; j++) {
	                board[i][j] = ' ';
	            }
	    }
	} else if (game.board == 2) {
		for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                board[i][j] = ' ';
            }
		}
	} else if (game.board == 3) {
        	for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                board[i][j] = ' ';
            }
        }
		}
}

void displayBoard(Game game) {
	if (game.board == 1) {
		system("cls");
            printf("\n");
            printf("        column\n");
            printf("       0   1   2\n");
            printf("      ___ ___ ___ \n");
            printf("     | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
            printf("   0 |___|___|___|\n");
            printf("     | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
            printf("   1 |___|___|___|\n");
            printf("     | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
            printf("   2 |___|___|___|\n");
            printf("  row\n");
	} else if (game.board == 2) {
		system("cls");
            printf("\n");
            printf("             column\n");
            printf("       0   1   2   3   4\n");
            printf("      ___ ___ ___ ___ ___ \n");
            printf("     | %c | %c | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4]);
            printf("   0 |___|___|___|___|___|\n");
            printf("     | %c | %c | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4]);
            printf("   1 |___|___|___|___|___|\n");
            printf("     | %c | %c | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4]);
            printf("   2 |___|___|___|___|___|\n");
            printf("     | %c | %c | %c | %c | %c |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4]);
            printf("   3 |___|___|___|___|___|\n");
            printf("     | %c | %c | %c | %c | %c |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4]);
            printf("   4 |___|___|___|___|___|\n");
            printf("  row\n");
	} else if (game.board == 3) {
        system("cls");
            printf("\n");
            printf("                    column\n");
            printf("        0    1    2    3    4    5    6  \n");
            printf("      ____ ____ ____ ____ ____ ____ ____ \n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]);
            printf("   0 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6]);
            printf("   1 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6]);
            printf("   2 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6]);
            printf("   3 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6]);
            printf("   4 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6]);
            printf("   5 |____|____|____|____|____|____|____|\n");
            printf("     | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6]);
            printf("   6 |____|____|____|____|____|____|____|\n");
            printf("  row\n");
	}
}

void inputIndex (Papan *indeks) {
	int time=timerAwal();
	printf(" Input row : ");
    scanf("%d", &(*indeks).baris);
    printf(" Input column : ");
    scanf("%d", &(*indeks).kolom);
    time=timerAkhir()-time;
    
    if(((double)time)/CLOCKS_PER_SEC > 10 && turn==1){
        turn=2;
	}else if(((double)time)/CLOCKS_PER_SEC > 10 && turn==2){
		turn=1;
	}
}

void checkValid (Papan indeks) {
	if (indeks.baris >= 0 && indeks.baris < 7 && indeks.kolom >= 0 && indeks.kolom < 7 && board[indeks.baris][indeks.kolom] == ' ') {
        if (turn == 1) {
            board[indeks.baris][indeks.kolom] = 'X';
            turn = 2;
        } else {
            board[indeks.baris][indeks.kolom] = 'O';
            turn = 1;
        }
    }
}

void checkWin (Game *game) {
    if ((*game).board == 1) {
		//cek win secara diagonal
	    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || 
	        (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
	        (*game).status = 1;
	    } 
	    //cek win secara horizontal dan vertikal
	    for (i = 0; i < 3; i++) {
	        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') || 
	            (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')) {
	            (*game).status = 1;
	        } 
	    }
	} else if ((*game).board == 2) {
		//cek win diagonal
        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4] && board[0][0] != ' ') ||
            (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] == board[4][0] && board[0][4] != ' ')) {
            (*game).status = 1;
        }
        //cek win secara vertikal
        for (i = 0; i < 5; i++) {
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] && board[0][i] != ' ')) {
                (*game).status = 1;
            }
        }
	} else if ((*game).board == 3) {
		//cek win diagonal
		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4] && board[0][0] == board[5][5] && board[0][0] == board[6][6] && board[0][0] != ' ') ||
            (board[0][6] == board[1][5] && board[0][6] == board[2][4] && board[0][6] == board[3][3] && board[0][6] == board[4][2] && board[0][6] == board[5][1] && board[0][6] == board[6][0] && board[0][6] != ' ')) {
            (*game).status = 1;
        }
        //cek win secara vertikal
        for (i = 0; i < 7; i++) {
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4] && board[i][0] == board[i][5] && board[i][0] == board[i][6] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] && board[0][i] == board[5][i] && board[0][i] == board[6][i] && board[0][i] != ' ')) {
                (*game).status = 1;
            }
        }
	}
}

void tambahScore (Game game) {
	player1.score = 0;
	player2.score = 0;
	
	if (game.status == 1 && turn == 1) {
		player2.score = player2.score + 1;
	} else if (game.status == 1 && turn == 2) {
		player1.score = player1.score + 1;
	} 
}

void whoIsWinner (Player player1, Player player2) {
	if (turn == 1) {
        displayWinner();
        printf("\t\t\t\t\t\tCONGRATS >>>%s<<<, YOU WIN !!\n\n", player2.nama);
        printf("\t\t\t\t\t\t   %s : %d", player2.nama, player2.score); 
        printf("\t\t\t\t\t\t   %s : %d", player1.nama, player1.score);
        
	} else {
        displayWinner();
        printf("\t\t\t\t\t\tCONGRATS >>>%s<<<, YOU WIN !!\n\n", player1.nama);
        printf("\t\t\t\t\t\t   %s : %d", player1.nama, player1.score); 
        printf("\t\t\t\t\t\t   %s : %d", player2.nama, player2.score);
    }
}

void displayWinner(){
  system("cls");
     gotoxy(32, 9); printf ("*           *  ***  **       *  **       *  *******  ****** ");
     gotoxy(32,10); printf ("*           *   *   * *      *  * *      *  *        *     *");
     gotoxy(32,11); printf ("*           *   *   *   *    *  *   *    *  *        *     *");
     gotoxy(32,12); printf ("*    **     *   *   *    *   *  *    *   *  *        *     *");
     gotoxy(32,13); printf ("*   *  *    *   *   *     *  *  *     *  *  *******  ****** ");
     gotoxy(32,14); printf ("*  *    *   *   *   *      * *  *      * *  *        **    ");
     gotoxy(32,15); printf ("* *       * *   *   *       **  *       **  *        * *   ");
     gotoxy(32,16); printf ("**         **   *   *        *  *        *  *        *  * ");
     gotoxy(32,17); printf ("*           *  ***  *        *  *        *  *******  *    *");
     printf("\n\n");  
}

char selectMenu(char *back){
	printf("\n\n");
	gotoxy (20, 25); printf ("End Game? (Y : yes) : ");
	scanf("%s", &*back);
	
	return *back;
}

void displayQuit(){
    system("cls");
     gotoxy(32, 9); printf ("******  *         *  *******       *    *    *");
     gotoxy(32,10); printf ("*     *  *       *   *             *    *    *");
     gotoxy(32,11); printf ("*     *   *     *    *             *    *    *");
     gotoxy(32,12); printf ("*     *    *   *     *             *    *    *");
     gotoxy(32,13); printf ("*****       ***      *******       *    *    *");
     gotoxy(32,14); printf ("*     *      *       *             *    *    *");
     gotoxy(32,15); printf ("*     *      *       *             *    *    *");
     gotoxy(32,16); printf ("*     *      *       *                        ");
     gotoxy(32,17); printf ("******       *       *******       *    *    *");
     printf("\n\n");
}

int timerAwal(){
	clock_t jamAwal;
	jamAwal=clock();
	return jamAwal;
}

int timerAkhir(){
	clock_t jamAkhir;
	jamAkhir=clock();
	return jamAkhir;
}
