#mysql
CASE - это оператор условного выражения в языке SQL, который позволяет выполнять различные действия в зависимости от значения определенного выражения или условия. Он часто используется для трансформации и агрегации данных.

Синтаксис CASE выглядит следующим образом:

```sql
CASE
    WHEN condition_1 THEN result_1
    WHEN condition_2 THEN result_2
    ...
    WHEN condition_n THEN result_n
    ELSE default_result
END
```

В этом выражении условия и результаты определены с помощью ключевых слов `WHEN` и `THEN`. Если ни одно из условий не выполняется, оператор CASE возвращает результат, указанный в блоке `ELSE`. Если блок `ELSE` не указан, то оператор CASE возвращает NULL.

1.  Простой пример использования CASE для выбора значения в зависимости от условия:

```sql
SELECT 
  product_name,
  CASE
    WHEN price < 50 THEN 'cheap'
    WHEN price >= 50 AND price <= 100 THEN 'moderate'
    ELSE 'expensive'
  END AS price_category
FROM products;
```

2.  CASE также может использоваться вместе с другими функциями агрегации, например, для вычисления суммы продаж в зависимости от категории товара:

```sql
SELECT 
  category,
  SUM(CASE
    WHEN price < 50 THEN sale_amount
    ELSE 0
  END) AS cheap_sales,
  SUM(CASE
    WHEN price >= 50 AND price <= 100 THEN sale_amount
    ELSE 0
  END) AS moderate_sales,
  SUM(CASE
    WHEN price > 100 THEN sale_amount
    ELSE 0
  END) AS expensive_sales
FROM sales
GROUP BY category;
```

3.  CASE также может использоваться для выполнения различных действий в зависимости от различных значений поля:

```sql
UPDATE employees
SET salary = 
  CASE 
    WHEN department = 'sales' THEN salary * 1.1
    WHEN department = 'marketing' THEN salary * 1.2
    ELSE salary
  END;
```

