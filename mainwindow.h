#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <unistd.h>

#include <QMainWindow>

#include "sudokulabels.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ///SudokuLabels* suko; Nunca lo utilizo
    QLineEdit* grid[9][9];
    void ejecutar();// Esta funcion crea el arreglo bidimensional de los QLineEdit (osea los cuadritos)
    void pintar();//Esta funcion es el que los pinta en la pantalla (tipo .setVisible)
    void example1();/* */
    void example2();/* Estas 3 deben ser 3 sudoku's diferentes, pero example2 y example 3 estan vacios */
    void example3();/**/
    void clean();//Esta funcion quita los numeros de todos los cuadritos
    void colorClean();//Esta funcion quita los colores de los cuadritos (osea los vuelve a pintar blancos)
    void checkFila(int, int, bool);// Si se repite en la misma fila, pinta ROJO
    void checkColumna(int, int, bool);// Si se repite en la misma columna, pinta ROJO
    void checkCuadra(int, int, bool);// Si se repite en la misma fila, pinta AZUL
    int juego = 0;

private slots:
    void on_new_game_clicked();//boton nuevo juego

    void on_Evaluate_clicked();//boton evaluar

    void on_Solve_clicked();//boton resolver

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
