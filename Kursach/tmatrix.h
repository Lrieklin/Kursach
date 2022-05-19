#ifndef TMATRIX_H
#define TMATRIX_H
#include "tvector.h"

class TMatrix
{
protected:
    std::vector<TVector> data;
    int n, m;
public:
    //��������� �����������
    TMatrix();
    //�������� ������� �� �������
    TMatrix(int n, int m);
    //����������� �����������
    TMatrix(const TMatrix& rval);
    //���������� �����
    inline int row_count() const { return data.size(); }
    //���������� ��������
    inline int col_count() const { return data.back().size(); }
    //��������� ������� �������
    void resize(int n, int m);
    TMatrix& operator = (const TMatrix& rval);
    //��������� �����
    inline TVector operator[](int i) const { return data[i]; }
    inline TVector& operator[](int i) { return data[i]; }
    //���������
    TMatrix operator - () const;
    TMatrix operator - (const TMatrix& rval) const;
    TMatrix operator + (const TMatrix& rval) const;
    TMatrix operator * (const long double rval) const;
    //��������� ���������
    TMatrix operator * (const TMatrix& rval) const;
    //��������� ������� �� ������
    TVector operator * (const TVector& rval) const;
    ~TMatrix();
};

#endif // TMATRIX_H