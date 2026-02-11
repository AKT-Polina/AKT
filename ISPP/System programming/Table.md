# 1. Создать источник данных
```c#
using System.Data;

var dt = new DataTable();
dt.Columns.Add("ID", typeof(int));
dt.Columns.Add("Имя", typeof(string));
dt.Columns.Add("Роль", typeof(string));

dt.Rows.Add(1, "Admin", "Босс");
dt.Rows.Add(2, "User1", "Разработчик");

```
# 2.Инициализируйте TableView и свяжите его с данными
```c#
var tableView = new TableView() {
    X = 0,
    Y = 0,
    Width = Dim.Fill(),
    Height = Dim.Fill()
};

tableView.Table = dt; // Привязываем DataTable к таблице

```
# 3. Настройте внешний вид
```c# 
// Например, чтобы выровнять колонку ID по центру
tableView.Style.GetOrCreateColumnStyle(dt.Columns["ID"]).Alignment = TextAlignment.Centered;

```
