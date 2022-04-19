#include <iostream>
#include <conio.h>
using namespace std;

void line(string str)
{
    cout << str << endl;
}/*
struct Auction{
   string title,cnic, bidd_name, st_date, end_date, pay_date,p={"hd"};, min_value[1000], t_pl = 0
   double shop_no, add_shop,pay_invoice, modify_shop, del_shop, no_shops,shop_valve;shop_no[100], st_value[1000]
   double   dep_cash,pl_counter=0,shop_counter,bidd_counter ,no_bidd, st_value, min_value, counter = 0;
};
//----------------------------------------------------------------------------------------------------------
struct Auction {//title[100], bidd_name[100], cnic[100], st_date[50], end_date[50],
    string  payment_date[50];
    double dep_cash[1000], no_bidd[1000];
    int  add_shop[100], del_shop[100], modify_shop[100], no_shops[100];
    int counter = 0, sh_valve[100], pay_invoice[100];
};*/
//--------------------------------------------------------------------------------------------------------------
string title,venue, st_date, end_date;
int t_pl = 0;
//------------------------------------------
struct  shop_reg {
    int shop_no, shop_value, st_value, min_value;
    string cnic;
    string name;
}shops[100];
int sh_counter = 0;
//------------------------------------------
struct bidd_reg {
    string bidd_name, cnic; int shop_no;
    double  payment,dep_cash, pay_invoice;
    shop_reg shop;
}bidd[100];
int bidd_counter = 0;

//--------------------------------------------------------------------------------
//---------------------------- functon prototype --------------------------------
shop_reg shop;
bidd_reg bid;
shop_reg search_shop(int);
void remove_shop_from_array(shop_reg);
void auc_config();
int sh_reg();
int bidd_reg();
int st_auc();
int auc_summ();
int bidder_rec();
int exit();
//=====================================================================================================================
//============================== CASE : 1 ======== auction confg ======================================================
void auc_config()
{
   char a;
   line("\n>>>>>>>>>>>>>>>>                          WELCOME TO THE AUCTION CONFIGURATION :");
   line("\n----------------------------------------------------------------------------------------------------------------------:");
   do {
    title:      cin.ignore();
    cout<<"\n ENTER AUCTION TITLE : ";
    getline(cin, title);
    cout<<"\n ENTER AUCTION  VENUE : ";
    getline(cin,venue);
    line("\n          WHAT YOU WANT 'ADD FURTHER OR GO AHEAD' : ?");
    line("              ADD-'Y'    ~    BACK-'N' ");
    cin >> a;
    {
     if (a == 'y' || a == 'Y')
     goto title;
     else
     goto date;
    }

  date: cin.ignore();
    cout << "\n ENTER START DATE :";
    getline(cin, st_date);
    cout << "\n ENTER LAST DATE :";
    getline(cin, end_date);
    cout<<"\n--------------------------";
    t_pl++;
     // for(int i=0; i<t_pl; i++)
   {
    cout<<"\n TITLE NAME IS : " << title;
    cout<<"\n AUCTION WILL BE LOCATED AT (VENUE) : "<<venue;
    }
    cout << "\n TOTAL AUCTION PLACES ARE : " << t_pl;
    line("\n\n                   'THANK YOU'");
    } while (a == 'y' || a == 'Y');
    cout << "\n----------------------------------------------------------------------------------------------------------------------:";
}


