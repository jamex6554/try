#include <iostream>

#include <cstdlib>

#include <cstdio>

#include <string>

#include <fstream>

#include <ctime>



using namespace std;



class Sudoku

{

public:

    Sudoku();

    void GiveQuestion();

    void ReadIn();

    void Solve();

    void sol();

    int Judge_Row(int k,int i);

    int Judge_Column(int k,int j);

    int Judge_Square(int k,int i,int j);



private:

    int original[12][12],inspect[12][12],number,record;

};
