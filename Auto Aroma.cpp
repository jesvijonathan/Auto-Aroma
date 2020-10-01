#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <algorithm>
#include <shlobj.h>
#include <Lmcons.h>
#include <atlbase.h>
#include <sstream>
#include <iomanip>
#include <shellapi.h>
#include <shlobj_core.h>
#include <sstream>

#pragma warning(disable : 4996)
//git sucks
#define Title "Auto Aroma"
#define Author "Jesvi Jonathan"
#define Version "v0.6.1"


using namespace std;
using namespace std::experimental::filesystem; 


typedef std::basic_string <TCHAR> StringType;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);



int Theme, P_flag = 0, d = 0, de = 0,in,lim=0,of=0,iof=0,backup=0;

string dir[13], c_pro, usr;

string dd[26] = {
         "                  Retrun Back To Event Editor",
        "                  Display Viewable Contents",
        "                  Display Selectable Options",
        "            Display A Popup Window Between Events",
        "        Add Functions That Operate With The Installer",
        "                        Miscellaneous",

        "                  Retrun Back To Event Editor",
        "              To Display Content Out Of Txt File",
        "           Display Viewable Contents Inside The Code",
        "                 A View Box With Agree Button",
        "              Display Content With A Bool Button",

        "                   Retrun Back To Event Editor",
        "           Multiple Options Can Be Selected In A Group",
        "                Allows Both Check & Selection Types",
        "              Can Select Only One Option In A Group",
        "                   A Gui Menu To Route The Slide" ,

        "                   Retrun Back To Event Editor",
        "                  An Alert Pop With 'OK' Button",
        "              An Popup Window With Custom Ok Button",
        "                    A Popup With Custom Text",

        "                   Retrun Back To Event Editor",
        "                        To Display A Logo",
        "                   To Display A Animated Logo",
        "                   Trigger The Update-Config",
        "                     To Exit The Installer",
        "                     To Reboot The Device" } ;


char* p_exe_path;

BOOL DirectoryExists(const char* dirName) {

    TCHAR nameu[UNLEN + 1];
    DWORD size = UNLEN + 1;
    if (GetUserName((TCHAR*)nameu, &size))
    {
        TCHAR* t = nameu;
        std::string str;
        std::wstring wStr = t;
        str = std::string(wStr.begin(), wStr.end());
        usr = str;

            dir[0] = (std::string("C:\\Users\\") + str),
            dir[1] = (std::string("C:\\Users\\") + str + "\\Documents"),
            dir[2] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma"),
            dir[3] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools" + ""),
            dir[4] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Projects"),
            dir[5] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Templates"),
            dir[6] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools\\List.txt");
            dir[7] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools\\Config.txt");
            dir[8] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools\\Themes");
            dir[9] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools\\Font");
            dir[10] = (std::string("C:\\Users\\") + str + "\\Documents\\Auto_Aroma\\Tools\\Language");
    }


    DWORD attribs = ::GetFileAttributesA(dirName);
    if (attribs == INVALID_FILE_ATTRIBUTES) {
        return false;
    }
    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void GetCurLoc() {
    char cCurrentPath[FILENAME_MAX];
    if (!_getcwd(cCurrentPath, sizeof(cCurrentPath))) { return; }
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    //printf ("The current working directory is %s", cCurrentPath);
   p_exe_path = cCurrentPath;
}

void setscreen(int x, int y)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}

void color(int type,int mode = Theme)
{

    Theme=mode;
    mode = Theme;

    if (mode == 0)
    {
        if (type == 0)
        {
            SetConsoleTextAttribute(console, 15);
        }
        if (type == 1)
        {
            SetConsoleTextAttribute(console, 010);
        }
    
    }

    if (mode == 1)
    {
        if (type == 0)
        {
            SetConsoleTextAttribute(console, 7);
        }
        if (type == 1)
        {
            SetConsoleTextAttribute(console, 240);
        }

    }
  
    



}

void Credits()
{
    system("cls");
    char author[23] = { "Made By Jesvi Jonathan" }, pgm[11] = { "Auto Aroma" };
    cout << "\n\n\n\n\n\t\t\t";

    for (int y = 0; y <= 10; y++)
    {
        color(0);
        cout << pgm[y];
        Sleep(200);
    }

    cout << "\n\n\t\t  ";
    
    for (int y = 0; y <= 22; y++)
    {
        color(0);
        cout << author[y];    
        Sleep(200);
    }


    for (int o = 3; o <= 7; o++)
    {
        system("cls");
        cout << "\n\n\n\n\n\t\t\t";
        cout << pgm;
        cout << "\n\n\t\t  ";

        for (int y = 0; y <= 22; y++)
        {
            color(1);
            cout << author[y];
            
        }
        
        Sleep(200);
        system("cls");
        
        cout << "\n\n\n\n\n\t\t\t";
        cout << pgm;
        cout << "\n\n\t\t  ";

        for (int y = 0; y <= 22; y++)
        {
            color(0);
            cout << author[y];         
        }

        Sleep(200);
    }

    cout << "\n\n";

    for (int y = 0; y <= 80; y++)
    {
        if (y % 2 == 1) { color(1); }
        else { color(0); }
        cout << pgm<<" (" << Version << ") " <<author;
        Sleep(50);
    }

    cout << "\n";
    Sleep(700);
    cout << "\n";
    Sleep(700);
    cout << "\t\tThank ";
    Sleep(500);
    cout << "You ";
    Sleep(1000);
    cout << "For ";
    Sleep(500);
    cout << "Your ";
    Sleep(500);
    cout<<"Patients ";
    Sleep(1000);
    cout<<"!";
    Sleep(1000);
    cout << "\n";
    Sleep(300);
    cout << "\n";
    Sleep(300);
    cout << "\t       Auto ";
    Sleep(500);
    cout << "Aroma ";
    Sleep(1500);
    cout << "By ";
    Sleep(1000);
    cout << "Jesvi ";
    Sleep(500);
    cout<<"Jonathan ";
        
    for (int o = 0; o <= 2; o++)
    {
        cout << ".";
        Sleep(500);     
    }
    
    _getch();

    cout << "\n\n       (Probably The Worst Credit Animation Ever :P)";
    Sleep(500);
}

int key1(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
{

    int Input = _getch();       //Get Keyboard Input 

    if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

    {
        switch (_getch())       //Check For Ascii
        {
        case 72:        //Up
            Pointing--;
            break;

        case 80:        //Down
            Pointing++;
            break;

        case 77:        //Right
            //goto Enter;
            break;

        case 75:        //Left
            //goto Esc;
            break;
        }

    }


    if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

    if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

    if (Input == 27)        //Confirm 'Esc' Input

      // Esc:

    {
        return 27;

    }

    if (Input == 13)

    {
        Pointing += 100;

    }


    return (Pointing);        //Returning Computed Input

}

int display(string* list, int no, int query = 0, int lines = 4, int Pointing_1 = 0, int view = 0, int space = 21, string qtest = "", string* ans = { NULL },int ansp=21)
{

    int No = 0;
    unsigned ttmp = Pointing_1;
    string q, r[20];
    No = no;

    No--;

    if (query == 1)
    {

        q = list[0];

        if (qtest != "")
        {
            q = qtest;
        }

        int yy = 0;

        for (int j = 1; j <= No; j++)
        {
            r[yy] = list[j];
           // cout << r[yy];
            yy++;
        }
    }

    do
    {
        Pointing_1 = ttmp;

        int tmp1 = 0;

        system("cls");

        for (tmp1; tmp1 <= No; tmp1++)
        {

            if (ttmp == 27)
            {
                return 27;
            }

            if (query == 1)
            {

                if (tmp1 == 0)
                {
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);

                    for (int hj = 0; hj < lines; hj++)
                        cout << "\n";

                    color(0);
                    cout << q;
                    color(1);


                    if (view == 1)
                    {
                        int j = 1;
                        if (Pointing_1 == 0 )
                        {
                            j = 3;
                        }
                        if (Pointing_1 == 1)
                        {
                            j = 2;
                        }

                        for (j ; j >= 0; j--)
                        {
                            cout << endl << endl;
                        }
                    }
                 
                    else
                    {
                        for (int j = No - 1; j >= (Pointing_1); j--)
                        {
                            cout << endl << endl;
                        }
                    }
                }

            }

            else
            {
                if (tmp1 == 0)
                {
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);


                    if (view == 1)
                    {
                        int j = 1;
                        if (Pointing_1 == 0)
                        {
                            j = 3;
                        }
                        if (Pointing_1 == 1)
                        {
                            j = 2;
                        }

                        for (j; j >= 0; j--)
                        {
                            cout << endl << endl;
                        }
                    }


                    else 
                    {
                        for (int j = No; j >= (Pointing_1); j--)
                        {
                            cout << endl << endl;
                        }
                    }
                }
            }


            if (query == 1)
            {

                if (view == 1)
                {
                    if (tmp1 == Pointing_1)
                    {
                        for (int i = 0; i < space; i++)
                        {
                            cout << " ";
                        }
                        cout << "-[ ";
                        color(0);
                        cout << r[tmp1];
                        color(1);
                        cout << " ]-" << endl << endl;
                    }

                    if ((tmp1 == Pointing_1 - 1 || tmp1 == Pointing_1 + 1 || tmp1 == Pointing_1 - 2 || tmp1 == Pointing_1 + 2))
                    {
                        for (int i = 0; i < space; i++)
                        {
                            cout << " ";
                        }
                        cout << "   ";
                        cout << r[tmp1] << endl << endl;
                    }
                }
          
                else {
                    if (tmp1 == Pointing_1)
                    {
                        for (int i = 0; i < space; i++)
                        {
                            cout << " ";
                        }
                        cout << "-[ ";
                        color(0);
                        cout << r[tmp1];
                        color(1);
                        cout << " ]-" << endl << endl;
                    }

                    else
                    {
                        for (int i = 0; i < space; i++)
                        {
                            cout << " ";
                        }
                        cout << "   ";
                        cout << r[tmp1] << endl << endl;
                    }
                }
            }


            else
            {

            if(view==1) 
            {
                if (tmp1 == Pointing_1)
                {
                    for (int i = 0; i < space; i++)
                    {
                        cout << " ";
                    }
                    cout << "-[ ";
                    color(0);
                    cout << list[tmp1];
                    color(1);
                    cout << " ]-" << endl << endl;
                }

                if (view == 1 && (tmp1 == Pointing_1 - 1 || tmp1 == Pointing_1 + 1 || tmp1 == Pointing_1 - 2 || tmp1 == Pointing_1 + 2))
                {
                    for (int i = 0; i < space; i++)
                    {
                        cout << " ";
                    }
                    cout << "   ";
                    cout << list[tmp1] << endl << endl;
                }
            }

            else 
            {
                if (tmp1 == Pointing_1)
                {
                    for (int i = 0; i < space; i++)
                    {
                        cout << " ";
                    }
                    cout << "-[ ";
                    color(0);
                    cout << list[tmp1];
                    color(1);
                    cout << " ]-" << endl << endl;
                }
            else
            {
                    for (int i = 0; i < space; i++)
                    {
                        cout << " ";
                    }
                    cout << "   ";
                    cout << list[tmp1] << endl << endl;
            }
            }

            }

            if (view == 1 &&  Pointing_1>=no-2)
            {
                if((tmp1 == no || tmp1 == no-1 || tmp1 == no-2))
                    cout << "";
            }

            if (d == 1 && tmp1==no-1)
            {
                cout << endl << endl << dd[de + Pointing_1];
            }
            if (lim == 1 && tmp1==no-1)
            {
                
                color(0);
                cout << "\n\n                      Type Limit : " << iof << "/" << of;
                color(1);
            }
            else if(lim == 2 && tmp1 == no - 1)
            {
                cout << "\n\n                      Type Limit : " <<iof<<"/"<<of;
            }
        }
        
        if (ans != NULL)
        {
            cout << endl << endl;


            if (ans[Pointing_1] == "")
            {
                color(1);
                cout << "\t\t       ! Field Empty !";
            }
            for (int i = 0; i < ansp; i++)
            {
                cout << " ";
            }
            color(0);
            cout << ans[Pointing_1];
            color(1);
        }
        if (query == 1) { ttmp = key1(No - 1, Pointing_1); }
        else { ttmp = key1(No, Pointing_1); }


    } while (ttmp != 27 && ttmp < 100);
    if (ttmp == 27)
    {
        return 27;
    }
    ttmp -= 100;
    if (query == 1)
    {

    }
    return ttmp;

}

struct project
{
    string project_name,
        developer_name,
        target_device,
        project_version,
        colour_space,

        theme, font,
        language,
        release_date,
        aroma_dpi,
        project_state,

        event_name[30],
        event_type[30];

    int no_events = 0,
        evntprop[30][30],   //0=event type 1=event specific type 2=no of same evnt specif type;
        vblim = 0,
        lblim = 0,
        grp = 0;

    string agroup[7],llist[300];

    ////////// text box
    string save[7], qsave[7], wsave[7], esave[7], iicon[30],
        icon[7];
    char vbstr[7][50];
    /////////// agree box
    char agree[7][20],ckvb[7][20];
} p;

class file
{
public:

    void sendfirst()
    {

        string q[50];
        int e = 0;

        ifstream config(dir[6]);


        while (config >> q[e] && q[e] != "\0")
        {
            e++;
        }

        config.close();

        ofstream config1(dir[6]);

        for (int w = 0; w < e; w++)

        {

            if (q[w] == c_pro)
            {
                config1 << "";
            }
            else
            {
                config1 << q[w] << endl;
            }
        }

        //config1 << "\r";
        config1.close();

    }

    bool fexists(const char* filename)
    {
        ifstream ifile(filename);
        if (ifile)
        {

            return 0;
        }
        else
        {
            return 1;
        }
    }