//======================================================================================================================
//============================== CASE : 2 ============== shop registration(for selling) ================================
int sh_reg()
{ // if(sh_counter<1)
  //{
 //  cout<<"\n PLEASE FIRST ADD ANY TITLE ~ VENUE AND THAN TRY : \n";
 //  return 1;
 // }
 // else
above: line(">>>>>>>>>>>>>>>>>>                          WELCOME TO THE AUCTION SHOP SYSYTEM : ");
    line("-----------------------------------------------------------------------------------------------------------------------:");
    line(" WHAT YOU WANT 'SELECT FROM BELOW'");
    line("----------------------------------:-");
    line("\n                            FOR NEW SHOPS REGISTRY PRESS '1'   ~   FOR SHOP MODIFICATION  PRESS '2' ");
    line("                            FOR DELETE YOUR  SHOP PRESS  '3'   ~   FOR GOBACK 'MAIN' PRESS '4' ");
    int n;
    cin >> n;
    if (n == 1)
    {
     line("                                               WELCOME TO THE AUCTION SHOP REGISTRY :"); //for selling
     line("-----------------------------------------------------------------------------------------------------------------------:");
     char a;
     do {
     // {
    // for(int i=0; i<sh_counter+1; i++)
    // cin.ignore();
      cout<<"\n ENTER YOUR SHOP NUMBER : ";
      cin >> shops[sh_counter].shop_no;
     cout<<"\n ENTER YOUR  SHOP VALUE : ";
      cin >> shops[sh_counter].shop_value;
      cout<<"\n ENTER STARTING  AMOUNT : ";
      cin >> shops[sh_counter].st_value;
      cout<<"\n ENTER  MINIMUM  AMOUNT : ";
      cin >> shops[sh_counter].min_value;
      // }
      line("\n\n           'YOUR SHOP HAS BEEN REGISTERED'");
      line("\n                    'THANK YOU'");
      sh_counter++;
       cout << "\n\n TOTAL SHOPS '" << sh_counter<<"' ARE ADDED FOR AUCTION :";
      line("\n\n          WHAT YOU WANT 'ADD FURTHER OR GO BACK' : ? ");
      line("\n                   'Y'-ADD   ~    'N'-BACK");
      cin >> a;
    } while (a == 'y' || a == 'Y');
     line("\n----------------------------------------------------------------------------------------------------------------------:");

     goto above;
  }

    //-------------------------------------------------------------------------------------------------------
    //----------------------------------------- SHOP MODIFICATION -------------------------------------------
    else if (n==2)
  {
     line("\n                                           WELCOME TO THE SHOP MODIFICATION :");
     line("----------------------------------------------------------------------------------------------------------------------:");
     int sh_mo;
 name1: cout<<"\n ENTER YOUR SHOP NUMBER FOR MODIFICATION : ";
      cin >> sh_mo;

     for(int i=0; i<sh_counter; i++)
     {
      if(shops[i].shop_no==sh_mo)
      {
     cout<<"-------------------------------------------\n";// shop datail
     cout << "\n YOUR  SHOP  No. IS : '" << shops[i].shop_no;
     cout << "\n YOUR SHOP VALUE IS : '" << shops[i].shop_value;
     cout << "\n YOUR STARTING AMOUNT IS : '"<<shops[i].st_value;
     cout << "\n YOUR MINIMUM  AMOUNT IS : '"<<shops[i].min_value;
     cout << "\n---------------------------------------\n";
     cout << "\n ENTER YOUR NEW DATA :";
     cout << "\n ---------------------";
     cout << "\n ENTER YOUR NEW SHOP NUMBR : "; cin>>shops[i].shop_no;
     cout << "\n ENTER YOUR NEW SHOP VALUE : "; cin>>shops[i].shop_value;
     cout << "\n ENTER YOUR NEW STARTING AMOUNT : "; cin>>shops[i].st_value;
     cout << "\n ENTER YOUR NEW MINIMUM  AMOUNT : "; cin>>shops[i].min_value;
     line("\n\n                  YOUR SHOP RECORD HAS BEEN MODIFIED");
     line("\n                          'THANK YOU'");
     line("\n----------------------------------------------------------------------------------------------------------------------:");
     goto above;
    }
    }
   if(shops[sh_counter].shop_no!=sh_mo)
   {
    cout << "\nYOUR SHOP IS NOT EXIST : ";
    cout << "\nDO YOU WANT TO TRY AGAIN : y/n ? : ";
    char tri;
    cin >> tri;
    if (tri == 'Y' || tri == 'y')
    goto name1;
     else
    line("\n----------------------------------------------------------------------------------------------------------------------:");
    goto above;
    }
  }
   //--------------------------------------------------------------------------------------------------------
    //---------------------------------------------SHOP DELETION --------------------------------------------
  else if(n==3)
   {
    int sh_no,index=0;
   line("\n                                           WELCOME TO THE SHOP DELETTION :");
   line("----------------------------------------------------------------------------------------------------------------------:");
del_sh:   cout << "ENTER YOUR SHOP NUMBER FOR DELETION: ";
   cin >> sh_no;


   //------------MY DELETION--------------------------------
   for(int i=0; i<sh_counter; i++)
   {
     if(sh_no==shops[i].shop_no)
       {
        index=i;
  // }
 //   {
  //   for(int i=0; i<sh_counter; i++)

      cout<<"\n YOUR SHOP NUMBER : "<<shops[i].shop_no;
      cout<<"\n YOUR  SHOP VALUE : "<<shops[i].shop_value;
      cout<<"\n STARTING  AMOUNT : "<<shops[i].st_value;
      cout<<"\n MINIMUM   AMOUNT : "<<shops[i].st_value;
      goto de;
    }
   }

    for(int i=0; i<sh_counter; i++)
    {
   if(sh_no!=shops[i].shop_no)
    {
    cout<<"\n YOUR'S SHOP NOT FOUND : \n";
    cout<<"\n DO YOU WANT TO TRY AGAIN : Y/N ? ";
   char a;
   cin>>a;
   if(a=='y' || a=='Y')
   {
    cout<<endl;
    goto del_sh;
   }
   else
   {
   goto above;
   }
   }
    }
de: line("\n");
    cout << "DO YOU REALLY WANT TO DELETE YOUR SHOP : (y/n) ?  ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice=='Y')
    {
    for(int i=index; i<sh_counter-1; i++)
    {
       shops[i]=shops[i+1];
    }
   sh_counter--;
   cout<<"\n YOUR'S SHOP HAS BEEN DELETED SUCCESSFULLY : \n";
  }
  else
    {
    cout<<"\nYOU CANCEL SHOP DELETION \n";
   line("----------------------------------------------------------------------------------------------------------------------:\n");
    goto above;
    }

   line("----------------------------------------------------------------------------------------------------------------------:\n");
    cout<<"\n DO YOU WANT TO DELETE FURTHER SHOPS : Y/N ? ";
   char a;
   cin>>a;
   if(a=='y' || a=='Y')
   {
    cout<<endl;
    goto del_sh;
   }
   else
   {
   goto above;
   }
   //-------------------------------------------------------------------------------------------------------
//---------------------------------RETURN BACK -------------------------------------------------------------
 }
    else if (n == 4)
    line("\n----------------------------------------------------------------------------------------------------------------------:");
    return 1;
}


