#include <iostream>
#include <vector>

using namespace std;

const int boardSize = 10;

// Gönderilen koordinatlarda geminin bulunup bulunmadığını kontrol eder.
bool checkShip(vector<vector<int> >& board, int x, int y) {
    return board[x][y] == 1;
}

// Oyuncuya ait gemileri, ana matrise yerleştirir.
void placeShips(vector<vector<int> >& board, int player) {
    cout << "Oyuncu " << player << ", gemilerinizi yerleştirin:" << endl;
    for (int i = 0; i < 5; i++) {
        int x, y;
        cout << "Gemiyi koymak için x ve y koordinatlarını girin (0-9): ";
        cin >> x >> y;

        // Koordinatların geçerli olup olmadığını kontrol et
        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
            cout << "Geçersiz koordinat! Tekrar deneyin." << endl;
            i--; // Geçersiz giriş için döngüyü tekrarla
            continue;
        }

        // Aynı koordinata gemi yerleştirilmiş mi kontrol et
        if (board[x][y] == 1) {
            cout << "Bu koordinata zaten gemi yerleştirilmiş! Tekrar deneyin." << endl;
            i--; // Geçersiz giriş için döngüyü tekrarla
            continue;
        }

        board[x][y] = 1;
    }
}

// Matrisin son halini yazdırır.
void printBoard(vector<vector<int> >& board) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == -1) {
                cout << "X "; // Vurulan gemi
            } else if (board[i][j] == 0) {
                cout << "~ "; // Su
            } else {
                cout << "1 "; // Gemi (oyuncuya gösterilmez)
            }
        }
        cout << endl;
    }
}

// Tüm gemiler vuruldu mu kontrol eder.
bool allShipsSunk(vector<vector<int> >& board) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 1) {
                return false; // Vurulmamış gemi var
            }
        }
    }
    return true; // Tüm gemiler vuruldu
}

int main() {
    vector<vector<int> > player1Board(boardSize, vector<int>(boardSize, 0));
    vector<vector<int> > player2Board(boardSize, vector<int>(boardSize, 0));

    // Oyuncular gemilerini yerleştirir
    placeShips(player1Board, 1);
    placeShips(player2Board, 2);

    bool gameOver = false;
    int currentPlayer = 1;

    while (!gameOver) {
        int x, y;
        cout << "Oyuncu " << currentPlayer << ", saldırmak için x ve y koordinatlarını girin (0-9): ";
        cin >> x >> y;

        // Koordinatların geçerli olup olmadığını kontrol et
        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
            cout << "Geçersiz koordinat! Tekrar deneyin." << endl;
            continue;
        }

        // Saldırıyı gerçekleştir
        if (currentPlayer == 1) {
            if (checkShip(player2Board, x, y)) {
                cout << "Oyuncu 1, bir gemi vurdu!" << endl;
                player2Board[x][y] = -1;
            } else {
                cout << "Oyuncu 1, isabet etmedi!" << endl;
            }
            printBoard(player2Board); // Oyuncu 2'nin tahtasını göster
            if (allShipsSunk(player2Board)) {
                cout << "Oyuncu 1 kazandı! Tüm gemiler vuruldu." << endl;
                gameOver = true;
            }
        } else {
            if (checkShip(player1Board, x, y)) {
                cout << "Oyuncu 2, bir gemi vurdu!" << endl;
                player1Board[x][y] = -1;
            } else {
                cout << "Oyuncu 2, isabet etmedi!" << endl;
            }
            printBoard(player1Board); // Oyuncu 1'in tahtasını göster
            if (allShipsSunk(player1Board)) {
                cout << "Oyuncu 2 kazandı! Tüm gemiler vuruldu." << endl;
                gameOver = true;
            }
        }

        // Diğer oyuncuya sıra geçiş yapılır.
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}
