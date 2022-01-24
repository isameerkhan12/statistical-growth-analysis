#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#include <cmath>

using namespace std;

char ch[4]={'A','B','C','T'};
int A=0,B=1,C=2,Total=3,Y2019=0,Y2020=1,x=0,highest=0;
int Health=0,Home=1,Sports=2,Fashion=3,Food=4,Electronic=5;
string Type[]={"Health","Home","Sports","Fashion","Food","Electronic"};
string Type1[]={"Health","Home","Sports","Fashion","Food","Electronic"}; 
float BranchSale_Year[4][2];
int Quantity_Year[3][2];
float Mean_Year[3][2];
int Mean_Quantity[3][6];
float BranchSale_Product[4][6][2];
int Quantity_Product[4][6][2];
int GraphA[10][20];
int Count[3]={0,0,0};
int gradient[3]={0,0,0};
int Frequency[3][2];
float ratingmean[3][2]; 
float SD[3][2]; 
int sort[6];
float StdDev[3][2];
void Title_Page()
{
   system("cls");
   system("color f1");
   cout<<"\n\t                       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
   cout<<"\n\t                       \xB2\xB2                                 \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     ***********************     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *     STATISTICAL     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *       GROWTH        *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *      ANALYSIS       *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     *                     *     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2     ***********************     \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2                                 \xB2\xB2";
   cout<<"\n\t                       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
   cout<<"\n\n-----------------------------------"<<endl;
   cout<<"PRESS ANY KEY TO CONTINUE......."<<endl;
   cout<<"-----------------------------------"<<endl;
   _getch();
}
class Customer
{
    char branch;
    string type;
    float price;
    
    int quantity;
    float total;
    int year;
    float rating;
    Customer * next;
    friend class Data;
};