//=====================================================================================================================
//=========================== CASE : 3 ================= bidder registration ==========================================
int bidd_reg()
{
  //  if(bidd_counter<1)
  //  {
  //  cout<<"\n PLEASE FIRST ADD SHOPS AND THAN TRY FOR BIDDER REGISTRATION : ";
  //  return 1;
 //   }
 //   else
above: line(">>>>>>>>>>>>>>>>>>                             WELCOME TO THE AUCTION BIDDER SYSYTEM : ");
    line("-----------------------------------------------------------------------------------------------------------------------:");
    line(" WHAT YOU WANT 'SELECT FROM BELOW'");
    line("----------------------------------:-");
    line("\n                            FOR NEW BIDDER REGISTRY PRESS '1'   ~   FOR BIDDER MODIFICATION  PRESS '2' ");
    line("                            FOR BIDDER  DELETION   PRESS  '3'   ~   FOR GO BACK TO 'MAIN' PRESS '4' ");
    int n;
    cin >> n;
    if (n == 1)
    {
    line("                                             WELCOME TO THE AUCTION BIDDER REGISTRY :"); // buyer registry
    line("-----------------------------------------------------------------------------------------------------------------------:");
    char a;
    do {
     cin.ignore();
     cout<<"\n ENTER  YOUR   GOOD  NAME : ";
     getline(cin, bidd[bidd_counter].bidd_name);
     cout<<"\n ENTER YOUR 'CNIC' NUMBER : ";
     getline(cin, bidd[bidd_counter].cnic);
     int sh_no;
     int index=-1;

    askId:
    cout<<"\n ENTER YOUR SHOP NUMBER : ";
    cin>>sh_no;
    for(int i=0; i<sh_counter; i++)
    {
    if(shops[i].shop_no == sh_no)
    {
     index = i;
     }
   }

   if(index!=-1) // found
   {
     bidd[bidd_counter].shop = shops[index];
    }
    else // not found
    {
     cout<<"\nYOUR'S SHOP NOT FOUND : ";
     cout<<"\nDO YOU WANT TO TRY AGAIN : Y/N ? ";
     char c;
     cin>>c;
     if(c=='y' || c=='Y')
     goto askId;
     else
     goto above;
  }

    cout<<"\n PLEASE DEPOSITE "<<shops[index].shop_value*.05<<" AS A BID SECURITY AMOUNT.";
    cin>> bidd[bidd_counter].dep_cash;
    bidd[bidd_counter].payment = shops[index].shop_value*.05;
    cout<<"\n\n ENTER INVOICE NUMBER : "; cin>>bidd[bidd_counter].pay_invoice;
    cout<<"\n\n YOU '"<<bidd[bidd_counter].bidd_name<<"' HAVE BEEN SUCCESSFULLY REGISTERED FOR AUCTION 'SHOP NO' : "<<shops[sh_counter].shop_no;
    bidd_counter++;
    //cout<<"\n Total Bidders:"<<CountBidders<<endl;
    line("\n\n           'YOUR REGISTRATION HAS BEEN APPROVED' : ");
    line("\n                      'THANK YOU'");
    cout<<"\n---------------------------------------\n";
    bidd_counter++;
    line("\n\n         WHAT YOU WANT 'ADD SOMEONE ELSE OR GO BACK' : ? ");
    line("\n                   ADD 'Y'   ~    BACK 'N'");
    cin >> a;
  } while (a != 'N' || a != 'n');
    line("\n----------------------------------------------------------------------------------------------------------------------:");
     goto above;
      //i++;
  }

  //----------------------------------------------------------------------------------------------------------
  //-----------------------------------------BIDDER ACCOUNT MODIFICATION -------------------------------------
   else if (n == 2)
   {
     line("\n                                           WELCOME TO THE ACCOUNT MODIFICATION :");
     line("----------------------------------------------------------------------------------------------------------------------:");
     int i = 0;
     string name;
 name1: cout<<"\n ENTER YOUR 'NAME'  : ";
      cin >> name;
      for(int i=0; i<bidd_counter; i++)
      {
      if (bidd[i].bidd_name==name)
      {  cin.ignore();                        // bidder data ------
       cout << "\n YOUR  G.D  NAME IS : " << bidd[i].bidd_name<<". ENTER YOUR NEW NAME : ";
       getline(cin,bidd[i].bidd_name);
       cout << "\n YOUR 'CNIC' No. IS : " << bidd[i].cnic<<". ENTER YOUR NEW CNIC : ";
       getline(cin,bidd[i].cnic);
       cout << "\n YOUR  DEP CASH IS : " << bidd[i].dep_cash<<". ENTER NEW DEP CASH : ";
       cin>>bidd[i].dep_cash;
       cout << "\n PAYMENT INVOICE IS : " << bidd[i].pay_invoice<<". ENTER NEW PAY INVOICE : ";
       cin>>bidd[i].pay_invoice;
       line("\n");
       line("\n\n                  YOUR ACCOUNT HAS BEEN MODIFIED");
      line("\n                          'THANK YOU'");
      line("\n----------------------------------------------------------------------------------------------------------------------:");
       goto above;
       }
     }

    if(bidd[i].bidd_name!=name)
      {
      cout << "\nYOUR SHOP IS NOT EXIST : ";
      cout << "\nDO YOU WANT TO TRY AGAIN : y/n ? : ";
      char tri;
      cin >> tri;
      if (tri == 'Y' || tri == 'y')
      goto name1;
      else
      line("\n----------------------------------------------------------------------------------------------------------------------:");
      goto above;
      }

   }
    //--------------------------------------------------------------------------------------------------------
    //------------------------------ BIDDER ACCOUNT DELETION -------------------------------------------------
    else if (n == 3)
    {
      int c; string nam;
     //first check if shop available or not
     //if not available than 'not found'
 name:   cout<<"\n ENTER YOUR NAME FOR ACCOUNT DELETION : ";
      cin >> nam; int index=0;
      for(int i=0; i<bidd_counter; i++)
      {
     if (bidd[i].bidd_name==nam)
      {   index=i;                        // bidder data ------
       cout << "\n YOUR  G.D  NAME IS : " << bidd[i].bidd_name;
       cout << "\n YOUR 'CNIC' No. IS : " << bidd[i].cnic;
       cout << "\n YOUR  PAID CASH IS : " << bidd[i].dep_cash;
       cout << "\n PAYMENT INVOICE IS : " << bidd[i].pay_invoice;
       line("\n");
        goto below;
      }
      }
        for(int i=0; i<bidd_counter; i++)
      {
      if(bidd[i].bidd_name!=nam)
      {
       cout << "\n                YOUR ACCOUNT IS NOT EXIST : ";
       cout << "\n              DO YOU WANT TO TRY AGAIN : y/n : ?";
       char tri;
       cin >> tri;
       if (tri == 'Y' || tri == 'y')
       goto name;
        else
       line("\n----------------------------------------------------------------------------------------------------------------------:");
       goto above;
      }
      }
  below:
      {
     cout << "\n DO YOU REALLY WANT TO DELETE YOUR ACCOUNT :y/n ? : ";
     char n; int c;
     cin >> n;
     if (n == 'y' || n == 'Y')
     {
         for(int i=index; i<bidd_counter-1; i++)
         {
            bidd[i]=bidd[i+1];
         }
         bidd_counter--;

        line("\n                YOUR ACCOUNT HAS BEEN REMOVED : ");
        line("\n\n                    'THANK YOU' ");
        line("\n----------------------------------------------------------------------------------------------------------------------:");
        goto above;
  }
}
}
//-------------------------------------------------------------------------------------------------
//---------------------------------- RETURN BACK --------------------------------------------------
    else if (n == 4)
    line("\n----------------------------------------------------------------------------------------------------------------------:");
    return 1;
}
//===========================================================================================================================================
//================== CASE 4 =============================== START AUCTION ===================================================================

