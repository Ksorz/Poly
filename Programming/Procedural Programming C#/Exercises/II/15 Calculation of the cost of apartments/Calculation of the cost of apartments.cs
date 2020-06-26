using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp
{
    class Program
    {
        /* Задание: Подсчет стоимости квартир
         *
         * Объявите структуру, которая бы описывала городскую квартиру с точки зрения агенства недвижимости. Предусмотрите в этой
         * структуре возможность вводить данные о площади каждой комнаты отдельно, кухни и площади остальных помещений. Сумма этих чисел
         * будет равняться общей площади квартиры.
         *
         * Напишите подпрограмму, которой подается на вход одномерный массив с информацией о квартирах. Подпрограмма должна
         * вычислять медиану цены для квартир у которых количество комнат равно Rooms, а общая площадь больше TotalSquare.
         * Rooms и TotalSquare - входные аргументы функции.
         *
         * Что такое медиана в статистике можно почитать тут:
         * ( https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B4%D0%B8%D0%B0%D0%BD%D0%B0_(%D1%81%D1%82%D0%B0%D1%82%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B0 )
         *
         * Оцениваться будет грамотное объявление структуры и сам алгоритм.*/

        // Random для генерации квартир
        public static Random rnd = new Random();

        static void Main(string[] args)
        {
            // Создадим от 45 до 120 квартир
            Apart[] aparts = NewAparts(45, 120);

            // Узнаем медиану цены квартир, в которых 4 комнаты и общая площадь больше 85
            MedianPrices(aparts, 4, 85);
        }

        static void MedianPrices(Apart[] aparts, int rooms, int totalSquare)
        {
            // Список учитываемых в расчетах квартир
            List<Apart> countedAparts = new List<Apart>();
            // С помощью total посчитаем общее количество к вартир, соответствующее rooms
            int total = 0;

            for (int i = 0; i < aparts.Length; i++)
            {
                // Добавим квартиру в список учёта, если соответствует условиям (кол-во комнат = rooms, общая площадь > totalSquare)
                if (aparts[i].roomsNumber == rooms && aparts[i].total > totalSquare) countedAparts.Add(aparts[i]);
                total++;
            }

            // Формируем список стоимости квартир из списка учтённых
            List<int> prices = new List<int>();

            foreach (var apart in countedAparts) prices.Add(apart.Price());

            prices.Sort();

            // Отобразим некоторую информацию
            foreach (var price in prices) Console.WriteLine(price);
            Console.WriteLine("\nNumber of counted aparts: {0}, total aparts with {1} rooms: {2}", prices.Count(), rooms, total);
            // Вычисляем медиану стоимости
            Console.WriteLine("\nMedian price: {0}\n", prices[prices.Count() / 2]);
        }

        // Генерация массива случайного количества квартир со случайными параметрами
        static Apart[] NewAparts(int from, int to)
        {
            Apart[] aparts = new Apart[rnd.Next(from, to)];
            int rooms;

            for (int i = 0; i < aparts.Length; i++)
            {
                rooms = rnd.Next(2, 7);
                aparts[i] = new Apart("Crab ave " + (i + 1));
                aparts[i].NewRoom("Kitchen", rnd.Next(7, 56));
                aparts[i].NewRoom("Bathroom", rnd.Next(5, 41));

                for (int j = 0; j < rooms; j++)
                {
                    aparts[i].NewRoom("Room " + (j + 1), rnd.Next(9, 45));
                }
            }
            return aparts;
        }
    }

    // Структура, определяющая параметры квартиры
    public struct Apart
    {
        public string adress;
        private Dictionary<string, int> rooms;
        public int total; // Общая площадь
        public int roomsNumber; // Количество комнат (без учета ванной и кухни)

        public Apart(string adr)
        {
            adress = adr;
            rooms = new Dictionary<string, int>();
            total = 0;
            roomsNumber = 0;
        }

        // Создание и учёт новой комнаты
        public void NewRoom(string title, int area)
        {
            rooms.Add(title, area);
            total += area;
            if (title != "Bathroom" && title != "Kitchen")  roomsNumber += 1;
        }

        // Метод, волшебными расчётами вычисляющий цену квартиры в печеньках
        public int Price()
        {
            int price = 0;
            foreach (var kvp in rooms)
            {
                price += kvp.Key == "Bathroom" || kvp.Key == "Kitchen" ? kvp.Value * 700 : kvp.Value * 1000;
            }
            return price;
        }

        // Метод, показывающий общую информацию о квартире
        public void Info()
        {
            Console.WriteLine("Adress: " + adress);
            foreach (var kvp in rooms)
            {
                Console.WriteLine("{0}: {1} sqm", kvp.Key, kvp.Value);
            }
            Console.WriteLine("Total square = {0}", total);
        }
    }
}
