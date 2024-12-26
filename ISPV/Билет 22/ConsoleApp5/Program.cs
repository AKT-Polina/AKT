using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //ввод n
            int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[n];
            //заполнение массива случайными чисалми
            //можно сделать так, чтоб заполнил пользователь сам
            Random random = new Random();
            for (int i = 0; i < n; i++)
            {
                arr[i] = random.Next(0,100);
            }
            //вывод массива на консоль до замены
            for (int i = 0; i < n; i++)
            {
                Console.Write(arr[i] + " ");
            }
            //поиск максимального
            int max = arr[0];
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
            //поиск среднего арифметического
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum+= arr[i];
            }
            int avg = sum / n;
            //замена элементов
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 0 && arr[i] < avg)
                {
                    arr[i] = max;
                }
            }
            Console.WriteLine(  );
            //вывод массива на консоль после замены
            for (int i = 0; i < n; i++)
            {
                Console.Write(arr[i] + " ");
            }
        }
    }
}
