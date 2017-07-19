#include <QCoreApplication>

#include "sorpproplib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SorpPropLib *sLib = new SorpPropLib;

    std::string ref, sorb;
    double tK, xMass;

    for(char exit = 'n';exit != 'y';){
        std::cout<<"\n\nPlease enter the refrigerant, sorbate, temperature[k], and mass fraction of sorbate[0.01].\n";

        std::cin>>ref>>sorb>>tK>>xMass;

        std::cout<<"temperature[K]\tmass ratio\tpressure[kPa]\tequation form\treference\n";

        sLib->calc(ref,sorb,tK,xMass);

//        std::cout<<"\n\nDo you wish to exit? [y/n]\n";

//        std::cin>>exit;
    }

    return 0;
}
