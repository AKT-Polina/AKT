#mysql
**По идее всё делается так у нормальных людей**
(Возможно нам не понадобятся первые два пункта, а если у нас не будет  MySql.Data.MySqlClient, я постараюсь выложить на ForAll установщик драйвера)
Для подключения к базе данных MySQL из приложения Windows Forms, вам нужно выполнить следующие шаги:

1.  Установить драйвер MySQL для .NET. Вы можете скачать его с официального сайта MySQL: [https://dev.mysql.com/downloads/connector/net/](https://dev.mysql.com/downloads/connector/net/)
    
2.  Добавить ссылку на драйвер MySQL в ваш проект Windows Forms. Для этого откройте Solution Explorer, щелкните правой кнопкой мыши на проекте и выберите "Add Reference". В появившемся окне выберите вкладку "Browse", найдите файл драйвера MySQL и добавьте его в проект. (C:\Program Files (x86)\MySQL\Connector NET 8.0\MySql.Data.dll)
    
3.  Импортировать пространство имен MySQL.Data.MySqlClient в код вашего приложения:

```c#
using MySql.Data.MySqlClient;

```

4. Создать объект подключения к базе данных MySQL:

```csharp
MySqlConnection conn = new MySqlConnection("server=localhost;user id=root;database=mydatabase");
```

где "localhost" - адрес сервера базы данных, "root" - имя пользователя базы данных, "mydatabase" - имя базы данных.

5. Открыть подключение к базе данных:

```csharp
conn.Open();
```

6. Выполнить запрос к базе данных:

```csharp
string sql = "SELECT * FROM mytable";
MySqlCommand cmd = new MySqlCommand(sql, conn);
MySqlDataReader reader = cmd.ExecuteReader();
while (reader.Read())
{
    // обработка результата запроса
}
```

где "mytable" - имя таблицы, из которой вы хотите получить данные.

7. Закрыть подключение к базе данных:

```csharp
conn.Close();
```

## Вывод данных в таблицу

Чтобы вывести данные из MySQL в DataGridView в C#, вам нужно использовать объекты MySqlDataAdapter и DataTable.  
  
Вот пример кода, который выполняет запрос на выборку данных из таблицы и выводит их в DataGridView:  
  
```csharp  
using MySql.Data.MySqlClient;  
using [System.Data](https://vk.com/away.php?to=http%3A%2F%2FSystem.Data&cc_key=);  
using System.Windows.Forms;  
  
// строка подключения к базе данных  
string connectionString = "server=localhost;user id=root;database=mydatabase";  
  
// запрос на выборку данных  
string query = "SELECT * FROM mytable";  
  
// создание объекта MySqlConnection  
using (MySqlConnection connection = new MySqlConnection(connectionString))  
{  
// создание объекта MySqlDataAdapter  
MySqlDataAdapter adapter = new MySqlDataAdapter(query, connection);  
  
// создание объекта DataTable для хранения результатов запроса  
DataTable table = new DataTable();  
  
// заполнение DataTable результатами запроса  
adapter.Fill(table);  
  
// вывод результатов в DataGridView  
DataGridView dataGridView1 = new DataGridView();  
dataGridView1.DataSource = table;  
}  
```  
  
В этом примере мы создали объект MySqlConnection, передав в конструктор строку подключения к базе данных. Затем мы создали объект MySqlDataAdapter, передав в конструктор запрос на выборку данных и объект MySqlConnection.  
  
Затем мы создали объект DataTable, который будет использоваться для хранения результатов запроса, и заполнили его результатами запроса с помощью метода Fill() объекта MySqlDataAdapter.  
  
Наконец, мы создали объект DataGridView и установили его источник данных в наш DataTable с помощью свойства DataSource.  

	MySqlDataAdapter - это класс-адаптер, который преобразует данные из MySQL в объекты, которые можно использовать в C#, такие как объекты DataTable и DataSet.  
	Он содержит методы для заполнения DataTable данными из результатов запросов, вставки, обновления и удаления строк в базе данных.    
	MySqlDataAdapter может быть использован для выполнения операций выборки, вставки, обновления и удаления данных в базе данных MySQL, а также для выполнения хранимых процедур и функций.