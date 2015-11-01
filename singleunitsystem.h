#ifndef SINGLEUNITSYSTEM_H
#define SINGLEUNITSYSTEM_H

#include "intmatrix.h"

/*Виконує задачу як однопроцесорна система.*/
class SingleUnitSystem
{
public:
    /*Конструктор за замовченням.*/
    SingleUnitSystem();

    /*Виконує додавання матриць.*/
    IntMatrix Add(const IntMatrix& left, const IntMatrix& right);

    /*Виконує множення матриць.*/
    IntMatrix Multiplicate(const IntMatrix& left, const IntMatrix& right);

    /*Виконує транспонування матриці.*/
    IntMatrix Transpose(const IntMatrix& source);
};

#endif // SINGLEUNITSYSTEM_H