    void save(int purp = 0)
    {



        if (DirectoryExists((std::string("") + dir[3] + std::string("\\Backups")).c_str()) == 0)
        {
            cout << "Creating Backup";
            system((std::string("mkdir ") + std::string("") + dir[3] + std::string("\\Backups")).c_str());
            Sleep(400);
            cout << "\r               \r";
        }

        ofstream save((std::string("") + dir[4] + std::string("\\") + c_pro + std::string("\\") + c_pro + std::string(".dat")).c_str(), ios::binary);

        save.write(reinterpret_cast<char*>(&p), sizeof(project));
        save.close();


        if (purp == 1)
        {


            string cc = { "" };
            int x = 0;

            if (fexists((std::string("") + dir[3] + std::string("\\Backups") + std::string("\\") + c_pro + std::string(".dat")).c_str()) == 0)
            {
            k:
                if (fexists((std::string("") + dir[3] + std::string("\\Backups") + std::string("\\") + c_pro + to_string(x) + std::string(".dat")).c_str()) == 0)
                {
                    x++;
                    if (x >= 20)
                    {


                    }
                    goto k;
                }
                cc = to_string(x);
            }

            string from = ((std::string("") + dir[4] + std::string("\\") + c_pro + std::string("\\") + c_pro + std::string(".dat")).c_str()),
                to = ((std::string("") + dir[3] + std::string("\\Backups") + std::string("\\") + c_pro + cc + std::string(".dat")).c_str());

            ofstream sab(to, ios::binary);
            sab.write(reinterpret_cast<char*>(&p), sizeof(project));
            sab.close();


        }

    }

    void load_m(string pame)
    {
        c_pro = pame;
        ifstream save((std::string("") + dir[4] + std::string("\\") + c_pro + std::string("\\") + c_pro + std::string(".dat")).c_str(), ios::binary);
        save.read(reinterpret_cast<char*>(&p), sizeof(project));
        save.close();

    }

    void del(string pro)
    {

        int er = 0;
        cout << "\n\n";
        color(0);
        cout << "Deleteing Project";
        color(1);
        cout << "\n\n";

        if (system((std::string("rmdir /s /q ") + dir[4] + std::string("\\") + pro).c_str()) == 0)
        {
            cout << "Deleted : " << ((dir[4] + std::string("\\") + pro).c_str()) << endl;
        }
        else
        {
            cout << "Error Deleteing : " << ((dir[4] + std::string("\\") + pro).c_str()) << endl;
            er = 1;
        }
        Sleep(250);
        string q[50];
        int e = 0;

        ifstream config(dir[6]);


        while (config >> q[e] && q[e] != "\0")
        {
            e++;
        }

        config.close();

        ofstream config1(dir[6]);

        for (int w = 0; w < e; w++)

        {

            if (q[w] == pro)
            {
                config1 << "";
            }
            else
            {
                config1 << q[w] << endl;
            }
        }

        //config1 << "\r";

        config1.close();



    }

    int load_sel(string project)
    {
        string srt[30] = { "\t\t\t\b\b\b\bSelected : " + project ,
            "  Return   ",
            "   Load    ",
            "  Delete   ",
            "    Zip    ",
            " Duplicate ", };

        switch (display(srt, 6, 1, 3, 1, 1))
        {
        case 0: {return 0; break; }
        case 1: {return 1; break; }
        case 2: {return 2; break; }
        case 3: {return 3; break; }
        case 4: {return 4; break; }
        case 27: {return 0; }
        }
        return 0;
    }

    int load()
    {
        int gt = 1;
        //string j[2] = {" "};
    re:
        int e = 2, y, gh;



        string st[30] = { "\t\tSelect The Project To Modify", "Return" };
        ifstream config(dir[6]);

        while (config >> st[e] && st[e] != "\0")
        {
            e++;
        }
        //e--;

        gh = (display(st, e, 1, 3, gt, 1));


        if (gh == 0 || gh == 27)
        {
            return 0;
        }
        else
        {
            gt = gh;
        }

        y = (load_sel(st[gt + 1]));

        if (y == 27 || y == 0)
        {
            goto re;
        }
        else
        {
            switch (y)
            {
            case 1: {
                load_m(st[gt + 1]);
                return 1;
                break; }
            case 2: {
                del(st[gt + 1]);
                gt = 1;
                goto re;
                break; }
            case 3: {break; }
            case 4: {break; }
            }
        }



        config.close();
        return 0;
    }
}f;

class edit
{


public:

    int y = 0;

    void content()
    {

        system("cls");

    }

    void tvb(int type)
    {
        f.save();

        if (p.evntprop[in][1] == 0)
        {
            int typel = 1, speci;
            string icon, txt, location, loc;

        s1:

            speci = p.evntprop[in][2];

            if (p.save[speci] == "\0")
            {
                string tmp;

                tmp = to_string(speci);
                string k1, k2;

                k1 = to_string(p.evntprop[in][2]);
                k2 = to_string(p.evntprop[in][1]);

                txt = ("Sample" + k2 + k1);
                p.save[speci] = txt;

                loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                ofstream crt(loc);
                crt.close();
            }
            else
            {
                txt = p.save[speci];
            }


            loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
            location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

            system("cls");

            cout << "\n\n\t\t     ";
            color(0);
            cout << Title << " (" << Version << ")";
            color(1);
            cout << "\n\n";
            cout << endl << "  ------------------------------------------------------" << endl;

            cout << "  Type : ";
            if (p.event_type[in].length() <= 20)
            {
                int s = p.event_type[in].length();
                cout << p.event_type[in];
                for (int i = 0; i < (20 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_type[in].substr(0.20) << endl;
            }

            cout << "|  Event Limit : ";
            cout << typel << "/3";
            cout << endl << "  ------------------------------------------------------" << endl << endl;

            if (type == 1)
            {

                //Saved_As
                if (y == 0)
                {
                    color(0);
                }
                cout << "  Saved As : ";

                if (txt.length() <= 16)
                {
                    int s = txt.length();
                    cout << txt;

                    for (int i = 0; i < (16 - s); i++)
                    {
                        cout << " ";
                    }

                }
                else {

                    cout << txt.substr(0, 16) << endl;
                }
                color(1);

                //Icon_Info
                if (y == 1)
                {
                    color(0);
                }
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "info";
                }
                cout << "|  Icon : ";
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "Info";
                }
                icon = p.icon[speci];
                cout << icon << endl << endl;
                color(1);

                //Title
                if (y == 2)
                {
                    color(0);
                }
                cout << "  Title : ";
                if (p.event_name[in].length() <= 19)
                {
                    int s = p.event_name[in].length();
                    cout << p.event_name[in];
                    for (int i = 0; i < (19 - s); i++)
                    {
                        cout << " ";
                    }
                }
                else {
                    cout << p.event_name[in].substr(0.19);
                }
                color(1);
                //return
                if (y == 3)
                {
                    color(0);
                }
                cout << "|  Return";
                color(1);
                //Text

                cout << endl << endl << "  ----------------------  Content  ----------------------" << endl << endl;
                if (y == 4)
                {
                    color(0);
                }
                string g;
                int limi = 0;
                fstream xon(loc);
                while (xon.eof() == 0)
                {
                    getline(xon, g);

                    if (limi == 0 && g == "\0")
                    {
                        cout << "  ~" << endl;
                    }
                    else {
                        cout << "  " << g << endl;
                    }
                    if (limi >= 5)
                    {
                        color(1);
                        cout << endl << "  (Click On Content To View/Edit More ...)\n";
                        goto ski;
                    }

                    limi++;
                }
            ski:
                xon.close();
                color(1);


                y = key1(4, y);



                if (y == 100)
                {
                    cout << "\n  Enter The File Name : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        fstream xon(loc);
                        string tt = loc;
                        txt = p.save[speci] = h;

                        loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                        location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                        ofstream con(loc);

                        while (xon.eof() == 0)
                        {
                            getline(xon, g);
                            con << g << endl;
                        }
                        xon.close();
                        con.close();
                        remove(tt.c_str());
                    }
                    y -= 100;
                }



                if (y == 103 || y == 27)
                {
                    return;
                }
                if (y == 104)
                {

                    system("cls");
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);                if (y == 102)
                {
                    cout << "\n  Enter Event Name/Title : ";
                    char h[22];

                    cin.sync();
                    cin.getline(h, 22);

                    if (h[0] != NULL || h[0] != '\0' || h[0] != ' ')
                    {
                        p.event_name[in] = h;
                    }
                    y -= 100;
                }

                if (y == 101)
                {
                    cout << "\n  Enter Icon Tag From Theme Config : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        p.icon[speci] = h;
                    }

                    y -= 100;

                }
                    cout << "\n\n";
                    cout << endl << "  Copy-Dropy  ------------------------------------------" << endl << endl;
                    cout << "  Bold       -  <b> </b>" << endl;
                    cout << "  Highligt   -  <#selectbg_g> </#>" << endl;
                    cout << "  Bulletin   -  <*> </*>" << endl;
                    cout << "  Underline  -  <u> </u>" << endl;
                    cout << "  Parah      -  <@fill> </@>" << endl;
                    cout << "  q          -  <q> </q>" << endl;
                    cout << "  Center     -  <@center> </@>" << endl;
                    cout << "  Tab        -  \\t" << endl;
                    cout << "  Next Line  -  \\n" << endl;
                    cout << endl << "  ------------------------------------------------------" << endl;
                    cout << endl << "  Save & Close The Notepad To Continue  ..." << endl;

                    system(location.c_str());
                    y -= 100;
                    Sleep(500);
                }

