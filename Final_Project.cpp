#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;


class history
{
    public:
    int y_t,mo_t,d_t,h_t,mi_t,year_t,month_t,day_t,hour_t,minute_t,r_year,r_month,r_day,r_hour,r_minute;

    public:
    void currenttime();
    void inputtime();
    void printtime();
    void input_y();
	void input_mo();
	void input_d();
	void input_h();
	void input_mi();
    void set_y(int);
	void set_mo(int);
	void set_d(int);
	void set_h(int);
	void set_mi(int);
    void remainingtime();
    void print_rtime();


};
void history::print_rtime(){

    cout<<"\n\n\tYear: "<< r_year<<setw(10)<< "Month: "<< r_month<<setw(8)<< "Day: "
    << r_day<<endl<<endl<< "\tHour: "<< r_hour<<setw(10)<< "Minute: "<<r_minute
    <<setw(10)<<endl;

}

void history::remainingtime(){
int mo,d,h,mi;
d = day_t - d_t;
if(day_t>d_t)
    r_year = year_t - y_t ;
    else
        r_year = year_t - y_t-1;


mo = month_t - mo_t;
if(day_t>d_t){
    if(mo<0)
        r_month=(12-mo_t)+month_t;
        else
            r_month=mo;
}
else{
    r_month = 12 - mo_t;
}


if(d<0){
   r_day=(30-d_t)+day_t;
}
else
    r_day=d;



h = hour_t - h_t;
if(h<0){
   r_hour=(23-h_t)+hour_t;
}
else
    r_hour=h;


mi = minute_t - mi_t;
if(mi<0){
   r_minute=(60-mi_t)+minute_t;
}
else
    r_minute=mi;



}
void history::input_y()
{
    int y;
    cout<< "\nYear(Format shamsi):";
    cin >> y;

    while(1){
    if( y>1398){
        break;
    }
    cout<<"Try again:";
    cin >> y;
    }
    set_y(y);
}

void history::input_mo()
{
    int mo;
    cout<< "\nMonth(1 - 12):";
    cin >> mo;

    while(1){
    if( mo>0 && mo<13 ){
        break;
    }
    cout<<"Try again:";
    cin >> mo;
    }
    set_mo(mo);

}

void history::input_d()
{
    int d;
    cout<< "\nDay(1 - 30/31):";
    cin >> d;

    while(1){
    if( d>0 && d<32 ){
        break;
    }
    cout<<"Try again:";
    cin >> d;
    }
    set_d(d);
}

void history::input_h()
{
     int h;
    cout<< "\nHour(24-hour format):";
    cin >> h;

    while(1){
    if( h>=0 && h<24 ){
        break;
    }
    cout<<"Try again:";
    cin >> h;
    }
    set_h(h);

}

void history::input_mi()
{
     int mi;
    cout<< "\nMinute(0 - 60):";
    cin >> mi;

    while(1){
    if( mi>=0 && mi<=60 ){
        break;
    }
    cout<<"Try again:";
    cin >> mi;
    }
    set_mi(mi);
}

void history::set_y(int y){
    year_t = y;
}
void history::set_mo(int mo){
    month_t = mo;
}
void history::set_d(int d){
    day_t = d;
}
void history::set_h(int h){
    hour_t = h;
}
void history::set_mi(int mi){
     minute_t = mi;
}

void history::currenttime(){

    time_t currentDateTime = time(0);

    tm *localTime = localtime(&currentDateTime);

    y_t = 1900 + localTime->tm_year;
    mo_t = 1 + localTime->tm_mon;
    d_t =  localTime->tm_mday;
    h_t =  localTime->tm_hour;
    mi_t = localTime->tm_min;

}

void history::inputtime(){
    input_y();
	input_mo();
	input_d();
	input_h();
	input_mi();
}

void history::printtime(){


    //cout<<"Year : "<<y_t<<endl<<"Month : "<<mo_t<<endl<<"Day : "<<d_t<<endl<<"Time : "<<h_t<<":"<<mi_t<<":"<<s_t<<endl;

    cout<<"Year: "<< year_t<<setw(10)<< "Month: "<< month_t<<setw(10)<< "Day: "
    << day_t<<endl<<endl<< "\tHour: "<< hour_t<<setw(10)<< "Minute: "<<minute_t<<setw(10)<<endl
    <<endl;


}




class reminder:public history
{
   private:
    int numberR,number,completion;
    string description;


   public:
    string user,usr;
    void create_r();
    void upcoming_r();
    void created_r();
    void finished_r();
    void search_r();

