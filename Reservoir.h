
/*
Разработать класс Reservoir (водоем). Класс обязательно
должен иметь поле "название". Класс должен содержать: конструктор по умолчанию,
конструктор с параметрами, при необходимости реализовать деструктор
и конструктор копирования.
добавить методи для:
    1. Определение приблизительного объема (ширина * длина *
       максимальная глубина);
    2. Определение площади водной поверхности;
    3. Метод для проверки, принадлежат ли водоемы к одному
    типу (море-море; бассейн-пруд);
    4. Для сравнения площади водной поверхности водоемов одного
    типа;
    5. Для копіювання об’єктів;
    6. Остальные методы на усмотрение разработчика (методы set
    и get).
Написать интерфейс для работы с классом. Реализовать динамический массив
объектов класса с возможностью добавления, удаления объектов из массива.
Реализовать возможность записи информации об объектах массива в текстовый файл,
бинарный файл.
Используйте explicit конструктор и константные функции-члены (например, для
отображения данных о водоеме и т.д.)
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