                goto s1;
                //system("explorer /select,C:\\Windows\\notepad.exe");
                // string topicName = "notepad \ " + dir[4] + "\\" + c_pro  + "\\" + txt ;
                //system(topicName.c_str());

            }
        }

        else if (p.evntprop[in][1] == 1)
        {

            int ad = 7;
            int typel = 1, speci;
            string icon, txt, location, loc;

        s2:

            speci = p.evntprop[in][2];

            txt = p.qsave[speci];

            if (txt == "\0")
            {
                string tmp, k1, k2;
                tmp = to_string(speci);

                k1 = to_string(p.evntprop[in][2]);
                k2 = to_string(p.evntprop[in][1]);

                txt = ("Sample" + k2 + k1);

                loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                ofstream crt(loc);
                crt.close();

                p.qsave[speci] = txt;

            }


            loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
            location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

            system("cls");

            cout << "\n\n\t\t     ";
            color(0);
            cout << Title << " (" << Version << ")";
            color(1);
            cout << "\n\n";
            cout << endl << "  ------------------------------------------------------" << endl;

            cout << "  Type : ";
            if (p.event_type[in].length() <= 20)
            {
                int s = p.event_type[in].length();
                cout << p.event_type[in];
                for (int i = 0; i < (20 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_type[in].substr(0.20) << endl;
            }

            cout << "|  Event Limit : ";
            cout << typel << "/3";
            cout << endl << "  ------------------------------------------------------" << endl << endl;

            if (type == 1)
            {

                //Saved_As
                if (y == 0)
                {
                    color(0);
                }
                cout << "  Saved As : ";

                if (txt.length() <= 16)
                {
                    int s = txt.length();
                    cout << txt;

                    for (int i = 0; i < (16 - s); i++)
                    {
                        cout << " ";
                    }

                }
                else {

                    cout << txt.substr(0, 16) << endl;
                }
                color(1);

                //Icon_Info
                if (y == 1)
                {
                    color(0);
                }
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "info";
                }
                cout << "|  Icon : ";
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "Info";
                }
                icon = p.icon[speci];
                cout << icon << endl << endl;
                color(1);

                //Title
                if (y == 2)
                {
                    color(0);
                }
                cout << "  Title : ";
                if (p.event_name[in].length() <= 19)
                {
                    int s = p.event_name[in].length();
                    cout << p.event_name[in];
                    for (int i = 0; i < (19 - s); i++)
                    {
                        cout << " ";
                    }
                }
                else {
                    cout << p.event_name[in].substr(0.19);
                }
                color(1);
                //return
                if (y == 3)
                {
                    color(0);
                }
                cout << "|  Return";
                color(1);
                //Text

                cout << endl << endl << "  ----------------------  Content  ----------------------" << endl << endl;
                if (y == 4)
                {
                    color(0);
                }

                string g;
                int limi = 0;
                fstream xon(loc);
                while (xon.eof() == 0)
                {
                    getline(xon, g);
                    if (limi == 0 && g == "\0")
                    {
                        cout << "  ~" << endl;
                    }
                    else {
                        cout << "  " << g << endl;
                    }
                    if (limi >= 5)
                    {
                        color(1);
                        cout << endl << "  (Click On Content To View/Edit More ...)\n";
                        goto ski1;
                    }

                    limi++;
                }
            ski1:

                xon.close();
                color(1);


                y = key1(4, y);



                if (y == 100)
                {
                    cout << "\n  Enter The File Name : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        fstream xon(loc);
                        string tt = loc;
                        txt = p.save[speci + ad] = h;

                        loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                        location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                        ofstream con(loc);

                        while (xon.eof() == 0)
                        {
                            getline(xon, g);
                            con << g << endl;
                        }
                        xon.close();
                        con.close();
                        remove(tt.c_str());
                    }
                    y -= 100;
                }

                if (y == 102)
                {
                    cout << "\n  Enter Event Name/Title : ";
                    char h[22];

                    cin.sync();
                    cin.getline(h, 22);

                    if (h[0] != NULL || h[0] != '\0' || h[0] != ' ')
                    {
                        p.event_name[in] = h;
                    }
                    y -= 100;
                }

                if (y == 101)
                {
                    cout << "\n  Enter Icon Tag From Theme Config : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        p.icon[speci] = h;
                    }

                    y -= 100;

                }

                if (y == 103 || y == 27)
                {
                    return;
                }
                if (y == 104)
                {

                    system("cls");
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);
                    cout << "\n\n";
                    cout << endl << "  Copy-Dropy  ------------------------------------------" << endl << endl;
                    cout << "  Bold       -  <b> </b>" << endl;
                    cout << "  Highligt   -  <#selectbg_g> </#>" << endl;
                    cout << "  Bulletin   -  <*> </*>" << endl;
                    cout << "  Underline  -  <u> </u>" << endl;
                    cout << "  Parah      -  <@fill> </@>" << endl;
                    cout << "  q          -  <q> </q>" << endl;
                    cout << "  Center     -  <@center> </@>" << endl;
                    cout << "  Tab        -  \\t" << endl;
                    cout << "  Next Line  -  \\n" << endl;
                    cout << endl << "  ------------------------------------------------------" << endl;
                    cout << endl << "  Save & Close The Notepad To Continue  ..." << endl;

                    system(location.c_str());
                    y -= 100;
                    Sleep(500);
                }

                goto s2;
                //system("explorer /select,C:\\Windows\\notepad.exe");
                // string topicName = "notepad \ " + dir[4] + "\\" + c_pro  + "\\" + txt ;
                //system(topicName.c_str());


            }

        }

        else if (p.evntprop[in][1] == 2)
        {
            int typel = 1, speci = NULL;
            string icon, txt, location, loc;

        s3:


            speci = p.evntprop[in][2];

            txt = p.wsave[speci];

            if (txt == "\0")
            {
                string tmp, k1, k2;
                tmp = to_string(speci);

                k1 = to_string(p.evntprop[in][2]);
                k2 = to_string(p.evntprop[in][1]);

                txt = ("Sample" + k2 + k1);

                loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                ofstream crt(loc);
                crt.close();

                p.wsave[speci] = txt;

            }


            loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
            location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

            system("cls");

            cout << "\n\n\t\t     ";
            color(0);
            cout << Title << " (" << Version << ")";
            color(1);
            cout << "\n\n";
            cout << endl << "  ------------------------------------------------------" << endl;

            cout << "  Type : ";
            if (p.event_type[in].length() <= 20)
            {
                int s = p.event_type[in].length();
                cout << p.event_type[in];
                for (int i = 0; i < (20 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_type[in].substr(0.20) << endl;
            }

            cout << "|  Event Limit : ";
            cout << typel << "/3";
            cout << endl << "  ------------------------------------------------------" << endl << endl;

            if (type == 1)
            {

                //Saved_As
                if (y == 0)
                {
                    color(0);
                }
                cout << "  Saved As : ";

                if (txt.length() <= 16)
                {
                    int s = txt.length();
                    cout << txt;

                    for (int i = 0; i < (16 - s); i++)
                    {
                        cout << " ";
                    }

                }
                else {

                    cout << txt.substr(0, 16) << endl;
                }
                color(1);

                //Icon_Info
                if (y == 1)
                {
                    color(0);
                }
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "info";
                }
                cout << "|  Icon : ";

                icon = p.icon[speci];
                cout << icon << endl << endl;
                color(1);

                //Title
                if (y == 2)
                {
                    color(0);
                }
                cout << "  Title : ";
                if (p.event_name[in].length() <= 19)
                {
                    int s = p.event_name[in].length();
                    cout << p.event_name[in];
                    for (int i = 0; i < (19 - s); i++)
                    {
                        cout << " ";
                    }
                }
                else {
                    cout << p.event_name[in].substr(0.19);
                }
                color(1);
                //return
                if (y == 3)
                {
                    color(0);
                }
                cout << "|  Return" << endl;
                color(1);
                //Text

                if (y == 4)
                {
                    color(0);
                }
                cout << endl << "  Agree Column Text : ";

                if (p.agree[speci][0] != NULL)
                {
                    cout << p.agree[speci];
                }
                else
                {
                    cout << "~";
                }
                color(1);

                cout << endl << endl << "  ----------------------  Content  ----------------------" << endl << endl;

                if (y == 5)
                {
                    color(0);
                }
                string g;
                int limi = 0;
                fstream xon(loc);

                while (xon.eof() == 0)
                {
                    getline(xon, g);

                    if (limi == 0 && g == "\0")
                    {
                        cout << "  ~" << endl;
                    }
                    else
                    {
                        cout << "  " << g << endl;
                    }

                    if (limi >= 3)
                    {
                        color(1);
                        cout << endl << "  (Click On Content To View/Edit More ...)";
                        goto ski2;
                    }

                    limi++;
                }
            ski2:
                xon.close();
                color(1);


                y = key1(5, y);



                if (y == 100)
                {
                    cout << endl << "\n  Enter The File Name : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        fstream xon(loc);
                        string tt = loc;
                        txt = p.wsave[speci] = h;

                        loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                        location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                        ofstream con(loc);

                        while (xon.eof() == 0)
                        {
                            getline(xon, g);
                            con << g << endl;
                        }
                        xon.close();
                        con.close();
                        remove(tt.c_str());
                    }
                    y -= 100;
                }

                if (y == 102)
                {
                    cout << endl << "\n  Enter Event Name/Title : ";
                    char h[22];

                    cin.sync();
                    cin.getline(h, sizeof(h));

                    if (h[0] != NULL || h[0] != '\0' || h[0] != ' ')
                    {
                        p.event_name[in] = h;
                    }
                    y -= 100;
                }

                if (y == 101)
                {
                    cout << endl << "\n  Enter Icon Tag From Theme Config : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        p.icon[speci] = h;
                    }

                    y -= 100;

                }

                if (y == 103 || y == 27)
                {
                    return;
                }

                if (y == 104)
                {

                    cout << endl << "\n  Enter Agree Column Text : ";
                    char h[100];

                    cin.getline(h, sizeof(h));



                    strcpy(p.agree[speci], h);



                    y -= 100;

                }
                if (y == 105)
                {

                    system("cls");
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);
                    cout << "\n\n";
                    cout << endl << "  Copy-Dropy  ------------------------------------------" << endl << endl;
                    cout << "  Bold       -  <b> </b>" << endl;
                    cout << "  Highligt   -  <#selectbg_g> </#>" << endl;
                    cout << "  Bulletin   -  <*> </*>" << endl;
                    cout << "  Underline  -  <u> </u>" << endl;
                    cout << "  Parah      -  <@fill> </@>" << endl;
                    cout << "  q          -  <q> </q>" << endl;
                    cout << "  Center     -  <@center> </@>" << endl;
                    cout << "  Tab        -  \\t" << endl;
                    cout << "  Next Line  -  \\n" << endl;
                    cout << endl << "  ------------------------------------------------------" << endl;
                    cout << endl << "  Save & Close The Notepad To Continue  ..." << endl;

                    system(location.c_str());
                    y -= 100;
                    Sleep(500);
                }

                goto s3;
                //system("explorer /select,C:\\Windows\\notepad.exe");
                // string topicName = "notepad \ " + dir[4] + "\\" + c_pro  + "\\" + txt ;
                //system(topicName.c_str());

            }
        }

        else if (p.evntprop[in][1] == 3)
        {
            int typel = 1, speci = NULL;
            string icon, txt, location, loc;

        s4:

            speci = p.evntprop[in][2];

            txt = p.esave[speci];

            if (txt == "\0")
            {
                string tmp, k1, k2;
                tmp = to_string(speci);

                k1 = to_string(p.evntprop[in][2]);
                k2 = to_string(p.evntprop[in][1]);

                txt = ("Sample" + k2 + k1);

                loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                ofstream crt(loc);
                crt.close();

                p.esave[speci] = txt;

            }


            loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
            location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

            system("cls");

            cout << "\n\n\t\t     ";
            color(0);
            cout << Title << " (" << Version << ")";
            color(1);
            cout << "\n\n";
            cout << endl << "  ------------------------------------------------------" << endl;

            cout << "  Type : ";
            if (p.event_type[in].length() <= 20)
            {
                int s = p.event_type[in].length();
                cout << p.event_type[in];
                for (int i = 0; i < (20 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_type[in].substr(0.20) << endl;
            }

            cout << "|  Event Limit : ";
            cout << typel << "/3";
            cout << endl << "  ------------------------------------------------------" << endl << endl;

            if (type == 1)
            {

                //Saved_As
                if (y == 0)
                {
                    color(0);
                }
                cout << "  Saved As : ";

                if (txt.length() <= 16)
                {
                    int s = txt.length();
                    cout << txt;

                    for (int i = 0; i < (16 - s); i++)
                    {
                        cout << " ";
                    }

                }
                else {

                    cout << txt.substr(0, 16) << endl;
                }
                color(1);

                //Icon_Info
                if (y == 1)
                {
                    color(0);
                }
                if (p.icon[speci] == "\0")
                {
                    icon = p.icon[speci] = "info";
                }
                cout << "|  Icon : ";

                icon = p.icon[speci];
                cout << icon << endl << endl;
                color(1);

                //Title
                if (y == 2)
                {
                    color(0);
                }
                cout << "  Title : ";
                if (p.event_name[in].length() <= 19)
                {
                    int s = p.event_name[in].length();
                    cout << p.event_name[in];
                    for (int i = 0; i < (19 - s); i++)
                    {
                        cout << " ";
                    }
                }
                else {
                    cout << p.event_name[in].substr(0.19);
                }
                color(1);
                //return
                if (y == 3)
                {
                    color(0);
                }
                cout << "|  Return" << endl;
                color(1);
                //Text

                if (y == 4)
                {
                    color(0);
                }
                cout << endl << "  Check Box Column Text : ";

                if (p.ckvb[speci][0] != NULL)
                {
                    cout << p.ckvb[speci];
                }
                else
                {
                    cout << "~";
                }
                color(1);

                cout << endl << endl << "  ----------------------  Content  ----------------------" << endl << endl;

                if (y == 5)
                {
                    color(0);
                }
                string g;
                int limi = 0;
                fstream xon(loc);
                while (xon.eof() == 0)
                {
                    getline(xon, g);
                    if (limi == 0 && g == "\0")
                    {
                        cout << "  ~" << endl;
                    }
                    else {
                        cout << "  " << g << endl;
                    }
                    if (limi >= 5)
                    {
                        color(1);
                        cout << endl << "  (Click On Content To View/Edit More ...)";
                        goto ski3;
                    }

                    limi++;
                }
            ski3:
                xon.close();
                color(1);


                y = key1(5, y);



                if (y == 100)
                {
                    cout << endl << "Enter The File Nmae Where The Content Will Be Saved : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        fstream xon(loc);
                        string tt = loc;
                        txt = p.esave[speci] = h;

                        loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
                        location = "notepad " + dir[4] + "\\" + c_pro + "\\" + txt + ".txt";

                        ofstream con(loc);

                        while (xon.eof() == 0)
                        {
                            getline(xon, g);
                            con << g << endl;
                        }
                        xon.close();
                        con.close();
                        remove(tt.c_str());
                    }
                    y -= 100;
                }

                if (y == 102)
                {
                    cout << endl << "Enter Event Name/Title : ";
                    char h[22];

                    cin.sync();
                    cin.getline(h, sizeof(h));

                    if (h[0] != NULL || h[0] != '\0' || h[0] != ' ')
                    {
                        p.event_name[in] = h;
                    }
                    y -= 100;
                }

                if (y == 101)
                {
                    cout << endl << "Enter Which Icon To Set From Theme Config To This Event : ";
                    string h;
                    cin >> h;
                    if (h != "\0")
                    {
                        p.icon[speci] = h;
                    }

                    y -= 100;

                }

                if (y == 103 || y == 27)
                {
                    return;
                }

                if (y == 104)
                {

                    cout << endl << "Enter The Text To Display In Check Box Columm : ";
                    char h[100];

                    cin.sync();
                    cin.getline(p.ckvb[speci], 100);

                    y -= 100;

                }
                if (y == 105)
                {

                    system("cls");
                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);
                    cout << "\n\n";
                    cout << endl << "  Copy-Dropy  ------------------------------------------" << endl << endl;
                    cout << "  Bold       -  <b> </b>" << endl;
                    cout << "  Highligt   -  <#selectbg_g> </#>" << endl;
                    cout << "  Bulletin   -  <*> </*>" << endl;
                    cout << "  Underline  -  <u> </u>" << endl;
                    cout << "  Parah      -  <@fill> </@>" << endl;
                    cout << "  q          -  <q> </q>" << endl;
                    cout << "  Center     -  <@center> </@>" << endl;
                    cout << "  Tab        -  \\t" << endl;
                    cout << "  Next Line  -  \\n" << endl;
                    cout << endl << "  ------------------------------------------------------" << endl;
                    cout << endl << "  Save & Close The Notepad To Continue  ..." << endl;

                    system(location.c_str());
                    y -= 100;
                    Sleep(500);
                }

                goto s4;
                //system("explorer /select,C:\\Windows\\notepad.exe");
                // string topicName = "notepad \ " + dir[4] + "\\" + c_pro  + "\\" + txt ;
                //system(topicName.c_str());

            }
        }

    }

    void dtvb(int poi)
    {

        string txt,loc;
        
        if (p.evntprop[poi][1] == 0)
        {
            txt = p.save[p.evntprop[poi][2]];
            loc = dir[4] + "\\" + c_pro + "\\" + txt + ".txt";
            remove(loc.c_str());
        }
        _getch();

    }

    void cvb(int poin)
    {
        f.save();

        if (p.evntprop[in][1] == 0)
        {  

            a1:

            system("cls");

            cout << "\n\n\t\t     ";
            color(0);
            cout << Title << " (" << Version << ")";
            color(1);
            cout << "\n\n";
            cout << endl << "  ------------------------------------------------------" << endl;

            cout << "  Type : ";
            if (p.event_type[in].length() <= 20)
            {
                int s = p.event_type[in].length();
                cout << p.event_type[in];
                for (int i = 0; i < (20 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_type[in].substr(0.20) << endl;
            }

            cout << "|  Event Limit : ";
            cout << "/3";
            cout << endl << "  ------------------------------------------------------" << endl << endl;

            //Title
            if (y == 0)
            {
                color(0);
            }
            cout << "  Title : ";
            if (p.event_name[in].length() <= 19)
            {
                int s = p.event_name[in].length();
                cout << p.event_name[in];
                for (int i = 0; i < (19 - s); i++)
                {
                    cout << " ";
                }
            }
            else {
                cout << p.event_name[in].substr(0.19);
            }
            color(1);

            //Icon_Info
            if (y == 1)
            {
                color(0);
            }
            int speci = 1;
            string icon;
            
            cout << "|  Icon : ";
            
            if (p.iicon[in] == "\0")
            {
            p.iicon[in] = "Info";
            }
 
            icon = p.iicon[in];

            cout << icon;
            color(1);
            cout << endl << endl;

            if (y == 2)
            {
                color(0);
            }
            cout << "  Manage Group               ";
            color(1);

            if (y == 3)
            {
                color(0);
            }
            cout << "|  Add To List               ";
            color(1);

            cout << endl << endl;

            if (y == 4)
            {
                color(0);
            }
            cout << "                             |";
            color(1);

            if (y == 5)
            {
                color(0);
            }
            cout << "  Return";
            color(1);

            cout << endl << endl << "  ______________________   Lists   _____________________" << endl << endl;
            cout << "  No.  |        Group        |        Title       |  Sel  " << endl;      
            cout << "  ______________________________________________________" << endl;


            y = key1(5, y);
            

            if (y == 100)
            {
                cout << "\n  Enter Event Name/Title : ";
                char h[22];

                cin.sync();
                cin.getline(h, 22);

                if (h[0] != NULL || h[0] != '\0' || h[0] != ' ')
                {
                    p.event_name[in] = h;
                }
                y -= 100;
            }

            if (y == 101)
            {
                cout << "\n  Enter Icon Tag From Theme Config : ";
                string h;
                cin >> h;
                if (h != "\0")
                {
                    p.iicon[in] = h;
                }

                y -= 100;

            }

            if (y == 102)
            {
                int inp=0;
                i:
                int r;
                string* lis;

                string grp[6] = { 
                    "       Return        ", 
                    "     View Group      ",
                    "  Create New Group   ",
                    "Delete Existing Group", 
                    "Rename Existing Group", 
                    "   Rearrange Group   "};

                inp=display(grp, 6, 0, 4, inp, 0, 16);
                
                string jk,t;

                switch (inp)
                {

                case 0:
                    y -= 100;
                    break;

                case 1:
                    g:

                    if (p.agroup[1] == "")
                    {
                        cout << endl << "No Groups Available !";
                        Sleep(1500);
                        goto i;
                    }
                    lis = p.agroup;
                    lis[p.grp] = "Return";

                    r = display(lis, p.grp + 1, 1, 4, p.grp - 1, 1, 16, "View Group");
                    r++;

                    if (r == p.grp)
                    {
                        goto i;
                    }
                    else
                    {
                        goto g;
                    }
                    goto i;
                    break;
                case 2: 

                    cout << "Enter Name Of The Group : ";
                    cin >> p.agroup[p.grp];
                    
                    p.grp++;
                    goto i;
                    break;
                
                case 3:

                    if (p.agroup[1] == "" || p.agroup[1]=="Return")
                    {
                        cout << endl << "No Groups Available !";
                        Sleep(1500);
                        goto i;
                    }
                    

                    lis = p.agroup;
                    lis[p.grp] = "Return";

                    r=display(lis, p.grp+1, 1, 4, p.grp-1, 1, 16,"Select The Group To Delete");
                    r++;
                    
                    t = p.agroup[r];

                    if (r==1 && p.grp == 1)
                    {
                        p.grp = 1;
                        p.agroup[p.grp]="";
                    }
                    else if (r == p.grp)
                    {
                        cout << "Returning...";
                        Sleep(200);
                        goto i;
                    }
                    else if (r == p.grp-1)
                    {
                        p.agroup[p.grp] = "";
                        p.grp--;
                    }
                    else
                    {
                       for (int b = r; b <= p.grp; b++)
                       {
                           p.agroup[b] = p.agroup[b+1];
                    
                       }
                       p.agroup[p.grp] = "";
                       p.grp--;
                    }

                    cout << endl << "Deleted Group '" << t << "'";
                    Sleep(500);
                    goto i;

                    break;
                case 4: 

                    if (p.agroup[1] == "")
                    {
                        cout << endl << "No Groups Available !";
                        Sleep(1500);
                        goto i;
                    }

                    lis = p.agroup;
                    lis[p.grp] = "Return";

                    r = display(lis, p.grp + 1, 1, 4, p.grp - 1, 1, 16, "Select The Group To Rename");
                    r++;

                    if (r == p.grp)
                    {
                        cout << "Returning...";
                        Sleep(200);
                        goto i;
                    }

                    cout << endl << "Rename To : ";
                    cin >> p.agroup[r];

                    goto i;
                    break;
                case 5: 
                    
                    if (p.agroup[1] == "")
                    {
                        cout << endl << "No Groups Available !";
                        Sleep(1500);
                        goto i;
                    }

                    goto i; 
                    break;
                default: ;
                }

            }

            if (y == 103)
            {
               
                char tt[41]="\0",ttt[200]="\0";
                int t = p.grp,fh=0,tttt=NULL;
                string gist[6],ann[6],ty,jfh[2];

                if (p.grp == 0)
                {
                    system("cls");
                    cout << "\n\n\n\n\n";
                    color(0);
                    cout << "                   No Groups Created Yet !,\n\n         Create Atleast One Group To Add To The List ..";
                    color(1);
                    Sleep(1500);
                    goto e;
                }

            to:
                if (tttt == 0)
                {
                    ty = "Checked";
                }
                else
                {
                    ty = "Unchecked";
                }

                system("cls");

                if (tt[0] == '\0')
                {
                    cout << "\n\n\n\n\n";
                    color(0);
                    cout << "       Leave The Entry Empy & Press Enter To Return\n\n";
                    cout << "           Enter The Name/Title Of The Option\n\n                           : ";
                    cin.getline(tt, 40);
                    if (tt[0] == '\0')
                    {
                        goto e;
                    }
                    color(1);
                    goto to;
                }

                gist[0] = (std::string("Name/Title Of The Option")).c_str();
                gist[1] = (std::string("      Description       ")).c_str();
                gist[2] = (std::string("    Selected Group      ")).c_str();
                gist[3] = (std::string("   Pre Select Option    ")).c_str();
                gist[4] = (std::string("         Done           ")).c_str();

                ann[0] = tt;
                ann[1] = ttt;
                ann[2] = p.agroup[t];
                ann[3] = ty;
                ann[4] = "Apply & Return";

                fh=display(gist, 5, 0, 4, fh, 1, 16,"",ann,26);
                char pp[200];

                switch (fh)
                {
                case 0:
                    color(0);
                    cout <<"\n\nEnter The Name/Title Of The Option : ";
                    cin.getline(pp, 40);
                    if (pp[0] != '\0')
                    {
                        strcpy(tt, pp);

                    }
                    color(1);
                    goto to;
                    break;

                case 1:
                    color(0);
                    cout << "\n\nEnter The Description For The Option : ";
                    cin.getline(pp, 190);
                    if (pp[0] != '\0')
                    {
                        strcpy(ttt, pp);

                    }
                    color(1);
                    goto to;
                    break;

                case 2:
                    
                    t=display(p.agroup,p.grp,0,4,0,1,21,"Select The Group To Be Placed In");
                    goto to;
                    break;

                case 3:


                    jfh[0] = "Checked";
                    jfh[1] = "Unchecked";
                    tttt= display(jfh, 2, 0, 4, 0, 0, 21, "Select The Default Option To Display");
                    goto to;
                    break;

                case 4:

                    goto e;
                    break;

                default :
                    goto to;
                    break;
                }

                e:               
                y -= 100;
            }

            if (y == 105)
            {
                return;
            }

            goto a1;
}

    }

};

class even
{
public:

    string  

        def_name[2] = {
        "       Return       ",
        "   Add New Event    " };

    int tmp = 0, sel = 0, Pointing_1, Input, st = 0, pre = 0, con = 0, uspc[30], spa = 0;

    string slist[30], mlist[30];
    string list[30];
    int no,vp=0;
    int fla = 0, ref, loop, loop2 = 0, space = 0, o = 0, sp = 0, yu = 0, head = 0, tail = 13;


    int arno = 0;


    ~even()
    {

    }

    int key11(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        int Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }


        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

        if (Input == 27)        //Confirm 'Esc' Input

          // Esc:

        {
            return 27;

        }

        if (Input == 13)

        {
            Pointing += 100;

        }


        return (Pointing);        //Returning Computed Input

    }

    int key1(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        int Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }


        if (Pointing < -2) { Pointing = -2; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

        if (Input == 27)        //Confirm 'Esc' Input

          // Esc:

        {
            return 27;

        }

        if (Input == 13)

        {
            Pointing += 100;

        }


        return (Pointing);        //Returning Computed Input

    }

    void left()
    {
        int last = 0;
        string get;
        
        if (sel == 0)
        {
            switch (st)
            {

            case 0:
            {
                if (tmp >= 0)
                {
                    cout << "          ";
                    color(0);
                    cout << "Event Name";
                    color(1);
                }

                st++;
                break;
            }

            case 1:
            {
                if (tmp >= 0)
                {
                    int t;
                    t = list[tmp].length();

                    if (t >= 20)
                    {
                        if (t >= 24)
                        {
                            if (t == 24)
                            {
                                cout << " ";
                            }
                            get = p.event_name[tmp];
                            cout << "  " << get.substr(0, 25);
                        }

                        else
                        {
                            cout << "  ";
                            switch (25 - t)
                            {
                            case 1: cout << " "; break;
                            case 2: cout << " "; break;
                            case 3: cout << "  "; break; //del one space for 3 & 5 to get right side align
                            case 4: cout << "  "; break;
                            case 5: cout << "   ";  break;
                            }
                            get = p.event_name[tmp];
                            cout << get.substr(0, t);
                        }
                    }

                    else
                    {
                        cout << "     " << slist[tmp];
                    }
                }

                st++;
                break;
            }

            case 2:
            {
                st++;
                break;
            }

            case 3:
            {                
                if (tmp >= 0)
            {
                cout << "          ";
                color(0);
                cout << "Event Type";
                color(1);
            }
                st++;
                break;
            }

            case 4:
            {
                if (tmp >= 0)
                {
                    if (p.event_type[tmp] == "\0")
                    {
                        int t;
                        t = list[tmp].length();

                        if (t >= 20)
                        {
                            if (t >= 24)
                            {
                                if (t == 24)
                                {
                                    cout << " ";
                                }
                                get = p.event_name[tmp];
                                cout << "  " << get.substr(0, 25);
                            }

                            else
                            {
                                cout << "  ";
                                switch (25 - t)
                                {
                                case 1: cout << " "; break;
                                case 2: cout << " "; break;
                                case 3: cout << "  "; break; //del one space for 3 & 5 to get right side align
                                case 4: cout << "  "; break;
                                case 5: cout << "   ";  break;
                                }
                                get = p.event_name[tmp];
                                cout << get.substr(0, t);
                            }
                        }

                        else
                        {
                            cout << "     " << slist[tmp];
                        }
                    }
                    else {
                        cout << "          " << p.event_type[tmp];
                    }
                }

                st++;
                break;
            }

            case 5:
            {
                st++;
                break;
            }

            case 6:
            {
                if (tmp >= 0) {
                    cout << "  -------------------------";
                }
                st++;
                break;
            }

            case 7:
            {
                st++;
                break;
            }

            case 8:
            {
                if (tmp >= 0)
                {
                    cout << "       Type Limit : ";
                    if (p.evntprop[tmp][0] == 0)
                    {
                        cout << p.vblim << "/" << "7";
                    }
                    if (p.evntprop[tmp][0] == 1)
                    {
                        cout << p.lblim << "/" << "7";
                    }

                }
                if (tmp == -2)
                {
                    cout << "    "; color(0); cout << "Return Back To Project"; color(1);
                }
                if (tmp == -1)
                {
                    cout << "    "; color(0); cout << "Add A New Event To The"; color(1);

                }
                st++;
                break;
            }

            case 9:
            {
                if (tmp == -2)
                {
                    cout << "         "; color(0); cout << "Title Screen"; color(1);
                }
                if (tmp == -1)
                {
                    cout << "         "; color(0); cout << "Event Editor"; color(1);
                }

                st++;
                break;
            }

            case 10:
            {
                if (tmp >= 0)
                {
                    cout << "    Type Count : ";
                    cout << p.evntprop[tmp][2] << " in [" << p.evntprop[tmp][1] << "/"<< p.evntprop[tmp][0]<<"]";
                }

                st++;
                break;
            }

            case 11:
            {
                st++;
                break;
            }

            case 12:
            {
                st++;
                break;
            }

            case 13:
            {
                st++;
                break;
            }

            case 14:
            {
                st++;
                break;
            }

            case 15:
            {
                st++;
                break;
            }

            case 16:
            {
                st++;
                break;
            }

            case 17:
            {
                st++;
                break;
            }

            case 18:
            {
                st++;
                break;
            }

            }
        }

        if(sel==1)
        {
            switch (st)
            {

            case 0:
            {
                if (tmp >= 0)
                {
                    cout << "          ";
                    color(0);
                    cout << "Event Name";
                    color(1);
                }

                st++;
                break;
            }

            case 1:
            {
                if (tmp >= 0)
                {
                    int t;
                    t = list[tmp].length();

                    if (t >= 20)
                    {
                        if (t >= 24)
                        {
                            if (t == 24)
                            {
                                cout << " ";
                            }
                            get = p.event_name[tmp];
                            cout << "  " << get.substr(0, 25);
                        }

                        else
                        {
                            cout << "  ";
                            switch (25 - t)
                            {
                            case 1: cout << " "; break;
                            case 2: cout << " "; break;
                            case 3: cout << "  "; break; //del one space for 3 & 5 to get right side align
                            case 4: cout << "  "; break;
                            case 5: cout << "   ";  break;
                            }
                            get = p.event_name[tmp];
                            cout << get.substr(0, t);
                        }
                    }

                    else
                    {
                        cout << "     " << slist[tmp];
                    }
                }

                st++;
                break;
            }

            case 2:
            {
                st++;
                break;
            }

            case 3:
            {
                if (tmp >= 0)
                {
                    cout << "          ";
                    color(0);
                    cout << "Event Type";
                    color(1);
                }
                st++;
                break;
            }

            case 4:
            {
                if (p.event_type[in] == "\0")
                {
                    cout << "         " << p.event_name[in];
                }
                else 
                {
                    cout << "          " << p.event_type[in];
                }
                st++;
                break;
            }

            case 5:
            {
                st++;
                break;
            }
            case 6:
            {
                cout << "  -------------------------";
                st++;
                break;
            }
            case 7:
            {
                st++;
                break;
            }

            case 8:
            {
                if (vp == 0)
                {
                    color(0);
                    cout << "         [  ";
                    cout << "Return";
                    cout << "  ]";
                    color(1);
                }
                else
                {
                    cout << "            ";
                    cout << "Return";
                    cout << "";
                }
                st++;
                break;
            }

            case 9:
            {
                if (vp == 1)
                {
                    color(0);
                    cout << "         [   ";
                    cout << "Move";
                    cout << "   ]";
                    color(1);
                }
                else
                {
                    cout << "             ";
                    cout << "Move";
                    cout << "";
                }

                st++;
                break;
            }


            case 10:
            {
                if (vp == 2)
                {
                    color(0);
                    cout << "         [   ";
                    cout << "Edit";
                    cout << "   ]";
                    color(1);
                }
                else
                {
                    cout << "             ";
                    cout << "Edit";
                    cout << "";
                }

                st++;
                break;
            }

            case 11:
            {
                if (vp == 3)
                {
                    color(0);
                    cout << "         [  ";
                    cout << "Delete";
                    cout << "  ]";
                    color(1);
                }
                else
                {
                    cout << "            ";
                    cout << "Delete";
                    cout << "";
                }
                st++;
                break;
            }


            }
        }

    }

    void cal()
    {

        string cstr, cstr2;

        char cstrtmp[21], cstrtmp2[21];

        no = p.no_events;


        if (no < 13)
        {
            tail = no;
        }

        for (loop = 0; loop < no; loop++)
        {

            cstr = list[loop] = p.event_name[loop];

            space = 20 - cstr.length();

            uspc[loop] = 0;

            for (int i = 0; i < 20; i++)
            {
                if (cstr[i] != '\0')
                {
                    cstrtmp2[i] = cstr[i];
                    uspc[loop] += 1;
                }
                else
                {
                    cstrtmp2[i] = '\0';
                    goto b;
                }
            }

        b:

            if (space <= 0)
            {
                for (int i = 0; i < 20; i++)
                {
                    cstrtmp[i] = cstr[i];
                    cstrtmp[i + 1] = '\0';
                }

                cstr = cstrtmp;

            }

            else if (space % 2 == 0)
            {

                int i;

                for (i = 0; i < space / 2; i++)
                {
                    cstrtmp[i] = ' ';
                    cstrtmp[i + 1] = '\0';
                }

                for (int u = 0; u < cstr.length(); u++, i++)
                {
                    cstrtmp[i] = cstr[u];
                    cstrtmp[i + 1] = '\0';
                }

                for (int u = 0; u < space / 2; u++, i++)
                {
                    cstrtmp[i] = ' ';
                    cstrtmp[i + 1] = '\0';
                }

                cstr = cstrtmp;

            }

            else
            {

                int i;

                for (i = 0; i < (space / 2); i++)
                {
                    cstrtmp[i] = ' ';
                    cstrtmp[i + 1] = '\0';
                }

                for (int u = 0; u < cstr.length(); u++, i++)
                {
                    cstrtmp[i] = cstr[u];
                    cstrtmp[i + 1] = '\0';
                }

                for (int u = 0; u < (space / 2) + 1; u++, i++)
                {
                    cstrtmp[i] = ' ';
                    cstrtmp[i + 1] = '\0';
                }

                cstr = cstrtmp;

            }

            slist[loop] = cstr;

            mlist[loop] = cstrtmp2;

        }

    }
   

    void addev()
    {
        int gg, ggg;
        if (ggg = NULL)
        {
            ggg = 0;
        }
    o:
        ///String Info


            string mtype[7] = {
    "                 Select The Type Event To Add",
            "Return",
            "Text View Boxes",
            "Selectable Boxes",
            "Popups",
            "Operational",
            "Others" },

            typeq[6] = {
    "              Select A Event Under View-Box Type",
                "Return",
                "Text Box",
                "View Box",
                "Agree Box",
                "Check View Box" },

            typew[6] = {
        "            Select A Event Under Selectables Type",
                    "Return",
                    "Check Box",
                    "Form",
                    "Select Box",
                    "Menu Box", },

            typee[5] = {
            "               Select A Event Under Popups Type",
                        "Return",
                    "Alert Popup",
                    "Confirm Popup",
                    "Text Popup" },

            typer[7] = {
            "             Select A Event Under Operational Type",
            "Return",
            "Splash Image",
            "Splash Animation",
            "Load Animation"
            "Install",
            "Exit",
            "Reboot", };


            string qmtype[7] = {
"                 Select The Type Event To Add",
        "     Return     ",
        " Text View Boxe ",
        "Selectable Boxes",
        "  Popup Window  ",
        "  Operationals  ",
        "     Others     " },

            qtypeq[6] = {
"              Select A Event Under View-Box Type",
            "    Return    ",
            "   Text Box   ",
            "   View Box   ",
            "  Agree  Box  ",
            "Check View Box" },

            qtypew[6] = {
        "            Select A Event Under Selectables Type",
                    "Return",
                    "Check Box",
                    "Form",
                    "Select Box",
                    "Menu Box", },

            qtypee[5] = {
                    "               Select A Event Under Popups Type",
                                "Return",
                            "Alert Popup",
                            "Confirm Popup",
                            "Text Popup" },

            qtyper[7] = {
                            "             Select A Event Under Operational Type",
                            "Return",
                            "Splash Image",
                            "Splash Animation",
                            "Load Animation"
                            "Install",
                            "Exit",
                            "Reboot", };

        


        d = 1;
        string h;
        int u = p.no_events;
        string i;
            
        ggg=display(qmtype,7,1,4,ggg,1,19 );
        
        if (ggg == 0 || ggg == 27)
        {
            d = 0;
            return;
        }
            gg=ggg-1;

           

        if(gg==0)
        { 
           de = 6;
           
           of = 7;
           iof = p.vblim;

           if(p.vblim==7)
           {
               lim = 1;
               gg = display(qtypeq, 6, 1, 4, 1, 1, 20);
               lim = 0;
               goto o;
           }
               lim = 2;
           gg = display(qtypeq, 6, 1, 4, 1, 1, 20);
               lim = 0;

            if (gg == 0 || gg == 27)
            {
                goto o;
            }
            gg++;
            h = typeq[gg];
            p.event_type[u] = h;

            p.evntprop[p.no_events][0] = 0;

            p.evntprop[p.no_events][1] = gg - 2;
            int j = 1;
            p.evntprop[p.no_events][2] = 1;
            
            for (int i = 0; i < p.no_events; i++)
            {
                if (p.evntprop[i][0] == 0 && p.evntprop[i][1] == gg - 2)
                {
                    j++;
                    p.evntprop[p.no_events][2] = j;
                }
            }


//            cout << p.evntprop[p.no_events][0] << p.evntprop[p.no_events][1] << "||" << p.evntprop[p.no_events][2];


            p.no_events++;
            p.vblim++;
            d = 0;
        }

        else if(gg==1)
        { 
            int limm = iof = p.lblim;
            de = 11;
            
            of = 7;

            if (limm >= 7)
            {
                lim = 1;
                gg = display(qtypew, 6, 1, 4, 1, 1, 20);
                lim = 0;
                goto o;
            }

            lim = 2;
            gg = display(qtypew, 6, 1, 4, 1, 1, 21);
            lim = 0;

            if (gg == 0 || gg == 27)
            {
                goto o;
            }
            gg++;
            h = typew[gg];
            p.event_type[u] = h;


            p.evntprop[p.no_events][0] = 1;

            p.evntprop[p.no_events][1] = gg - 2;

            int j = 1;
            p.evntprop[p.no_events][2] = 1;

            for (int i = 0; i < p.no_events; i++)
            {
                if (p.evntprop[i][0] == 1 && p.evntprop[i][1] == gg - 2)
                {
                    j++;
                    p.evntprop[p.no_events][2] = j;
                }
            }

            p.no_events++;
            d = 0;
            p.lblim++;

        }

        else if (gg == 2)
        {
            de = 15;
            gg = display(qtypee, 5, 1, 4, 1, 1, 21);
            if (gg == 0 || gg == 27)
            {
                goto o;
            }
            gg++;
            h = typee[gg];
            p.event_type[u] = h;
            p.no_events++;
            d = 0;
        }
        else if (gg == 3)
        {
            de = 19;
            gg = display(qtyper, 7, 1, 4, 1, 1, 21);
            if (gg == 0 || gg == 27)
            {
                goto o;
            }
            gg++;
            h = typer[gg];
            p.event_type[u] = h;
            p.no_events++;
            d = 0;
        }
       
        p.event_name[u] = h;

}


    int display2(int Pointing_1 = 0)
    {

        Pointing_1 = tmp = -2;
        goto sk;
    r:
        
        Pointing_1 = tmp =  -1;
    sk:
        sel = 0;
 
        f.save();

        if(p.no_events==0)
        {

            //tmp = Pointing_1 = -1;

            do
            {
                f.save();

                system("cls");

                cout << "\n\n\t\t     ";
                color(0);
                cout << Title << " (" << Version << ")";
                color(1);
                cout << "\n\n";

                cout << endl << "  ------------------------  |"; left();

                if (Pointing_1 == -2)
                {
                    cout << endl << "  "; color(0); cout << "["; cout << " "; cout << def_name[0];  cout << " "; cout << "]"; color(1); cout << "  |"; left();
                    cout << endl << "    "; color(0); cout << def_name[1]; color(1); cout << "    |"; left();
                }

                else if (Pointing_1 == -1)
                {
                    cout << endl << "    "; color(0); cout << def_name[0]; color(1); cout << "    |"; left();
                    cout << endl << "  "; color(0); cout << "["; cout << " "; cout << def_name[1]; cout << " "; cout << "]"; color(1); cout << "  |"; left();
                }

                cout << endl << "  ------------------------  |"; left();
                cout << endl << "                            |"; left();

                for (int o = 0; o < 14; o++)
                {
                    if (o == 3)
                    {
                        cout << endl << "       ! Slot Empty !       |"; left();

                    }
                    else
                    {
                        cout << endl << "                            |"; left();
                    }
                }

                Pointing_1 = key1(0, Pointing_1);

                if (Pointing_1 == 27 || Pointing_1 == 98)
                {
                    return 0;
                }

                if (Pointing_1 == 99)
                {
                    addev();
                    goto r;
                }

                if (Pointing_1 >= 0)
                {
                    Pointing_1 = -1;
                }

                pre = tmp;
                tmp = Pointing_1;
                st = 0;

            } while (Pointing_1 != 27 && Pointing_1 != 98);

            return 0;
        }

            cal();
        
            se:

        do
        {
            f.save();

            system("cls");

            for (ref = 0; ref < no; ref++)
            {
                if (ref == 0)
                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);
                    cout << "\n\n";

                    cout << endl << "  ------------------------  |"; left();

                    if (Pointing_1 == -2)
                    {
                        cout << endl << "  "; color(0); cout << "["; cout << " "; cout << def_name[0];  cout << " "; cout << "]"; color(1); cout<< "  |"; left();
                        cout << endl << "    "; color(0); cout << def_name[1]; color(1);cout << "    |"; left();
                    }

                    else if (Pointing_1 == -1)
                    {
                        cout << endl << "    "; color(0); cout << def_name[0]; color(1); cout << "    |"; left();
                        cout << endl << "  "; color(0); cout << "["; cout << " "; cout << def_name[1]; cout << " "; cout << "]"; color(1); cout << "  |"; left();
                    }

                    else
                    {
                        cout << endl << "    "; color(0); cout << def_name[0]; color(1); cout << "    |"; left();
                        cout << endl << "    "; color(0); cout << def_name[1]; color(1); cout << "    |"; left();
                    }

                    cout << endl << "  ------------------------  |"; left();
                    cout << endl << "                            |"; left();

                }

                if (Pointing_1 == head - 1 && Pointing_1 >= 0)
                {
                        --head;
                        --tail; 
                }
                

                if (Pointing_1 == tail + 1 )
                {
                    ++head;
                    ++tail;
                }

                if (ref < Pointing_1)
                {
                    if (ref >= head) {
                        cout << endl << "    " << slist[ref] << "    |"; left();

                    }
                }


                if (Pointing_1 == ref)
                {
                    if (sel==0)
                    {
                        cout << endl << "  "; color(0); cout << "["; color(1);
                        cout << " ";
                        cout << slist[Pointing_1];
                        cout << " "; color(0); cout << "]"; color(1); cout << "  |";
                        left();
                    }
                    else
                    {
                        cout << endl << "  ";
                        color(0); cout << "["; color(1);
                        cout << " "; color(0);
                        cout << slist[Pointing_1]; color(1);
                        cout << " "; color(0); cout << "]"; color(1);
                        cout << "  |";
                        left();
                    }
                }


                if (ref > Pointing_1)
                {
                    if (ref <= tail) {
                        cout << endl << "    " << slist[ref] << "    |"; left();

                    }
                }
            }

            if (15 - no > 0)
            {
                for (int o = 0; o < 14 - no; o++)
                {
                    cout << endl << "                            |"; left();
                }
            }

            if (sel == 1)
            {

                edit c;

                vp = key11(3, vp);
                
                if (vp == 101) 
                {
                    st = 0;
                    goto sk;
                }
                else if (vp == 102)
                {
                    st = 0;
                    
                    if (p.evntprop[Pointing_1][0] == 0)
                    {
                        c.tvb(1);
                    }

                    else if (p.evntprop[Pointing_1][0] == 1)
                    {
                        c.cvb(Pointing_1);
                    }
                    
                    goto sk;
                }
                else if(vp==103)

                {

                    if (p.evntprop[Pointing_1][0] == 0)
                    {
                        //c.dtvb(Pointing_1);
                    }
                       
                    
                    st = 0;
                    goto sk;
                }
                
                if (vp == 27 || vp == 100)
                {
                    st = 0;
                    vp = 0;
                    goto sk;
                }
                left();
                st = 0;
                goto se;
            }

            Pointing_1 = key1(no-1, Pointing_1);
            st = 0;
            vp = 0;
            
            if (Pointing_1 == 27 || Pointing_1 == 98)
            {
                return 0;
            }
            if (Pointing_1 == 99)
            {
                addev();
                goto r;
            }

            pre = tmp;
            tmp = Pointing_1;
            st = 0;
            
            if (Pointing_1 >=100 && Pointing_1 <190)
            {
                sel = 1;
                tmp = tmp - 100;
                Pointing_1 = Pointing_1 - 100;
                in = tmp;
            }
            else
            {
                sel = 0;
                vp = 0;
                goto se;
            }            

           

        } while (rand()!=6);

        tmp -= 100;

        return tmp;

    }


    void event_menu()
    {

        file f;

        int ge = display2(0);

        f.save();

    }

};