	void set_n(int);
	void set_c(int);
	void set_d(string);
    int n;
	void number_reminder();
	void input_c();
	void input_di();
	void print_reminder();
    void r_t_off();
    void reminders();
    void delete_r();

};
void reminder::delete_r(){

}

void reminder::r_t_off(){

completion=1;

}
void reminder::reminders(){

     fstream reminders_file("reminders", ios::app | ios::in);
    if(!reminders_file)
    {
        cerr<< "file cannot open";
        exit(EXIT_FAILURE);
    }

    int x,v,shomarande;
    usr=user;

    while(1){

        system("cls");
    cout << "\n1.Create reminder\n\n";
    cout << "2.Upcoming reminders\n\n";
    cout << "3.Reminders created\n\n";
    cout << "4.Finished reminders\n\n";
    cout << "5.Search for reminders\n\n";
    cout << "6.Exit\n\n\n";
    cout << "Select One:";

cin>>x;

if(cin.fail())
    cin>>x;

	switch (x)
	{
	case 1:
		system("cls");
        create_r();
        reminders_file<<numberR<<' '<<user<<' '<<year_t<<' '<<month_t<<' '<<day_t<<' '<<hour_t<<' '<<minute_t<<' '<<completion<<' '<<description<<' ';
        reminders_file.close();

        break;
	case 2:
		system("cls");
		shomarande=1;
		for(int w=1;w<20;w++){
        reminders_file>>numberR>>user>>year_t>>month_t>>day_t>>hour_t>>minute_t>>completion>>description;
        if(numberR==shomarande && user==usr){
            ++shomarande;
            upcoming_r();
            reminders_file<<numberR<<' '<<user<<' '<<year_t<<' '<<month_t<<' '<<day_t<<' '<<hour_t<<' '<<minute_t<<' '<<completion<<' '<<description<<' ';
		}
		}
        reminders_file.close();

        cout<<"\n\t0.Back\n\tSelect : ";
        cin>>v;
        if(v==0)
            break;
	case 3:
	    system("cls");
	    shomarande=1;
        for(int w=1;w<20;w++){
        reminders_file>>numberR>>user>>year_t>>month_t>>day_t>>hour_t>>minute_t>>completion>>description;
        if(numberR==shomarande && user==usr){
           ++shomarande;
            created_r();
        }
        }
        reminders_file.close();

        cout<<"\n\t0.Back\n\tSelect : ";
        cin>>v;
        if(v==0)
            break;
	case 4:
	    system("cls");
        for(int w=1;w<20;w++){
        reminders_file>>numberR>>user>>year_t>>month_t>>day_t>>hour_t>>minute_t>>completion>>description;
        if(numberR==shomarande && user==usr){
            ++shomarande;
            finished_r();
        }
        }
        reminders_file.close();

        cout<<"\n\t0.Back\n\tSelect : ";
        cin>>v;
        if(v==0)
            break;
	case 5:
		 system("cls");
		 cout<<"\n\tEnter number of reminder(1 - 10) : ";
	    cin>>n;
	    cout<<endl;
        for(int w=1;w<20;w++){
        reminders_file>>numberR>>user>>year_t>>month_t>>day_t>>hour_t>>minute_t>>completion>>description;

        if(numberR==n && user==usr){
            shomarande=1;
            search_r();
            break;
        }
        }
        reminders_file.close();

        cout<<"\n\t0.Back\n\n\tSelect :";
        cin>>v;
        if(v==0)
            break;



    case 6:
        exit(1);

	}
	system("cls");
}
}



void reminder::create_r(){
    number_reminder();
    inputtime();
    input_c();
    input_di();

}
void reminder::upcoming_r(){
    int y;
    if(completion==0){
        print_reminder();
        cout<<"\n\t1.Turn off reminder\n\tselect:";
        cin>>y;
    }

    if(y==1)
        r_t_off();

}
void reminder::created_r(){
    print_reminder();
}
void reminder::finished_r(){
    if(completion==1){
        print_reminder();
    }
}
void reminder::search_r(){
        int y;
        print_reminder();

}

void reminder::set_c(int c){
    completion = c;
}
void reminder::set_d(string d){
    description=d;
}




void reminder::number_reminder()
{
    int n;
    cout<<"Number of Reminders:";
    cin>>n;
    numberR=n;

}

void reminder::input_c()
{

    set_c(0);

}
void reminder::input_di()
{
    string d;
    cout<< "\nDescription:";
    cin >> d;
    set_d(d);

}
void reminder::print_reminder()
{
    currenttime();
    remainingtime();
    //print_rtime();

    cout<<endl<<"###############################################"<<endl;
    cout<<endl<<"      =>=>=> Number of Reminders: "<< numberR<<" <=<=<="<<endl<<"\n\t";
    printtime();
    cout<< "\tCompletion status: "<< completion<<endl<<endl<< "\tDescription: "
    <<description<<endl<<endl<<"\tRemaining time:";
    print_rtime();

    cout<<endl<<endl<<endl<<"###############################################"<<endl;
}







