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
        cout << "3) remove item;" << endl;
        cout << "4) approximate volume output;" << endl;
        cout << "5) Determination of water surface area;" << endl;
        cout << "6) check whether water bodies belong to the same type;" << endl;
        cout << "7) compare the water surface area of water bodies of the same type;" << endl;
        cout << "0) exit;" << endl;
        cin >> choice;
        cout << "================================\n";
        switch (choice)
        {
        case 0:
            cout << "Goodbye !";
            return 0;
        case 1:
            if (!isInitializer) 
            {
                list = new Reservoir[howMany_Items];
            }
            for (int i = howMany_Items; i == howMany_Items; i++)
            {
                list[i].input();
                cout << "================================\n";
            }
            howMany_Items++;
            isInitializer = true;
            break;
        case 2:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "id: " << i << endl;
                list[i].output();
                cout << "================================\n";
            }
            break;
        case 3:
            int deleteItem;
            cout << "Which item do you want delete ?\n";
            cin >> deleteItem;
            if (deleteItem < 0 || deleteItem >= howMany_Items) {
                cout << "Неверный индекс" << endl;
                break;
            }
            cout << "================================\n";
            list->remove(list, deleteItem, howMany_Items);
            howMany_Items--;
            break;
        case 4:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "approximate volume output from " << list[i].getName() << " is " << list[i].Determining_the_approximate_volume() << endl;
            }
            cout << "================================\n";
            break;
        case 5:
            for (int i = 0; i < howMany_Items; i++)
            {
                cout << "Determination of water surface area from " << list[i].getName() << " is " << list[i].water_surface_area() << endl;
            }
            cout << "================================\n";
            break;
        case 6:
            for (int i = 0; i+1 < howMany_Items; i++)
            {
                if (list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() << " is " << list[i].getType() << endl;
                }
                else if (!list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() <<
                        " it's not the same type." << endl;
                }
            }
            cout << "================================\n";
            break;
        case 7:
            for (int i = 0; i+1 < howMany_Items; i++)
            {
                if (list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].ater_bodies_belong_to_the_same_type(list[i + 1]) << endl;
                }
                else if (!list[i].check_if_the_type_of_water(list[i + 1]))
                {
                    cout << list[i].getName() << " and " <<
                        list[i + 1].getName() <<
                        " it's not the same type." << endl;
                }
            }
            cout << "================================\n";
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            cout << "================================\n";
        }
    }
}
