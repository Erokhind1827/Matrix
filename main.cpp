#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include "matrix.h"
using namespace std;

int matrix::count=0;

void instructions();

int main()
{
    int n,m,choice;
    instructions();
    cout << "? ";
    cin >> choice;
    while (choice != 0)
    {
        switch(choice)
        {

            case 1:
            {
                cout<<endl<<"!determinant!"<<endl<<endl;
                cout<<"input the size of your matrix: A(n*m)"<<endl;
                cin>>n>>m;
                matrix A(n,m);
                if (A.symmetric())
                {
                    A.setmatrix();
                    cout<<A;
                    int det=A.determinant();
                    cout<<det<<endl;
                }
                else
                    cout<<"matrix is not symmetrical, determinant doesn't exist"<<endl;
                break;
            }
            case 2:
            {
                cout<<endl<<"!multiplication!"<<endl<<endl;
                cout<<"input the size of matrix A1(n*m)"<<endl;
                cin>>n>>m;
                matrix A1(n,m);
                cout<<"input the size of matrix: A2(n*m)"<<endl;
                cin>>n>>m;
                matrix A2(n,m);
                if (A1.multipliable(A2))
                {
                    A1.setmatrix();
                    A2.setmatrix();
                    cout<<A1<<A2;
                    matrix rez;
                    rez*=A1*A2;
                    cout<<rez;
                }
//                else if (A2.multipliable(A1))
//                    {
//                        A1.setmatrix();
//                        A2.setmatrix();
//                        cout<<A1<<A2;
//                        matrix rez;
//                        rez*=A2*A1;
//                        cout<<rez;
//                    }
                else
                    cout<<"matrices are not multipliable"<<endl;
                break;
            }
            case 3:
            {
                cout<<endl<<"!summation!"<<endl<<endl;
                cout<<"input the size of matrix A1(n*m)"<<endl;
                cin>>n>>m;
                matrix A1(n,m);
                cout<<"input the size of matrix: A2(n*m)"<<endl;
                cin>>n>>m;
                matrix A2(n,m);
                if (A1.summable(A2))
                {
                    A1.setmatrix();
                    A2.setmatrix();
                    cout<<A1<<A2;
                    matrix rez;
                    rez*=A2+A1;
                    cout<<rez;
                }
                else
                    cout<<"matrices are not summable"<<endl;
                break;
            }           
            case 4:
            {
                cout<<endl<<"!transposition!"<<endl<<endl;
                cout<<"input the size of your matrix: A(n*m)"<<endl;
                cin>>n>>m;
                matrix A(n,m);
                A.setmatrix();
                cout<<A;
                A.t();
                cout<<A;
                break;
            }
            case 5:
            {
                cout<<endl<<"!reverse!"<<endl<<endl;
                cout<<"input the size of your matrix: A(n*m)"<<endl;
                cin>>n>>m;
                matrix A(n,m);
                if (A.symmetric())
                {
                    A.setmatrix();
                    cout<<A;
                    A.reverse();
                    cout<<A;
                }
                else
                    cout<<"matrix is not symmetrical, reverse matrix doesn't exist"<<endl;
                break;
            }
            default:
            {
                cout<<"invalid choice"<<endl<<endl;
                instructions();
                break;
            }
        }
        cout<<endl<<"? ";
        cin >> choice;
    }
    cout<<"end of run."<<endl;
    _CrtDumpMemoryLeaks();
    return 0;
}

void instructions()
{
    cout<<"enter your choice:"<<endl;
    cout<<"1 find the determinant of a matrix;"<<endl;
    cout<<"2 to multiply two matrices;"<<endl;
    cout<<"3 to sum two matrices;"<<endl;
    cout<<"4 to transposition your matrix"<<endl;
    cout<<"0 to end the run."<<endl;
}
