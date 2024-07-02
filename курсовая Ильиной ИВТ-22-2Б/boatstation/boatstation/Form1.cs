using System;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace boatstation
{
    public partial class Form1 : Form
    {
        private TextBox txtUsername;
        private TextBox txtPassword;
        private TextBox txt;
        private Button btnStart;
        private Button btnSelect;
        private Button btnInsert;
        private Button btnUpdate;
        private Button btnDelete;
        private Button btn;
        private Button sql;
        private MySqlConnection conn;
        private MySqlCommand cmd;
        private string connectionString;
        private DataGridView dataGridView;
        public Form1()
        {
            InitializeComponent();
            this.FormClosing += Form1_FormClosing;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            StartScreen();
        }
        private void StartScreen()
        {
            ClearFormControls();
            Label lbl = new Label();
            lbl.Text = "Вход в базу данных Лодочной станции";
            lbl.AutoSize = true;
            lbl.Location = new System.Drawing.Point(200, 50);
            Controls.Add(lbl);

            Label lblUsername = new Label();
            lblUsername.Text = "Имя пользователя:";
            lblUsername.Location = new System.Drawing.Point(200, 100);
            Controls.Add(lblUsername);

            txtUsername = new TextBox();
            txtUsername.Size = new System.Drawing.Size(100, 20);
            txtUsername.Location = new System.Drawing.Point(300, 100);
            Controls.Add(txtUsername);

            Label lblPassword = new Label();
            lblPassword.Text = "Пароль:";
            lblPassword.Location = new System.Drawing.Point(200, 150);
            Controls.Add(lblPassword);

            txtPassword = new TextBox();
            txtPassword.Size = new System.Drawing.Size(100, 20);
            txtPassword.Location = new System.Drawing.Point(300, 150);
            Controls.Add(txtPassword);

            btnStart = new Button();
            btnStart.Text = "Войти";
            btnStart.Location = new System.Drawing.Point(250, 200);
            btnStart.Click += BtnStart_Click;
            Controls.Add(btnStart);
        }
        private void MainScreen()
        {
            Label user = new Label();
            user.Text = "Пользователь: " + txtUsername.Text;
            user.AutoSize = true;
            user.Location = new System.Drawing.Point(490 - user.Text.Count(), 0);
            Controls.Add(user);

            Label lbl = new Label();
            lbl.Text = "Выберете действие:";
            lbl.AutoSize = true;
            lbl.Location = new System.Drawing.Point(100, 10);
            Controls.Add(lbl);
            
            Label lblSelect = new Label();
            lblSelect.Text = "Просмотр данных";
            lblSelect.AutoSize = true;
            lblSelect.Location = new System.Drawing.Point(100, 60);
            Controls.Add(lblSelect);

            btnSelect = new Button();
            btnSelect.Text = "Select";
            btnSelect.Location = new System.Drawing.Point(400, 60);
            btnSelect.Click += BtnSelect_Click;
            Controls.Add(btnSelect);

            Label lblInsert = new Label();
            lblInsert.Text = "Добавить новые записи";
            lblInsert.AutoSize = true;
            lblInsert.Location = new System.Drawing.Point(100, 110);
            Controls.Add(lblInsert);

            btnInsert = new Button();
            btnInsert.Text = "Insert";
            btnInsert.Location = new System.Drawing.Point(400, 110);
            btnInsert.Click += BtnInsert_Click;
            Controls.Add(btnInsert);

            Label lblUpdate = new Label();
            lblUpdate.Text = "Изменить данные";
            lblUpdate.AutoSize = true;
            lblUpdate.Location = new System.Drawing.Point(100, 160);
            Controls.Add(lblUpdate);

            btnUpdate = new Button();
            btnUpdate.Text = "Update";
            btnUpdate.Location = new System.Drawing.Point(400, 160);
            btnUpdate.Click += BtnUpdate_Click;
            Controls.Add(btnUpdate);

            Label lblDelete = new Label();
            lblDelete.Text = "Удалить данные";
            lblDelete.AutoSize = true;
            lblDelete.Location = new System.Drawing.Point(100, 210);
            Controls.Add(lblDelete);

            btnDelete = new Button();
            btnDelete.Text = "Delete";
            btnDelete.Location = new System.Drawing.Point(400, 210);
            btnDelete.Click += BtnDelete_Click;
            Controls.Add(btnDelete);

            Label lblUser = new Label();
            lblUser.Text = "Выйти";
            lblUser.AutoSize = true;
            lblUser.Location = new System.Drawing.Point(390, 275);
            Controls.Add(lblUser);

            btn = new Button();
            btn.Text = "User";
            btn.Location = new System.Drawing.Point(500, 270);
            btn.Click += BtnUsers_Click;
            Controls.Add(btn);

            Label lblSQL = new Label();
            lblSQL.Text = "Вызов консоли SQL";
            lblSQL.AutoSize = true;
            lblSQL.Location = new System.Drawing.Point(390, 305);
            Controls.Add(lblSQL);

            sql = new Button();
            sql.Text = "SQL";
            sql.Location = new System.Drawing.Point(500, 300);
            sql.Click += BtnSQL_Click;
            Controls.Add(sql);
        }
        private void BtnMain_Click(object sender, EventArgs e)
        {
            MainScreen();
        }
        private void BtnSQL_Click(object sender, EventArgs e)
        {
            ClearFormControls();
        }
        private void BtnUsers_Click(object sender, EventArgs e)
        {
            StartScreen();
        }
        private void BtnStart_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text;
            string password = txtPassword.Text;
            connectionString += "Data Source=localhost;Initial Catalog=BoatStation;User ID=" + username + ";Password=" + password;
            conn = new MySqlConnection(connectionString);
            try
            {
                conn.Open();
                ClearFormControls();
                MainScreen();
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка подключения");
            }
        }
        private void BtnSelect_Click(object sender, EventArgs e)
        {
            ClearFormControls();
            Label lbl = new Label();
            lbl.Text = "Вывод таблицы(столбцов):";
            lbl.AutoSize = true;
            lbl.Location = new System.Drawing.Point(10, 10);
            Controls.Add(lbl);

            txt = new TextBox();
            txt.Size = new System.Drawing.Size(490, 20);
            txt.Location = new System.Drawing.Point(10, 25);
            Controls.Add(txt);

            btn = new Button();
            btn.Text = "Вывод";
            btn.Location = new System.Drawing.Point(500, 25);
            btn.Click += BtnSelect1_Click;
            Controls.Add(btn);

            Button button = new Button();
            button = new Button();
            button.Text = "Выход";
            button.Location = new System.Drawing.Point(500, 0);
            button.Click += BtnMain_Click;
            Controls.Add(button);
        }
        private void BtnSelect1_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM " + txt.Text;
            ClearDataGridView();
            try
            {
                MySqlDataAdapter adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView = new DataGridView();
                dataGridView.DataSource = dataTable;
                dataGridView.Size = new Size(2000, 1000);
                dataGridView.Location = new Point(0, 50);
                Controls.Add(dataGridView);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка выполнения запроса: " + ex.Message);
            }
        }
        private void BtnInsert_Click(object sender, EventArgs e)
        {
            ClearFormControls();
            string boatName = "Example Boat"; // Пример имени лодки
            string boatType = "Sailing"; // Пример типа лодки
            int boatCapacity = 10; // Пример вместимости лодки

            string sql = "INSERT INTO Boat (Name, Type, Capacity) VALUES (@Name, @Type, @Capacity)";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@Name", boatName);
            cmd.Parameters.AddWithValue("@Type", boatType);
            cmd.Parameters.AddWithValue("@Capacity", boatCapacity);

            try
            {
                conn.Open();
                int rowsAffected = cmd.ExecuteNonQuery();
                MessageBox.Show(rowsAffected + " запись(и/ей) добавлена(ы) успешно");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка при добавлении записи: " + ex.Message);
            }
        }
        private void BtnDelete_Click(object sender, EventArgs e)
        {
            ClearFormControls();
            int boatIdToDelete = 1; // Пример ID лодки для удаления

            string sql = "DELETE FROM Boat WHERE BoatID = @BoatID";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@BoatID", boatIdToDelete);

            try
            {
                conn.Open();
                int rowsAffected = cmd.ExecuteNonQuery();
                MessageBox.Show(rowsAffected + " запись(и/ей) удалена(ы) успешно");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка при удалении записи: " + ex.Message);
            }
        }
        private void BtnUpdate_Click(object sender, EventArgs e)
        {
            ClearFormControls();
            int boatIdToUpdate = 1; // Пример ID лодки для обновления
            string updatedBoatName = "Updated Boat"; // Пример обновленного имени лодки
            string updatedBoatType = "Motor"; // Пример обновленного типа лодки
            int updatedBoatCapacity = 12; // Пример обновленной вместимости лодки

            string sql = "UPDATE Boat SET Name = @Name, Type = @Type, Capacity = @Capacity WHERE BoatID = @BoatID";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@Name", updatedBoatName);
            cmd.Parameters.AddWithValue("@Type", updatedBoatType);
            cmd.Parameters.AddWithValue("@Capacity", updatedBoatCapacity);
            cmd.Parameters.AddWithValue("@BoatID", boatIdToUpdate);

            try
            {
                int rowsAffected = cmd.ExecuteNonQuery();
                MessageBox.Show(rowsAffected + " запись(и/ей) обновлена(ы) успешно");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка при обновлении записи: " + ex.Message);
            }
        }
        private void ClearFormControls()
        {
            Controls.Clear();
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (conn != null && conn.State == ConnectionState.Open)
                conn.Close();
        }
        private void ClearDataGridView()
        {
            foreach (Control control in Controls)
            {
                if (control is DataGridView)
                {
                    Controls.Remove(control);
                    control.Dispose();
                    break; // После удаления первого DataGridView, выходим из цикла
                }
            }
        }
    }
}
