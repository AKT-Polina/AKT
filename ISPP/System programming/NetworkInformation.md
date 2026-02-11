Информация об устройствах 
```c#
using System.Net.NetworkInformation;
 
var adapters = NetworkInterface.GetAllNetworkInterfaces();
Console.WriteLine($"Обнаружено {adapters.Length} устройств");
foreach (NetworkInterface adapter in adapters)
{
    Console.WriteLine("=====================================================================");
    Console.WriteLine();
    Console.WriteLine($"ID устройства: ------------- {adapter.Id}");
    Console.WriteLine($"Имя устройства: ------------ {adapter.Name}");
    Console.WriteLine($"Описание: ------------------ {adapter.Description}");
    Console.WriteLine($"Тип интерфейса: ------------ {adapter.NetworkInterfaceType}");
    Console.WriteLine($"Физический адрес: ---------- {adapter.GetPhysicalAddress()}");
    Console.WriteLine($"Статус: -------------------- {adapter.OperationalStatus}");
    Console.WriteLine($"Скорость: ------------------ {adapter.Speed}");
 
    IPInterfaceStatistics stats = adapter.GetIPStatistics();
    Console.WriteLine($"Получено: ----------------- {stats.BytesReceived}");
    Console.WriteLine($"Отправлено: --------------- {stats.BytesSent}");
}
```
Информация о подключениях 
```c#
using System.Net.NetworkInformation;
 
var ipProps = IPGlobalProperties.GetIPGlobalProperties();
var tcpConnections = ipProps.GetActiveTcpConnections();
 
Console.WriteLine($"Всего {tcpConnections.Length} активных TCP-подключений");
Console.WriteLine();
foreach (var connection in tcpConnections)
{
    Console.WriteLine("=============================================");
    Console.WriteLine($"Локальный адрес: {connection.LocalEndPoint.Address}:{connection.LocalEndPoint.Port}");
    Console.WriteLine($"Адрес удаленного хоста: {connection.RemoteEndPoint.Address}:{connection.RemoteEndPoint.Port}");
    Console.WriteLine($"Состояние подключения: {connection.State}");
}
```
Отслеживание трафика
```c#
using System.Net.NetworkInformation;
 
var ipProps = IPGlobalProperties.GetIPGlobalProperties();
var ipStats = ipProps.GetIPv4GlobalStatistics();
Console.WriteLine($"Входящие пакеты: {ipStats.ReceivedPackets}");
Console.WriteLine($"Исходящие пакеты: {ipStats.OutputPacketRequests}");
Console.WriteLine($"Отброшено входящих пакетов: {ipStats.ReceivedPacketsDiscarded}");
Console.WriteLine($"Отброшено исходящих пакетов: {ipStats.OutputPacketsDiscarded}");
Console.WriteLine($"Ошибки фрагментации: {ipStats.PacketFragmentFailures}");
Console.WriteLine($"Ошибки восстановления пакетов: {ipStats.PacketReassemblyFailures}");
```