class Account:public reminder
{
public:

	string F_name;
	string L_name;
	int age;
	string username;
	int password;
	int account_number;
public:
	void set_A(string, string, int, string, int, int);
	void set_F(string);
	void set_L(string);
	void set_a(int);
	void set_u(string);
	void set_p(int);
	void set_n(int);
	string get_F();
	string get_L();
	int get_a();
	string get_u();
	int get_p();
	int get_n();
	bool check_Fn(string*);
	bool check_Ln(string*);
	bool check_age(int);
	bool check_user(string*);
	bool check_pass(int);
	bool check_AN(int, fstream);
	void s_l_account(int p);

	void send_Account(fstream);
	void input_Fn();
	void input_Ln();
	void input_age();
	void input_user();
	void input_pass();
	void a_number();
	void welcome();
	void load_account();
	void save_account();
	bool check_account(string,int);

};


void Account::welcome(){
   cout<<"\n\t#################################################\n";
    for(int i=0;i<17;i++){
    cout<<"\t#"<<setw(49)<<"#\n";
    if(i==2){
        cout<<"\t#"<<setw(47)<<  "  W E L L C O M E                 "<<"#\n";
    }
    if(i==6){
        cout<<"\t#"<< "      Your First Name : "<<setw(20)<< F_name<<"   #\n";
    }
     if(i==9){
        cout<<"\t#"<<"      Your Last Name : "<<setw(20)<< L_name<<"    #\n";
    }
     if(i==12){
        cout<<"\t#"<<"      Your Username : "<<setw(20)<<username<<"     #\n";
    }
    }
    cout<<"\t#################################################";

user=username;


}

void Account::set_A(string f, string l, int a, string u, int p, int n)
{
	set_F(f);
	set_L(l);
	set_a(a);
	set_u(u);
	set_p(p);
	set_n(n);
}

void Account::set_F(string f)
{
	F_name= f;
}

void Account::set_L(string l)
{
	L_name= l;
}

void Account::set_a(int a)
{
	age = a;
}

void Account::set_u(string u)
{
	username= u;
}

void Account::set_p(int p)
{
	password = p;
}

void Account::set_n(int n)
{
    account_number = n;
}
bool Account::check_account(string usr,int pswrd){
 if(username==usr && password==pswrd)
    return true;
 else
    return false;

}

void Account::save_account(){
fstream account_file("Account", ios::app | ios::in);
    if(!account_file)
    {
        cerr<< "file cannot open";
        exit(EXIT_FAILURE);
    }

  account_file<<account_number<<'\n'<<F_name<<' '<<L_name<<' '<<age<<' '<<username<<' '<<password<<'\n';
    account_file.close();


}





void Account::a_number()
{
    int n;
    cin>>n;
    set_n(n);

}
void Account::input_Fn()
{
	string f;
	cin>> f;

	set_F(f);
}

void Account::input_Ln()
{
	string l;
	cin>> l;

	set_L(l);
}

void Account::input_age()
{
    int a;
    cin>> a;

	set_a(a);
}

void Account::input_user()
{
	string u;
	cin>> u;

	set_u(u);
}

void Account::input_pass()
{
	int p;
	cin>> p;

	set_p(p);

}



class screen :public Account
{
public:
	static screen* instance;
	static screen* getInstance();
	void inputmenu();
	void login_user();
	void register_user();
	void menu();
	void input_mainmenu();
	void settings();
	void Background();
	void send_Account();
	void load_account();

private:
	screen(){
		cout << "\n\n";
		cout << setw(30) << "Welcome to App\n\n\n";
		cout << setw(18) << "1.Login\n";
		cout << setw(21) << "2.Register\n";
		cout << setw(17) << "3.Help\n";
		cout << setw(21) << "4.Settings\n";
		cout << setw(19) << "5.Exit\n\n\n";
		cout << setw(21) << "Select One:";
	}
};

screen* screen::instance = NULL;

screen* screen::getInstance()
{
	if (instance == NULL)
	{
		instance = new screen();
	}
	return instance;
}


void screen::send_Account(){




}