void call()
{
    even u;
    u.event_menu();
}

class RW
{
    
    public:

        int n = 8;

        string f[8] = {
        "Auto_Aroma",
        "Config.txt" },

        ff[8] = {
        "Auto_Aroma\\Projects",
        "Auto_Aroma\\Templates", },

        r[8] = {
        "Tools",
        "Projects",
        "Templates" },

        e[8] = {
        "Compiled_Script",
        "Original_Script",
        "Backups" },

        s[10] = { "Theme_Set",
        "Auto_Backup",
        "Name",
        "No_Templates",
        "User_Name",
        "Recent_Viewed_Project",
        "No_Custom_Lines", },

        o[10] = { "0",
        "1",
        "-",
        "0",
        "-",
        "-",
        "0", },

        v = { "\\" };

        char h[42] = "C:\\Users\\jesvi\\Documents\\Auto_Aroma\\Tools";
    

    void File_Error(int a)
    {

        switch (a) 
        {
        
            color(0);
        
        case 0: 
        {
            
            cout << "\n\nAn Unexpected Error Ocured While Creating Directory.. \n";
            cout << "(The Files In \"" << dir[1] << "Auto_Aroma\" Might Be In Use Or Opened)\n"; 
        break; 
        }
        
        case 1:
        {
            cout << "\n\nAn Unexpected Error Ocured While Creating Config File.. \n";
            cout << "(The Files In \"" << dir[2] << "Auto_Aroma\" Might Be In Use Or Opened)\n";
            break;
        }

        default: 
        {
            cout << "Oops ! An Error Occured"; 
            break; 
        }
        }
           color(1);
        
           _getch();
    }

