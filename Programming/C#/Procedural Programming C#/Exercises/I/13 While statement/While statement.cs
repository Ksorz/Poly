﻿using System;
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
            /* Сидоров купил квартиру в ипотеку за N(uint) рублей.Каждый месяц он выплачивает по ипотеке M(uint) рублей,
            после чего(ежемесячно) банк начисляет P(double) процентов с округлением до целого в меньшую сторону и
            добавляет к оставшейся сумме.В последний месяц выплачивается оставшаяся сумма. Вычислите, через количество
            месяцев Сидоров полностью выплатит ипотеку. */

            /*
            Введите ответ для следующих входных данных  N=6300000, M=100000, P=1.1%. Ответ: 106
            Введите ответ для следующих входных данных  N=3500000, M=75000, R=0.7%. Ответ: 57
            */

            UInt32 N = 3500000;
            UInt32 M = 75000;
            double P = 0.7;

            int i = 1;
            
            while (N > M)
            {
                N -= M;
                N += Convert.ToUInt32(Math.Floor(N * (P / 100)));
                i++;
            }

            Console.WriteLine("Ипотека будет выплачена за " + i + " месяцев.");
        }
    }
}
