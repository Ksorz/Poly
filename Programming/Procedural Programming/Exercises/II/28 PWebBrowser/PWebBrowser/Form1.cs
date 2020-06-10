using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace PWebBrowser
{
    /* Задание: Browser
     * Скачайте заготовку для этого задания.
     * 
     * Проанализируйте работу образца. Откройте проект и разберитесь с содержанием модуля формы (примите во внимание то, что объяснялось на лекции).
     * 
     * Напишите содержимое обработчика события FormClosed. 
     * Открываем файл strINIFile (если он не существует, то создаем),
     * Создаем объект StreamWriter.
     * Записываем название секции HeadWindow и значения пар ключ-значение для следующих параметров окна: Left, Top, Width, Height, WindowState.
     * Записываем название секции HeadBrowser и значение для ключа URL - wbBrowser.Url
     * Названия ключей можно посмотреть в образце, в файле Browser.ini
     * Закрываем файл (объект StreamWriter).
     * 
     * Напишите содержимое обработчика события Load. 
     * Открываем файл strINIFile (если он не существует, то загружаем форму с параметрами по умолчанию).
     * Создаем объект StreamReader.
     * Находим секции (см. выше) и считываем параметры, записанные под ними.
     * 
     * Необходимо предусмотреть следующие ситуации:
     * Отсутствие файла.
     * Порядок секций и ключей может быть любой.
     * Значение справа от ключа может быть некорректным. */

    public partial class Form1 : Form
    {
        private string strINIFile = "browser.ini";
        private const string HeadWindow = "[Window]";
        private const string HeadBrowser = "[Browser]";


        public Form1()
        {
            InitializeComponent();
        }

        // Обработчик события закрытия формы
        private void Form1_FormClosed(Object sender, FormClosedEventArgs e)
        {
            FileInfo file = new FileInfo(strINIFile);
            StreamWriter sw = file.CreateText();
            // Создаём/перезаписываем файл с настройками окна браузера
            sw.WriteLine(HeadWindow);
            sw.WriteLine("Lft = " + Form.ActiveForm.Location.X);
            sw.WriteLine("Top = " + Form.ActiveForm.Location.Y);
            sw.WriteLine("Wdt = " + Size.Width);
            sw.WriteLine("Hgh = " + Size.Height);
            try { sw.WriteLine("Sta = " + WindowState); }
            catch { sw.WriteLine("Sta = Minimized"); }
            sw.WriteLine(HeadBrowser);
            sw.WriteLine("URL = " + wbBrowser.Url);

            sw.Close();
        }

        // Обработчик события загрузки формы
        private void Form1_Load(object sender, EventArgs e)
        {
            FileInfo file = new FileInfo(strINIFile);
            // Размер окна
            Analyzer(file, "Wdt", out string i); Analyzer(file, "Hgh", out string j);
            Size = new Size(Convert.ToInt32(i), Convert.ToInt32(j));
            // Положение окна
            Analyzer(file, "Lft", out i); Analyzer(file, "Top", out j);
            Location = new Point(Convert.ToInt32(i), Convert.ToInt32(j));
            // Последний открытый сайт
            Analyzer(file, "URL", out i);
            wbBrowser.Navigate(i);
            // Положение окна (свёрнуто, стандарт, на весь экран)
            Analyzer(file, "Sta", out i);
            if (i == "Maximized") { WindowState = FormWindowState.Maximized; }
            else if (i == "Minimized") { WindowState = FormWindowState.Minimized; }
            else { WindowState = FormWindowState.Normal; }
        }

        
        // Обработчик события нажатия клавиши
        private void txtURL_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            // Check for the flag being set in the KeyDown event.
            if (e.KeyChar == (char)Keys.Return)
            {
                //MessageBox.Show(txtURL.Text);
                wbBrowser.Navigate(txtURL.Text);
                e.Handled = true;
            }

        }
        // Функция возвращает значение из файла по аргументу (key), возвращает значение по умолчанию, если файла нет или значение не найдено
        static void Analyzer(FileInfo file, string key, out string val)
        {
            val = "Default";
            // Значения по умолчанию
            if (key == "Lft") { val = "185"; }
            else if (key == "Top") { val = "26"; }
            else if (key == "Wdt") { val = "930"; }
            else if (key == "Hgh") { val = "573"; }
            else if (key == "Sta") { val = "Normal"; }
            else if (key == "URL") { val = "http://www.avalon.ru/"; }

            if (file.Exists)
            { 
                StreamReader sr = file.OpenText();
                while (!sr.EndOfStream)
                {
                    string line = sr.ReadLine();
                    if (line.Split('=')[0].Trim() == key)
                    {
                        val = line.Split('=')[1].Trim();
                        break;
                    }
                }
                sr.Close();
            }
        }
    }
}