    string Config(const char* refer,const char* value,int Use)
    { 

        string tmp[100];
        int i = 0;

        fstream config1(dir[7]);

        while (config1 >> tmp[i] && tmp[i]!="\0")
        {            
            i++;
        }
        
        config1.close();
        

        if (Use == 0)
        {

            fstream config2(dir[7]);

            for (int y = 0; y <= i; y = y + 3)
            {
                if (tmp[y] == refer)
                {
//                    cout << tmp[y] << " " << tmp[y + 1] << " " << value << endl;
                    config2 << tmp[y] << " " << tmp[y + 1] << " " << value << endl;
                }

                else
                {
//                    cout << tmp[y] << " " << tmp[y + 1] << " " << tmp[y + 2] << endl;
                    config2 << tmp[y] << " " << tmp[y + 1] << " " << tmp[y + 2] << endl;
                }
            }

            config2.close();

            return "";
        }

        else
        {
            for (int o = 0; o < i; o++)
            {
                if (tmp[o] == refer)
                {
                    return tmp[o+2];                
                }
            }
        }
        return "";
    }
    
    void getinfo()
    {
         stringstream g1(Config("Theme_Set", "1", 1));
         g1 >>Theme;

         stringstream g2(Config("Auto_Backup", "1", 1));
         g2 >> backup;

         cout << usr;

         Config("Name", usr.c_str(), 0);
 
    }

