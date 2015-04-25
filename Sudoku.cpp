#include "Sudoku.h"
#include <stdio.h>




    Sudoku::Sudoku()

    {

        record=0;

    }



    void Sudoku::GiveQuestion()

    {
    int i,j,k,sudoku[12][12]={8,1,2,7,5,3,-1,-1,-1,4,6,9,
        9,4,3,6,8,2,-1,-1,-1,1,5,7,
        6,7,5,4,9,1,-1,-1,-1,8,2,3,
        -1,-1,-1,9,7,4,3,6,8,2,1,5,
        -1,-1,-1,5,2,6,9,1,7,3,8,4,
        -1,-1,-1,3,1,8,4,5,2,9,7,6,
        1,5,4,2,3,7,8,9,6,-1,-1,-1,
        3,6,9,8,4,5,7,2,1,-1,-1,-1,
        2,8,7,1,6,9,5,3,4,-1,-1,-1,
        5,2,1,-1,-1,-1,6,4,9,7,3,8,
        4,3,8,-1,-1,-1,1,7,5,6,9,2,
        7,9,6,-1,-1,-1,2,8,3,5,4,1};
    for(k=0;k<35;k++){
        i=(rand()%12);
        j=(rand()%12);
        if(-1!=sudoku[i][j]){
            sudoku[i][j]=0;
        }
        else
            k--;
    }

    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            cout<<" "<<sudoku[i][j];
        }
        cout<<endl;
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

