using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class TEST
    {
        static void Main(string[] args)
        {
            double h_angle;
            Console.WriteLine("Please, enter the hour hand angle (degrees)");
            // записываем в переменную вводимое значение
            double.TryParse(Console.ReadLine(), out h_angle);
            // на всякий случай округляем угол часовой стрелки в пределах 360°
            h_angle %= 360;                                                     

            // минутная стрелка делает оборот 360° каждые 30° часовой стрелки, поэтому ищем остаток
            double m_angle = h_angle % 30;
            // находим угол минутной стрелки относительно часовой, "поворачиваем" тригоном. окружность, превращая её в циферблат (+ 90°)
            m_angle = (m_angle * 12) + 90;
            // в некоторых ситуациях угол минутной стрелки будет > 360°, окруляем его в пределах 360°
            m_angle %= 360;

            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Angle of the hour   hand ~ " + Math.Round(h_angle * Math.PI / 180, 3) + " radians");
            Console.WriteLine("Angle of the minute hand ~ " + Math.Round(m_angle * Math.PI / 180, 3) + " radians");
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Angle of the hour   hand ~ " + Math.Round(h_angle, 2) + " degrees");
            Console.WriteLine("Angle of the minute hand ~ " + Math.Round(m_angle, 2) + " degrees");
            Console.WriteLine("-------------------------------------------");

            
            double pi = Math.PI;

            double hAngle;
            Console.WriteLine("Please, enter the hour hand angle (in radians)");
            double.TryParse(Console.ReadLine(), out hAngle);
            Console.WriteLine("hAngle = " + hAngle);
            hAngle %= (pi * 2);

            double mAngle = hAngle % (pi / 6);
            mAngle = (mAngle * 12) + (pi / 2);
            mAngle %= (pi * 2);

            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Angle of the hour   hand ~ " + Math.Round(hAngle, 3) + " radians");
            Console.WriteLine("Angle of the minute hand ~ " + Math.Round(mAngle, 3) + " radians");
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Angle of the hour   hand ~ " + Math.Round(hAngle * 180 / pi, 1) + " degrees");
            Console.WriteLine("Angle of the minute hand ~ " + Math.Round(mAngle * 180 / pi, 1) + " degrees");
            Console.WriteLine("-------------------------------------------");
            
        }
    }
}
