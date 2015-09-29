#include <stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<vector>
#include<utility>
#include<string>
#include<map>
#include<algorithm>
#include"../Libraries/Vectors.h"
#define isFile 0
#define Problem "A"
#define SL 0
#define filePath "./"
#define lp1(I,A) for(int I=0;I<(A);I++)
#define lp2(I,A,B) for(int I=(A);I<(B);I++)
#define lp3(I,A,B) for(int I=(A);I>=(B);I--)

using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            switch(c)
            {
                case '1':
                    cout<<"ㄅ";
                    break;
                case 'q':
                    cout<<"ㄆ";
                    break;
                case 'a':
                    cout<<"ㄇ";
                    break;
                case 'z':
                    cout<<"ㄈ";
                    break;
                case '2':
                    cout<<"ㄉ";
                    break;
                case 'w':
                    cout<<"ㄊ";
                    break;
                case 's':
                    cout<<"ㄋ";
                    break;
                case 'x':
                    cout<<"ㄌ";
                    break;
                case '3':
                    cout<<"ˇ";
                    break;
                case 'e':
                    cout<<"ㄍ";
                    break;
                case 'd':
                    cout<<"ㄎ";
                    break;
                case 'c':
                    cout<<"ㄏ";
                    break;
                case '4':
                    cout<<"ˋ";
                    break;
                case 'r':
                    cout<<"ㄐ";
                    break;
                case 'f':
                    cout<<"ㄑ";
                    break;
                case 'v':
                    cout<<"ㄒ";
                    break;
                case '5':
                    cout<<"ㄓ";
                    break;
                case 't':
                    cout<<"ㄔ";
                    break;
                case 'g':
                    cout<<"ㄕ";
                    break;
                case 'b':
                    cout<<"ㄖ";
                    break;
                case '6':
                    cout<<"ˊ";
                    break;
                case 'y':
                    cout<<"ㄗ";
                    break;
                case 'h':
                    cout<<"ㄘ";
                    break;
                case 'n':
                    cout<<"ㄙ";
                    break;
                case '7':
                    cout<<"˙";
                    break;
                case 'u':
                    cout<<"ㄧ";
                    break;
                case 'j':
                    cout<<"ㄨ";
                    break;
                case 'm':
                    cout<<"ㄩ";
                    break;
                case '8':
                    cout<<"ㄚ";
                    break;
                case 'i':
                    cout<<"ㄛ";
                    break;
                case 'k':
                    cout<<"ㄜ";
                    break;
                case ',':
                    cout<<"ㄝ";
                    break;
                case '9':
                    cout<<"ㄞ";
                    break;
                case 'o':
                    cout<<"ㄟ";
                    break;
                case 'l':
                    cout<<"ㄠ";
                    break;
                case '.':
                    cout<<"ㄡ";
                    break;
                case '0':
                    cout<<"ㄢ";
                    break;
                case 'p':
                    cout<<"ㄣ";
                    break;
                case ';':
                    cout<<"ㄤ";
                    break;
                case '/':
                    cout<<"ㄥ";
                    break;
                case '-':
                    cout<<"ㄦ";
                    break;
            }
            
        }
        cout<<endl;
    }
}