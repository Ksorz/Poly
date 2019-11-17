using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercises
{
    class E1
    {
        /* 5 Добрый работодатель
        Вася до завтра должен написать важную подпрограмму для Доброго Работодателя. Оставалось дописать всего один метод, когда Вася от переутомления крепчайше заснул.

        Напишите метод, который принимает на вход имя и зарплату и возвращает строку вида: Hello, <Name>, your salary is <Salary>.

        Но так как Работодатель Добр, он всегда округляет зарплату до ближайшего целого числа вверх.

        Во многих редакторах и IDE сочетание клавиш Ctrl + Space показывает контекстную подсказку. Тут подсказки также работают, однако внутри Visual Studio они гораздо полнее и удобнее. */
        private static string GetGreetingMessage(string name, double salary)
        {
            return "Hello, " + name + ", your salary is " + Math.Round(salary + 0.499999999).ToString();
        }

        /* 6 Главный вопрос Вселенной
        Многие знают, что ответ на главный вопрос жизни, вселенной и всего такого — 42. Но Вася хочет большего! Он желает знать квадрат этого числа!

        Вы разделили с Васей работу — он написал главный метод Main, а вам осталось лишь дописать методы Print и GetSquare.

        Создайте два метода Print и GetSquare, так, чтобы код снизу заработал. Если забыли синтаксис определения методов — подсмотрите в видеолекции или в предыдущие задачи. */
        static void Print(double a)
        {
            Console.WriteLine(a);
        }

        static double GetSquare(double a)
        {
            return Math.Pow(a, 2);
        }

        /* 7 Разыскиваются методы!
        Напишите тело метода так, чтобы он возвращал вторую половину строки text, из которой затем удалены пробелы. Можете считать, что text всегда четной длины. */
        static string GetLastHalf(string text)
        {
            return text.Substring(text.Length / 2, text.Length / 2).Replace(" ", "");
        }

        // MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN • • • • • • • • • • • • • • • • • • • • • • • •
        static void Main(string[] args)
        {
            // 1 Ошибки преобразования типов
            double pi = Math.PI;
            int tenThousand = 10000;
            double tenThousandPi = pi * tenThousand;
            int roundedTenThousandPi = (int)Math.Round(tenThousandPi);
            int integerPartOfTenThousandPi = (int)tenThousandPi;
            Console.WriteLine(integerPartOfTenThousandPi);
            Console.WriteLine(roundedTenThousandPi);

            // 2 Биткоины в массы!
            double amount = 1.11; //количество биткоинов от одного человека
            int peopleCount = 60; // количество человек
            int totalMoney = (int)Math.Round(amount * peopleCount); // ← исправьте ошибку в этой строке
            Console.WriteLine(totalMoney);

            // 3 Преобразование строки в число
            string doubleNumber = "894376.243643";
            double number = double.Parse(doubleNumber, CultureInfo.InvariantCulture); // Вася уверен, что ошибка где-то тут
            Console.WriteLine(number + 1);

            // 4 Использование var
            double a = 5; // ← исправьте эту строку
            a += 0.5;
            Console.WriteLine(a);
        }
    }
}
