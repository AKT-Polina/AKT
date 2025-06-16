```powershell
Add-Type -AssemblyName System.Windows.Forms

# Создаём форму
$form = New-Object System.Windows.Forms.Form
$form.Text = "Моё первое окно"
$form.Width = 300
$form.Height = 200

# Добавляем кнопку
$button = New-Object System.Windows.Forms.Button
$button.Text = "Нажми меня!"
$button.Width = 100
$button.Height = 30
$button.Add_Click({
    [System.Windows.Forms.MessageBox]::Show("Привет, PowerShell GUI!", "Ура!")
})

# Размещаем кнопку по центру
$button.Left = ($form.Width - $button.Width) / 2
$button.Top = ($form.Height - $button.Height) / 2

# Добавляем кнопку на форму
$form.Controls.Add($button)

# Показываем форму
$form.ShowDialog()
```