    void Create_D_S()
    {
        
        ofstream config((std::string("") + dir[7]).c_str());

        if (!config)
        {
            File_Error(1);
        }
        else
        {
            cout << "\n\n";
            color(0);
            cout << "Applying Default Settings -";
            color(1);
            cout << "\n\n";
        }
        
        o[2] = usr;

        for (int i = 0; i <= n; i++)
        {
            config<<s[i]<<" : "<<o[i]<<endl;
        }

        cout << "Set Initial Parameter\n";

        config.close();
    }

    void Delete_S()
    {
        color(0);
        cout << "\nDeleteing Config File -";
        color(1);
        cout << "\n\n";

        ofstream config((std::string("") +  dir[7]).c_str());
        config.close();

        if (remove("C:\\Users\\jesvi\\Documents\\Auto_Aroma\\Tools\\Config.txt") == 0)
        {
            cout << "Deleted : " << dir[7];
        }

        Create_D_S();
    }

    void Delete_L()
    {
        ofstream config((std::string("") + dir[6]).c_str());
        config.close();
        if (remove("C:\\Users\\jesvi\\Documents\\Auto_Aroma\\Tools\\List.txt") == 0)
        {

        }
    }

    void Reset_f()
    {
        color(0);
        cout << "\n\nReseting Program Files -\n\n";
        color(1);

        if(system((std::string("rmdir /s /q ") + dir[2]).c_str())==0)
        {
            cout << "Deleted : "<< dir[2];
        }

        Delete_L();

        if ((system((std::string("mkdir ") + dir[2] ).c_str())) == 0)
        {

            color(0);
            cout << "\n\nPlacing Program Files -\n\n";
            color(1);

            for (int u = 0; u <= 2; u++)
            {
                if ((system((std::string("mkdir ") + dir[3+u] ).c_str())) == 0)
                {
                    cout << "Created : "<< dir[3+u] <<endl;
                }
                
                else
                {
                    cout << "Error Creating : "<< dir[3+u]<< ""<<endl;
                }
            }
        }
        
        else
        {
            File_Error(0);
        }
        
        for (int i = 0; i <= 2; i++)
        {
            if ((system((std::string("mkdir ") + dir[8 + i]).c_str())) == 0)
            {
                cout << "Created : " << dir[8 + i] << endl;
            }

            else
            {
                cout << "Error Creating : " << dir[8 + i] << "" << endl;
            }
        }


    }

    void Reset_f1()
    {
        int er = 0;
        cout << "\n\n";
        color(0);
        cout << "Reseting Program Files -";
        color(1);
        cout << "\n\n";

        for (int d = 0; d <= 1; d++)
        {
            if (system((std::string("rmdir /s /q ") + dir[4+d]).c_str()) == 0)
            {
                cout << "Deleted : " << dir[4+d] << endl;
            }
            else
            {
                cout << "Error Deleteing : " << dir[4+d] << endl;
                er = 1;
            }
        }

        Delete_L();

        if ((!DirectoryExists((std::string("rmdir /s /q ") + dir[3]).c_str())) != 0)
        {
            cout << "\n";
            color(0);
            cout << "Placing Program Files -";
            color(1);
            cout << "\n\n";

            for (int u = 0; u <= 1; u++)
            {
                if ((system((std::string("mkdir ") + dir[4+u]).c_str())) == 0)
                {
                    cout << "Created : " << dir[4+u] << endl;
                }

                else
                {
                    cout << "Error Creating : " << dir[4+u] << "" << endl;
                    er = 1;
                }
            }
        }

        else
        {
            File_Error(0);
        }

        cout << endl;
        
        if (er == 1)
        {
            _getch();
        }

        for (int i = 0; i <= 2; i++)
        {
            if (system((std::string("rmdir /s /q ") + dir[8 + i]).c_str()) == 0)
            {
            }

            if ((system((std::string("mkdir ") + dir[8 + i]).c_str())) == 0)
            {
                cout << "Created : " << dir[8 + i] << endl;
            }

            else
            {
                cout << "Error Creating : " << dir[8 + i] << "" << endl;
            }
        }

    }

    void Reset_lvl(int b)
    {
        if (b == 1 )
        {
            Reset_f1();
        }
        
        if (b == 2)
        {
            Reset_f();
        }
        
        if (b == 0 || b == 2)
        {
            Delete_S();
        }
        Sleep(500);
    }
    
    void Check_Dir()
    {
        if (!DirectoryExists(h))
        {
            color(0);
            cout << "\nProgram Files Missing !\n";
            color(1);

            Sleep(500);
            
            Reset_lvl(2);
            
            Sleep(500);

            color(0);
            cout << "\nStarting Auto Aroma...";
            color(0);
            Sleep(2000);
        }

    }

    int List_Add(string Project_Name,int Use=0,int retsame=0)
    {
        ifstream config(dir[6]);

        int e=0,tmp=0;
        string h[21],f,ft,fg, same;
        f = Project_Name;


        for_each(f.begin(), f.end(), [](char& c) {c = ::tolower(c); });


        while (config >> h[e] && h[e] != "\0")
        {
            ft = h[e];

            for_each(ft.begin(), ft.end(), [](char& c) {c = ::tolower(c); });
            
            if(f==ft)
            {
                tmp = 1;
                same = h[e];
            }
            e++;
        }
        config.close();

        if (retsame == 1)
        {
            c_pro = same;
            Use = 1;
            Project_Name = same;
        }

        int w = 0;

        if (Use == 1) 
        {
            ofstream config1(dir[6]);
            
            config1 << Project_Name<<endl;

            for (int w = 0; w < e; w++)

            {
                fg=h[w];

                for_each(fg.begin(), fg.end(), [](char& c) {c = ::tolower(c); });

                if (fg == f)
                {
                    config1 << "";
                }
                else
                {
                    config1 << h[w] << endl;
                }
            }

            config1 << "\r";
            
                config1.close();
        }
    
        else
        {
            return tmp;
        }
        return 0;
    }

    void Create_Project_Dir()
        {
        color(1);
        cout << "\n\n";
        
        if (DirectoryExists((dir[4] + std::string("\\") + c_pro).c_str()) != 0)
        {
            Sleep(250);
            cout << "Cleaning Up";
            system((std::string("rmdir /s /q ") + dir[4] + std::string("\\") + c_pro).c_str());
        }
   
        system((std::string("mkdir ") + dir[4] + std::string("\\") + c_pro).c_str());
        
        cout << "\n\n";
        color(1);
        cout << "Creating Project Workspace";
        cout << "\n\n";
        file g;
        g.save();
        Sleep(250);
        cout << "Alright..";
        Sleep(500);
    }
    
};

class Theme_Set
{


    public:

        int Pointing_1 = 1;     //A Temporary Variable To Store User Input In Func 'Key'

        string Ptr = { " <-" },      //Pointer Icon
            Confirm_[3] = { "   Select The Theme To Apply", " Day Theme ", "Night Theme" };        //Exit Prompt With Two Options Stores In A Variable


        void Load_Theme()
        {
            RW r;
            
            if (r.Config("Theme_Set", "1", 1) == "0")
            {
                color(1, 0);
            }
            
            else
            {
                color(1, 1);
            }
        }

        int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
                                                        //Pointing -For Intial Value To Be Modified, Default Value = 0     
        {


            int Input = _getch();       //Get Keyboard Input 

            if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

            {

                switch (_getch())       //Check For Ascii
                {
                case 72:        //Up
                    Pointing--;
                    break;

                case 80:        //Down
                    Pointing++;
                    break;

                case 77:        //Right
                    //goto Enter;
                    break;

                case 75:        //Left
                    //goto Esc;
                    break;
                }

            }

            if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

            if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

            if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

                //Enter:

            {

                color(1, 1);            //If Pointing To Exit
                RW r;
                r.Config("Theme_Set", "1",0);
                return 27;
            }


            if (Input == 13 && Pointing_1 == 1)     //If Pointing To No

            {
                color(1, 0);
                RW r;
                r.Config("Theme_Set", "0",0);
                return 27;
            }

            if (Input == 27)        //Confirm 'Esc' Input

                //Esc:

            {

                return 27;    //Call The Exit Function 

            }

            return Pointing;        //Returning

        }

        void Theme_Menu()

        {
            Pointing_1 = 1;

            do

            {

                system("cls");

                for (int tmp1 = 0; tmp1 <= 1; tmp1++)       //Display Propmt Text

                {

                    if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                    {



                        cout << "\n\n\t\t     ";
                        color(0);
                        cout << Title << " (" << Version << ")";
                        cout << "\n\n";
                        color(1);
                        cout << "\n\n\n\n\n\t       ";
                        color(0);
                        cout << Confirm_[tmp1] << endl;
                        color(1);

                        //SetConsoleTextAttribute(console, 010);

                        for (int j = 1; j >= (Pointing_1); j--)
                        {
                            cout << endl << endl;
                        }

                    }


                    // For use of SetConsoleTextAttribute()


                    if (tmp1 == Pointing_1)
                    {
                        cout << "\t\t     -[ ";
                        //SetConsoleTextAttribute(console, 15);
                        color(0);
                        cout << Confirm_[tmp1 + 1];
                        //SetConsoleTextAttribute(console, 010);
                        color(1);
                        cout << " ]-" << endl << endl;
                    }
                    else
                    {
                        cout << "\t\t        " << Confirm_[tmp1 + 1] << endl << endl;
                    }

                }  Pointing_1 = key(1, 0);
                //Get User Keystroke Input

            } while (Pointing_1 != 27);        //Do Till Infinity

        }

    };

