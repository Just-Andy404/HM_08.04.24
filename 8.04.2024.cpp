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
#include <iostream>
#include <cstring>
#include "Reservoir.h"
using namespace std;

int main() {
    int choice;
    int howMany_Items = 0;
    bool isInitializer = false;
    int size;
    Reservoir* list = nullptr;
    while (true) {
        cout << "1) add item;" << endl;
        cout << "2) print items;" << endl;
        cout << "3) approximate volume output;" << endl;
        cout << "4) Determination of water surface area;" << endl;
        cout << "5) check whether water bodies belong to the same type;" << endl;
        cout << "6) compare the water surface area of water bodies of the same type;" << endl;
        cout << "0) exit;" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            howMany_Items++;
            list = new Reservoir[howMany_Items];
            size = list->getLength();
            list->input();
            cout << "================================\n";
            isInitializer = true;
            list->add(list, howMany_Items);
            break;
        case 2:
            for (int i = 0; i < howMany_Items; i++)
            {
                list[i].output();
                cout << "================================\n";
            }
            break;
        case 3:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "approximate volume output is " << list[i].Determining_the_approximate_volume();
            }
            break;
        case 4:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "Determination of water surface area is " << list[i].water_surface_area();
            }
            break;
        case 5:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "Determination of water surface area is " << list[i].water_surface_area();
            }
            break;
        case 6:
            for (int i = 0; i < howMany_Items; i++)
            {
                if (list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() << list[i].getType();
                }
                else if (!list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() <<
                        " it's not the same type.";
                }
            }
            break;
        case 7:
            for (int i = 0; i < howMany_Items; i++)
            {
                if (list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].ater_bodies_belong_to_the_same_type(list[i + 1]);
                }
                else if (!list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() <<
                        " it's not the same type.";
                }
            }
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    }
}
