using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Объявление структур
         * Предложите объявление структур для описания следующих объектов, явлений (обязательны комментарии к полям структуры).

         * Не обязательно описывать в структуре все свойства объекта (сущности), достаточно объявить 5-7 полей. 
         * Но обязательно продемонстрировать использование полей-массивов и вложенных структур в том или ином пункте.
         * 
         * Вариант I
         */

        // Файл на диске.
        public struct File
        {
            public DateTime createDate; //дата и время создания
            public string fileName; //имя файла
            public string type; //тип / расширение
            public double byteSize; //размер в байтах
            public string description; //описание
        }

        // Информация о текущем состоянии погоды.
        public struct Weather
        {
            public DateTime date; //дата и время
            public int celsiusDeg; //градусы цельсия
            public double fahrenheitDeg; //градусы по фаренгейту
            public double pressure; //давление
            public double humidity; //влажность
            public int windSpeed; //скорость ветра м/с

            public Weather(DateTime d, int cel, double pres, double hum, int wspeed)
            {
                date = d;
                celsiusDeg = cel;
                fahrenheitDeg = cel * 1.8 + 32;
                pressure = pres;
                humidity = hum;
                windSpeed = wspeed;
            }
        }

        // Информация об отделении в армии (обычно в мотострелковом отделении 9-13 человек).
        public struct Division
        {
            public int number; //номер отделения
            public string branch; //род войск
            public Personnel[] Personnels; //информация о солдатах
            public string[] technics; //техника
            public string location; //текущее место дислокации
        }
        
        public struct Personnel
        {
            public string rank; //звание
            public string firstName; //имя
            public string lastName; //фамилия
            public int age; //возраст
        }

        static void Main(string[] args)
        {

        }        
    }
}
