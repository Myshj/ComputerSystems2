#include "unitswithlocalmemory.h"
#include "iostream"


void DoAddition(UnitsWithLocalMemorySystem& target){
    while(true){
        unsigned int row = target.GetNextUndoneRow();

        if(-1 == row){
            return;
        }

        for(unsigned int col = 0; col < target.result.GetColCount(); col++){
            cout << "Adding: " << 100 * (row*target.result.GetColCount() + col) / (target.result.GetRowCount() * target.result.GetColCount()) << endl;
            target.result.SetAt(row, col, target.result.GetAt(row, col) + target.right->GetAt(row, col));
        }
    }
}

void DoMultiplication(UnitsWithLocalMemorySystem& target){
    while(true){
        unsigned int row = target.GetNextUndoneRow();

        if(-1 == row){
            return;
        }

        for(unsigned int col = 0; col < target.result.GetColCount(); col++){
            cout << "Multiplicating: " << 100 * (row*target.result.GetColCount() + col) / (target.result.GetRowCount() * target.result.GetColCount()) << endl;
            //target.result.SetAt(row, col, target.result.GetAt(row, col) + target.right->GetAt(row, col));
            unsigned int newElement = 0;
            for(unsigned int r = 0; r < target.left->GetColCount(); r++){
                newElement += target.left->GetAt(row, r) * target.right->GetAt(r, col);
            }
            target.result.SetAt(row, col, newElement);
        }
    }
}

void DoTransposition(UnitsWithLocalMemorySystem& target){
    while(true){
        unsigned int row = target.GetNextUndoneRow();

        if(-1 == row){
            return;
        }

        for(unsigned int col = 0; col < target.result.GetColCount(); col++){
            cout << "Transposing: " << 100 * (row*target.result.GetColCount() + col) / (target.result.GetRowCount() * target.result.GetColCount()) << endl;
            //target.result.SetAt(row, col, target.result.GetAt(row, col) + target.right->GetAt(row, col));
            target.result.SetAt(row, col, target.left->GetAt(col, row));
        }
    }
}

UnitsWithLocalMemorySystem::UnitsWithLocalMemory()
{

}

/*Виконує додавання матриць.*/
IntMatrix UnitsWithLocalMemorySystem::Add(IntMatrix &left, IntMatrix &right)
{
    result = left;
    if(!left.SizesAreEqual(right) || isWorking){
        return IntMatrix();
    }

    isWorking = true;
    this->left = &left;
    this->right = &right;

    for(unsigned int row = 0; row < result.GetRowCount(); row++){
        undoneRows.push_back(row);
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads.push_back(thread(DoAddition, std::ref(*this)));
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads[unit].join();
    }

    threads.clear();

    isWorking = false;

    cout << "Finished addition!" << endl;
    return result;
}

/*Виконує множення матриць.*/
IntMatrix UnitsWithLocalMemorySystem::Multiplicate(IntMatrix &left, IntMatrix &right)
{
    result = IntMatrix(left.GetRowCount(), right.GetColCount());
    if((left.GetColCount() != right.GetRowCount()) || isWorking){
        return IntMatrix();
    }

    isWorking = true;
    this->left = &left;
    this->right = &right;

    for(unsigned int row = 0; row < result.GetRowCount(); row++){
        undoneRows.push_back(row);
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads.push_back(thread(DoMultiplication, std::ref(*this)));
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads[unit].join();
    }

    threads.clear();

    isWorking = false;

    cout << "Finished multiplication!" << endl;
    return result;
}

/*Виконує транспонування матриці.*/
IntMatrix UnitsWithLocalMemorySystem::Transpose(IntMatrix &source)
{
    result = IntMatrix(source.GetColCount(), source.GetRowCount());
    if(isWorking){
        return IntMatrix();
    }

    isWorking = true;
    this->left = &source;

    for(unsigned int row = 0; row < result.GetRowCount(); row++){
        undoneRows.push_back(row);
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads.push_back(thread(DoTransposition, std::ref(*this)));
    }

    for(unsigned short int unit = 0; unit < countOfUnits; unit++){
        threads[unit].join();
    }

    threads.clear();

    isWorking = false;

    cout << "Finished transposition!" << endl;
    return result;
}

/*Встановлює кількість процесорних елементів, що працюватимуть над задачею.*/
void UnitsWithLocalMemorySystem::SetCountOfUnits(unsigned short newCountOfUnits)
{
    if(!isWorking){
        countOfUnits = newCountOfUnits;
    }
}

/*Отримує номер наступного вільного рядка.*/
int UnitsWithLocalMemorySystem::GetNextUndoneRow()
{
    m.lock();
    if(undoneRows.empty()){
        m.unlock();
        return -1;
    }
    unsigned int row = undoneRows.back();
    undoneRows.pop_back();
    m.unlock();
    return row;
}






