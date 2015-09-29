using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net;

namespace UVA_Download
{
    public partial class Form1 : Form
    {
        string FP = "C:\\";
        public Form1()
        {
            InitializeComponent();
        }

        private void download_Click(object sender, EventArgs e)
        {
            label1.Text = "Downloading...";
            for (int i = 8; i <= 129; i++)
            {
                if (i >= 20 && i <= 99) continue;
                int volume = i;
                for (int j = 0; j < 100; j++)
                {
                    int problemID = volume*100+j;
                    richTextBox1.Text = "uva_" + problemID.ToString() + "\n";
                    string url = "http://uva.onlinejudge.org/external/" + volume.ToString() + "/" + problemID.ToString() + ".html";
                    string FN = "uva_" + problemID.ToString() + ".html";
                    //label1.Text = url + " To " + FN;

                    try
                    {
                        HttpWebRequest httpReq = (HttpWebRequest)WebRequest.Create(url);
                        httpReq.Timeout = 3000;
                        HttpWebResponse httpRes = (HttpWebResponse)httpReq.GetResponse();

                        System.IO.Stream dataStream = httpRes.GetResponseStream();
                        byte[] buffer = new byte[8192];
                        FileStream fs = new FileStream(FP + FN, FileMode.Create, FileAccess.Write);
                        label1.Text = url + " To " + FN;
                        int size = 0;
                        long totalSize = httpRes.ContentLength;
                        long procSize = 0;
                        int ratio;
                        do
                        {
                            size = dataStream.Read(buffer, 0, buffer.Length);
                            procSize += size;
                            ratio = (int)(100 * procSize / totalSize);
                            progressBar1.Value = ratio;
                            if (size > 0)
                                fs.Write(buffer, 0, size);
                        } while (size > 0);
                        fs.Close();

                        httpRes.Close();
                    }
                    catch
                    {
                        label1.Text = url + " Not Found";
                    }

                    url = "http://uva.onlinejudge.org/external/" + volume.ToString() + "/" + problemID.ToString() + ".pdf";
                    FN = "uva_" + problemID.ToString() + ".pdf";
                    //label1.Text = url + " To " + FN;

                    try
                    {
                        HttpWebRequest httpReq = (HttpWebRequest)WebRequest.Create(url);
                        httpReq.Timeout = 3000;
                        HttpWebResponse httpRes = (HttpWebResponse)httpReq.GetResponse();

                        System.IO.Stream dataStream = httpRes.GetResponseStream();
                        byte[] buffer = new byte[8192];
                        FileStream fs = new FileStream(FP + FN, FileMode.Create, FileAccess.Write);
                        int size = 0;
                        long totalSize = httpRes.ContentLength;
                        long procSize = 0;
                        int ratio;
                        do
                        {
                            size = dataStream.Read(buffer, 0, buffer.Length);
                            procSize += size;
                            ratio = (int)(100 * procSize / totalSize);
                            progressBar1.Value = ratio;
                            if (size > 0)
                                fs.Write(buffer, 0, size);
                        } while (size > 0);
                        fs.Close();

                        httpRes.Close();
                    }
                    catch
                    {
                        label1.Text = url + " Not Found";
                        //continue;
                    }
                    
                    //Download images;
                    int imgnum = 1;
                    while (true)
                    {
                        string imageFN = problemID.ToString() + "img" + imgnum.ToString() + ".gif";
                        url = "http://uva.onlinejudge.org/external/" + volume.ToString() + "/" + imageFN;
                        //label1.Text = url + " To " + imageFN;
                        try
                        {
                            HttpWebRequest httpReq = (HttpWebRequest)WebRequest.Create(url);
                            httpReq.Timeout = 3000;
                            HttpWebResponse httpRes = (HttpWebResponse)httpReq.GetResponse();

                            System.IO.Stream dataStream = httpRes.GetResponseStream();
                            byte[] buffer = new byte[8192];
                            FileStream fs = new FileStream(FP + imageFN, FileMode.Create, FileAccess.Write);
                            
                            int size = 0;
                            long totalSize = httpRes.ContentLength;
                            long procSize = 0;
                            int ratio;
                            do
                            {
                                size = dataStream.Read(buffer, 0, buffer.Length);
                                procSize += size;
                                ratio = (int)(100 * procSize / totalSize);
                                progressBar1.Value = ratio;
                                if (size > 0)
                                    fs.Write(buffer, 0, size);
                            } while (size > 0);
                            fs.Close();

                            httpRes.Close();
                        }
                        catch
                        {
                            label1.Text = url + " Not Found";
                            break;
                        }
                        imgnum++;
                    }
                    //label1.Text = problemID.ToString() + " Done";
                }
            }
            label1.Text = "Done";
        }

        private void browse_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1.ShowDialog();
            FP = folderBrowserDialog1.SelectedPath + "\\";
            label2.Text = "Save in : " + FP;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ServicePointManager.DefaultConnectionLimit = 10;
        }
    }
}
