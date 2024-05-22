
/*
����������� ����� Reservoir (������). ����� �����������
������ ����� ���� "��������". ����� ������ ���������: ����������� �� ���������,
����������� � �����������, ��� ������������� ����������� ����������
� ����������� �����������.
�������� ������ ���:
    1. ����������� ���������������� ������ (������ * ����� *
       ������������ �������);
    2. ����������� ������� ������ �����������;
    3. ����� ��� ��������, ����������� �� ������� � ������
    ���� (����-����; �������-����);
    4. ��� ��������� ������� ������ ����������� �������� ������
    ����;
    5. ��� ��������� �ᒺ���;
    6. ��������� ������ �� ���������� ������������ (������ set
    � get).
�������� ��������� ��� ������ � �������. ����������� ������������ ������
�������� ������ � ������������ ����������, �������� �������� �� �������.
����������� ����������� ������ ���������� �� �������� ������� � ��������� ����,
�������� ����.
����������� explicit ����������� � ����������� �������-����� (��������, ���
����������� ������ � ������� � �.�.)
*/
#pragma once
#include <iostream>

class Reservoir {
    char* sName;
    int width;
    int length;
    int maximum_depth;
    char* type;

public:
    Reservoir();
    Reservoir(char* reservoirName, int userWidth, int userLength, int userMaximum_depth);
    Reservoir(const Reservoir& other);
    ~Reservoir();
    double Determining_the_approximate_volume();
    int water_surface_area();
    bool check_if_the_type_of_water(const Reservoir& other);
    bool ater_bodies_belong_to_the_same_type(Reservoir& other);
    void output();
    void input();
    Reservoir add(Reservoir*& array, int& size, Reservoir newElement);

    char getName();
    char getType();
};