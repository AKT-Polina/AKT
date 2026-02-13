# Изменение яркости экрана:
```c#
using System;
using System.Management; // Не забудьте добавить ссылку на System.Management.dll

namespace WmiBrightness
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Начинаем плавное изменение яркости...");

            // Плавно уменьшаем до 0, затем увеличиваем до 100
            FadeBrightness(0);
            System.Threading.Thread.Sleep(1000);
            FadeBrightness(100);

            Console.WriteLine("Готово!");
        }

        static void FadeBrightness(int targetBrightness)
        {
            int current = GetCurrentBrightness();
            int step = (current < targetBrightness) ? 1 : -1;

            while (current != targetBrightness)
            {
                current += step;
                SetBrightness((byte)current);
                System.Threading.Thread.Sleep(20); // Задержка для плавности
            }
        }

        // Метод для установки яркости
        static void SetBrightness(byte targetBrightness)
        {
            try
            {
                ManagementScope scope = new ManagementScope("root\\wmi");
                SelectQuery query = new SelectQuery("WmiMonitorBrightnessMethods");

                using (ManagementObjectSearcher searcher = new ManagementObjectSearcher(scope, query))
                {
                    foreach (ManagementObject obj in searcher.Get())
                    {
                        // 1-й параметр: Timeout (через сколько применить)
                        // 2-й параметр: Brightness (уровень в процентах 0-100)
                        obj.InvokeMethod("WmiSetBrightness", new object[] { uint.MaxValue, targetBrightness });
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка при установке яркости: " + ex.Message);
            }
        }

        // Метод для получения текущей яркости
        static int GetCurrentBrightness()
        {
            try
            {
                ManagementObjectSearcher searcher = new ManagementObjectSearcher("root\\wmi", "SELECT CurrentBrightness FROM WmiMonitorBrightness");
                foreach (ManagementObject obj in searcher.Get())
                {
                    return Convert.ToInt32(obj["CurrentBrightness"]);
                }
            }
            catch { }
            return 50; // Значение по умолчанию, если не удалось прочитать
        }
    }
}

```
# Включение, отключение Bluetooth устройств
```c#
// Пример логики для работы с устройствами
using (var searcher = new ManagementObjectSearcher("SELECT * FROM Win32_PnPEntity WHERE Name LIKE '%Bluetooth%'"))
{
    foreach (ManagementObject device in searcher.Get())
    {
        // В теории мы можем вызвать Disable или Enable
        // Но внимание: эти методы доступны не для всех объектов напрямую через WMI,
        // иногда требуется работа через Win32_NetworkAdapter для сетевых карт.
        device.InvokeMethod("Disable", null); 
        Console.WriteLine($"{device["Name"]} был деактивирован");
    }
}

```
# Пример запроса
```c#
ConnectionOptions options = new ConnectionOptions();
options.Username = "Administrator"; 
options.Password = "Password123";

// Подключаемся к чужому ПК по IP или имени
ManagementScope scope = new ManagementScope(@"\\192.168.1.100\root\cimv2", options);
scope.Connect();

// Теперь все запросы будут выполняться НА ТОМ компьютере
ObjectQuery query = new ObjectQuery("SELECT * FROM Win32_OperatingSystem");
// ... выполнение действий ...

```
