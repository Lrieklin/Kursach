#ifndef VECTOR_ALG_H
#define VECTOR_ALG_H
#include <vector>
#include <cmath>
using namespace std;
class TMatrix;
class TVector
{
protected:
    int n;
    std::vector<long double> data;
public:
    //����������� ���������
    TVector();
    //�������� ������� ������������ �������
    TVector(int n);
    //����������� �����������
    TVector(const TVector& rval);
    //��������� ������� �������
    inline int size() const { return data.size(); }
    //��������� ������� �������
    void resize(int n);
    //��������� ��������
    inline long double operator[](int i) const { return data[i]; }
    inline long double& operator[](int i) { return data[i]; }
    //���������� �������
    TVector& operator = (const TVector& rval);
    //������ �������
    long double length() const;
    //���������
    TVector operator - () const;
    TVector operator - (const long double rval) const;
    TVector operator - (const TVector& rval) const;
    TVector operator + (const long double rval) const;
    TVector operator + (const TVector& rval) const;
    //��������� �������� ��������
    TVector operator ^ (const TVector& rval) const;
    TVector operator * (const long double rval) const;
    //��������� ��������� ��������
    long double operator * (const TVector& rval) const;
    ~TVector();
};

#endif VECTOR_ALG_H