int st_auc()
{
   // if(sh_counter<1)
  //  {
   //  cout<<"\n PLEASE FIRST ADD THE SHOPS FOR AUCTION AND THAN TRY : \n";
   //  return 1;
   // }
  //  else

    for(int i=0; i<sh_counter; i++)
    { int minusOne = 0; double bidAmount;
     cout<<endl<<i+1<<". SHOP : "<<shops[i].shop_no<<endl<<" STARTING FROM : "<<shops[i].st_value<<endl;
    while(minusOne<3)
    {
     int amount;
      cout<<"ENTER BIDD AMOUNT: ";
      cin>>amount;
     if(amount==-1)
     minusOne++;
     else
     {
     minusOne=0;
     bidAmount = amount;
      }
    }
     string cnic;
    cout<<"\nPLEASE ENTER THE WINNER CNIC NO. : ";
    cin>>cnic;
  }
}
//=============================================================================================================================
//====================== case 5 ========================= AUCTION SUMMARY =====================================================

int auc_summ()
{
 //  if(t_pl<1 || sh_counter<1 || bidd_counter<1)
 //  {
 //  cout<<"\n PLEASE FIRST ADD ANY RECORD AND THAN WATCH SUMMARY : ";
 //   return 1;
 //   }
 // else
    int i = 0;
    line("\n>>>>>>>>>>>>>>>>                         WELCOME TO THE AUCTION SUMMARY  :");
    line("\n---------------------------------------------------------------------------------------------------------------------:");
    line("\n DO YOU WANT TO SEE AUCTION SUMMARY : y/n ? : ");
    char s;
    cin >> s;
    if (s == 'Y' || s == 'y')
    {
    line("-----------------------------");
    cout<<"\n AUCTION TITLE IS : "<<title;
    cout<<"\n AUCTION WILL BE LOCATED AT : "<<venue;
    cout<<"\n THE AUCTION WILL START FROM : "<<st_date;
    cout<<"\n AND THE AUCTION WILL END ON : "<<end_date;
    cout<<"\n TOTAL SHOPS ARE :"<<sh_counter;
    cout<<"\n TOTAL BIDDERS ARE :"<<bidd_counter;
    line("\n-----------------------------");
    cout<<"\n\n SHOP RECORD : \n";
    cout<<"---------------------------\n";
    for(int i=0; i<sh_counter; i++)
    {
    cout<<i+1<<". SHOP : "<<shops[i].shop_no<<endl;
    cout<<" SHOP   VALUE  IS : "<<shops[i].shop_value<<endl;
    cout<<" MINIMUM VALUE IS : "<<shops[i].min_value<<endl;
    cout<<" START  VALUE  IS : "<<shops[i].st_value<<endl;
    cout<<"      ~     \n\n";
    }
    cout<<"----------------------------\n";

    cout<<"\n BIDDER RECORD : \n";
    cout<<"----------------------------\n";
    for(int i=0; i<bidd_counter; i++)
    {
    cout<<i+1<<". BIDDER:"<<bidd[i].bidd_name<<endl;
    cout<<"  BIDD CNIC: "<<bidd[i].cnic<<endl;
    cout<<"  Payment  : "<<bidd[i].payment<<endl;
    cout<<"  INVOICE NUMBER:"<<bidd[i].pay_invoice<<endl;
    cout<<"  Applied For   :"<<shops[i].shop_no<<endl;
    cout<<"        ~    \n\n";
    }
    cout<<"-------------------------------"<<endl;
    cout << "\n\n                'THANK YOU; ";
    cout<<"\n\n";
    }
    else
    {
    line("\n----------------------------------------------------------------------------------------------------------------------:");
     return 1;
    }
}
//====================================================================================================================
//==================== case 6 ===========BIDDER RECORD ===============================================================
int bidder_rec()
{
 //   if(bidd_counter<1)
 //   {
 //   cout<<"\n PLEASE FIRST ADD ANY BIDDER RECORD AND THAN TRY : ";
 //   return 1;
 //   }
 //   else

    line("\n>>>>>>>>>>>>>>>>                         WELCOME TO THE BIDDER RECORD  :");
    line("\n---------------------------------------------------------------------------------------------------------------------:");
rec:    cout<<"\n ENTER YOUR NAME TO CHECK YOUR RECORD : ";
     string naam;
    cin>>naam;
    for(int i=0; i<bidd_counter; i++)
    {
    if(naam==bidd[i].bidd_name)
    {
    goto be;
    }

    for(int i=0; i<bidd_counter; i++)
    {
    if(naam!=bidd[i].bidd_name)
    {
    cout << "\n             YOUR RECORD IS NOT FOUND : ";
    cout << "\n           DO YOU WANT TO TRY AGAIN : y/n :";
    char tri;
    cin >> tri;
   if (tri == 'Y' || tri == 'y')
     goto rec;
    else
    line("\n----------------------------------------------------------------------------------------------------------------------:");
    return 1;;
    }
    }
                            // bidder data ------
be: cout<<"\n BIDDER RECORD : \n";
    cout<<"-----------------------------\n";
    for(int i=0; i<bidd_counter; i++)
    {
    cout<<i+1<<". BIDDER:"<<bidd[i].bidd_name<<endl;
    cout<<"  BIDD CNIC: "<<bidd[i].cnic<<endl;
    cout<<"  Payment  : "<<bidd[i].payment<<endl;
    cout<<"  INVOICE NUMBER:"<<bidd[i].pay_invoice<<endl;
    cout<<"  Applied For   :"<<shops[i].shop_no<<endl;
    cout<<"        ~    \n";
    cout<<"----------------------------\n";
    }
    }
    cout<<"\nSHOP RECORD : \n";
    cout<<"--------------------------\n";
    for(int i=0; i<sh_counter; i++)
    {
    if(bidd[i].bidd_name==naam)
    {
    cout<<". SHOP : "<<shops[i].shop_no<<endl;
    cout<<" SHOP   VALUE  IS : "<<shops[i].shop_value<<endl;
    cout<<" MINIMUM VALUE IS : "<<shops[i].min_value<<endl;
    cout<<" START  VALUE  IS : "<<shops[i].st_value<<endl;
    cout<<"      ~     \n";
    }
    cout<<"-------------------------------"<<endl;
    cout << "\n\n                'THANK YOU; ";
    cout<<"\n\n";
     }

    return 1;
}
//==========================================================================================================================
//=================================== MAIN FUNCTION ========================================================================
//==========================================================================================================================

