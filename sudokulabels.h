#ifndef SUDOKULABELS_H
#define SUDOKULABELS_H
#include <QTextEdit>
#include <iostream>

using namespace std;


class SudokuLabels //Esta clase no sirve !!, nunca la utilizo ! !
{
public:
    SudokuLabels(QTextEdit* lab[9][9]);
    QTextEdit* grid[81];

    void fillgrid();
    void showgrid();
};

#endif // SUDOKULABELS_H
