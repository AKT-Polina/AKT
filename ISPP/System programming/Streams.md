```c#
using System.IO;

// Открываем поток к файлу
using (FileStream fs = new FileStream("large_video.mp4", FileMode.Open, FileAccess.Read))
{
    byte[] buffer = new byte[4096]; // Буфер на 4 КБ
    int bytesRead;

    // Читаем, пока данные не закончатся
    while ((bytesRead = fs.Read(buffer, 0, buffer.Length)) > 0)
    {
        // Обрабатываем считанный кусочек (buffer)
        Console.WriteLine($"Прочитано байт: {bytesRead}");
    }
}

```
	- **NetworkStream:** Читаем данные из интернета.
```c#
using System.Net.Sockets;
using System.Text;

// Представим, что мы подключились к серверу
TcpClient client = new TcpClient("127.0.0.1", 8080);
using (NetworkStream ns = client.GetStream())
{
    byte[] buffer = new byte[1024];
    
    // Ждем данные от сервера асинхронно
    int bytesRead = await ns.ReadAsync(buffer, 0, buffer.Length);
    
    string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);
    Console.WriteLine($"Сервер ответил: {response}");
}

```
	- **MemoryStream:** Читаем массив байт прямо из оперативной памяти.
```c#
using System.IO;

byte[] myData = { 72, 101, 108, 108, 111 }; // Байты слова "Hello"

// Оборачиваем массив в поток
using (MemoryStream ms = new MemoryStream(myData))
{
    // Мы можем переместить "курсор" в начало или конец
    ms.Seek(0, SeekOrigin.Begin);

    int firstByte = ms.ReadByte();
    Console.WriteLine($"Первый байт: {firstByte}"); // Выведет 72 (буква 'H')
}
```
