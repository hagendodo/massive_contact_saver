#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void header(){
    cout<<"==========================================\n"
        <<"||            Contact Saver             ||\n"
        <<"==========================================\n"
        <<endl;
}

int main(){
    header();
    ofstream myFile;
    int n;
    string filename,format_name;

    cout<<"Masukan nama file: ";
    cin>>filename;
    cout<<"Masukan banyaknya kontak: ";
    cin>>n;
    string* nomor = new string[n];
    cout<<"Masukan format nama kontak (tanpa spasi atau diganti dengan \"_\"): ";
    cin>>format_name;
    cout<<endl;
    cout<<"*Disarankan menggunakan satu jenis format \"08\" atau \"+62\""<<endl;
    for(int j=0;j<n;j++){
        cout<<"Masukan kontak ke-"<<j+1<<" : ";
        cin>>nomor[j];
        if(nomor[j][0]=='0'){
            nomor[j].replace(0,1,"+62");
        }else if(nomor[j][0]=='8'){
            nomor[j].replace(0,1,"+628");
        }else if(nomor[j][0]=='+'){
        }
    }

    string ext = ".vcf";
    string filename_final = filename+ext;

    myFile.open(filename_final,ios::app);
        for(int i=0;i<n;i++){
            myFile  <<"BEGIN:VCARD"<<endl
                    <<"VERSION:3.0"<<endl
                    <<"N:;"<<format_name<<"_"<<i+1<<";;;"<<endl
                    <<"FN:"<<format_name<<"_"<<i+1<<endl
                    <<"TEL;TYPE=CELL:"<<nomor[i]<<endl
                    <<"END:VCARD"<<endl;
        }
    myFile.close();
    system("cls");
    header();
    cout<<"process success...\n"
        <<n<<" contact added...\n"
        <<"+------------------------------------------------+\n"
        <<"file name : "<<filename<<"\n"
        <<"format name : "<<format_name<<"_xxx\n"
        <<"+------------------------------------------------+\n\n"
        <<"Press Enter for close the Application"
        <<endl;

    system("pause>0");
    delete [] nomor;
    return 0;
}