```C#
using System;
using System.Diagnostics; // Обязательно для Stopwatch
using System.Threading;

class Program
{
    static void Main()
    {
        // 1. Проверяем, поддерживает ли система высокоточное измерение
        if (!Stopwatch.IsHighResolution)
        {
            Console.WriteLine("Внимание: Высокая точность не поддерживается.");
        }

        // 2. Создаем и запускаем секундомер
        // StartNew() сразу создает объект и начинает отсчет
        Stopwatch sw = Stopwatch.StartNew();

        //  Имитируем работу 
        Thread.Sleep(42); // Заснем на 42 мс
        // ----------------------------------------------

        // 3. Останавливаем замер
        sw.Stop();

        // 4. Получаем результаты в разных форматах
        Console.WriteLine($"Прошло времени (TimeSpan): {sw.Elapsed}");
        Console.WriteLine($"Миллисекунд: {sw.Elapsed.TotalMilliseconds} мс");
        
        // Самый точный показатель — тики QPC (не путать с тиками DateTime!)
        Console.WriteLine($"Тиков счетчика: {sw.ElapsedTicks}");

        // 5. Сброс и повторное использование
        sw.Restart(); // Сбросит время в 0 и запустит снова
        // ... еще какой-то код ...
        sw.Stop();
    }
}
```
