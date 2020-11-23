using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Ищем похожих
         
         * Объявите структуру SHuman, описывающую человека и включающую в себя поля "Фамилия”, ”Имя”, ”Отчество”, ”Год рождения”.
         * На вход подпрограммы подается массив элементов данной структуры.
         
         * Напишите функцию, разбивающую этих людей на группы следующим образом - если у двух человек совпадает хотя бы одно поле, они попадают в одну группу
         * (Владимир Семенович Высоцкий и Василий Васильевич Смыслов не имеют «общих» полей, но если в компании есть также Василий Семенович Лановой, 
         * то все трое попадут в одну группу). Порядок элементов в группах не важен.
         
         * Выберите оптимальный формат возвращаемого значения (как проще всего описать разбиение?).
         * При разработке алгоритма используйте класс List<>
         */

        public struct SHuman
        {
            public string Surname;          // фамилия
            public string Firstname;        // имя
            public string Patronymic;       // отчество
            public int Year;                // год рождения
            public SHuman(string surname, string firstname, string patronymic, int year)
            {
                this.Surname = surname;
                this.Firstname = firstname;
                this.Patronymic = patronymic;
                this.Year = year;
            }

        }

        static void Main(string[] args)
        {
            SHuman[] Group = {new SHuman("Пушкин", "Александр", "Сергеевич", 1799),
                            new SHuman("Ломоносов", "Михаил", "Васильевич", 1711),
                            new SHuman("Тютчев", "Фёдор", "Иванович", 1803),
                            new SHuman("Суворов", "Александр", "Васильевич", 1729),
                            new SHuman("Менделеев", "Дмитрий", "Иванович", 1834),
                            new SHuman("Ахматова", "Анна", "Андреевна", 1889),
                            new SHuman("Володин", "Александр", "Моисеевич", 1919),
                            new SHuman("Мухина", "Вера", "Игнатьевна", 1889),
                            new SHuman("Верещагин", "Петр", "Петрович", 1834)};

            var result = Sorting(Group);

            foreach(List<SHuman> list in result) // Печать групп элементов созданного ступенчатого списка
            {
                foreach(SHuman obj in list)
                {
                    Console.Write(obj.Surname + ' ');
                    Console.Write(obj.Firstname + ' ');
                    Console.Write(obj.Patronymic + ' ');
                    Console.WriteLine(obj.Year);
                }
                Console.WriteLine();
            }
        }

        //=========================== РЕШЕНИЕ ===========================//
        static List<List<SHuman>> Sorting(SHuman[] args) // Сортировка массива структур по заданному условию 
        {
            List<List<SHuman>> sorted = new List<List<SHuman>>(); // Ступенчатый список для для описания разбиения на группы
            List<SHuman> listArgs = args.Cast<SHuman>().ToList(); // Создаём из входного массива список
            int index = 0; // Итератор групп в ступенчатом списке

            while(listArgs.Count > 0)
            {
                sorted.Add(new List<SHuman>()); // Новый список первой размерности на каждой итерации для группировки (1 итерация = заполняем 1 группу)
                // Следующие 2 команды: Добавляем первый элемент в список для группировки и удаляем его из несортированного (переносим)
                sorted[index].Add(listArgs[0]);
                listArgs.RemoveAt(0);

                // Цикл сортировки одной группы (за основу берём первый элемент, добавленный ваначале).
                for(int i = 0, j = 0; i < listArgs.Count;)
                {
                    if (sorted[index][j].Surname == listArgs[i].Surname || // условия сортировки
                    sorted[index][j].Firstname == listArgs[i].Firstname ||
                    sorted[index][j].Patronymic == listArgs[i].Patronymic ||
                    sorted[index][j].Year == listArgs[i].Year)
                    {
                        sorted[index].Add(listArgs[i]); // Переносим элемент, если условия подходящие
                        listArgs.RemoveAt(i);

                        // Условие смены основного элемента (для сравнения). Если был добавлен элемент в группу, то его тоже нужно проверить
                        if(i == listArgs.Count & j + 1 < sorted[index].Count) { j++; i = 0; }
                        continue;
                    }
                    i++; // Итератор до условия т.к. он участвует в проверке условия
                    if (i == listArgs.Count & j + 1 < sorted[index].Count) { j++; i = 0; }
                }
                index++;
            }
            return sorted;
        }
    }
}
