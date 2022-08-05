#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

signed main()
{   
    int region_no;
    int salesman_no;
    int product_code;
    int no_of_units;

    int records[4][6];
    for(int i=0; i<4; i++)
        for(int j=0; j<6; j++)
            records[i][j] = 0;

    int price_lookup[8][2] = {{1102, 450},{1103, 550},{1104,650},{1105,750},{2101,500},{2102,600},{2103,700},{2104,800}};

    ifstream fin("input.txt");
    
    while(fin)
    {
        fin >> region_no >> salesman_no >> product_code >> no_of_units;
        
        int temp = records[region_no-1][salesman_no-1];
        for(int i=0; i<8; i++)
            if(price_lookup[i][0] == product_code)
                temp += price_lookup[i][1]*no_of_units;

        records[region_no-1][salesman_no-1] = temp;    
        if(fin.eof())
            break; 
    }

    fin.close();

    ofstream fout("output.txt");
    double total = 0;
    time_t t = time(0);
    tm *now = localtime(&t);
    fout<<"__________________REGIONAL_SALES_RECORD__________________"<<endl;
    fout<<"..................Generated on "<<(now->tm_mday)<<"_"<<(now->tm_mon+1)<<"_"<< (now->tm_year+1900)<<".................."<<endl;

    fout<<"_________________________________________________________"<< endl;
    for(int i=0; i< 4; i++)
    {
        fout<<"---------------------------------------------------------"<< endl;
        fout << "Region "<< i+1 << endl << "---------------------------------------------------------"<< endl;
        total = 0;
        for(int j= 0; j < 6; j++)
        {
            total += records[i][j];
            fout<<"Salesman " << j+1 << " is Rs " << records[i][j] << endl;
        }
        fout<<"Total Sale at Region " <<i+1<<" Rs "<< total <<endl<<endl;
    }
    fout.close();
}