class Data
{
    Customer *head,*tail;
    public:
    Data(){head=NULL;tail=NULL;}
    void ReadData()
    {
        ifstream is("C://Users//Sameer//Desktop//university//SEM 3//DS//Project//Statistical Growth Annalysis//DataSet.txt");
        if(is)
        {
            for(int i=0;i<600;i++)
            {
                Customer *temp = new Customer;		
                is>>temp->branch;
                is>>temp->type;
                is>>temp->price;
                is>>temp->quantity;
                is>>temp->total;
                is>>temp->year;
                is>>temp->rating;
                temp->next=NULL;  
   
                if(temp->branch=='A')
                {Count[A]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[A][Y2019]++;
                            Quantity_Product[A][k][Y2019]=Quantity_Product[A][k][Y2019]+temp->quantity;
                            BranchSale_Product[A][k][Y2019]=BranchSale_Product[A][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[A][Y2019]=BranchSale_Year[A][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;
                            Mean_Year[A][Y2019]=BranchSale_Year[A][Y2019]/Count[A];
                            Frequency[A][Y2019]=Mean_Year[A][Y2019]/12;
                            ratingmean[A][Y2019]=(ratingmean[A][Y2019]+temp->rating)/Count[A];
                            SD[A][Y2019]=((temp->rating-ratingmean[A][Y2019])); 
                            }
                            else
                            {Quantity_Year[A][Y2020]++;
                            Quantity_Product[A][k][Y2020]=Quantity_Product[A][k][Y2020]+temp->quantity;
                            BranchSale_Product[A][k][Y2020]=BranchSale_Product[A][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[A][Y2020]=BranchSale_Year[A][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;
                            Mean_Year[A][Y2020]=BranchSale_Year[A][Y2020]/Count[A];
                            Frequency[A][Y2020]=Mean_Year[A][Y2020]/12;
                            ratingmean[A][Y2020]=(ratingmean[A][Y2020]+temp->rating)/Count[A];
                            SD[A][Y2020]=((temp->rating-ratingmean[A][Y2020]));
                            }
                        }
                    }
                //  Graph((Mean_Year[A][Y2019]+Mean_Year[A][Y2020])/2);
                }            
                if(temp->branch=='B')
                {Count[B]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[B][Y2019]++;
                            Quantity_Product[B][k][Y2019]=Quantity_Product[B][k][Y2019]+temp->quantity;
                            BranchSale_Product[B][k][Y2019]=BranchSale_Product[B][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[B][Y2019]=BranchSale_Year[B][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;
                            Mean_Year[B][Y2019]=BranchSale_Year[B][Y2019]/Quantity_Year[B][Y2019];
                            Frequency[B][Y2019]=Mean_Year[B][Y2019]/12;
                            ratingmean[B][Y2019]=(ratingmean[B][Y2019]+temp->rating)/Count[B];
                            SD[B][Y2019]=((temp->rating-ratingmean[B][Y2019]));
                            }
                            else
                            {Quantity_Year[B][Y2020]++;
                            Quantity_Product[B][k][Y2020]=Quantity_Product[B][k][Y2020]+temp->quantity;
                            BranchSale_Product[B][k][Y2020]=BranchSale_Product[B][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[B][Y2020]=BranchSale_Year[B][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;
                            Mean_Year[B][Y2020]=BranchSale_Year[B][Y2020]/Quantity_Year[B][Y2020];
                            Frequency[B][Y2020]=Mean_Year[B][Y2020]/12;
                            ratingmean[B][Y2020]=(ratingmean[B][Y2020]+temp->rating)/Count[B];
                            SD[B][Y2019]=((temp->rating-ratingmean[B][Y2020]));}
                        }
                    }
                }
                if(temp->branch=='C')
                {Count[C]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[C][Y2019]++;
                            Quantity_Product[C][k][Y2019]=Quantity_Product[C][k][Y2019]+temp->quantity;
                            BranchSale_Product[C][k][Y2019]=BranchSale_Product[C][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[C][Y2019]=BranchSale_Year[C][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;
                            Mean_Year[C][Y2019]=BranchSale_Year[C][Y2019]/Quantity_Year[C][Y2019];
                            Frequency[C][Y2019]=Mean_Year[C][Y2019]/12;
                            ratingmean[C][Y2019]=(ratingmean[C][Y2019]+temp->rating)/Count[C];
                            SD[C][Y2019]=((temp->rating-ratingmean[C][Y2019]));}
                            else
                            {Quantity_Year[C][Y2020]++;
                            Quantity_Product[C][k][Y2020]=Quantity_Product[C][k][Y2020]+temp->quantity;
                            BranchSale_Product[C][k][Y2020]=BranchSale_Product[C][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[C][Y2020]=BranchSale_Year[C][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;
                            Mean_Year[C][Y2020]=BranchSale_Year[C][Y2020]/Quantity_Year[C][Y2020];
                            Frequency[C][Y2020]=Mean_Year[C][Y2020]/12;
                            ratingmean[C][Y2020]=(ratingmean[B][Y2020]+temp->rating)/Count[B];
                            SD[C][Y2020]=((temp->rating-ratingmean[C][Y2020]));}
                        }
                    }
                }
                if(head==NULL)
                  {head=temp;
                  tail=temp;}
                else
                  {tail->next=temp;
                  tail=tail->next;}
            }
        }
        else
        {cout<<"exit";}
    }
    void CalStanDev()
    { 
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                StdDev[i][j]=StdDev[i][j]+(SD[i][j]*SD[i][j]);
                StdDev[i][j]=StdDev[i][j]/100;
            }
        }
        StdDev[2][2]=1;
    }
    void CalMean()
    {
        Mean_Year[A][Y2019]=BranchSale_Year[A][Y2019]/Quantity_Year[A][Y2019];
        Mean_Year[B][Y2019]=BranchSale_Year[B][Y2019]/Quantity_Year[B][Y2019];
        Mean_Year[C][Y2019]=BranchSale_Year[C][Y2019]/Quantity_Year[C][Y2019];
        Mean_Year[A][Y2020]=BranchSale_Year[A][Y2020]/Quantity_Year[A][Y2020];
        Mean_Year[B][Y2020]=BranchSale_Year[B][Y2020]/Quantity_Year[B][Y2020];
        Mean_Year[C][Y2020]=BranchSale_Year[C][Y2020]/Quantity_Year[C][Y2020];
    }
    void CalGradient()
    {
        gradient[A]=(Mean_Year[A][Y2020]-Mean_Year[A][Y2019])/(12-0);
        gradient[B]=(Mean_Year[B][Y2020]-Mean_Year[B][Y2019])/(12-0);
        gradient[C]=(Mean_Year[C][Y2020]-Mean_Year[C][Y2019])/(12-0);
    }
    void GetGraph(int Branch)
    {
        for(int i=0;i<2;i++)
        {
            int j;
            if(i==0){
                cout<<" 2019: ";
            for(j=0;j<Frequency[Branch][i];j+=1) 
            {cout <<"\xB2";}
            cout<<" <"<<Frequency[Branch][i]<<"> ";}
            else{
                cout<<" 2020: ";
            for(j=0;j<Frequency[Branch][i];j+=1) 
            {cout <<"\xB1";}
            cout<<" <"<<Frequency[Branch][i]<<"> ";}
            cout <<"\n\n";
        }
    }   
    void Graph1()
    {
        int Grad=0;
        for(int i=0;i<3;i++)
        {
            cout<<"------------------------------"<<endl;
            cout<<"<BRANCH "<<ch[i]<<">"<<endl;
            for(int j=0;j<6;j++)
            {
                cout<<"\n "<<Type[j]<<": ";
                for(int k=0;k<(Quantity_Product[i][j][0])/12;k++)
                {cout<<"\xB2";}
                cout<<" <"<<Quantity_Product[i][j][0]<<" >";
                cout<<"\n "<<Type[j]<<": ";
                for(int k=0;k<(Quantity_Product[i][j][1])/12;k++)
                {cout<<"\xB1";}
                cout<<" <"<<Quantity_Product[i][j][1]<<" >";
                cout<<endl;
            }
            cout <<"\n";
            MaxProduct(i);   
            cout<<"CONCLUSION :\n Branch "<<ch[i]<<" should increase stock of "<<Type1[highest]<<" section.\n"<<endl;
            getch();
        }   
    }
    void MaxProduct(int branch)
    {
        int m=-9999;
        for(int j=0;j<6;j++)
        {
            Mean_Quantity[branch][j]=((Quantity_Product[branch][j][0]/2)*0.30)+Quantity_Product[branch][j][1]*0.70;    // linear regression
            sort[j]=Mean_Quantity[branch][j]; // saving all sales (mean)
        }
        for(int i=0;i<6;i++)
        {
            if(sort[i]>m)
            {
                m=sort[i];
                highest=i;
            }
        }
    }
    void AnalysisByYear()
    {
        CalGradient();
        cout<<"<BRANCH A> : \n\n";
        GetGraph(A);
        if(gradient[A]<1)
        {cout<<" CONCLUSION:\n Branch A sales has Decreace in last 1 years\n\n";}
        else{cout<<"CONCLUSION:\n Branch A sales has Increased in last 1 years\n\n";}
        getch();
        system("CLS");
        cout<<"<BRANCH B> : \n\n";
        GetGraph(B);
        if(gradient[B]<1)
        {cout<<" CONCLUSION:\n Branch B sales has Decreace in last 1 years\n\n";}
        else{cout<<"CONCLUSION:\n Branch B sales has Increased in last 1 years\n\n";}
        getch();
        system("CLS");
        cout<<"<BRANCH C> : \n\n";
        GetGraph(C);
        if(gradient[C]<1)
        {cout<<" CONCLUSION:\n Branch C sales has Decreace in last 1 years\n\n";}
        else{cout<<"CONCLUSION:\n Branch C sales has Increased in last 1 years\n\n";}
    }
    void Display_StdDev(int b)
    {
        for(int j=0;j<2;j++)
        {   
            cout<<"STANDARD DEVIATION : <"<<StdDev[b][j]<<">";
            cout<<"\n Conclusion Year "<<j+1<<" : ";
            if(StdDev[b][j]>=0.9)
             {cout<<" Customer rating varies hence sales may Decrease.\n\n ";}
            else{cout<<" Customer rating are stable hence sales may Increase.\n\n ";}
        }
    }
    void DisplayData()
    {Customer *temp=head;
        while(temp!=NULL)
        {cout<<temp->branch<<"\t";
        cout<<temp->type<<"\t";
        cout<<temp->price<<"\t";
        cout<<temp->quantity<<"\t"; 
        cout<<temp->total<<"\t";
        cout<<temp->year<<"\t";
        cout<<temp->rating<<"\t";
        cout<<endl;
        temp=temp->next;}
    } 
    void Display_Branch_Sale()
    {cout<<"\n #   | 2019"<<"\t2020"<<endl;
    cout<<"------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<" "<<ch[i]<<"   |";
        for(int j=0;j<2;j++)
        {
            cout<<" "<<BranchSale_Year[i][j]<<"\t";
        }
        cout<<endl;
    }} 
    void Display_Branch_Mean()
    {cout<<"\n MEAN| 2019"<<"\t2020"<<endl;
    cout<<"------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<" "<<ch[i]<<"   |";
        for(int j=0;j<2;j++)
        {
            cout<<" "<<Mean_Year[i][j]<<"\t";
        }
        cout<<endl;
    }}
    void Display_Product_Sale()
    {
    cout<<"\n #19 |";
    for(int i=0;i<6;i++)
    {cout<<" "<<left<<setw(10)<<Type[i];}
    cout<<"\n--------------------------------------------------------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<" "<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<" "<<left<<setw(10)<<BranchSale_Product[i][j][Y2019];
        }
        cout<<endl;
    }
    cout<<"\n #20 |";
    for(int i=0;i<6;i++)
    {cout<<" "<<left<<setw(10)<<Type[i];}
    cout<<"\n--------------------------------------------------------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<" "<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<" "<<left<<setw(10)<<BranchSale_Product[i][j][Y2020];
        }
        cout<<endl;
    }}
    void Display_Product_Quantity()
    {cout<<"\n#19 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<Quantity_Product[i][j][Y2019];
        }
        cout<<endl;
    }
    cout<<"\n#20 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<Quantity_Product[i][j][Y2020];
        }
        cout<<endl;
    }}
};
void main_menu()
{
    Data ob1;
    ob1.ReadData();
    ob1.CalMean();

    Here1:
    system("CLS");    
    system("color f1");
       cout<<endl<<endl<<endl;
       cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";
       cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";        
       cout<<"                      \xB2\xB2                         ------------WELCOME TO SGA------------                    \xB2\xB2\n";
       cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
       cout<<"                      \xB2\xB2                           1. VIEW STATSISTICS                                     \xB2\xB2\n";
       cout<<"                      \xB2\xB2                           2. VIEW ANALYSIS                                        \xB2\xB2\n";
       cout<<"                      \xB2\xB2                           3. VIEW PEROFMANCES                                     \xB2\xB2\n";
       cout<<"                      \xB2\xB2                           0. EXIT                                                 \xB2\xB2\n";
       cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
	   cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";
       
	   cout<<"\n\n\n ---------------------";
	   int mchoice;
       cout<<"\n~ENTER YOUR CHOICE: ";
       cin>>mchoice;

switch(mchoice)
{
    case 1:
    {
        Here2:
        system("CLS");
    	system("color f1");
        cout<<endl<<endl<<endl;
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";        
        cout<<"                      \xB2\xB2                         ------------WELCOME TO SGA------------                    \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           1. VIEW TOTAL ANNUAL SALES                              \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           2. VIEW MEAN ANNUAL SALES                               \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           3. VIEW SALES BY DEPARTMENT                             \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           0. BACK                                                 \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";	 
        cout<<"\n\n\n   Enter Choice : ";
	 	int choice12;
	 	cin>>choice12;
        system("CLS");
		if(choice12==1)
	 	 {cout<<"TOTAL ANNUAL SALES :\n";
          cout<<"------------------------"<<endl;
         ob1.Display_Branch_Sale();
         cout<<"\nBRANCH A : \n";
         cout<<"------------------------"<<endl;
         cout<<" Cumulative Frequency : \n\n";
         ob1.GetGraph(A);                       // calculated using frequency
         cout<<"\nBRANCH B : \n";
         cout<<"------------------------"<<endl;
         cout<<" Cumulative Frequency : \n\n";
         ob1.GetGraph(B);
         cout<<"\nBRANCH C: \n";
         cout<<"------------------------"<<endl;
         cout<<" Cumulative Frequency : \n\n";
         ob1.GetGraph(C);
         _getch();
         goto Here2;}
        else if(choice12==2)
	 	  {cout<<"MEAN ANNUAL SALES :\n";
          cout<<"------------------------"<<endl;
          ob1.Display_Branch_Mean();
	      _getch();
          goto Here2;}
        else if(choice12==3)
	 	  {cout<<"SALES BY DEPARTMENT :\n";
          cout<<"------------------------"<<endl;
          ob1.Display_Product_Sale();
         _getch();
         goto Here2;}
		else if(choice12==0)
		 {goto Here1;}
        else{cout<<" Invalid Input\n ";
        cout<<"\n\n-----------------------------------"<<endl;
        cout<<"PRESS ANY KEY TO CONTINUE......."<<endl;
        cout<<"-----------------------------------"<<endl;
        getch();
        goto Here2;}
    }
    case 2:
    {
        Here3:
        system("CLS");
    	system("color f1");
        cout<<endl<<endl<<endl;
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";        
        cout<<"                      \xB2\xB2                         ------------WELCOME TO SGA------------                    \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           1. ANALYSIS BY ANNUAL SALES                             \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           2. ANALYSIS BY DEPARTMENTAL SALES                       \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           3. ANALYSIS BY CUSTOMER RATINGS                         \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           0. BACK                                                 \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";	 
        cout<<"\n\n\n   Enter Choice : ";
	 	int choice12;
	 	cin>>choice12;
         system("CLS");
		if(choice12==1)
	 	 {cout<<"ANALYSIS BY ANNUAL SALES :\n";
          cout<<"------------------------"<<endl;
          ob1.AnalysisByYear();     // uses gradient (MEANS sales)
         _getch();
         goto Here3;}
        else if(choice12==2)
	 	 {cout<<"ANALYSIS BY DEPARTMENTAL SALES :\n"; // using unit sold with linear regression 
          ob1.Graph1();
         _getch();
         goto Here3;}
        else if(choice12==3)
	 	{
            ob1.CalStanDev();
            cout<<"\nBRANCH A : \n";
            cout<<"------------------------"<<endl;
            ob1.Display_StdDev(A);
            _getch();
            cout<<"\nBRANCH B : \n";
            cout<<"------------------------"<<endl;
            ob1.Display_StdDev(B);
            _getch();
            cout<<"\nBRANCH C : \n";
            cout<<"------------------------"<<endl;
            ob1.Display_StdDev(C);
	        _getch();
            goto Here3;
		}
        else if(choice12==0)
		 {goto Here1;}
        else{cout<<"Invalid Input\n ";
         cout<<"\n\n-----------------------------------"<<endl;
         cout<<"PRESS ANY KEY TO CONTINUE......."<<endl;
         cout<<"-----------------------------------"<<endl;
         getch();
         goto Here3;}
    }
    case 3:
    {
        Here4:
        system("CLS");
    	system("color f1");
        cout<<endl<<endl<<endl;
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";        
        cout<<"                      \xB2\xB2                         ------------WELCOME TO SGA------------                    \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           1. BRANCH A                                             \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           2. BRANCH B                                             \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           3. BRANCH C                                             \xB2\xB2\n";
        cout<<"                      \xB2\xB2                           0. BACK                                                 \xB2\xB2\n";
        cout<<"                      \xB2\xB2                                                                                   \xB2\xB2\n";
        cout<<"                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n";	 
        cout<<"\n\n\n   Enter Choice : ";
	 	int choice12;
	 	cin>>choice12;
         system("CLS");
		if(choice12==1)
	 	 {ob1.Display_Product_Quantity();
         cout<<endl;
         ob1.GetGraph(A);
         getch();
         goto Here4;}
        else if(choice12==2)
	 	 {ob1.Display_Product_Quantity();
         cout<<endl;
         ob1.GetGraph(B);
         getch();
         goto Here4;}
        else if(choice12==3)
	 	 {ob1.Display_Product_Quantity();
         cout<<endl;
         ob1.GetGraph(C);
         getch();
         goto Here4;}
		else if(choice12==0)
		 {goto Here1;}
        else{cout<<"Invalid Input\n ";
        cout<<"\n\n-----------------------------------"<<endl;
        cout<<"PRESS ANY KEY TO CONTINUE......."<<endl;
        cout<<"-----------------------------------"<<endl;
        getch();


        goto Here4;}
    }
    case 0:
    {exit(0);}
    default :
    {cout<<"Invalid Input\n";
    cout<<"\n\n-----------------------------------"<<endl;
    cout<<"PRESS ANY KEY TO CONTINUE......."<<endl;
    cout<<"-----------------------------------"<<endl;
    getch();
    main_menu();}
    break;
    }
}

int main()
{
    Title_Page();
    main_menu();
    Data ob;
    ob.ReadData();
    ob.CalMean();
    // ob.DisplayData(); 
    // ob.Display_Branch_Sale();
    // ob.Display_Product_Sale(); 
    // cout<<endl;
    // ob.Display_Product_Quantity();
    // ob.Display_Branch_Mean();
    // ob.GetGraph(C);
    // ob.AnalysisByYear();
    // ob.Graph1();
    // ob.MaxProduct(A);
    // ob.CalStanDev();
    return 0;
}