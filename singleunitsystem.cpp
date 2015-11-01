#include "singleunitsystem.h"
#include "iostream"

SingleUnitSystem::SingleUnitSystem()
{

}

/*Виконує додавання матриць.*/
IntMatrix SingleUnitSystem::Add(const IntMatrix &left, const IntMatrix& right)
{
    IntMatrix ret = left;
    if(!left.SizesAreEqual(right)){
        return IntMatrix();
    }

    for(unsigned int row = 0; row < ret.GetRowCount(); row++){
        for(unsigned int col = 0; col < ret.GetColCount(); col++){
            ret.SetAt(row, col, ret.GetAt(row, col) + right.GetAt(row, col));
            cout << "Adding: " << 100 * (row*ret.GetColCount() + col) / (ret.GetRowCount() * ret.GetColCount()) << '%' << endl;
        }
    }

    return ret;
}

/*Виконує множення матриць.*/
IntMatrix SingleUnitSystem::Multiplicate(const IntMatrix &left, const IntMatrix &right)
{
    IntMatrix ret;
    if(left.GetColCount() != right.GetRowCount()){
        return ret;
    }

    ret = IntMatrix(left.GetRowCount(), right.GetColCount());

    for(unsigned int row = 0; row < ret.GetRowCount(); row++){
        for(unsigned int col = 0; col < ret.GetColCount(); col++){
            cout << "Multiplicating: " << 100 * (row*ret.GetColCount() + col) / (ret.GetRowCount() * ret.GetColCount()) << '%' << endl;

            unsigned int newElement = 0;
            for(unsigned int r = 0; r < left.GetColCount(); r++){
                newElement += left.GetAt(row, r) * right.GetAt(r, col);
            }
            ret.SetAt(row, col, newElement);
        }
    }

    return ret;
}

/*Виконує транспонування матриці.*/
IntMatrix SingleUnitSystem::Transpose(const IntMatrix &source)
{
    IntMatrix ret = IntMatrix(source.GetColCount(), source.GetRowCount());

    for(unsigned int row = 0; row < ret.GetRowCount(); row++){
        for(unsigned int col = 0; col < ret.GetColCount(); col++){
            ret.SetAt(row, col, source.GetAt(col, row));
            cout << "Transposing: " << 100 * (row*ret.GetColCount() + col) / (ret.GetRowCount() * ret.GetColCount()) << '%' << endl;
        }
    }

    return ret;
}

