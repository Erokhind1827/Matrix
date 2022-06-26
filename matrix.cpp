#include "matrix.h"


ostream& operator<<(ostream& out, const matrix& obj)
{
    int max=abs(obj.A[0][0]);
    bool sign=false;
    int size=0;
    for (int i=0;i<obj.c_length;i++)
        for (int j=0;j<obj.r_length;j++)
        {
            if(obj.A[i][j]<0)
                sign=true;
            if (abs(obj.A[i][j])>max)
                max=obj.A[i][j];
        }
    int exponent=1;
    int temp;
    do
    {
        exponent*=10;
        temp=max/exponent;
        size++;
    } while (temp!=0);
    if (sign)
        size++;
    cout<<endl;
    for (int i=0;i<obj.r_length;i++)
    {
        cout<<"-";
        for (int j=0;j<size;j++)
            cout<<"-";
    }
    cout<<"-"<<endl;
    for (int i=0;i<obj.c_length;i++)
    {
        cout<<"|";
        for (int j=0;j<obj.r_length;j++)
        {
            cout.width(size);
            cout<<obj.A[i][j];
                cout<<"|";
        }
        cout<<endl;
    }
    for (int i=0;i<obj.r_length;i++)
    {
        cout<<"-";
        for (int j=0;j<size;j++)
            cout<<"-";
    }
    cout<<"-"<<endl;
    return out;
}

matrix::matrix(int n, int m)
{
    cout<<++count<<" objects aviable"<<endl;
    r_length=n;
    c_length=m;
    A=new float*[c_length];
    for(int i=0;i<c_length;i++)
    {
        A[i]=new float[r_length];
    }
}

matrix::~matrix()
{
    this->deleteA();
}

matrix &matrix::operator*(matrix &obj)
{
    int s=obj.c_length;
    int m=this->c_length;
    int n=obj.r_length;
    float sum;
    matrix *mult=new matrix(n,m);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            sum=0;
            for (int k=0;k<s;k++)
                sum+=this->A[i][k]*obj.A[k][j];
            mult->A[i][j]=sum;
        }
    }
    return *mult;
}

matrix &matrix::operator+(matrix &obj)
{
    matrix *sum=new matrix(r_length,c_length);
    for (int i=0;i<c_length;i++)
    {
        for (int j=0;j<r_length;j++)
        {
            sum->A[i][j]=A[i][j]+obj.A[i][j];
        }
    }
    return *sum;
}

void matrix::t()
{
    matrix *at = new matrix(c_length,r_length);
    for (int i=0;i<c_length;i++)
    {
        for (int j=0;j<r_length;j++)
        {
            at->A[j][i]=A[i][j];
        }
    }
    *this*=*at;
    count++;
}

void matrix::operator*=(matrix &obj)
{
    if (this->r_length>0)
        this->~matrix();
//    this->deleteA();
    r_length=obj.r_length;
    c_length=obj.c_length;
    A=new float*[c_length];
    for(int i=0;i<c_length;i++)
    {
        A[i]=new float[r_length];
    }
    for (int i=0;i<c_length;i++)
    {
        for (int j=0;j<r_length;j++)
        {
            A[i][j]=obj.A[i][j];
        }
    }
    obj.deleteA();
}

void matrix::operator=(matrix &obj)
{
    if (this->r_length>0)
        this->~matrix();
    r_length=obj.r_length;
    c_length=obj.c_length;
    A=new float*[c_length];
    for(int i=0;i<c_length;i++)
    {
        A[i]=new float[r_length];
    }
    for (int i=0;i<c_length;i++)
    {
        for (int j=0;j<r_length;j++)
        {
            A[i][j]=obj.A[i][j];
        }
    }
}

void matrix::setmatrix()
{
    srand(time(NULL));
    int z,min,max;
    do
    {
        cout << "1 for random, 2 for manual" <<endl;
        cin >> z;
    } while (z<1||z>2);
    if (z==1)
    {
        cout << "input the range(MIN|MAX) for coefficient(s)"<<endl;
        cin >> min >> max;
        for (int i=0;i<c_length;i++)
            for (int j=0;j<r_length;j++)
                A[i][j]=min+rand()%(max-min+1);
    }
}

void matrix::reverse()
{
    int i,j,k,l;
    float deter=this->determinant();
    if (deter==0)
        cout<<"reverse matrix doesn't exist"<<endl;
    else
    {
        matrix R(r_length,c_length);
        for (i=0;i<c_length;i++)
        {
            for (j=0;j<r_length;j++)
            {
                matrix A1(r_length-1,c_length-1);
                for (k=0;k<c_length;k++)
                {
                    for (l=0;l<r_length;l++)
                    {
                        if (k<i&&l<j)
                        {
                            A1.A[k][l]=A[k][l];
                        }
                        if (k>i&&l<j)
                        {
                            A1.A[k-1][l]=A[k][l];
                        }
                        if (k<i&&l>j)
                        {
                            A1.A[k][l-1]=A[k][l];
                        }
                        if (k>i&&l>j)
                        {
                            A1.A[k-1][l-1]=A[k][l];
                        }
                    }
                }
                cout<<A1;
                R.A[j][i]=pow(-1,i+j)*A1.determinant()/deter;
            }
        }
        *this=R;
        count++;
    }
}

bool matrix::multipliable(matrix &obj)
{
    if (this->r_length==obj.c_length)
        return true;
    return false;
}

bool matrix::summable(matrix &obj)
{
    if (this->c_length==obj.c_length||this->r_length==obj.r_length)
        return true;
    return false;
}

float matrix::determinant()
{
    if (c_length==1)
        return A[0][0];
    if (c_length==2)
        return A[0][0]*A[1][1]-A[1][0]*A[0][1];
    float det=0;
    int i,j,k;
    for (i=0;i<this->c_length;i++)
    {
        matrix A1(c_length-1,r_length-1);
        for (j=0;j<this->r_length;j++)
        {
            for (k=0;k<A1.c_length;k++)
            {
                if (j<i)
                {
//                    cout<<this->A[k+1][j]<<endl;
                    A1.A[k][j]=this->A[k+1][j];
//                    cout<< A1.A<<" "<<endl;
                }
                if (j>i)
                {
//                    cout<<this->A[k+1][j]<<endl;
                    A1.A[k][j-1]=this->A[k+1][j];
                }
            }
        }
//        cout<<A1;
        det+=pow(-1,1+i+1)*A[0][i]*A1.determinant();
//        if (A1.r_length>=2)
//            A1.deleteA();
    }
    return det;
}

bool matrix::symmetric()
{
    if (c_length==r_length)
        return true;
    return false;
}

void matrix::deleteA()
{
//    cout<< *this;
   cout<<--count<<" objects aviable"<<endl;
    for (int i=0;i<r_length;i++)
        delete [] A[i];
    delete [] A;
}
