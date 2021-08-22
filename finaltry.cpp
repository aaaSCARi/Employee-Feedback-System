#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

float overall;

struct teacher
{
    int teach_rating[12];
    int opp;
    float mathavgoverall;
    float phyavgoverall;
    float chemavgoverall;
  public:
    void getdata()
    {
        RE2:
        cout<<"Select Option:- \nMathematics - 1 \nPhysics     - 2 \nChemistry   - 3 \n";
        cin>>opp;
        if ( opp < 1 || opp > 3)
           {
               cout<<"Wrong Option entered\n";
               goto RE2;
           }
        system("cls");
        cout<<"Tell us what you think about the Teacher \nRate out of 1-5";
        Reinput:
        cout<<"\nPunctuality : ";
            cin>>teach_rating[0];
        cout<<"Clarity : " ;
            cin>>teach_rating[1];
        cout<<"Interaction : " ;
            cin>>teach_rating[2];
        cout<<"Subject Knowledge : ";
            cin>>teach_rating[3];
        cout<<"Doubt-clarification : ";
            cin>>teach_rating[4];
        cout<<"Individual attention: ";
            cin>>teach_rating[5];
        cout<<"Class control: ";
            cin>>teach_rating[6];
        cout<<"On time Syllabus completion : ";
            cin>>teach_rating[7];
        cout<<"Timeliness : ";
            cin>>teach_rating[8];
        cout<<"General rating : ";
            cin>>teach_rating[9];
        int i;
        float allsum=0;
        for(i =0 ; i<10;i++)
        {
            if(teach_rating[i] > 5 || teach_rating[i]<0 )
            {
                cout<<"\nDue to Incorrect input of values Reinput the DATA ";
                goto Reinput;
            }
        allsum=allsum+teach_rating[i];
        }
        overall=allsum/10;
         cout<<"Thanks for your feedback!\n";
        switch (opp)
         {
            case 1:
                mathfile(overall);
                break;
            case 2:
                phyfile(overall);
                break;
            case 3:
                chemfile(overall);
                break;
         }
    }
    void showdata()
    {
        int opp;
        RE3:
        cout<<"Select Option:- \nMathematics - 1 \nPhysics     - 2 \nChemistry   - 3 \n";
        cin>>opp;
        switch(opp)
        {
        case 1:cout<<"Overall teacher rating is ";
              mathteach();
              break;
        case 2:cout<<"Overall teacher rating is ";
              phyteach();
              break;
        case 3:cout<<"Overall teacher rating is ";
              chemteach();
              break;
        default:
              cout<<"Wrong Option entered\n";
              goto RE3;
        }
    }
        fstream file;
            int mathfile(float moa)
            {
                float msum=0,mpart=0,mavg;
                    //File 'Average'
                  fstream mf1("mathsum.dat",ios::out|ios::in);
                    mf1>>msum;
                    msum=msum+moa;
                    mf1.close();
                  ofstream mf3("mathsum.dat");
                    mf3<<msum;
                    mf3.close();
                    //File 'Participants'
                  fstream mf2("mathpart.dat",ios::out|ios::in);
                    mf2>>mpart;
                    mpart++;
                    mf2.close();
                  ofstream mf4("mathpart.dat");
                    mf4<<mpart;
                  mf4.close();
                  mavg=msum/mpart;
            return 0;
            }
            int mathteach()
            {
                float msum=0,mpart=0,mavg;
                    //File 'Average'
                fstream mf3("mathsum.dat",ios::out|ios::in);
                    mf3>>msum;
                mf3.close();

                fstream mf4("mathpart.dat",ios::out|ios::in);
                    mf4>>mpart;
                mf4.close();
                mavg=msum/mpart;
                printf("%.2f\n",mavg);
                return 0;
            }

            int phyfile(float poa)
            {
                float psum=0,ppart=0,pavg;
                    //File 'Average'
                  fstream pf1("physum.dat",ios::out|ios::in);
                    pf1>>psum;
                    psum=psum+poa;
                  pf1.close();
                  ofstream pf3("physum.dat");
                  pf3<<psum;
                  pf3.close();
                    //file 'Participants'
                  fstream pf2("phypart.dat",ios::out|ios::in);
                    pf2>>ppart;
                    ppart++;
                  pf2.close();
                  ofstream pf4("phypart.dat");
                  pf4<<ppart;
                  pf4.close();
                pavg=psum/ppart;
            return 0;
            }
            int phyteach()
            {
                float psum=0,ppart=0,pavg;
                    //File 'Average'
                fstream pf3("physum.dat",ios::out|ios::in);
                    pf3>>psum;
                pf3.close();

                fstream pf4("phypart.dat",ios::out|ios::in);
                    pf4>>ppart;
                pf4.close();
                pavg=psum/ppart;
                printf("%.2f\n",pavg);
            }

            int chemfile(float coa)
            {
                float csum=0,cpart=0,cavg;
                    //File 'Average'
                  fstream cf1("chemsum.dat",ios::out|ios::in);
                    cf1>>csum;
                    csum=csum+coa;
                    cf1.close();
                   ofstream cf3("chemsum.dat");
                    cf3<<csum;
                    cf3.close();
                    //file 'Participants'
                  fstream cf2("chempart.dat",ios::out|ios::in);
                  cf2>>cpart;
                  cf2.close();
                  cpart++;
                  ofstream cf4("chempart.dat");
                  cf4<<cpart;
                  cf4.close();
                cavg=csum/cpart;
            return 0;
            }
            int chemteach()
            {
                float csum=0,cpart=0,cavg;
                    //File 'Average'
                fstream cf3("chemsum.dat",ios::out|ios::in);
                    cf3>>csum;
                cf3.close();

                fstream cf4("chempart.dat",ios::out|ios::in);
                    cf4>>cpart;
                cf4.close();
                cavg=csum/cpart;
                printf("%.2f\n",cavg);
            }
};


int main()
{
    teacher t;
    int n,rno,passkey;
    RE0:
    cout<<"Are you a\n 1.Student \n 2.Teacher\n 3.Exit\n";
    cin>>n;
    system("cls");
    switch(n)
    {
        case 1: //View & Edit
        {
        system("cls");
        cout<<"Enter your Roll Number\n";
        cin>>rno;
        RE1:
        cout<<"Enter PassKey\n";
        cin>>passkey;
        if(passkey==1234)
             t.getdata();
        else
            {
             cout<<"Incorrect Passkey, try again\n";
             goto RE1;
            }
        goto RE0;
        }
        break;
        case 2://View only
        {
        system("cls");
        RE2:
        cout<<"Enter Teacher Passkey ";
            cin>>passkey;
        if(passkey==4321)
             t.showdata();
        else
            {
             cout<<"Incorrect Passkey, try again";
             goto RE2;
            }
        goto RE0;
        }
        break;
        case 3:cout<<" ";
        break;
        default:
        {
            cout<<"Wrong option entered\n";
            goto RE0;
        }
    }

}
