#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ejecutar()
{
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            grid[i][v] = new QLineEdit("caja" + i + v, this);
            grid[i][v]->setText("");
        }
    }
    ///suko = new SudokuLabels(grid);
}

void MainWindow::pintar()
{
    int posx = 90;
    int posy = 150;
    for (int i=0; i < 9; i++)
    {
        if (i%3 == 0)
            posy+= 20;
        for (int v=0; v < 9; v++)
        {
            if (v%3 == 0)
                posx+= 20;
            grid[i][v]->move(posx, posy);
            grid[i][v]->show();
            posx += 100;
        }
        posy += 40;
        posx = 90;
    }
}

void MainWindow::on_new_game_clicked()//funcion del boton new game
{
    cout << "voy a dormir..." << endl;
    sleep(1);
    cout << "woke up!" << endl;
    clean();
    switch (juego)
    {
    case 0:
        example1();
        break;
    case 1:
        example2();
        break;
    case 2:
        example3();
        break;
    }
    juego++;
    if (juego > 2)
        juego = 0;
    cout << juego << endl;
}

void MainWindow::example1()
{
    for (int i=0; i < 9; i++)
    {
        if (i == 0)
        {
            grid[i][2]->setText("6");
            grid[i][3]->setText("4");
            grid[i][4]->setText("8");
            grid[i][5]->setText("1");
            grid[i][6]->setText("3");
        }
        else if (i == 1)
        {
            grid[i][1]->setText("2");
            grid[i][7]->setText("4");
        }
        else if (i == 2)
        {
            grid[i][0]->setText("7");
            grid[i][8]->setText("9");
        }
        else if (i == 3)
        {
            grid[i][0]->setText("8");
            grid[i][4]->setText("9");
            grid[i][8]->setText("4");
        }
        else if (i == 4)
        {
            grid[i][0]->setText("6");
            grid[i][3]->setText("3");
            grid[i][4]->setText("4");
            grid[i][5]->setText("2");
            grid[i][8]->setText("1");
        }
        else if (i == 5)
        {
            grid[i][0]->setText("5");
            grid[i][4]->setText("6");
            grid[i][8]->setText("2");
        }
        else if (i == 6)
        {
            grid[i][0]->setText("3");
            grid[i][8]->setText("5");
        }
        else if (i == 7)
        {
            grid[i][1]->setText("9");
            grid[i][7]->setText("7");
        }
        else
        {
            grid[i][2]->setText("5");
            grid[i][3]->setText("7");
            grid[i][4]->setText("1");
            grid[i][5]->setText("6");
            grid[i][6]->setText("2");
        }
    }
}

void MainWindow::example2()
{
    ;
}

void MainWindow::example3()
{
    ;
}

void MainWindow::clean()
{
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            grid[i][v]->setText("");
            grid[i][v]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        }
    }
}

void MainWindow::colorClean()
{
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            grid[i][v]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        }
    }
}

void MainWindow::checkFila(int fila, int valor, bool igual)
{
    int temp;
    for (int i=0; i < 9; i++)
    {
        temp = grid[fila][i]->text().toInt();
        if (temp == 0)
            continue;
        if (valor == temp)
        {
            if (igual)
                grid[fila][i]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            else
                igual = true;
        }
    }
}

void MainWindow::checkColumna(int columna, int valor, bool igual)
{
    int temp;
    for (int i=0; i < 9; i++)
    {
        temp = grid[i][columna]->text().toInt();
        if (temp == 0)
            continue;
        if (valor == temp)
        {
            if (igual)
                grid[i][columna]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            else
                igual = true;
        }
    }
}

void MainWindow::checkCuadra(int cuadra, int valor)
{
    int fila, col;
    switch (cuadra)
    {
    case 0:
        fila = 0;
        col = 0;
        break;
    case 1:
        fila = 0;
        col = 3;
        break;
    case 2:
        fila = 0;
        col = 6;
        break;
    case 3:
        fila = 3;
        col = 0;
        break;
    case 4:
        fila = 3;
        col = 3;
        break;
    case 5:
        fila = 3;
        col = 6;
        break;
    case 6:
        fila = 6;
        col = 0;
        break;
    case 7:
        fila = 6;
        col = 3;
        break;
    case 8:
        fila = 6;
        col = 6;
        break;
    }
    for (int i=0; i < 3; i++)
    {
        for (int v=0; v < 3; v++)
        {
            if (valor == grid[fila + i][col + i]->text().toInt())
            {
                grid[fila+i][col+i]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            }
        }
    }
}

void MainWindow::on_Evaluate_clicked()//Funcion del boton evaluar
{
    colorClean();
    int valor;
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            valor = grid[i][v]->text().toInt();
            checkFila(i, valor, false);
            checkColumna(i, valor, false);
            //checkCuadra(i, v);
        }
    }
}
