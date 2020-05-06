using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime;
using System.Runtime.InteropServices;

namespace ConsoleApp
{
    class Program
    {
        /* Задание: Разбор арифметических выражений
         * 
         * Вариант 1
         * 
         * Разработать программу, которая принимает строку - арифметическое выражение и вычисляет его результат по алгоритму Рутисхаузера. 
         * Требования к выражению аналогичны описанным в уроке.
         * При чтении символов и их анализе помещайте их в список. Элементом списка будет структура со значением очередного символа и его весом.
         * При реализации программы разработайте в отдельном классе функции, реализующие работу списка. Реализация списка должна быть с 
         * использованием массива и курсоров. */

        // + = 1;; - = 2;; * = 3;; / = 4;; ( = 9;; ) = 0;;

        public struct Expression
        {
            public List<string> expFragments;
            public List<int> weigths;

            public Expression(string exp)
            {
                expFragments = new List<string>();

                for (int i = 0; i < exp.Length; i++)
                {
                    if (char.IsDigit(exp[i]) || exp[i] == ',') 
                    {
                        expFragments.Add(WhatIsThisDigit(exp.Substring(i), ref i)); 
                    }
                    else { expFragments.Add(exp[i].ToString()); }                    
                }

                weigths = new List<int>();
                int level = 0;

                for (int i = 0; i < expFragments.Count; i++)
                {
                    if (expFragments[i] == "(") level++;
                    
                    weigths.Add(level);

                    if (char.IsDigit(expFragments[i][0])) weigths[i]++;

                    if (expFragments[i] == ")") { level--; }
                }
            }
            public double Calc(Expression exp)
            {
                double result = 0;
                
                
                while (exp.expFragments.Count > 1)
                {
                    Console.WriteLine(exp.expFragments.Count + "  == expCount beginning");
                    int max = exp.weigths.Max();
                    int index = exp.weigths.IndexOf(max);
                    Console.WriteLine(index + " index beginning");
                    if (exp.expFragments[index + 1] == "+")
                    {
                        result = Convert.ToDouble(exp.expFragments[index]) + Convert.ToDouble(exp.expFragments[index + 2]);
                    }
                    else if (exp.expFragments[index + 1] == "-")
                    {
                        result = Convert.ToDouble(exp.expFragments[index]) - Convert.ToDouble(exp.expFragments[index + 2]);
                    }
                    else if (exp.expFragments[index + 1] == "*")
                    {
                        result = Convert.ToDouble(exp.expFragments[index]) * Convert.ToDouble(exp.expFragments[index + 2]);
                    }
                    else
                    {
                        result = Convert.ToDouble(exp.expFragments[index]) / Convert.ToDouble(exp.expFragments[index + 2]);
                    }

                    Console.WriteLine();

                    Console.WriteLine(exp.expFragments.Count + "  == expCount before");
                    Console.WriteLine(index + "  == index before");


                    for(int i = 0; i < 5; i++)
                    {
                        exp.expFragments.RemoveAt(index - 1);
                        exp.weigths.RemoveAt(index - 1);
                    }
                    
                    Console.WriteLine(exp.expFragments.Count + "  == expCount after");
                    Console.WriteLine(index + "  == index after");
                    Console.WriteLine();


                    exp.expFragments.Insert(index - 1, Convert.ToString(result));
                    exp.weigths.Insert(index - 1, max - 1);


                }
                return Convert.ToDouble(exp.expFragments[0]); 
            }
        }

        static string WhatIsThisDigit(string xxx, ref int j)
        {
            string result = xxx[0].ToString();

            for (int i = 1; i < xxx.Length - 1; i++, j++)
            {
                if (char.IsDigit(xxx[i]) || xxx[i] == ',') { result = result + xxx[i]; }
                else { break; }
            }
            return result;
        }

        static void Main(string[] args)
        {
            string x = "((75*8)-(2+(7*(29,8/(64,1-2)))))";
            Expression one = new Expression(x);

            for(int i = 0; i < one.expFragments.Count; i++)
            {
                Console.Write(one.weigths[i] + "   ");
                Console.WriteLine(one.expFragments[i]);
            }

            Console.WriteLine(one.Calc(one));

            for (int i = 0; i < one.expFragments.Count; i++)
            {
                Console.Write(one.weigths[i] + "   ");
                Console.WriteLine(one.expFragments[i]);
            }
        }
    }
}
