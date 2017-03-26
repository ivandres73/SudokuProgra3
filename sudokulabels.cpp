#include "sudokulabels.h"

SudokuLabels::SudokuLabels(QTextEdit* lab[9][9])
{
    int a = 0;
    for (int i=0; i<9; i++)
    {
        for (int v=0; v<9; v++)
        {
            cout << a << " - ";
            grid[a++] = lab[0][0];
            cout << a << endl;
        }
    }
}

void SudokuLabels::fillgrid()
{
    QString caca;
    for (int i=0; i<81; i++)
    {
        //caca = grid[i]->text();
        //cout << caca << endl;
    }
}

void SudokuLabels::showgrid()
{
//    for (int i=0; i<10; i++)
//    {
//        for (int v=0; v<10; v++)
//        {
//            grid[i][v]->show();
//        }
//    }
}
