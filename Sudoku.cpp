#include "Sudoku.h"
#include <stdio.h>




    Sudoku::Sudoku()

    {

        record=0;

    }



    void Sudoku::GiveQuestion()

    {

        srand(time(NULL));

        int i,j;

        int arrays[9][9];

        for (i=0; i<9; i++)

        {

            for(j=0;j<9;j++)

            {

                arrays[i][j]=0;

            }

        }





        for(i=0;i<9;i++)

        {

            arrays[0][i]=(rand()%9)+1;

            for(j=0;j<i;j++)

            {

                if(arrays[0][j]==arrays[0][i])

                {

                    i=i-1;

                }

            }

        }



        for(i=0;i<9;i++){

            arrays[3][i]=arrays[0][(i+1)%3+(i/3)*3];



        }

        for (i=0; i<9; i++) {

            arrays[6][i]=arrays[3][(i+1)%3+(i/3)*3];

        }

        for(i=0;i<9;i++){

            arrays[1][(i+3)%9]=arrays[0][i];

        }

        for(i=0;i<9;i++){

            arrays[2][(i+3)%9]=arrays[1][i];

        }

        for(i=0;i<9;i++){

            arrays[4][(i+3)%9]=arrays[3][i];

        }

        for(i=0;i<9;i++){

            arrays[5][(i+3)%9]=arrays[4][i];

        }

        for(i=0;i<9;i++){

            arrays[7][(i+3)%9]=arrays[6][i];

        }

        for(i=0;i<9;i++){

            arrays[8][(i+3)%9]=arrays[7][i];

        }

        for (i=0; i<30; i++) {

            arrays[(rand()%9)+1][(rand()%9)+1]=0;

        }



        for(i=0;i<3;i++){

            printf("%d %d %d %d %d %d -1 -1 -1 %d %d %d\n",arrays[0][3*i],arrays[0][3*i+1],arrays[0][3*i+2],arrays[1][3*i],arrays[1][3*i+1],arrays[1][3*i+2],arrays[2][3*i],arrays[2][3*i+1],arrays[2][3*i+2]);

        }

        for(i=0;i<3;i++){

            printf("-1 -1 -1 %d %d %d %d %d %d %d %d %d\n",arrays[4][3*i],arrays[4][3*i+1],arrays[4][3*i+2],arrays[5][3*i],arrays[5][3*i+1],arrays[5][3*i+2],arrays[3][3*i],arrays[3][3*i+1],arrays[3][3*i+2]);

        }

        for(i=0;i<3;i++){

            printf(" %d %d %d %d %d %d %d %d %d -1 -1 -1\n",arrays[3][3*i],arrays[3][3*i+1],arrays[3][3*i+2],arrays[7][3*i],arrays[7][3*i+1],arrays[7][3*i+2],arrays[8][3*i],arrays[8][3*i+1],arrays[8][3*i+2]);

        }

        for(i=0;i<3;i++){

            printf(" %d %d %d -1 -1 -1 %d %d %d %d %d %d\n",arrays[6][3*i],arrays[6][3*i+1],arrays[6][3*i+2],arrays[2][3*i],arrays[2][3*i+1],arrays[2][3*i+2],arrays[7][3*i],arrays[7][3*i+1],arrays[7][3*i+2]);

        }

    }



    void Sudoku::ReadIn()

    {

        int i,j,k;

        cout << "Enter a sudoku:\n";



        for(i=0;i<12;i++)

        {

            for(j=0;j<12;j++)

            {

                cin >> original[i][j];

            }

        }

        cout<<endl;

    }



    void Sudoku::Solve()

    {

        int i,j;



        sol();



        if(record==0)

        {

            cout << "0\n";

        }

        else if(record==1)

        {

            cout << "1\n";

            for(i=0;i<12;i++)

            {

                for(j=0;j<12;j++)

                {

                    cout << inspect[i][j] << " ";

                }

                cout << endl;

            }

        }

        else

        {

            cout << "2\n";

        }

    }



    void Sudoku::sol()

    {

        int i,j,k;

        int blank=0;



        for(i=0;i<12;i++) //count how many blank

        {

            for(j=0;j<12;j++)

            {

                if(original[i][j]==0)

                {

                    blank++;

                }

            }

        }



        if(blank==0)  //when find a solution

        {

            record++;

            for(i=0;i<12;i++)

            {

                for(j=0;j<12;j++)

                {

                    inspect[i][j] = original[i][j];

                }

            }

            return;

        }



        for(i=0;i<12;i++)

        {

            for(j=0;j<12;j++)

            {

                if(original[i][j]==0)

                {

                    for(k=1;k<=9;k++)

                    {

                        if(Judge_Square(k,i,j)==1 && Judge_Row(k,i)==1 && Judge_Column(k,j)==1)

                        {

                            original[i][j]=k;

                            sol();

                            original[i][j]=0;

                        }



                        if(record==2)

                        {

                            return;

                        }

                    }



                    return;

                }

            }

        }

    }



    int Sudoku::Judge_Row(int k,int i) //check the row

    {

        int p;

        for(p=0;p<12;p++)

        {

            if(k == original[i][p])

            {

                return 0;

            }

        }

        return 1;

    }



    int Sudoku::Judge_Column(int k,int j) //check the column

    {

        int p;

        for(p=0;p<12;p++)

        {

            if(k == original[p][j])

            {

                return 0;

            }

        }

        return 1;

    }



    int Sudoku::Judge_Square(int k,int i,int j) //check the square

    {

        int m,n;

        m = i - (i%3);

        n = j - (j%3);



        for (int x=0;x<3;x++)

        {

            for (int y=0;y<3;y++)

            {

                if(original[m+x][n+y] == k)

                {

                    return 0;

                }

            }

        }

        return 1;

    }

