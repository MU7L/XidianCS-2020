#include <iostream>

using namespace std;

const int ROW = 2;
const int COL = 3;

class Matrix
{
public:
    int elem[ROW][COL];
    Matrix();
    friend istream &operator>>(istream &in, Matrix &m);
    friend ostream &operator<<(ostream &out, Matrix &m);
};

Matrix::Matrix()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            elem[i][j] = 0;
        }
    }
}

istream &operator>>(istream &in, Matrix &m)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            in >> m.elem[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, Matrix &m)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            out << m.elem[i][j] << ' ';
        }
        out << "\n";
    }
    return out;
}

int main()
{
    Matrix m;
    cout << "input:" << endl;
    cin >> m;
    cout << "output:" << endl;
    cout << m << endl;
    return 0;
}