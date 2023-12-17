#include <iostream>
using namespace std;

void memory()
{
    system("cls");
    cout << "Размер типов данных в байтах" << "\n";
    cout << " Тип данных Int занимает: " << sizeof(int) << " байт(а).\n";
    cout << " Тип данных Short int занимает: " << sizeof(short int) << "байт(а).\n";
    cout << " Тип данных Long int занимает: " << sizeof(long int) << "байт(а).\n";
    cout << "Тип данных Float занимает: " << sizeof(float) << "байт(а).\n";
    cout << "Тип данных Double занимает: " << sizeof(double) << "байт(а).\n";
    cout << "Тип данных Long double занимает: " << sizeof(long double) << "байт(а).\n";
    cout << "Тип данных Char занимает: " << sizeof(char) << "байт(а).\n";
    cout << "Тип данных Bool занимает: " << sizeof(bool) << "байт(а).\n";
    system("pause");
}

void integer()
{
    unsigned int bytes = sizeof(int) * 8, masks = 1 << (bytes - 1), intNum;
    system("cls");
    int subChoice;
    cout << "Выберите следующее действие:" << "\n";
    cout << "1. Двоичное представление в памяти числа типа int" << "\n";
    cout << "2. Инвертированное двоичное представление в памяти числа типа int" << "\n";
    cin >> subChoice;

    if (subChoice == 1)

    {
        system("cls");
        cout << "Введите число типа int: ";
        cin >> intNum;
        masks = 1;
        masks <<= sizeof(int) - 1;
        for (int i = 1; i <= bytes; i++)
        {
            putchar(intNum & masks ? '1' : '0');
            
            intNum <<= 1;
            cout << (i == 1 || i % 8 == 0 ? " " : "");
        }

        cout << "\n";
    }

    else if (subChoice == 2)

    {
        system("cls");
        cout << "Введите число типа int: ";
        cin >> intNum;
        intNum = ~intNum;
        for (int i = 1; i <= bytes; i++)
        {
            putchar(intNum & masks ? '1' : '0');
            intNum <<= 1;
            cout << (i == 1 || i % 8 == 0 ? " " : "");

        }

        cout << "\n";
    }

    else

    {

        cout << "Некорректный выбор. Пожалуйста, выберите пункт меню снова." << "\n";

    }

    system("pause");
}


void float_()
{
    unsigned int bytes = sizeof(int) * 8, masks = 1 << (bytes - 1);
    system("cls");
    int subChoice2;
    cout << "Выберите следующее действие:" << "\n";
    cout << "1. Двоичное представление в памяти числа типа float" << "\n";
    cout << "2. Инвертированное двоичное представление в памяти числа типа float" << "\n";
    cin >> subChoice2;

    if (subChoice2 == 1) 
    {
        system("cls");
        cout << "Введите число типа float: ";
        union
        {
            int intFloat;
            float floatNum;
        };

        cin >> floatNum;
        for (int i = 1; i <= bytes; i++)
        {
            putchar(intFloat & masks ? '1' : '0');
            intFloat <<= 1;
            if (i == 1 || i == 2 || i == 9)
                putchar(' ');
        }

        cout << "\n";

    }

    else if (subChoice2 == 2)

    {
        system("cls");
        cout << "Введите число типа float: ";
        union
        {
            int intNum2;
            float floatNum;
        };

        cin >> floatNum;
        intNum2 = ~intNum2;
        for (int i = 1; i <= bytes; i++) 
        {
            putchar(intNum2 & masks ? '1' : '0');
            intNum2 <<= 1;
            if (i == 1 || i == 2 || i == 9)
                putchar(' ');
        }

        cout << "\n";

    }
    else
    {

        cout << "Некорректный выбор. Пожалуйста, выберите пункт меню снова." << "\n";

    }

    system("pause");
}

void double_()
{
    system("cls");
    int subChoice3;
    cout << "Выберите следующее действие : " << "\n";
    cout << "1. Двоичное представление в памяти числа типа double" << "\n";
    cout << "2. Инвертированное двоичное представление в памяти числа типа double" << "\n";
    cin >> subChoice3;

    if (subChoice3 == 1) 
    {
        system("cls");
        cout << "Введите число типа данных double: ";
        union
        {
            int integerA[2];
            double doubleB;
        };


        cin >> doubleB;

        unsigned int order = sizeof(int) * 8;
        unsigned int mask = 1 << order - 1;

        for (int i = 1; i >= 0; i--)
        {
            mask = 1 << order - 1;
            for (int j = 0; j < order; j++)
            {
                putchar(integerA[i] & mask ? '1' : '0');
                mask >>= 1;
                if ((j == 11) && i)
                {
                    putchar(' ');
                }
                if ((j % order == 0) && i)
                {
                    putchar(' ');
                }
            }
        }
        cout << '\n';
    }

    else if (subChoice3 == 2) 
    {

        system("cls");
        cout << "Введите число типа данных double: ";
        union
        {
            int integerA[2];
            double doubleB;
        };

        cin >> doubleB;
        integerA[0] = ~integerA[0];
        integerA[1] = ~integerA[1];
        unsigned int order = sizeof(int) * 8;
        unsigned int mask = 1 << order - 1;

        for (int i = 1; i >= 0; i--)
        {
            mask = 1 << order - 1;
            for (int j = 0; j < order; j++)
            {
                putchar(integerA[i] & mask ? '1' : '0');
                mask >>= 1;
                if ((j == 11) && i)
                {
                    putchar(' ');
                }
                if ((j % order == 0) && i)
                {
                    putchar(' ');
                }
            }
        }
        cout << '\n';

    }

    else

    {

        cout << "Некорректный выбор. Пожалуйста, выберите пункт меню снова." << "\n";

    }

    system("pause");

}

void menu() 
{
    while (true) 
    {
        setlocale(0, "");
        system("cls");
        cout << "Главное меню:" << "\n";
        cout << "1. Размер типов данных (в байтах)" << "\n";
        cout << "2. Вывести двоичное представление в памяти числа типа int " << "\n";
        cout << "3. Вывести двоичное представление в памяти числа типа float" << "\n";
        cout << "4. Вывести двоичное представление в памяти числа типа double" << "\n";
        cout << "5. Завершить работу программы(" << "\n";

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;


        switch (choice) {
        case 1:
            memory();
            break;
        case 2:
            integer();
            break;
        case 3:
            float_();
            break;
        case 4:
            double_();
            break;
        case 5:
            cout << "Хорошего дня)" << "\n";
            return;
        default:
            system("cls");
            cout << "Некорректный выбор. Пожалуйста, выберите пункт меню снова." << "\n";
            system("pause");
        }
    }
}

int main()

{
    setlocale(0, "");
    menu();
    return 0;
}
           