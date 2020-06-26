using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace WorkWithStrings
{
    /* Задание: Индексированный поиск файлов
     * 
     * Задача: разработать приложение для более быстрого, индексированного поиска файлов по заданному пользователем имени.
     * Индексирование и поиск выполнять в пределах указанной пользователем папки.
     * 
     * Цели:
     * 
     ** познакомиться с понятием хеширования,
     ** закрепить знания по обработке исключительных ситуаций,
     ** вспомнить рекурсию и работу с папками и файлами,
     ** вспомнить работу со списками.
     *
     * Шаг 1. Скачайте архив, распакуйте. Ознакомьтесь с работой образца Demo.exe. программа сначала предлагает ввести имя папки,
     * чтобы проиндексировать все файлы в этой папке и ее подпапках, а затем предлагает выполнить поиск по заданному имени файла, 
     * используя при этом хеш-таблицу.
     * 
     * Шаг 2. Разработайте хеш-функцию для получения хеш-кода входной строки. Хеш-код предполагается - целое число в интервале
     * от 0 до 255 (тип Byte).
     * 
     * Шаг 3. Разработайте функцию формирования хеш-таблицы со списками. Входной аргумент - имя стартовой папки. 
     * Результат работы - массив arrRes[0-255], каждый элемент которого типа List<..>
     * 
     * Шаг 4. Разработайте подпрограмму Main, которая обеспечивает пользовательский интерфейс и логику работы, аналогичную примеру-образцу.
     * 
     * Обязательное условие: при реализации всех указанных выше подпрограмм все нештатные ситуации нужно обрабатывать оператором TRY CATCH:
     * 
     ** Отсутствие хеш-кода указанного файла в хеш-таблице
     ** Ввод пользователем неверного значения или неверного имени папки
     ** Ошибки доступа к элементам файловой системы */

    public struct Filename
    {
        public string FullName;
        public string Name;
        public Filename(string FullName, string Name)
        {
            this.FullName = FullName;
            this.Name = Name;
        }
        public void Display()
        {
            Console.WriteLine(this.FullName);
            Console.WriteLine(this.Name);
        }
    }

    class List
    {
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    if (!Menu()) break;
                }
                catch (Exception)
                {
                    Console.WriteLine("ошибка, перезапуск программы");
                }
                Console.ReadKey();
            }
        }

        static bool Menu()
        {
            string CurDir, InpDir, Name;
            List<Filename> list = new List<Filename>();
            // текущая директория
            CurDir = "C:\\Users\\Ksorz\\OneDrive\\Документы\\Poly";
            DirectoryInfo dir = new DirectoryInfo(CurDir);

            Console.WriteLine("------------");
            Console.WriteLine("Список подпапок в директории: ");
            Console.WriteLine(CurDir);
            foreach (var subdirectoty in dir.GetDirectories())
                Console.WriteLine(@"...\" + subdirectoty.Name);
            Console.WriteLine("------------");
            Console.WriteLine("Введите имя подпапки (или оставьте поле пустым) и нажмите Enter");
            Console.WriteLine("------------");
            InpDir = Console.ReadLine();
            GetFilesToList(CurDir + @"\" + InpDir, list); // рекурсивно создаем список файлов
            List<Filename>[] HashTable = MakeHashTable(list); // создаем хэш-таблицу из списка
            Console.WriteLine("------------");
            Console.WriteLine("Введите имя файла которое ищем");
            Console.WriteLine("------------");
            Name = Console.ReadLine();
            Find(Name, HashTable, out List<Filename> fileList);
            Console.WriteLine("------------");
            Console.Write("Ищем: ");
            Console.WriteLine(Name.ToUpper());
            Console.WriteLine("------------");
            if (fileList.Count == 0)
            {
                Console.WriteLine("Не нашли");
                Console.WriteLine("------------");
            }
            else
            {
                Console.WriteLine("Нашли файлы:");
                foreach (Filename file in fileList)
                {
                    Console.WriteLine(file.FullName); // выводим результаты  поиска
                }
                Console.WriteLine("------------");

            }
            Console.WriteLine("Введите 0 для выхода");
            if (Convert.ToInt32(Console.ReadLine()) == 0)
                return false;
            return true;
        }

        // создает хэш-таблицу из списка файлов
        static List<Filename>[] MakeHashTable(List<Filename> list)
        {
            byte Hash = 0;

            List<Filename>[] HashTable = new List<Filename>[256];
            for (int i = 0; i < HashTable.Length; i++)
            {
                HashTable[i] = new List<Filename>();
            }

            foreach (Filename file in list)
            {
                Hash = GetHash(file.Name);
                HashTable[Hash].Add(file);
            }
            return HashTable;
        }
        // рекурсивно проходит папки и подпапки и добавляет файлы в список
        static void GetFilesToList(string Path1, List<Filename> list)
        {
            DirectoryInfo dir = new DirectoryInfo(Path1);
            //перебор файлов в папке
            try
            {
                foreach (var file in dir.GetFiles())
                {
                    list.Add(new Filename(Path1 + @"\" + file, Path.GetFileNameWithoutExtension(file.FullName).ToUpper()));
                }
            }
            catch
            {
                Console.WriteLine("нет папки с таким имененем");
                throw new Exception();
            }

            //перебор подпапок
            foreach (var subdirectoty in dir.GetDirectories())
                GetFilesToList(Path1 + @"\" + subdirectoty, list);
        }
        //ищет файлы с имененем input в HashTable, результаты записывает в список
        static bool Find(string input, List<Filename>[] HashTable, out List<Filename> fileList)
        {
            fileList = new List<Filename>();
            byte Hash = GetHash(input.ToUpper());
            bool find = false;
            foreach (Filename file in HashTable[Hash])
            {
                if (input.ToUpper().Equals(file.Name.ToUpper()))
                {
                    fileList.Add(file);
                    find = true;
                }
            }
            return find;
        }
        // возвращает byte хэш(0 - 255) из string
        static byte GetHash(string StrInput)
        {
            int hash = 0;
            foreach (char symbol in StrInput)
            {
                hash += symbol;
            }
            return (byte)hash;
        }
    }
}