int main()
/*{  ( pass:
    string pass;
    cout<<" PLEASE ENTER A PASSWORD : ";
    cin>>pass;
    if(pass==auc.p)
    {goto prog;}
    else
    {cout<<"\nWRONG PASSWORD ~ TRY AGAIN : \n";goto pass;}
 prog:*/
{
    bool repeat;
    do
    {

   line("-----------------------------------------------------------------------------------------------------------------------:");
   line("                                            WELCOME TO THE 'AUCTION SYSTEM' :");
   line("-----------------------------------------------------------------------------------------------------------------------:");
   line("                                                     MAIN MENU :                             ");
   line("-----------------------------------------------------------------------------------------------------------------------:");
 menu:
   int choise;
   cout << "\n                   PRESS '1' FOR 'AUCTION CONFIGURATION'  :";
   cout << "      PRESS '2' FOR 'SHOP REGISTRATION'     :";
   cout << "\n                   PRESS '3' FOR 'BIDDER  REGISTRATION'   :";
   cout << "      PRESS '4' FOR 'TO  START  AUCTION'    :";
   cout << "\n                   PRESS '5' FOR 'FOR  AUCTION  SUMMARY'  :";
   cout << "      PRESS '6' FOR CHECK  BIDDER  RECORD   : ";
   cout << "\n                   PRESS '7' FOR 'EXIT AUCTION PROGRAM'   :\n  ~ ";
   cin >> choise;

   switch (choise)
     {
      case 1:
       {
           auc_config();
          // goto menu;
          // break;
        }
        //===========================
        case 2:
        {
            sh_reg();
            goto menu;
            break;
        }
        //==========================
        case 3:
        {
            bidd_reg();
            goto menu;
            break;
        }
        //===========================
        case 4:
        {
          line("\n>>>>>>>>>>>>>>>>                         WELCOME TO THE AUCTION SYSYTEM  :");
          line("\n-------------------------------------------------------------------------------------------------------------------:");
          st_auc();
          goto menu;
           break;
        }
        //============================
        case 5:
        {
          auc_summ();
          goto menu;
          break;
        }
        //===========================
        case 6:
        {
          bidder_rec();
          goto menu;
          break;
        }
        //===========================
        case 7:
        {
          cout<<"\n\n     'GOOD BYE'   : ";
          cout<<"\n-----------------------";
          return 0;
          break;
        }

        default:
         line("  WRONG INPUT : ENTER VALID NUMBER");
         goto menu;
        }
    } while (repeat);

    getch();
    return 0;
}
