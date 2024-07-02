using System;
using System.Data;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace DB
{
    public partial class Form1 : Form
    {
        private string connectionString;
        private MySqlConnection conn;
        private System.Data.DataTable dataTable;
        private MySqlDataAdapter adapter;
        private string tableName;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void button13_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Water_place";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button12_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Type_of_flotation_device";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text;
            string password = textBox2.Text;
            connectionString = "Data Source=localhost;Initial Catalog=BoatStation;User ID= " + username + ";Password=" + password;
            conn = new MySqlConnection(connectionString);
            try
            {
                conn.Open();
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка входа");
            }
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (conn != null && conn.State == ConnectionState.Open)
                conn.Close();
        }
        private void button11_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Type_of_condition";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button10_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Technical_condition";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button9_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Staff";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button8_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Repair";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button7_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Orders";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button6_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Customer";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button5_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Issuance_of_watercraft";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Instruction";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button3_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Flotation_device";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * FROM Danger_level";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
        private void button24_Click(object sender, EventArgs e)
        {
            try
            {
                MySqlCommandBuilder commandBuilder = new MySqlCommandBuilder(adapter);
                adapter.Update(dataTable);

            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button14_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT o.number, o.date_order, o.amount, s.surname, s.name, s.patronymic_name " +
                "FROM Orders o " +
                "JOIN Staff s ON o.stuff_ID = s.stuff_ID;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button23_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT o.type_float, o.date_order, o.amount " +
                "FROM Orders o " +
                "JOIN Staff s ON o.stuff_ID = s.stuff_ID " +
                "WHERE s.stuff_ID = 1;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button15_Click(object sender, EventArgs e)
        {
            string selectQuery = 
                "SELECT s.surname, s.name, s.patronymic_name, i.number_of_float " +
                "FROM Staff s " +
                "JOIN Issuance_of_watercraft i ON s.stuff_ID = i.stuff_ID;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button16_Click(object sender, EventArgs e)
        { 
            string selectQuery = "SELECT r.number_of_float " +
                "FROM Repair r " +
                "WHERE r.finish_date IS NULL;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button20_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT f.number_of_float, f.type_float " +
                "FROM Flotation_device f " +
                "WHERE f.availability = 'свободно';";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button17_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT p.water, i.number_of_float, d.level " +
                "FROM Water_place p " +
                "JOIN Issuance_of_watercraft i ON p.water = i.water " +
                "JOIN Flotation_device f ON f.number_of_float = i.number_of_float " +
                "JOIN Danger_level d ON d.type_float = f.type_float;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button21_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT i.number_of_float, c.surname_cust, w.water " +
                "FROM Issuance_of_watercraft i " +
                "JOIN Customer c ON i.passport = c.passport " +
                " JOIN Water_place w ON i.water = w.water;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button18_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT i.number_of_float, i.water, c.surname_cust, t.type AS technical_condition " +
                "FROM Issuance_of_watercraft i " +
                "JOIN Customer c ON i.passport = c.passport " +
                "JOIN Technical_condition t ON i.number_of_float = t.number_of_float;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button22_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * " +
                "FROM Flotation_device " +
                "WHERE amt_life_safing_equipment > 2;";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button19_Click(object sender, EventArgs e)
        {
            string selectQuery = "SELECT * " +
                "FROM Issuance_of_watercraft " +
                "WHERE end_date = '2024-05-15';";
            try
            {
                adapter = new MySqlDataAdapter(selectQuery, conn);
                System.Data.DataTable dataTable = new System.Data.DataTable();
                adapter.Fill(dataTable);
                dataGridView1.DataSource = dataTable;
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }

        private void button26_Click(object sender, EventArgs e)
        {
            try
            {
                int selectedIndex = dataGridView1.SelectedRows[0].Index;
                dataGridView1.Rows.Remove(dataGridView1.Rows[selectedIndex]);
                MySqlCommandBuilder commandBuilder = new MySqlCommandBuilder(adapter);
                adapter.Update(dataTable);
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка выполнения запроса");
            }
        }
    }
}
