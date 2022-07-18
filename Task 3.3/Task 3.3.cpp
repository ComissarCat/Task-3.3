#include <iostream>
using namespace std;

void task_1();
void show_menu(double menu_codes[][4], string menu_names[]);
void show_order(double menu_codes[][4], string menu_names[]);
void task_2();
void menu();

int main()
{
    setlocale(LC_ALL, "Russian");

    menu();

    return 0;
}

void task_1()
{
    double menu_codes[7][4] =
    {
        { 11, 10, 0, 0 },
        { 12, 20, 0, 0 },
        { 13, 30, 0, 0 },
        { 14, 40, 0, 0 },
        { 21, 1, 0, 0 },
        { 22, 2, 0, 0 },
        { 23, 3, 0, 0 }
    };
    string menu_names[7] = { "Маргарита", "Четыре сыра", "Гавайская", "Пепперони", "Фруктовый сок", "Газировка", "Черный чай" };    
    int number_of_pizzas = 0, order_code = 0, order_number = 0;
    show_menu(menu_codes, menu_names);
    do
    {
        for(;;)
        {            
            cout << "Введите код товара, 0 для завершения: ";
            cin >> order_code;
            if (not order_code) break;
            for (int i = 0; i < 7; i++)
            {
                if (menu_codes[i][0] == order_code)
                {
                    do
                    {
                        cout << "Введите количество товара: ";
                        cin >> order_number;
                    } while (order_number < 0);
                    for (int j = 0; j < order_number; j++)
                    {
                        menu_codes[i][2]++;
                        if (((int)menu_codes[i][0] / 10) == 1)
                        {
                            number_of_pizzas++;
                            if (not(number_of_pizzas % 5)) continue;
                            else menu_codes[i][3] += menu_codes[i][1];
                        }
                        else menu_codes[i][3] += menu_codes[i][1];                        
                    }
                    break;
                }                
            }
        }
    } while (order_code);
    for (int i = 0; i < 7; i++)
    {
        if (((int)menu_codes[i][0] / 10 == 2) and (menu_codes[i][1] > 2) and ((menu_codes[i][2] > 3)))
        {
            for (int i = 0; i < 7; i++)
            {
                if (((int)menu_codes[i][0] / 10) == 2) menu_codes[i][3] *= 0.75;
            }
            break;
        }
    }
    show_order(menu_codes, menu_names);
}

void show_menu(double menu_codes[][4], string menu_names[])
{
    cout << "\n\n\t\t\tМЕНЮ\n\n";
    cout << "Название\t\tКод\t\tСтоимость\n\n";
    for (int i = 0; i < 7; i++)
    {
        cout << menu_names[i] << "\t\t" << menu_codes[i][0] << "\t\t" << menu_codes[i][1] << "\n\n";
    }
    cout << "\n\n";
}

void show_order(double menu_codes[][4], string menu_names[])
{
    double cost_of_order = 0;
    cout << "\n\n\t\t\tЗаказ\n\n";
    cout << "Название\t\tКод\t\tСтоимость\t\tКоличество\t\tСумма\n\n";
    for (int i = 0; i < 7; i++)
    {
        if (menu_codes[i][2])
        {
            cost_of_order += menu_codes[i][3];
            cout << menu_names[i] << "\t\t" << menu_codes[i][0] << "\t\t" << menu_codes[i][1] << "\t\t\t"
                << menu_codes[i][2] << "\t\t\t" << menu_codes[i][3] << "\n\n";
        }
    }
    cout << "ИТОГО:\t" << cost_of_order;
    cout << "\n\n";
}

void task_2()
{
    int base_salary = 200, best_manager = 0;
    double sales[3], salary[3] = { 0, 0, 0 };
    for (int i = 0; i < 3; i++)
    {        
        do
        {
            cout << "Введите объём продаж " << i + 1 << " менеджера: ";
            cin >> sales[i];
        } while (sales[i] < 0);
        (sales[i] > sales[best_manager]) ? best_manager = i : best_manager;
        if (sales[i] < 500) salary[i] = sales[i] * 0.03;
        else if (sales[i] < 1000) salary[i] = sales[i] * 0.05;
        else salary[i] = sales[i] * 0.08;
        salary[i] += base_salary;
    }
    salary[best_manager] += base_salary;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " менеджер: " << salary[i] << endl;
    }
}

void menu()
{
    int task = 0;
    void(*list_of_menu[2])() = { task_1, task_2 };
    do
    {
        do
        {
            cout << "Введите номер задания, 0 - выход: ";
            cin >> task;
        } while (task < 0 or task > 2);
        if (task) list_of_menu[task - 1]();
    } while (task);
}