void screen::load_account(){
fstream account_file("Account", ios::app | ios::in);
    if(!account_file)
    {
        cerr<< "file cannot open";
        exit(EXIT_FAILURE);
    }

    string usr;
    int pswrd,f,y=0,t=0,u=0;

    cout << "Enter the username and password to login\n" << endl;
	cout << "Username:";
	cin>>usr;
	cout << "\n";
	cout << "Password:";
	cin>>pswrd;


while(1){
	while(1){
    account_file>>account_number>>F_name>>L_name>>age>>username>>password;
    if(check_account(usr,pswrd)==true)
   {
            cout<<"\n\n\tLogin Successfully";
            y=1;
            Sleep(1000);
            break;
    }
    else{
            ++t;
    if(t==20){
        u=1;
        break;
    }
    }

    if(check_account(usr,pswrd)==false && u==1){
            account_file.close();
            cout<<"\n\tYour information is not available,Please try again or register.\n\t1.Retry\n\n\t2.Register\n\n";
            cin>>f;
            if(f==1){
            u=1;
            system("cls");
            cout << "Enter the username and password to login\n" << endl;
            cout << "Username:";
            cin>>usr;
            cout << "\n";
            cout << "Password:";
            cin>>pswrd;
        }
        if(f==2){
            system("cls");
            register_user();
            save_account();
            menu();
            input_mainmenu();
        }
        }
	}
	if(y==1)
        break;
    }
}




void screen::inputmenu()
{
    int x;
    cin >> x;
	switch (x)
	{
	case 1:
		system("cls");

		load_account( );
        menu();
        input_mainmenu();
		break;
	case 2:
		system("cls");
		register_user();
		save_account();
		menu();
		input_mainmenu();
		break;
	case 3:
	    system("cls");
        cout<<"\n\tThis app is for storing and managing reminders.\n"<<
        "\tCreating a user account for each user and saving his reminders and knowing the remaining reminder time.\n\n\t"<<
        "Creater: \n\n\t\tMohammad Hosein Ebadati\n\t\tMehrdad Monavvari Nasab\n\n";
        Sleep(8000);
        system("cls");
        screen();
        inputmenu();


            break;

	case 4:
	    system("cls");
	    settings();
		break;
	case 5:
		exit(1);

		break;
	}


}

void screen::settings(){
    int p;

    cout << "\nChange font color and background.\n";
    cout << "\nHelp : The first color is the background and the second is the font.\n";
    cout << "\n1.White-Black(Default)\n\n2.Bright White-Black\n\n3.Blue-Bright White\n\n4.Aqua-Bright White\n\n5.Red-Light Aqua\n\n6.Light Yellow-Green\n\n7.Back\n\nselect one:";

    cin >> p;
    switch(p)
    {
    case 1:
        system("color 70");
        system("cls");
        screen();
        inputmenu();
       break;
    case 2:
        system("color F0");
        system("cls");
        screen();
        inputmenu();
        break;
    case 3:
       system("color 1F");
       system("cls");
       screen();
       inputmenu();
       break;
    case 4:
        system("color 3F");
        system("cls");
        screen();
        inputmenu();
        break;
    case 5:
        system("color 4B");
        system("cls");
        screen();
        inputmenu();
        break;
    case 6:
        system("color E2");
        system("cls");
        screen();
        inputmenu();
        break;
    case 7:
        system("cls");
        screen();
        inputmenu();

}
}
void screen::register_user()
{
    int z;
	cout << "Enter the details to register\n" << endl;
	cout << "First Name:";
	input_Fn();
	cout << "\n";
	cout << "Last Name:";
	input_Ln();
	cout << "\n";
	cout << "Age:";
	input_age();
	cout << "\n";
	cout << "Username:";
	input_user();
	cout << "\n";
	cout << "Password:";
	input_pass();
	cout << "\n";
	cout << "Account Number:";
	a_number();


}


void screen::menu()
{
    system("cls");
    welcome();
    Sleep(4000);
    system("cls");
    cout << "\n1.Create reminder\n\n";
    cout << "2.Upcoming reminders\n\n";
    cout << "3.Reminders created\n\n";
    cout << "4.Finished reminders\n\n";
    cout << "5.Search for reminders\n\n";
    cout << "6.Exit\n\n\n";
    cout << "Select One:";
    reminders();

}
void screen::input_mainmenu(){
int e;
cin >> e;
switch (e)
	{
	case 1:
		system("cls");
    cout << "dfgdf";
		break;
	case 2:
		system("cls");

		break;
	case 3:
	    system("cls");

		break;
	case 4:
	    system("cls");

		break;
	case 5:
	    system("cls");

		break;
    case 6:
        system("cls");

		break;
	}

}

int main()
{


    SetConsoleTitle("Reminder");
    system("color 70");
	screen* obj;
	obj = screen::getInstance();
	obj->inputmenu();

	_getche();
	return 0;
}
