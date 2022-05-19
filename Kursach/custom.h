#pragma once//---------------------------------------------------------------------------
#include "model.h"
#include <tuple>
#include <math.h>
#include <vector>
#include <fstream>
#include "generator.h"
using namespace std;
using namespace arma;
//---------------------------------------------------------------------------

class TArenstorfModel : public TModel
{
protected:
    static const long double m;
    long double D1, D2;
public:
    TArenstorfModel();
    void getRight(const vec& X, long double t, vec& Y);
};

class TSatellite : public TModel
{
protected:
    const long double Re{ 6371000.0L };
    const long double nu{ 398600.436e9 }; //���� ��������
    const long double Rorb{ 23222000.0L }; //m
    const long double W{ 7.292115E-5 }; //������� �������� �������� �����
    int satellite_number{ 0 }, satellite_count{ 27 };
    //��������� ������
    long double orb_height{ Re + Rorb }; //������ �� ������ ����� (�)
    const int planes_number{ 3 }; // ���������� ����������
    long double period{ 50685.0L }; //������ ��������� (�)
    long double i{ 0.0L/*0.977384L*/ };//���������� (���)
    long double eccentricity{ 0.1L };//������������ (���� �������)
    long double u{ M_PI/*0.174533L*/ };//�������� ������ (���)
    long double omega{ 3.0L * M_PI / 2.0L/*3.75246L*/ };//������� ����������� ���� (���)
    vec X_oscul;//������ ��������� � ������������ ���������
    vec V_oscul;//������ ��������� � ������������ ���������
    //������� ��������
    mat A; //������� �������� ����� ��������� ����������� �� � ����� �������� ��
    //���� � �����������
public:
    mat R;
    long double ch_lat, ch_lon;
    TSatellite(int satellite_number, long double d_u, long double d_omega, long double i);//�� ������ ��������� (��������� 9) ������ ���� �� ���� �����, ������
    void getRight(const vec& X, long double t, vec& Y);
};


