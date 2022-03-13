using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace 内测版
{
    public partial class frmmomo : Form
    {
        public static string fileToString(String filePath)
        {
            string strData = "";
            try
            {
                string line;
                // 创建一个 StreamReader 的实例来读取文件 ,using 语句也能关闭 StreamReader
                using (System.IO.StreamReader sr = new System.IO.StreamReader(filePath))
                {
                    // 从文件读取并显示行，直到文件的末尾
                    while ((line = sr.ReadLine()) != null)
                    {
                        //Console.WriteLine(line);
                        strData = line;
                    }
                }
            }
            catch (Exception e)
            {
                // 向用户显示出错消息
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
            return strData;
        }
        public static int SavaProcess(string data, string FileName, int X, int Y,int loc)
        {
            //设置目录
            string CurDir = System.AppDomain.CurrentDomain.BaseDirectory;
            //判断路径是否存在
            if (!System.IO.Directory.Exists(CurDir))
            {
                System.IO.Directory.CreateDirectory(CurDir);
            }
            //不存在就创建
            String FilePath = CurDir + FileName;
            //文件覆盖方式添加内容
            System.IO.StreamWriter file = new System.IO.StreamWriter(FilePath, false);
            //保存数据到文件
            file.Write("<Protocol Name>,1.6.2020.0203, <User Name>, 06/15/2021, 12:45\n");
            file.Write("PurePlate80_200, Source Plate 1, 8.00E-05, MWP 96, Target Plate 1, H12, Eppi\n");
            file.Write("DispenseToWaste=False, DispenseToWasteCycles=3, DispenseToWasteVolume=1e-7,UseDeionisation=True,OptimizationLevel=ReorderAndParallel,WasteErrorHandlingLevel=Ask,SaveLiquids=Ask\n");
            file.Write("Source Well, Target Well, Volume [uL], Liquid Name\n");
            char[] mes = data.ToCharArray();
            int i, j, t = loc;

            for (i = 1; i < Y + 1; i++)
            {
                char hen = 'A';
                char hen0 = 'A';
                hen0--;
                for (j = 0; j < X; j++)
                {
                    if (t >= data.Length)
                    { //关闭文件
                        file.Close();
                        //释放对象
                        file.Dispose();
                        return t;
                    }
                    char q1 = 'A';
                    int q2 = '0';
                    if (mes[t] - 'L' <= 0)
                        q2 = mes[t] - 'A' + 1;
                    else
                    {
                        q1 = 'B';
                        q2 = mes[t] - 'L';
                    }
                    if (j > 25)
                    {
                        file.Write(q1);
                        file.Write(q2 + "," + hen0 + hen + i + ",," + mes[t] + "\n");
                    }
                    else
                    {
                        file.Write(q1);
                        file.Write(q2 + "," + hen + i + ",," + mes[t] + "\n");
                    }
                    t++;
                    if (hen == 'Z')
                    {
                        hen = 'A';
                        hen0++;
                    }
                    else
                        hen++;
                }
            }
            file.Close();
            //释放对象
            file.Dispose();
            return t;
        }
        public frmmomo()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.textxt.Text.Trim() == string.Empty)
            {
                MessageBox.Show("请输入应读取的txt文件", "输入提示", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                this.textxt.Focus();
                return;
            }
            if (this.texX.Text.Trim() == string.Empty)
            {
                MessageBox.Show("请输入横行X的大小", "输入提示", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                this.textxt.Focus();
                return;
            }
            if (this.texY.Text.Trim() == string.Empty)
            {
                MessageBox.Show("请输入纵列Y的大小", "输入提示", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                this.textxt.Focus();
                return;
            }
            if (this.textxt.Text.Trim() == string.Empty)
            {
                MessageBox.Show("请输入文件名", "输入提示", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                this.textxt.Focus();
                return;
            }
            string date = fileToString(textxt.Text + ".txt");
            int tX = Convert.ToInt32(texX.Text);
            int tY = Convert.ToInt32(texY.Text);
            int num = 1, lod = date.Length;
            int loc=0;
            for (num = 1; lod >= 0; lod -= tX * tY, num++)
               loc= SavaProcess(date, texname.Text +"_"+ num + ".csv", tX, tY,loc);
            MessageBox.Show("已经读取并写入了" + date.Length + "个字符", "写入完成", MessageBoxButtons.OK);
        }

        private void labout_Click(object sender, EventArgs e)
        {

        }

        private void texX_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void KeyPressed(object sender, KeyPressEventArgs e)
        {
            if (((int)e.KeyChar < 48 || (int)e.KeyChar > 57) && (int)e.KeyChar != 8 )
                e.Handled = true;
        }

        private void frmmomo_Load(object sender, EventArgs e)
        {

        }

      
    }
}
