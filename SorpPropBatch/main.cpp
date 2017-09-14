#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "sorpproplib.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile iFile("input.txt");
    QFile oFile("output.txt");
    std::string ref, sorb;
    double tK, xMass;
    for(char exit = 'n';exit != 'y';){

        if(!iFile.exists()){
            std::cout<<"input file not found,\nstart single point inquiry:\n";

            std::cout<<"\n\nPlease enter the refrigerant, sorbate, temperature[k], and mass fraction of sorbate[0.01].\n";

            std::cin>>ref>>sorb>>tK>>xMass;

            std::cout<<"temperature[K]\tmass ratio\tpressure[kPa]\tequation form\treference\n";

            SorpPropLib *sLib = new SorpPropLib;

            sLib->calc(ref,sorb,tK,xMass);

            delete sLib;
        }
        else{
            if(iFile.open(QIODevice::ReadOnly)){

                bool write = true;
                if(!oFile.open(QIODevice::WriteOnly)){
                    std::cout<<"failed to open output file.\n";
                    write = false;
                }


                SorpPropLib *sLib = new SorpPropLib;
                QTextStream in(&iFile);
                QTextStream out(&oFile);

                std::string str;

                QString ref_s, sorb_s, tK_s, xMass_s;
                while (!in.atEnd()){
                    QString line = in.readLine();
                    if(line.startsWith("ref/sorb")){

                        if(write){
                            out<<line<<'\n';
                            out<<"t[K]\tmass ratio\tp[kPa]\tequation form\treference\n";
                        }

                        ref_s = line.split("\t").at(1);
                        sorb_s = line.split("\t").at(2);

                        ref = ref_s.toStdString();
                        sorb = sorb_s.toStdString();                        

                        std::cout<<"ref: "<<ref<<" sorb: "<<sorb<<"\n";
                        std::cout<<"t[K]\tmass ratio\tpressure[kPa]\tequation form\treference\n";
                    }
                    else if(line.at(0).isDigit()){
                        tK_s= line.split("\t").at(0);
                        tK = tK_s.toDouble();
                        xMass_s = line.split("\t").at(1);
                        xMass = xMass_s.toDouble();

                        str=sLib->calc(ref,sorb,tK,xMass);
                        if(write){
                            out<<QString::fromStdString(str);
                        }
                    }

                }
                delete sLib;

                in.flush();
                iFile.close();
            }
        }

        std::cout<<"\nexit?[y/n]\n";
        std::cin>>exit;

    }

    return 0;
}
