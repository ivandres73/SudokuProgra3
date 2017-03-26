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
    ///SudokuLabels* suko;
    QLineEdit* grid[9][9];
    void ejecutar();
    void pintar();
    void example1();
    void example2();
    void example3();
    void clean();
    void colorClean();
    void checkFila(int, int, bool);
    void checkColumna(int, int, bool);
    void checkCuadra(int, int);
    int juego = 0;

private slots:
    void on_new_game_clicked();

    void on_Evaluate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
