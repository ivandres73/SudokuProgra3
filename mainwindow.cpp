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

void MainWindow::ejecutar()//basicamente aqui se crea el arreglo
{
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            grid[i][v] = new QLineEdit("caja" + i + v, this);
            grid[i][v]->setText("");
            grid[i][v]->setValidator(new QIntValidator(1, 9, this));
        }
    }
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
                posx+= 20;// Cada 3 QLineEdits los separa mas, para que se miren 9 cuadras 3x3
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
    clean();
    switch (juego)
    {
    case 0:
        example1();//Este es el primer juego, es el unico que tiene por ahora
        break;
    case 1:
        example2();///vacio
        break;
    case 2:
        example3();///vacio
        break;
    }
    juego++;
    if (juego > 2)
        juego = 0;
}

void MainWindow::example1()//Esos numeros con esas posiciones las saque de internet
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
            grid[i][v]->setText("");//vacio los QLine
            grid[i][v]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");//Pinta los QLineEdits en blanco
        }
    }
}

void MainWindow::colorClean()
{
    for (int i=0; i < 9; i++)
    {
        for (int v=0; v < 9; v++)
        {
            grid[i][v]->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");//Solo pinta de blanco si vaciar los numeros
        }
    }
}

short MainWindow::checkFila(int fila, int valor, bool igual)
{
    short repetidos = 0;
    int temp;
    for (int i=0; i < 9; i++)
    {
        temp = grid[fila][i]->text().toInt();//Aqui agarra el valor del QLineEdit
        if (temp == 0)//Esto es porque si el QLineEdit esta vacio me agarra el 0, pero en el juego sudoku nunca se usa el 0
            continue;
        if (valor == temp)
        {
            if (igual)//Este buleano es para que pinte si encuentra el mismo numero 2 o mas veces.
            {
                grid[fila][i]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
                repetidos += 1;
            }
            else
                igual = true;
        }
    }
    return repetidos;
}

short MainWindow::checkColumna(int columna, int valor, bool igual)//Misma logica que el checkColumna basicamente
{
    short repetidos = 0;
    int temp;
    for (int i=0; i < 9; i++)
    {
        temp = grid[i][columna]->text().toInt();
        if (temp == 0)
            continue;
        if (valor == temp)
        {
            if (igual)
            {
                grid[i][columna]->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
                repetidos += 1;
            }
            else
                igual = true;
        }
    }
    return repetidos;
}

short MainWindow::checkCuadra(int cuadra, int valor, bool igual)
{
    short repetidos;
    int fila, col;
    switch (cuadra)//Este pijasal de cases es para ser precisos en la cuadra en que este, son 9 cuadras 3x3
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
            if (valor == grid[fila + i][col + v]->text().toInt())
            {
                if (igual)
                {
                    grid[fila+i][col+v]->setStyleSheet("QLineEdit { background: rgb(0, 255, 255); }");//Lo pintat de AZUL
                    repetidos += 1;
                }
                else
                {
                    igual = true;
                }
            }
        }
    }
    return repetidos;
}

void MainWindow::on_Evaluate_clicked()//Funcion del boton evaluar
{
    colorClean();
    int valor;
    int cuadra;
    for (int i=0; i < 9; i++)
    {
        cuadra = 0;
        if (i >= 3 && i <= 5)
            cuadra = 3;
        else if (i > 5)
            cuadra = 6;
        for (int v=0; v < 9; v++)
        {
            if (v == 3)
                cuadra += 1;
            if (v == 6)
                cuadra += 1;
            valor = grid[i][v]->text().toInt();
            if (valor == 0)
                continue;
            checkFila(i, valor, false);
            checkColumna(v, valor, false);
            checkCuadra(cuadra, valor, false);
        }
    }
}

void MainWindow::on_Solve_clicked()//Falta terminar este metodo
{
    int cuadra;
    int valor = 0;
    for (int i=0; i < 9; i++)
    {
        cuadra = 0;
        if (i >= 3 && i <= 5)
            cuadra = 3;
        else if (i > 5)
            cuadra = 6;
        for (int v=0; v < 9; v++)
        {
            if (v == 3)
                cuadra += 1;
            if (v == 6)
                cuadra += 1;
            if (grid[i][v]->text() != "")
                continue;
            for (int aux = 1; aux < 10; aux++)
            {
                valor++;
                if (valor == 10)
                    valor = 1;
                grid[i][v]->setText(toString(valor));
                if (checkFila(i, valor, false) == 0)
                {
                    if (checkColumna(v, valor, false) == 0)
                    {
                        if (checkCuadra(cuadra, valor, false) == 0)
                        {
                            colorClean();
                            cout << v << endl;
                            break;
                            //sleep(2);
                        }
                    }
                }
                grid[i][v]->setText("");
            }
        }
    }
}

QString MainWindow::toString(int number)
{
    if (number == 0)
        return "0";
    if(number < 0)
        return "-"+toString(-number);
    QString temp="";
    QString returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}//cortesia de ahmed