class SExit
{

public:

    int Pointing_1 = 1;     //A Temporary Variable To Store User Input In Func 'Key'

    string Ptr = { " <-" },      //Pointer Icon
        Confirm_[3] = { "Are You Sure You Want To Leave ?", "     Yes     ", "     No      "};        //Exit Prompt With Two Options Stores In A Variable


    void Exit_Yes()

    {
        system("cls");      //Clear Screen For Small Outro Animation

        cout << "\n\n\n\n\n\n\n\n\t\t     ";

        color(0);
        cout << Title << " (" << Version << ")\n\n";

        color(1);
        Sleep(300);

        cout << "\n\n\n\t\t      ";
        color(0);
        cout << "@ ";

        cout << Author;

        Sleep(1000);

        exit(1);        //Exit
    }

    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
                                                    //Pointing -For Intial Value To Be Modified, Default Value = 0     
    {


        int Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {

            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }

        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value


        if (Input == 13 && Pointing_1 == 0)     //If Pointing To Yes

        {
            return 11;
        }

        if (Input == 13 && Pointing_1 == 1)     //If Pointing To No

        {
            return 27;
        }


        if (Input == 27)        //Confirm 'Esc' Input

            //Esc:

        {

            return 27;    //Call The Exit Function 

        }

        return Pointing;        //Returning

    }

    int Exit_Confirm()

    {
        Pointing_1 = 1;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 1; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {



                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    cout << "\n\n";
                    color(1);
                    cout << "\n\n\n\n\n\t       ";
                    color(0);
                    cout << Confirm_[tmp1] << endl;
                    color(1);

                    //SetConsoleTextAttribute(console, 010);

                    for (int j = 1; j >= (Pointing_1); j--)
                    {
                        cout << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t    -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Confirm_[tmp1 + 1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {

                    cout << "\t\t       " << Confirm_[tmp1 + 1] << endl << endl;
                }

            }  Pointing_1 = key(1, Pointing_1);
            //Get User Keystroke Input

        } while (Pointing_1 != 27 && Pointing_1 != 11);        //Do Till Infinity

        return (Pointing_1);
    }

};

class RExit
{

public:

    int Pointing_1 = 1;     //A Temporary Variable To Store User Input In Func 'Key'

    string Ptr = { " <-" },      //Pointer Icon
        Confirm_[5] = { "A Project With Similar Name Already Exists !", "Overwrite Existing Project", "          Rename          ", "       Load Project       ",  "          Return          " };        //Exit Prompt With Two Options Stores In A Variable


    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
                                                    //Pointing -For Intial Value To Be Modified, Default Value = 0     
    {


        int Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {

            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }

        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value


        if (Input == 13 && Pointing_1 == 0)     //If Pointing To Yes

        {
            return 100;
        }

        if (Input == 13 && Pointing_1 == 1)     //If Pointing To No

        {
            return 11;
        }

        if (Input == 13 && Pointing_1 == 2)     //If Pointing To No

        {
            return 101;
        }

        if (Input == 13 && Pointing_1 == 3)     //If Pointing To No

        {
            return 27;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            //Esc:

        {

            return 27;    //Call The Exit Function 

        }

        return Pointing;        //Returning

    }

    int Exit_Confirm()

    {
        Pointing_1 = 1;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 3; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {



                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    cout << "\n\n";
                    color(1);
                    cout << "\n\n\n\n\n\t ";
                    color(0);
                    cout << Confirm_[tmp1] << endl;
                    color(1);

                    //SetConsoleTextAttribute(console, 010);

                    for (int j = 3; j >= (Pointing_1); j--)
                    {
                        cout << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t      -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Confirm_[tmp1 + 1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {

                    cout << "\t         " << Confirm_[tmp1 + 1] << endl << endl;
                }

            }  Pointing_1 = key(3, Pointing_1);
            //Get User Keystroke Input

        } while (Pointing_1 != 27 && Pointing_1 != 11 && Pointing_1 !=100 && Pointing_1 !=101);        //Do Till Infinity

        return (Pointing_1);
    }

};

class Reset
{
public:

    int Input,      //A Temporary Variable To Store User Input In Func 'Key'
        Pointing_1 = 0;       //A Reference Variable For 'Pointing'

    string Menu_Text_[4] = { "    Reset Settings   ", "Reset Project Folders", "     Full Reset      ", "       Return        " },
        Ptr[3] = { "-> ", " <-", "-" };


    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }

        RW r;

        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value


        if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

        {
            r.Reset_lvl(0);
        }

        if (Input == 13 && Pointing_1 == 1)        //Confirm 'Enter' Input

        {
            r.Reset_lvl(1);
        }

        if (Input == 13 && Pointing_1 == 2)        //Confirm 'Enter' Input

        {
            r.Reset_lvl(2);
        }

        if (Input == 13 && Pointing_1 == 3)        //Confirm 'Enter' Input

        {
            goto Esc;
        }


        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {
            return 27;
        }

        return Pointing;        //Returning Computed Input

    }

    void Menu()

    {
        int k = 4;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 3; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);


                    cout << "\n\n";

                    //color(1);
                    //SetConsoleTextAttribute(console, 010);

                    for (int j = 3; j >= (Pointing_1); j--)
                    {
                        cout << endl << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t-[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Menu_Text_[tmp1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {
                    cout << "\t\t   " << Menu_Text_[tmp1] << endl << endl;
                }




            }

            Pointing_1 = key(3, Pointing_1);       //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

};

class Settings
{
public:

    int Input,      //A Temporary Variable To Store User Input In Func 'Key'
        Pointing_1 = 0;       //A Reference Variable For 'Pointing'

    string Menu_Text_[5] = { "  Viewport Theme ", "  Extra Features ", "Compiler Settings", "  Reset Options  ", "     Return      " },
        Ptr[3] = { "-> ", " <-", "-" };

    string Menu_Text_1[4] = { "    Return     ", "    Backup     ", "   Templates   ", "    Report     " };
    string Menu_Text_2[3] = { "", "Turn On", "Turn Off"};

    void extra()
    {
    k:

        RW r;

        int u;
        u=display(Menu_Text_1, 4, 0, 4, 0, 0, 21);
    
        if (u == 0 || u == 27)
        {
            return;
        }

        if (u == 1)
        {
            int j;

            if (backup == 1)
            {
                Menu_Text_2[0] = { "           Project Auto Backup  ( Currently : On )" };
            }

            else
            {
                Menu_Text_2[0] = { "           Project Auto Backup  ( Currently : Off )" };
            }

            j = display(Menu_Text_2, 3, 1, 6, 0, 0, 23);



            if(j==0)
            {
                stringstream g2(r.Config("Auto_Backup", "1", 0));
                backup = 1;
            }
            else
            {
                    stringstream g2(r.Config("Auto_Backup", "0", 0));
                    backup = 0;
            }
        
            goto k;
        
        }
    }


    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }


        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value


        if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

        {
            Theme_Set t;
            t.Theme_Menu();
        }

        if (Input == 13 && Pointing_1 == 1)        //Confirm 'Enter' Input

        {
            
            extra();
        }

        if (Input == 13 && Pointing_1 == 2)        //Confirm 'Enter' Input

        {

        }

        if (Input == 13 && Pointing_1 == 3)        //Confirm 'Enter' Input

        {
            Reset r;
            r.Menu();
        }

        if (Input == 13 && Pointing_1 == 4)     //If Pointing To Esc

        {
            goto Esc;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {
            return 27;
        }

        return Pointing;        //Returning Computed Input

    }

    void SMenu_Disp()

    {
        int k = 5;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 4; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);


                    cout << "\n\n";

                    //color(1);
                    //SetConsoleTextAttribute(console, 010);

                    for (int j = 4; j >= (Pointing_1); j--)
                    {
                        cout << endl << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t  -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Menu_Text_[tmp1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {
                    cout << "\t\t     " << Menu_Text_[tmp1] << endl << endl;
                }




            }

            Pointing_1 = key(4, Pointing_1);       //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

};

class errorhandling {
    /*
    addsd




     











































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    */
};

class runtime {
    /*
    addsd













































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    */
};

class Main_Scripter
{

public:

    int Input,      //A Temporary Variable To Store User Input In Func 'Key'
        Pointing_1 = 1,       //A Reference Variable For 'Pointing'
        No_Events,
        Event_Created_Flag = 0,
        flag_once=0,
        tmpn;

    string Events_Text_[12] = {
        "      Return     ",
        "   Project Name  ",
        " Project Version ",
        "Project Developer",
        "  Target Device  ",
        "  Release  Date  ",
        "    Aroma DPI    ",
        "  Colour  Space  ",
        "     Themes      ",
        "      Font       ",
        "    Language     ",
        "  Project State  "},

        Ptr[3] = { "-> ", " <-", "-" },

        Events_Text_Sel[10] = { "[ Not Set ]",
                             "Enter",
                             "Your Name",
                             "Auto Add Before Compiling",
                             "Genric",
                             "Default",
                             "" },
                             In_The_Shell[12];

    char tmp[20];

    void theme()
    {

    }

    void font()
    {
        string gf[4] = { "Installer Font Set","Return", "Select Font","Font Size" };

        display(gf, 4, 1, 4, 1, 0, 21);

        while (1)
        {
            system("explorer C:\\Windows\\Fonts");
        }
        _getch();
    }

    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }


        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

        if (Input == 13 && Pointing_1 != 0)
        {
            Event_Created_Flag = 1;
        }
 

        if (Input == 13 && (Pointing_1 >= 1 && Pointing_1 <= 11))        //Confirm 'Enter' Input

        {
            if (Input == 13 && Pointing_1 == 1)
            {
            cout << "\n\n\t\t  ";
            cout << "Enter Data : ";
            cin.getline(tmp, 20);
            In_The_Shell[Pointing_1] = tmp;
            p.project_name = tmp;
            }

            if (Input == 13 && Pointing_1 == 2)
            {
                cout << "\n\n\t\t  ";
                cout << "Enter Data : ";
                cin.getline(tmp, 20);
                In_The_Shell[Pointing_1] = tmp;
                p.project_version = tmp;
            }
            
            if (Input == 13 && Pointing_1 == 3)
            {
                cout << "\n\n\t\t  ";
                cout << "Enter Data : ";
                cin.getline(tmp, 20);
                In_The_Shell[Pointing_1] = tmp;
                p.developer_name = tmp;
            }

            if (Input == 13 && Pointing_1 == 4)
            {
                cout << "\n\n\t\t  ";
                cout << "Enter Data : ";
                cin.getline(tmp, 20);
                In_The_Shell[Pointing_1] = tmp;
                p.target_device = tmp;
            
            }

            if (Input == 13 && Pointing_1 == 5)
            {
                cout << "\n\n\t\t  ";
                cout << "Enter Data : ";
                cin.getline(tmp, 20);
                In_The_Shell[Pointing_1] = tmp;
                p.release_date = tmp;

            }

            if (Input == 13 && Pointing_1 == 6)
            {


                string cl[7] = { "\t\t      Select Aroma Dpi      ", "     1     ", "     2     ", "     3     ","     4     ","     5     ","  Default  " };

                switch (display(cl, 7, 1, 4, 5,1))
                {
                case 0: {In_The_Shell[Pointing_1] = p.aroma_dpi = "1"; break; }
                case 1: {In_The_Shell[Pointing_1] = p.aroma_dpi = "2"; break; }
                case 2: {In_The_Shell[Pointing_1] = p.aroma_dpi = "3"; break; }
                case 3: {In_The_Shell[Pointing_1] = p.aroma_dpi = "4"; break; }
                case 4: {In_The_Shell[Pointing_1] = p.aroma_dpi = "5"; break; }
                case 5: {In_The_Shell[Pointing_1] = p.aroma_dpi = "0"; break; }
                }
            }

            if (Input == 13 && Pointing_1 == 7)
            {
                string col[5] = { "\t      Select The Colour-Space To Be Set      ", "   rgba   ", "   abgr   ", "   argb   ", "   bgra   " },
                       en[4] = { "rgba", "abgr", "argb", "bgra" };
                
                switch (display(col, 5, 1, 4, 0))
                {
                case 0: {In_The_Shell[Pointing_1] = p.colour_space = en[0]; break; }
                case 1: {In_The_Shell[Pointing_1] = p.colour_space = en[1]; break; }
                case 2: {In_The_Shell[Pointing_1] = p.colour_space = en[2]; break; }
                case 3: {In_The_Shell[Pointing_1] = p.colour_space = en[3]; break; }
                }
            }

            if (Input == 13 && Pointing_1 == 8)
            {
                theme();
            }

            if (Input == 13 && Pointing_1 == 9)
            {
                font();
            }

            if (Input == 13 && Pointing_1 == 10)
            {

            }

            if (Input == 13 && Pointing_1 == 11)
            {

                string ol[6] = { "\t\t    Set Project State To :  ",
                    "   Stable   ",
                    "    Beta    ",
                    "    Test    ",
                    "   Alpha    ",
                    "   Custom   " },
                    nh[4] = { "Stable", "Beta", "Test", "Alpha" };

                switch (display(ol, 6, 1, 4, 0,1))
                {
                case 0: {In_The_Shell[Pointing_1] = p.project_state = nh[0]; break; }
                case 1: {In_The_Shell[Pointing_1] = p.project_state = nh[1]; break; }
                case 2: {In_The_Shell[Pointing_1] = p.project_state = nh[2]; break; }
                case 3: {In_The_Shell[Pointing_1] = p.project_state = nh[3]; break;
                case 4: {                
                    cout << "\n\n\t\t  ";
                    cout << "Enter Data : ";
                    cin.getline(tmp, 20);
                    In_The_Shell[Pointing_1] = tmp;
                    p.project_state = tmp; } }
                }
                
            }

        
            if (tmp != "\0")
            {
                Event_Created_Flag = 1;
            }
            f.save();
        }
        

        if (Input == 13 && Pointing_1 == 0)     //If Pointing To Esc

        {
            goto Esc;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {
            return 27;

        }

        return Pointing;        //Returning Computed Input

    }

    void Menu_Disp()

    {

        {
            if (p.project_name != "\0")
            {
                In_The_Shell[1] = p.project_name;
            }
            if (p.project_version != "\0")
            {
                In_The_Shell[2] = p.project_version;
            }
            if (p.developer_name != "\0")
            {
                In_The_Shell[3] = p.developer_name;
            }
            if (p.target_device != "\0")
            {
                In_The_Shell[4] = p.target_device;
            }
            if (p.release_date != "\0")
            {
                In_The_Shell[5] = p.release_date;
            }
            if (p.aroma_dpi != "\0")
            {
                In_The_Shell[6] = p.aroma_dpi;
            }
            if (p.colour_space != "\0")
            {
                In_The_Shell[7] = p.colour_space;
            }
            if (p.theme != "\0")
            {
                In_The_Shell[8] = p.theme;
            }
            if (p.font != "\0")
            {
                In_The_Shell[9] = p.font;
            }
            if (p.language != "\0")
            {
                In_The_Shell[10] = p.language;
            }
            if (p.project_state != "\0")
            {
                In_The_Shell[11] = p.project_state;
            }
        }

        int k = 11;
        
        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 11; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);

                    cout<<"\n\n\n\n";

                }

                if (tmp1 == Pointing_1)
                {
                    if (tmp1 == 0) 
                    {
                        cout << endl << endl<< endl << endl;
                    }

                    if (tmp1 >= 1)
                    {
                        cout << endl << endl;
                        cout << "\t\t     " << Events_Text_[tmp1 -1] << endl << endl;
                    }

                    cout <<"\t\t  -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Events_Text_[tmp1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;

                    if (tmp1 <= 10)
                    {
                        cout << "\t\t     " << Events_Text_[tmp1 + 1] << endl << endl;
                        //cout << "\t\t\t    v";
                    }
                    
                    cout << "\n\n\n\n";
                    if (tmp1 == 11)
                    {
                        cout << "\n\n";
                    }

                    if (In_The_Shell[Pointing_1] != "\0" && Pointing_1 !=0)
                    {
                        
                        
                            cout << "\t\t    Set Entry : " << In_The_Shell[Pointing_1];
                     
                    }
                    else if (In_The_Shell[Pointing_1] == "\0" && Pointing_1 != 0 )
                    {
                        cout << "\t\t\t[ Not Set ]";
                    }
                    else
                    {
                        
                    }
                }

            }

            Pointing_1 = key(11, Pointing_1);       //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

};

class Event
{

public:

    int Input,      //A Temporary Variable To Store User Input In Func 'Key'
        Pointing_1 = 0,       //A Reference Variable For 'Pointing'
        No_Events,
        Event_Created_Flag = 0,
        A_Flag=0;

    string Event_Text_[5] = { " Edit Basic Parameter", "     Edit Events     ", "    More Settings    ", "    Compile Script   ","       Return        " },
        Ptr[3] = { "-> ", " <-", "-" };

    char Project_Name[21];

    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }


        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

        if (Input == 13 && Pointing_1 != 4)
        {
            Event_Created_Flag = 1;
        }

        if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

        {
            Main_Scripter Ma;
            Ma.Menu_Disp();
            if (backup == 1)
                f.save(1);
            else
                f.save(0);
        }

        if (Input == 13 && Pointing_1 == 1)        //Confirm 'Enter' Input

        {
            call();
            if (backup == 1)
                f.save(1);
            else
                f.save(0);
            
            
        }



        if (Input == 13 && Pointing_1 == 4)     //If Pointing To Esc

        {
            goto Esc;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {
            if (Event_Created_Flag == 1)
            {
                SExit e;
                if ((e.Exit_Confirm()) == 11)
                {
                    if (backup == 1)
                        f.save(1);
                    else
                        f.save(0);

                    return 27;
                }
            }
            else
            {
                if (backup == 1)
                    f.save(1);
                else
                    f.save(0);

                return 27;
            }
        }

        return Pointing;        //Returning Computed Input

    }

    void Menu_Disp()

    {
        int k = 4;

        do

        {

            system("cls");
            f.save();

            for (int tmp1 = 0; tmp1 <= 4; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    color(1);

                    cout << "\n\n\t\t    ";
                    cout << "Project : ";
                    cout<< c_pro;
                    cout << "";
                    //color(1);
                    //SetConsoleTextAttribute(console, 010);

                    for (int j =4; j >= (Pointing_1); j--)
                    {
                        cout << endl << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t-[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout <<   Event_Text_[tmp1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {
                    cout << "\t\t   " << Event_Text_[tmp1] << endl << endl;
                }


            }

            Pointing_1 = key(4, Pointing_1);       //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

    int Get_Project_Name()
    {

        int y = 0;
        t:
        system("cls");
        cout << "\n\n\t\t     ";
        color(0);
        cout << Title << " (" << Version << ")";
        color(1);

        cout << "\n\n\n\n\n\n";

        if (P_flag == 0 || P_flag == 1)
        {
            cout << "\n\n\t     (Enter Name Alone, eg: \"Eulah Rom\") \n\n  (& Don't Include The Version Or Any Other Package Info)\n\n";
            P_flag ++;
        }
        cout << "\t   ";
        color(0);
        cout << "Enter Project Name";
        color(0);
        cout << " : ";

        if (A_Flag == 1)
        {
            goto end;
        }

        cin.getline(Project_Name,21);       
        y = 0;
        while(Project_Name[y]!='\0')
        { 
    
            if (Project_Name[y] == '|' || Project_Name[y] == '\\' || Project_Name[y] == '*' || 
                Project_Name[y] == '?' || Project_Name[y] == '/' || Project_Name[y] == '<' || 
                Project_Name[y] == '>' || Project_Name[y] == ':' || Project_Name[y] == '"' ||
                Project_Name[y] == ',' || Project_Name[y] == ';' || Project_Name[y] == '=' ||
                Project_Name[y] == '&' || Project_Name[y] == '^' || Project_Name[y] == '.')
            {
                color(1);
                cout << "\n\t       ";
                color(0);
                cout<<"Illegal Character \""<<Project_Name[y]<<"\" Entered !";
                color(1);
                cout << "\n\n\t\tPress Any Key To Try Again ...";
                _getch();
                goto t;
            }

            if (Project_Name[y] == ' ')
            {
                Project_Name[y] = '_';
            }
            
            y++;
        }

        if(Project_Name[0] == NULL)
        {
            return 27;
        }


        A_Flag = 1;
        goto t;
        end:

        //cout << "\n\t\t   ";
        for (int g = 0; g < y; g++)
        {
            cout << Project_Name[g];
            Sleep(70);
        }
        Sleep(300);

        RW m;
        int g=m.List_Add(Project_Name, 0);
        
        if (g == 1) {

            RExit r;
            int f=r.Exit_Confirm();
            
            if (f==11)
            {
                A_Flag = 0;
                goto t;
            }
            else if (f == 101)
            {
                RW T;
                T.List_Add(Project_Name,0,1);
                file f;
                f.load_m(c_pro);
                return 1;
            }
            else if (f == 27)
            {
                return 27 ;
            }
            else
            {

            }
        }
        p.project_name = c_pro =Project_Name;
        f.sendfirst();
        
        RW rw;
        rw.Create_Project_Dir();
        
        m.List_Add(Project_Name,1);
        return 0;
    }
    
    
};

class Exit
{

public:

    int Pointing_1 = 1;     //A Temporary Variable To Store User Input In Func 'Key'

    string Ptr = { " <-" },      //Pointer Icon
        Confirm_[3] = { "Are You Sure You Want To Exit ?", " Yes ", " No  " };        //Exit Prompt With Two Options Stores In A Variable


    void Exit_Yes()

    {
        system("cls");      //Clear Screen For Small Outro Animation

        cout << "\n\n\n\n\n\n\n\n\t\t     ";
        
        color(0);
        cout << Title << " (" << Version << ")\n\n";

        color(1);
        Sleep(300);

        cout << "\n\n\n\t\t      ";
        color(0);
        cout<<"@";
        
        cout<< Author;

        Sleep(1000);

        exit(1);        //Exit
    }

    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
                                                    //Pointing -For Intial Value To Be Modified, Default Value = 0     
    {
        

        int Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {

            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }

        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value

        if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

            //Enter:

        {

            Exit_Yes();            //If Pointing To Exit

        }


        if (Input == 13 && Pointing_1 == 1)     //If Pointing To No

        {
            goto Esc;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {

            return 27;    //Call The Exit Function 

        }

        return Pointing;        //Returning

    }

    void Exit_Confirm()

    {
        Pointing_1 = 1;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 1; tmp1++)       //Display Propmt Text

            {

                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt

                {

                    

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout << Title << " (" << Version << ")";
                    cout<<"\n\n";
                    color(1);
                    cout << "\n\n\n\n\n\t       ";
                    color(0);
                    cout << Confirm_[tmp1] << endl;
                    color(1);
                    
                    //SetConsoleTextAttribute(console, 010);

                    for (int j = 1; j >= (Pointing_1); j--)
                    {
                        cout << endl << endl;
                    }

                }


                // For use of SetConsoleTextAttribute()


                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t        -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Confirm_[tmp1+1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout << " ]-" << endl << endl;
                }
                else
                {
                    cout << "\t\t           " << Confirm_[tmp1+1] << endl << endl;
                }

            }  Pointing_1 = key(1, 0);
                  //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

};

class Menu
{

public:
    

    
    int Input,      //A Temporary Variable To Store User Input In Func 'Key'
        Pointing_1=0;       //A Reference Variable For 'Pointing'

    string Menu_Text_[6] = { "Create New Script", "  Modify Script  ", "    Credits      ", "    Settings     ","      Exit       " },
        Ptr[3] = { "-> ", " <-", "-" };

    Exit e;

    int key(int No_Options, int Pointing)       //No_Options -For Total Pointer Movement        
    {

        Input = _getch();       //Get Keyboard Input 

        if (Input == 224)       //Confirm Whether It Is 'Arrow' Input     (This Function Randomly Works)

        {
            switch (_getch())       //Check For Ascii
            {
            case 72:        //Up
                Pointing--;
                break;

            case 80:        //Down
                Pointing++;
                break;

            case 77:        //Right
                //goto Enter;
                break;

            case 75:        //Left
                //goto Esc;
                break;
            }

        }
        
        Event E;

        if (Pointing < 0) { Pointing = 0; }     //Set The Min Value

        if (Pointing >= No_Options) { Pointing = No_Options; }      //Set The Max Value


        if (Input == 13 && Pointing_1 == 0)        //Confirm 'Enter' Input

        {
            

            project k;
            p = k;
            int u=E.Get_Project_Name();
            if (u == 101)
            {
                f.load();
            }
            else if(u==27)
            {
             
            }
            else 
            {
                E.Menu_Disp();
            }
            
        }

        if (Input == 13 && Pointing_1 == 1)        //Confirm 'Enter' Input

        {
            int io;
            io=f.load();
            if(io==1)
            {
                E.Menu_Disp();
            }
            
        }

        if (Input == 13 && Pointing_1 == 2)        //Confirm 'Enter' Input

        {
            Credits();
        }

        if (Input == 13 && Pointing_1 == 3)        //Confirm 'Enter' Input

        {
            Settings s;
            s.SMenu_Disp();
        }

        if (Input == 13 && Pointing_1 == 4)     //If Pointing To Esc

        {
            goto Esc;
        }

        if (Input == 27)        //Confirm 'Esc' Input

            Esc:

        {   
            e.Exit_Confirm();
        }

        return Pointing;        //Returning Computed Input

    }
  
    void Menu_Disp()

    {
        int k = 5;

        do

        {

            system("cls");

            for (int tmp1 = 0; tmp1 <= 4; tmp1++)       //Display Propmt Text

            {
                
                if (tmp1 == 0)      //For First Line Proper Alignment After Propmt
                
                {

                    cout << "\n\n\t\t     ";
                    color(0);
                    cout<<Title << " (" << Version << ")"; 
                    color(1);


                    cout<<"\n\n";
    
                    //color(1);
                    //SetConsoleTextAttribute(console, 010);
                
                    for (int j = 4; j >= (Pointing_1); j--)
                    {
                        cout << endl<<endl;
                    }

                }

    
                 // For use of SetConsoleTextAttribute()

                
                if (tmp1 == Pointing_1)
                {
                    cout << "\t\t  -[ ";
                    //SetConsoleTextAttribute(console, 15);
                    color(0);
                    cout << Menu_Text_[tmp1];
                    //SetConsoleTextAttribute(console, 010);
                    color(1);
                    cout<< " ]-" << endl << endl;
                }
                else
                {                
                    cout << "\t\t     " <<Menu_Text_[tmp1] << endl<<endl ;
                }
            
            
            
            
            }

            Pointing_1 = key(4, Pointing_1);       //Get User Keystroke Input

        } while (Pointing_1 != 27);        //Do Till Infinity

    }

};

int main()
{   

    setscreen(500, 450);     //Set Initial Window Size

    RW r;
    r.Check_Dir();
    r.getinfo();

    Theme_Set t;
    t.Load_Theme();     //Set Theme

	Menu M;     //Create Class Menu Reference
    M.Menu_Disp();

    return 0;
    
    // 8k lines
}